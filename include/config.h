//
// Created by roy on 18-11-6.
//

#ifndef CPPBLOG_CONFIG_H
#define CPPBLOG_CONFIG_H

#include <cppcms/application.h>
#include <cppcms/applications_pool.h>
#include <cppcms/service.h>
#include <cppcms/http_response.h>
#include <cppcms/http_request.h>
#include <cppcms/url_dispatcher.h>
#include <cppcms/url_mapper.h>
#include <cppcms/mount_point.h>
#include <cppcms/util.h>

#include <soci/soci.h>
#include <soci/connection-pool.h>
#include <soci/mysql/soci-mysql.h>

#include <maddy/parser.h>

#include <iostream>
#include <stdlib.h>
#include <memory>
#include <string>
#include <cstdio>

#include "content.h"
#include "content_article.h"
#include "datatype.h"
#include "file_server.h"
#include "markdown.h"


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


#endif //CPPBLOG_CONFIG_H
