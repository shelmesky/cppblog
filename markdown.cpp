//
// Created by roy on 18-11-7.
//

#include <iostream>
#include <cstring>
#include "markdown.h"


Markdown::Markdown(char *data) :_input_buffer(data){
    if( (doc = mkd_string(data, int(strlen(data)), MKD_TOC)) == nullptr ) {
        throw std::runtime_error("mkd_string init failed!");
    }
    _output_buffer = (char *)malloc(strlen(data));
}


Markdown::~Markdown() {
    if(_output_buffer != nullptr) {
        std::cout << "free _output_buffer" << std::endl;
        free(_output_buffer);
    }
}

char * Markdown::render() {
    if( !mkd_compile(doc, 0)) {
        std::cout << "compile failed!" << std::endl;
        return nullptr;
    }

    int ret = mkd_document(doc, &_output_buffer);
    if(ret == 0) {
        return nullptr;
    }

    return _output_buffer;
}
