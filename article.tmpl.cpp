#line 1 "article.tmpl"
#include "content_article.h" 
#line 2 "article.tmpl"
namespace my_skin {
	#line 3 "article.tmpl"
	struct  message_article :public cppcms::base_view
	#line 3 "article.tmpl"
	{
	#line 3 "article.tmpl"
		content::message_article &content;
	#line 3 "article.tmpl"
		message_article(std::ostream &_s,content::message_article &_content): cppcms::base_view(_s),content(_content),_domain_id(0)
	#line 3 "article.tmpl"
		{
	#line 3 "article.tmpl"
			_domain_id=booster::locale::ios_info::get(_s).domain_id();
	#line 3 "article.tmpl"
		}
		#line 4 "article.tmpl"
		virtual void render() {
		#line 4 "article.tmpl"
			cppcms::translation_domain_scope _trs(out(),_domain_id);

			#line 13 "article.tmpl"
			out()<<"\n"
				"<html>\n"
				"  <head>\n"
				"  <meta http-equiv=\"Content-type\" content=\"text/html; charset=utf-8\" />\n"
				"  </head>\n"
				"\n"
				"  <body>\n"
				"    <div>\n"
				"\n"
				"    ";
			#line 13 "article.tmpl"
			out()<<cppcms::filters::escape(content.title);
			#line 15 "article.tmpl"
			out()<<"\n"
				"    </br>\n"
				"    ";
			#line 15 "article.tmpl"
			out()<<cppcms::filters::escape(content.keyword);
			#line 17 "article.tmpl"
			out()<<"\n"
				"    </br>\n"
				"    ";
			#line 17 "article.tmpl"
			out()<<cppcms::filters::escape(content.real_body);
			#line 22 "article.tmpl"
			out()<<"\n"
				"\n"
				"    </div>\n"
				"      </body>\n"
				"    </html>\n"
				"    ";
		#line 22 "article.tmpl"
		} // end of template render
	#line 23 "article.tmpl"
	private:
	#line 23 "article.tmpl"
		int _domain_id;
	#line 23 "article.tmpl"
	}; // end of class message_article
#line 24 "article.tmpl"
} // end of namespace my_skin
#line 2 "article.tmpl"
namespace my_skin {
#line 24 "article.tmpl"
} // end of namespace my_skin
#line 24 "article.tmpl"
namespace {
#line 24 "article.tmpl"
 cppcms::views::generator my_generator; 
#line 24 "article.tmpl"
 struct loader { 
#line 24 "article.tmpl"
  loader() { 
#line 24 "article.tmpl"
   my_generator.name("my_skin");
#line 24 "article.tmpl"
   my_generator.add_view<my_skin::message_article,content::message_article>("message_article",true);
#line 24 "article.tmpl"
    cppcms::views::pool::instance().add(my_generator);
#line 24 "article.tmpl"
 }
#line 24 "article.tmpl"
 ~loader() {  cppcms::views::pool::instance().remove(my_generator); }
#line 24 "article.tmpl"
} a_loader;
#line 24 "article.tmpl"
} // anon 
