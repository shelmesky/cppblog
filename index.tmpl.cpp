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

			#line 7 "index.tmpl"
			out()<<"\n"
				"<html>\n"
				"  <body>\n"
				"    <h1>";
			#line 7 "index.tmpl"
			out()<<cppcms::filters::escape(content.text);
			#line 10 "index.tmpl"
			out()<<" World!</h1>\n"
				"  </body>\n"
				"</html>\n"
				"";
		#line 10 "index.tmpl"
		} // end of template render
	#line 11 "index.tmpl"
	private:
	#line 11 "index.tmpl"
		int _domain_id;
	#line 11 "index.tmpl"
	}; // end of class message
#line 12 "index.tmpl"
} // end of namespace my_skin
#line 2 "index.tmpl"
namespace my_skin {
#line 12 "index.tmpl"
} // end of namespace my_skin
#line 12 "index.tmpl"
namespace {
#line 12 "index.tmpl"
 cppcms::views::generator my_generator; 
#line 12 "index.tmpl"
 struct loader { 
#line 12 "index.tmpl"
  loader() { 
#line 12 "index.tmpl"
   my_generator.name("my_skin");
#line 12 "index.tmpl"
   my_generator.add_view<my_skin::message,content::message>("message",true);
#line 12 "index.tmpl"
    cppcms::views::pool::instance().add(my_generator);
#line 12 "index.tmpl"
 }
#line 12 "index.tmpl"
 ~loader() {  cppcms::views::pool::instance().remove(my_generator); }
#line 12 "index.tmpl"
} a_loader;
#line 12 "index.tmpl"
} // anon 
