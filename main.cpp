#include <cppcms/application.h>  
#include <cppcms/applications_pool.h>  
#include <cppcms/service.h>  
#include <cppcms/http_response.h>
#include <cppcms/url_dispatcher.h>
#include <cppcms/url_mapper.h>

#include <iostream>
#include <stdlib.h>

#include "content.h"

class hello : public cppcms::application {
public:
    hello(cppcms::service &srv) :
        cppcms::application(srv)
    {
        dispatcher().assign("/number/(\\d+)", &hello::number, this, 1);
        mapper().assign("number", "/number/{1}");

        dispatcher().assign("/smile", &hello::smile, this);
        mapper().assign("smile", "/smile");

        dispatcher().assign("", &hello::index, this);
        mapper().assign("");

        mapper().root("/");
    }
    //virtual void main(std::string url);
    void index();
    void number(std::string number);
    void smile();
    void welcome();
};


void hello::number(std::string number) {
    int no = atoi(number.c_str());
    response().out() << "This number is " << no << "<br/>\n";
    response().out() << "<a href='" << url("/") << "'>Go back</a>";
}

void hello::smile() {
    response().out() << ":-) <br/>\n";
    response().out() << "<a href='" << url("/") << "'>Go back</a>";
}

void hello::welcome() {
    response().out() <<
    "<h1> Welcome To Page with links </h1>\n"
    "<a href='" << url("/number",1)  << "'>1</a><br>\n"
    "<a href='" << url("/number",15) << "'>15</a><br>\n"
    "<a href='" << url("/smile") << "' >:-)</a><br>\n";
}


void hello::index()
{
    content::message c;
    c.text=">>>Hello<<<";
    render("message",c);
}


int main(int argc,char ** argv)
{
    try {
        cppcms::service srv(argc,argv);
        srv.applications_pool().mount(cppcms::applications_factory<hello>());
        srv.run();
    }
    catch(std::exception const &e) {
        std::cerr << e.what() << std::endl;
    }
}
