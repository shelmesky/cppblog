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

        dispatcher().assign("/archives", &cppblog::archives, this);
        mapper().assign("/archives");

        dispatcher().assign("/page/(\\d+)", &cppblog::index_page, this, 1);
        mapper().assign("page", "/page/{1}");

        mapper().root("/");
    }

    void index();
    void archives();
    void show_article(std::string number);
    void index_page(std::string number);
    std::list<article> get_articles(int page);
    article get_single_article(int id);
};


class GlobalConfig{
public:
    explicit GlobalConfig(int poolSize = 10, int number_per_page=20)
    : number_per_page(number_per_page), poolSize(poolSize) {
        try {
            db_pool = std::make_shared<soci::connection_pool>(poolSize);
            dummyBodyCache = std::make_shared<Cache<int, std::string>>();
            realBodyCache = std::make_shared<Cache<int, std::string>>();
        } catch(std::exception& e){
            std::cerr << e.what() << std::endl;
        }
    }

    GlobalConfig(const GlobalConfig&) = delete;
    GlobalConfig& operator = (const GlobalConfig&) = delete;

    int poolSize = 0;
    int number_per_page = 0;
    std::shared_ptr<soci::connection_pool> db_pool = nullptr;
    std::shared_ptr<Cache<int, std::string>> dummyBodyCache = nullptr;
    std::shared_ptr<Cache<int, std::string>> realBodyCache = nullptr;
};


#endif //CPPBLOG_APP_H
