#include "config.h"


const int number_per_page = 10;
const size_t poolSize = 20;
std::shared_ptr<soci::connection_pool> db_pool = nullptr;
std::shared_ptr<Cache<int, std::string>> dummyBodyCache = nullptr;
std::shared_ptr<Cache<int, std::string>> realBodyCache = nullptr;


void init() {
    try {
        db_pool = std::make_shared<soci::connection_pool>(poolSize);
        dummyBodyCache = std::make_shared<Cache<int, std::string>>();
        realBodyCache = std::make_shared<Cache<int, std::string>>();
    } catch(std::exception& e){
        std::cerr << e.what() << std::endl;
    }
}


int initSOCIConnectionPool(std::string const& db_type, std::string const& db_conn) {
    try {
        for (size_t i = 0; i != poolSize; i++) {
            soci::session &sql = db_pool->at(i);
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
    std::shared_ptr<maddy::Parser> parser = std::make_shared<maddy::Parser>();
    article ret;

    soci::session sql(*db_pool);

    using namespace soci;

    sql << "set names utf8mb4";
    sql << "select id, title, IFNULL(keyword, ''), IFNULL(real_body, '') from articles where id= "
        << id, into(ret.id), into(ret.title), into(ret.keyword), into(ret.real_body);

    std::string realBody = realBodyCache->Read(id);

    if(realBody.empty()) {
        MKIOT blob((char *)ret.real_body.c_str(), ret.real_body.size(), 0);
        blob.compile(0);

        char *output_buffer;

        blob.document(&output_buffer);

        ret.real_body = std::string(output_buffer);
        realBodyCache->Write(id, ret.real_body);
    } else {
        ret.real_body = realBody;
    }

    return ret;
}


std::list<article> cppblog::get_articles(int page) {
    std::shared_ptr<maddy::Parser> parser = std::make_shared<maddy::Parser>();

    std::list<article>article_list;
    soci::session sql(*db_pool);

    sql << "Set NAMES utf8mb4";

    std::string sql_str = "select id, title, IFNULL(keyword, ''), IFNULL(dummy_body, ''), "
                          "real_body from articles order by id desc limit :limit, :offset";

    int limit = (page-1)*number_per_page;
    int offset = number_per_page;
    soci::rowset<soci::row> rs =
            (sql.prepare << sql_str, soci::use(limit), soci::use(offset));

    for (soci::rowset<soci::row>::const_iterator it = rs.begin(); it != rs.end(); ++it) {
        article a;
        soci::row const &row = *it;

        a.id = row.get<int>(0);
        a.title = row.get<std::string>(1);
        a.keyword = row.get<std::string>(2);

        std::string dummyBody = dummyBodyCache->Read(a.id);
        if(dummyBody.empty()) {
            std::string input = row.get<std::string>(3);

            MKIOT blob((char *)input.c_str(), input.size(), 0);
            blob.compile(0);

            char *output_buffer;

            blob.document(&output_buffer);

            a.dummy_body = std::string(output_buffer);
            dummyBodyCache->Write(a.id, a.dummy_body);

        } else {
            a.dummy_body = dummyBody;
        }

        a.real_body = row.get<std::string>(4);
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
    init();

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
