#include <cppcms/application.h>  
#include <cppcms/applications_pool.h>  
#include <cppcms/service.h>  
#include <cppcms/http_response.h>
#include <iostream>
#include "content.h"

class hello : public cppcms::application {
public:
    hello(cppcms::service &srv) :
        cppcms::application(srv)
    {
    }
    virtual void main(std::string url);
};


void hello::main(std::string /*url*/)
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
