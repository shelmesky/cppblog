//
// Created by roy on 18-11-5.
//

#ifndef CPPBLOG_DATATYPE_H
#define CPPBLOG_DATATYPE_H

#include <iostream>

struct article {
    int id;
    std::string title;
    std::string keyword;
    std::string dummy_body;
    std::string real_body;
};

#endif //CPPBLOG_DATATYPE_H
