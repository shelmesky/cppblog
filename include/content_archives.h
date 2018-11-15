//
// Created by roy on 18-11-15.
//

#ifndef CPPBLOG_CONTENT_ARCHIVES_H
#define CPPBLOG_CONTENT_ARCHIVES_H

#include <cppcms/view.h>
#include <string>
#include "datatype.h"

namespace content  {
    struct message_archives : public cppcms::base_content {
        std::list<article>archives_list;

        int prev_page_number;
        int next_page_number;
    };
}

#endif //CPPBLOG_CONTENT_ARCHIVES_H
