#include "config.h"

const size_t poolSize = 20;
soci::connection_pool db_pool(poolSize);
Cache<int, std::string> dummyBodyCache;


int initSOCIConnectionPool() {
    try {
        for (size_t i = 0; i != poolSize; i++) {
            soci::session &sql = db_pool.at(i);
            sql.open("mysql", "db=cppblog user=root password='4974481lmh'");
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
        mapper().assign("number", "/number/{1}");

        dispatcher().assign("/smile", &cppblog::smile, this);
        mapper().assign("smile", "/smile");

        dispatcher().assign("/", &cppblog::index, this);
        mapper().assign("");

        mapper().root("/");
    }
    void index();
    void show_article(std::string number);
    void smile();
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


void cppblog::index()
{
    std::shared_ptr<maddy::Parser> parser = std::make_shared<maddy::Parser>();

    std::list<article>article_list;
    soci::session sql(db_pool);

    int articles_count;
    sql << "select count(*) from articles", soci::into(articles_count);

    if (articles_count > 0) {
        soci::rowset<soci::row> rs = (sql.prepare << "select id, title, keyword, dummy_body, real_body from articles");

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

    content::message c;
    c.article_list = article_list;
    c.text=">>>Hello<<<";
    render("message",c);
}


int main(int argc,char ** argv)
{
    initSOCIConnectionPool();

    try {
        cppcms::service srv(argc,argv);
        srv.applications_pool().mount(cppcms::applications_factory<cppblog>());
        srv.run();
    }
    catch(std::exception const &e) {
        std::cerr << e.what() << std::endl;
    }
}
