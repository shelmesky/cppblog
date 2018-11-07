#line 1 "index.tmpl"
#include "content.h" 
#line 2 "index.tmpl"
namespace my_skin {
	#line 3 "index.tmpl"
	struct  message :public cppcms::base_view
	#line 3 "index.tmpl"
	{
	#line 3 "index.tmpl"
		content::message &content;
	#line 3 "index.tmpl"
		message(std::ostream &_s,content::message &_content): cppcms::base_view(_s),content(_content),_domain_id(0)
	#line 3 "index.tmpl"
		{
	#line 3 "index.tmpl"
			_domain_id=booster::locale::ios_info::get(_s).domain_id();
	#line 3 "index.tmpl"
		}
		#line 4 "index.tmpl"
		virtual void render() {
		#line 4 "index.tmpl"
			cppcms::translation_domain_scope _trs(out(),_domain_id);

			#line 8 "index.tmpl"
			out()<<"\n"
				"<html>\n"
				"  <body>\n"
				"    <div>\n"
				"    ";
			#line 8 "index.tmpl"
			if((content.article_list).begin()!=(content.article_list).end()) {
				#line 10 "index.tmpl"
				out()<<"\n"
					"        <ul>\n"
					"        ";
				#line 10 "index.tmpl"
				for(CPPCMS_TYPEOF((content.article_list).begin()) article_ptr=(content.article_list).begin(),article_ptr_end=(content.article_list).end();article_ptr!=article_ptr_end;++article_ptr) {
				#line 10 "index.tmpl"
				CPPCMS_TYPEOF(*article_ptr) &article=*article_ptr;
					#line 11 "index.tmpl"
					out()<<"\n"
						"            <li> ";
					#line 11 "index.tmpl"
					out()<<cppcms::filters::escape(article.id);
					#line 11 "index.tmpl"
					out()<<"  ";
					#line 11 "index.tmpl"
					out()<<cppcms::filters::escape(article.title);
					#line 11 "index.tmpl"
					out()<<" ";
					#line 11 "index.tmpl"
					out()<<cppcms::filters::escape(article.keyword);
					#line 11 "index.tmpl"
					out()<<" ";
					#line 11 "index.tmpl"
					out()<<cppcms::filters::escape(article.dummy_body);
					#line 11 "index.tmpl"
					out()<<" ";
					#line 11 "index.tmpl"
					out()<<cppcms::filters::escape(article.real_body);
					#line 12 "index.tmpl"
					out()<<"</li>\n"
						"        ";
				#line 12 "index.tmpl"
				} // end of item
				#line 14 "index.tmpl"
				out()<<"\n"
					"        </ul>\n"
					"    ";
			#line 14 "index.tmpl"
			 } else {
				#line 16 "index.tmpl"
				out()<<"\n"
					"        没有文章\n"
					"    ";
			#line 16 "index.tmpl"
			} // end of empty
			#line 21 "index.tmpl"
			out()<<"\n"
				"    </div>\n"
				"\n"
				"    <div>\n"
				"    <p>\n"
				"    <a href=\"/page/";
			#line 21 "index.tmpl"
			out()<<cppcms::filters::escape(content.prev_page_number);
			#line 22 "index.tmpl"
			out()<<"\">上一页</a> &nbsp; &nbsp; &nbsp;\n"
				"    <a href=\"/page/";
			#line 22 "index.tmpl"
			out()<<cppcms::filters::escape(content.next_page_number);
			#line 27 "index.tmpl"
			out()<<"\">下一页</a>\n"
				"    </p>\n"
				"     </div>\n"
				"  </body>\n"
				"</html>\n"
				"";
		#line 27 "index.tmpl"
		} // end of template render
	#line 28 "index.tmpl"
	private:
	#line 28 "index.tmpl"
		int _domain_id;
	#line 28 "index.tmpl"
	}; // end of class message
#line 29 "index.tmpl"
} // end of namespace my_skin
#line 2 "index.tmpl"
namespace my_skin {
#line 29 "index.tmpl"
} // end of namespace my_skin
#line 29 "index.tmpl"
namespace {
#line 29 "index.tmpl"
 cppcms::views::generator my_generator; 
#line 29 "index.tmpl"
 struct loader { 
#line 29 "index.tmpl"
  loader() { 
#line 29 "index.tmpl"
   my_generator.name("my_skin");
#line 29 "index.tmpl"
   my_generator.add_view<my_skin::message,content::message>("message",true);
#line 29 "index.tmpl"
    cppcms::views::pool::instance().add(my_generator);
#line 29 "index.tmpl"
 }
#line 29 "index.tmpl"
 ~loader() {  cppcms::views::pool::instance().remove(my_generator); }
#line 29 "index.tmpl"
} a_loader;
#line 29 "index.tmpl"
} // anon 
