#include <cppcms/application.h>  
#include <cppcms/applications_pool.h>  
#include <cppcms/service.h>  
#include <cppcms/http_response.h>
#include <cppcms/http_request.h>
#include <cppcms/url_dispatcher.h>
#include <cppcms/url_mapper.h>

#include <soci/soci.h>
#include <soci/connection-pool.h>
#include <soci/mysql/soci-mysql.h>

#include <iostream>
#include <stdlib.h>

#include "content.h"

const size_t poolSize = 10;
soci::connection_pool db_pool(poolSize);

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
    //virtual void main(std::string url);
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
    soci::session sql(db_pool);
    soci::rowset<soci::row> rs = (sql.prepare << "select id, title, keyword, dummy_body, real_body from articles");

    for(soci::rowset<soci::row>::const_iterator it=rs.begin(); it != rs.end(); ++it) {
        soci::row const& row = *it;
        std::cout << "ID: " << row.get<int>(0) << '\n'
        << "title: " << row.get<std::string>(1) << '\n'
        << "keyword: " << row.get<std::string>(2) << '\n'
        << "dummy_body: " << row.get<std::string>(3) << '\n'
        << "real_body: " << row.get<std::string>(4) << '\n';
    }

    std::cout << "remote_addr:" << request().remote_addr() << std::endl;
    content::message c;
    c.text=">>>Hello<<<";
    render("message",c);
}


int main(int argc,char ** argv)
{
    if (initSOCIConnectionPool() != 0) {
        return -1;
    }

    try {
        cppcms::service srv(argc,argv);
        srv.applications_pool().mount(cppcms::applications_factory<cppblog>());
        srv.run();
    }
    catch(std::exception const &e) {
        std::cerr << e.what() << std::endl;
    }
}
