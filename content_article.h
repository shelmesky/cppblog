//
// Created by roy on 18-11-8.
//

#ifndef CPPBLOG_CONTENT_ARTICLE_H
#define CPPBLOG_CONTENT_ARTICLE_H

#include <cppcms/view.h>
#include <string>
#include "datatype.h"

namespace content  {
    struct message_article : public cppcms::base_content {
        std::string title;
        std::string keyword;
        std::string real_body;
    };
}

#endif //CPPBLOG_CONTENT_ARTICLE_H
