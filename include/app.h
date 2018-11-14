//
// Created by roy on 18-11-14.
//

#ifndef CPPBLOG_APP_H
#define CPPBLOG_APP_H

#include "config.h"


class cppblog : public cppcms::application {
public:
    cppblog(cppcms::service &srv) :
            cppcms::application(srv)
    {
        dispatcher().assign("/article/(\\d+)", &cppblog::show_article, this, 1);
        mapper().assign("article", "/article/{1}");

        dispatcher().assign("/", &cppblog::index, this);
        mapper().assign("");

        dispatcher().assign("/page/(\\d+)", &cppblog::index_page, this, 1);
        mapper().assign("page", "/page/{1}");

        mapper().root("/");
    }
    void index();
    void show_article(std::string number);
    void index_page(std::string number);
    std::list<article> get_articles(int page);
    article get_single_article(int id);
};


#endif //CPPBLOG_APP_H
