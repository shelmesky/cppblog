//
// Created by roy on 18-11-3.
//

#ifndef CPPBLOG_CONTENT_H
#define CPPBLOG_CONTENT_H


#include <cppcms/view.h>
#include <string>
#include "datatype.h"

namespace content  {
    struct message : public cppcms::base_content {
        std::string text;
        std::list<article>article_list;
    };
}

#endif //CPPBLOG_CONTENT_H
