#include "config.h"


const int number_per_page = 5;
const size_t poolSize = 20;
soci::connection_pool db_pool(poolSize);
Cache<int, std::string> dummyBodyCache;


int initSOCIConnectionPool(std::string const& db_type, std::string const& db_conn) {
    try {
        for (size_t i = 0; i != poolSize; i++) {
            soci::session &sql = db_pool.at(i);
            sql.open(db_type, db_conn);
        }
    } catch(std::exception const &e) {
        std::cout << "init soci connection poll failed: " << e.what() << std::endl;
        return -1;
    }

    return 0;
}


class cppblog : public cppcms::application {
public:
    cppblog(cppcms::service &srv) :
        cppcms::application(srv)
    {
        dispatcher().assign("/article/(\\d+)", &cppblog::show_article, this, 1);
        mapper().assign("article", "/article/{1}");

        dispatcher().assign("/smile", &cppblog::smile, this);
        mapper().assign("smile", "/smile");

        dispatcher().assign("/", &cppblog::index, this);
        mapper().assign("");

        dispatcher().assign("/page/(\\d+)", &cppblog::index_page, this, 1);
        mapper().assign("page", "/page/{1}");

        mapper().root("/");
    }
    void index();
    void show_article(std::string number);
    void index_page(std::string number);
    void smile();
    std::list<article> get_articles(int page);
};


void cppblog::show_article(std::string number) {
    int no = atoi(number.c_str());
    response().out() << "This number is " << no << "<br/>\n";
    response().out() << "<a href='" << url("/") << "'>Go back</a>";
}

void cppblog::smile() {
    response().out() << ":-) <br/>\n";
    response().out() << "<a href='" << url("/") << "'>Go back</a>";
}


std::list<article> cppblog::get_articles(int page) {
    std::shared_ptr<maddy::Parser> parser = std::make_shared<maddy::Parser>();

    std::list<article>article_list;
    soci::session sql(db_pool);

    int articles_count;
    sql << "select count(*) from articles", soci::into(articles_count);

    std::string sql_str = "select id, title, keyword, dummy_body, "
                          "real_body from articles limit :limit, :offset";

    if (articles_count > 0) {
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

            std::string dummyBody = dummyBodyCache.Read(a.id);
            if(dummyBody.empty()) {
                std::stringstream dummy_body = std::stringstream(row.get<std::string>(3));
                a.dummy_body = parser->Parse(dummy_body);
                dummyBodyCache.Write(a.id, a.dummy_body);
            } else {
                a.dummy_body = dummyBody;
            }

            a.real_body = row.get<std::string>(4);
            article_list.push_back(a);
        }
    } else {
        std::cout << "articles is empty" << std::endl;
    }

    return article_list;
}


void cppblog::index_page(std::string number) {
    int page = atoi(number.c_str());
    std::list<article> article_list = get_articles(page);

    content::message c;
    c.article_list = article_list;
    if(page == 1) {
        c.prev_page_number = 1;
    } else {
        c.prev_page_number = page - 1;
    }
    c.next_page_number = page + 1;
    c.text=">>>Hello<<<";
    render("message",c);
}


void cppblog::index()
{
    std::list<article> article_list = get_articles(1);

    content::message c;
    c.article_list = article_list;
    c.text=">>>Hello<<<";
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
