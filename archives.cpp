//
// Created by roy on 18-11-15.
//

#include "app.h"

extern GlobalConfig globalConfig;


std::list<article> cppblog::get_archives(int page) {
    std::list<article>article_list;
    soci::session sql(*globalConfig.db_pool);

    sql << "set names utf8mb4";

    std::string sql_str = "select id, title from articles order by id desc limit :limit, :offset";

    int limit = (page-1)*globalConfig.number_per_page;
    int offset = globalConfig.number_per_page;
    soci::rowset<soci::row> rs =
            (sql.prepare << sql_str, soci::use(limit), soci::use(offset));

    for (soci::rowset<soci::row>::const_iterator it = rs.begin(); it != rs.end(); ++it) {
        article a;
        soci::row const &row = *it;

        a.id = row.get<int>(0);
        a.title = row.get<std::string>(1);

        article_list.push_back(a);
    }

    return article_list;
}


void cppblog::archives() {
    std::list<article> article_list = get_archives(1);

    content::message_archives c;
    c.archives_list = article_list;
    c.prev_page_number = 1;
    c.next_page_number = 2;
    render("message_archives",c);
}

void cppblog::archives_page(std::string number) {
    int page = std::stoi(number);
    std::list<article> archives_list = get_archives(page);

    content::message_archives c;
    c.archives_list = archives_list;
    if(page == 1) {
        c.prev_page_number = 1;
    } else {
        c.prev_page_number = page - 1;
    }
    c.next_page_number = page + 1;
    render("message_archives",c);
}