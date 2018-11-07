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

#include <boost/program_options.hpp>
namespace po = boost::program_options;

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
#include "datatype.h"
#include "file_server.h"

#endif //CPPBLOG_CONFIG_H
