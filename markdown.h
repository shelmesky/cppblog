#ifndef CPPBLOG_MARKDOWN_H
#define CPPBLOG_MARKDOWN_H

#include "mkdio.h"

class Markdown {
public:
    explicit Markdown(char *data);

    Markdown(const Markdown&) = delete;
    Markdown operator=(const Markdown&) = delete;

    ~Markdown();

    char * render();

private:
    char *_input_buffer;
    char *_output_buffer;
    MMIOT *doc;
};

#endif