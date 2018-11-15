#include "app.h"

GlobalConfig globalConfig(10, 15);


int initSOCIConnectionPool(std::string const& db_type, std::string const& db_conn) {
    try {
        for (size_t i = 0; i != globalConfig.poolSize; i++) {
            soci::session &sql = globalConfig.db_pool->at(i);
            sql.open(db_type, db_conn);
        }
    } catch(std::exception const &e) {
        std::cout << "init soci connection poll failed: " << e.what() << std::endl;
        return -1;
    }

    return 0;
}


void cppblog::show_article(std::string number) {
    int no = std::stoi(number);
    const article& ret = get_single_article(no);
    content::message_article message;
    message.title = ret.title;
    message.keyword = ret.keyword;
    message.real_body = ret.real_body;

    render("message_article", message);
}


article cppblog::get_single_article(int id) {
    article ret;

    soci::session sql(*globalConfig.db_pool);

    using namespace soci;

    sql << "set names utf8mb4";
    sql << "select id, title, IFNULL(keyword, ''), IFNULL(real_body, '') from articles where id= "
        << id, into(ret.id), into(ret.title), into(ret.keyword), into(ret.real_body);

    std::string realBody = globalConfig.realBodyCache->Read(id);

    if(realBody.empty()) {
        MKIOT blob((char *)ret.real_body.c_str(), ret.real_body.size(), 0);
        blob.compile(0);

        char *output_buffer;

        blob.document(&output_buffer);

        ret.real_body = std::string(output_buffer);
        globalConfig.realBodyCache->Write(id, ret.real_body);
    } else {
        ret.real_body = realBody;
    }

    return ret;
}


std::list<article> cppblog::get_articles(int page) {
    std::list<article>article_list;
    soci::session sql(*globalConfig.db_pool);

    char time_buffer[32];

    sql << "set names utf8mb4";

    std::string sql_str = "select id, title, IFNULL(keyword, ''), IFNULL(dummy_body, ''), "
                          "real_body, IFNULL(created_time, CAST('1970-01-01 00:00:01' as DATETIME)) "
                          "from articles order by id desc limit :limit, :offset";

    int limit = (page-1)*globalConfig.number_per_page;
    int offset = globalConfig.number_per_page;
    soci::rowset<soci::row> rs =
            (sql.prepare << sql_str, soci::use(limit), soci::use(offset));

    for (soci::rowset<soci::row>::const_iterator it = rs.begin(); it != rs.end(); ++it) {
        article a;
        soci::row const &row = *it;

        a.id = row.get<int>(0);
        a.title = row.get<std::string>(1);
        a.keyword = row.get<std::string>(2);

        std::string dummyBody = globalConfig.dummyBodyCache->Read(a.id);
        if(dummyBody.empty()) {
            std::string input = row.get<std::string>(3);

            MKIOT blob((char *)input.c_str(), input.size(), 0);
            blob.compile(0);

            char *output_buffer;

            blob.document(&output_buffer);

            a.dummy_body = std::string(output_buffer);
            globalConfig.dummyBodyCache->Write(a.id, a.dummy_body);

        } else {
            a.dummy_body = dummyBody;
        }

        a.real_body = row.get<std::string>(4);
        std::tm created_time = row.get<std::tm>(5);
        std::strftime(time_buffer, 64, "%Y-%m-%d %H:%M:%S", &created_time);
        a.created_time = time_buffer;
        article_list.push_back(a);
    }

    return article_list;
}


void cppblog::index_page(std::string number) {
    int page = std::stoi(number);
    std::list<article> article_list = get_articles(page);

    content::message c;
    c.article_list = article_list;
    if(page == 1) {
        c.prev_page_number = 1;
    } else {
        c.prev_page_number = page - 1;
    }
    c.next_page_number = page + 1;
    render("message",c);
}


void cppblog::index()
{
    std::list<article> article_list = get_articles(1);

    content::message c;
    c.article_list = article_list;
    c.prev_page_number = 1;
    c.next_page_number = 2;
    render("message",c);
}


int main(int argc,char ** argv)
{
    try {
        cppcms::service srv(argc,argv);

        std::string db_type = srv.settings().get("application.db_type","");
        std::string db_conn = srv.settings().get("application.db_conn", "");
        initSOCIConnectionPool(db_type, db_conn);

        auto flags = cppcms::app::synchronous;
        srv.applications_pool().mount(cppcms::create_pool<cppblog>(), cppcms::mount_point(""), flags);
        srv.applications_pool().mount(cppcms::create_pool<file_server>(), cppcms::mount_point("/file"), flags);
        srv.run();
    }
    catch(std::exception const &e) {
        std::cerr << e.what() << std::endl;
    }
}
