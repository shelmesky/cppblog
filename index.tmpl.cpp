#line 1 "index.tmpl.html"
#include "content.h" 
#line 2 "index.tmpl.html"
namespace my_skin {
	#line 3 "index.tmpl.html"
	struct  message :public cppcms::base_view
	#line 3 "index.tmpl.html"
	{
	#line 3 "index.tmpl.html"
		content::message &content;
	#line 3 "index.tmpl.html"
		message(std::ostream &_s,content::message &_content): cppcms::base_view(_s),content(_content),_domain_id(0)
	#line 3 "index.tmpl.html"
		{
	#line 3 "index.tmpl.html"
			_domain_id=booster::locale::ios_info::get(_s).domain_id();
	#line 3 "index.tmpl.html"
		}
		#line 4 "index.tmpl.html"
		virtual void render() {
		#line 4 "index.tmpl.html"
			cppcms::translation_domain_scope _trs(out(),_domain_id);

			#line 66 "index.tmpl.html"
			out()<<"\n"
				"<html lang=\"en\">\n"
				"\n"
				"  <head>\n"
				"      <meta http-equiv=\"Content-type\" content=\"text/html; charset=utf-8\" />\n"
				"      <meta name=\"viewport\" content=\"width=device-width, initial-scale=1, shrink-to-fit=no\">\n"
				"    <meta name=\"description\" content=\"\">\n"
				"    <meta name=\"author\" content=\"\">\n"
				"\n"
				"    <title>天地孤影任我行</title>\n"
				"\n"
				"    <!-- Bootstrap core CSS -->\n"
				"    <link href=\"/file/vendor/bootstrap/css/bootstrap.min.css\" rel=\"stylesheet\">\n"
				"\n"
				"    <!-- Custom styles for this template -->\n"
				"    <link href=\"/file/css/blog-post.css\" rel=\"stylesheet\">\n"
				"\n"
				"\n"
				"    <link rel=\"stylesheet\" href=\"/file/highlight/styles/default.min.css\">\n"
				"    <script src=\"/file/highlight/highlight.pack.js\"></script>\n"
				"\n"
				"  </head>\n"
				"\n"
				"  <body>\n"
				"\n"
				"    <!-- Navigation -->\n"
				"    <nav class=\"navbar navbar-expand-lg navbar-dark bg-dark fixed-top\">\n"
				"      <div class=\"container\">\n"
				"        <a class=\"navbar-brand\" href=\"/\">天地孤影任我行</a>\n"
				"        <button class=\"navbar-toggler\" type=\"button\" data-toggle=\"collapse\" data-target=\"#navbarResponsive\" aria-controls=\"navbarResponsive\" aria-expanded=\"false\" aria-label=\"Toggle navigation\">\n"
				"          <span class=\"navbar-toggler-icon\"></span>\n"
				"        </button>\n"
				"        <div class=\"collapse navbar-collapse\" id=\"navbarResponsive\">\n"
				"          <ul class=\"navbar-nav ml-auto\">\n"
				"            <li class=\"nav-item active\">\n"
				"              <a class=\"nav-link\" href=\"#\">Home\n"
				"                <span class=\"sr-only\">(current)</span>\n"
				"              </a>\n"
				"            </li>\n"
				"            <li class=\"nav-item\">\n"
				"              <a class=\"nav-link\" href=\"#\">About</a>\n"
				"            </li>\n"
				"            <li class=\"nav-item\">\n"
				"              <a class=\"nav-link\" href=\"#\">Services</a>\n"
				"            </li>\n"
				"            <li class=\"nav-item\">\n"
				"              <a class=\"nav-link\" href=\"#\">Contact</a>\n"
				"            </li>\n"
				"          </ul>\n"
				"        </div>\n"
				"      </div>\n"
				"    </nav>\n"
				"\n"
				"    <!-- Page Content -->\n"
				"    <div class=\"container\">\n"
				"\n"
				"      <div class=\"row\">\n"
				"\n"
				"\n"
				"        <!-- Post Content Column -->\n"
				"        <div class=\"col-lg-8\">\n"
				"\n"
				"          ";
			#line 66 "index.tmpl.html"
			if((content.article_list).begin()!=(content.article_list).end()) {
				#line 67 "index.tmpl.html"
				out()<<"\n"
					"          ";
				#line 67 "index.tmpl.html"
				for(CPPCMS_TYPEOF((content.article_list).begin()) article_ptr=(content.article_list).begin(),article_ptr_end=(content.article_list).end();article_ptr!=article_ptr_end;++article_ptr) {
				#line 67 "index.tmpl.html"
				CPPCMS_TYPEOF(*article_ptr) &article=*article_ptr;
					#line 70 "index.tmpl.html"
					out()<<"\n"
						"\n"
						"          <!-- Title -->\n"
						"          <h3 class=\"mt-4\"><a href=\"/article/";
					#line 70 "index.tmpl.html"
					out()<<cppcms::filters::escape(article.id);
					#line 70 "index.tmpl.html"
					out()<<"\">";
					#line 70 "index.tmpl.html"
					out()<<cppcms::filters::escape(article.title);
					#line 75 "index.tmpl.html"
					out()<<"</a></h3>\n"
						"\n"
						"          <!-- Author -->\n"
						"          <p class=\"lead\">\n"
						"              标签:\n"
						"              <a href=\"#\">";
					#line 75 "index.tmpl.html"
					out()<<cppcms::filters::escape(article.keyword);
					#line 83 "index.tmpl.html"
					out()<<"</a>\n"
						"          </p>\n"
						"\n"
						"          <!-- Date/Time -->\n"
						"          <p>Posted on January 1, 2018 at 12:00 PM</p>\n"
						"\n"
						"          摘要: </br>\n"
						"          <!-- Post Content -->\n"
						"            ";
					#line 83 "index.tmpl.html"
					out()<<cppcms::filters::raw(article.dummy_body);
					#line 84 "index.tmpl.html"
					out()<<"\n"
						"          <a href=\"/article/";
					#line 84 "index.tmpl.html"
					out()<<cppcms::filters::escape(article.id);
					#line 87 "index.tmpl.html"
					out()<<"\">阅读全文</a></br>\n"
						"          <hr>\n"
						"\n"
						"          ";
				#line 87 "index.tmpl.html"
				} // end of item
				#line 89 "index.tmpl.html"
				out()<<"\n"
					"\n"
					"          ";
			#line 89 "index.tmpl.html"
			 } else {
				#line 91 "index.tmpl.html"
				out()<<"\n"
					"          <h3>没有文章</h3>\n"
					"          ";
			#line 91 "index.tmpl.html"
			} // end of empty
			#line 201 "index.tmpl.html"
			out()<<"\n"
				"\n"
				"        </div>\n"
				"\n"
				"\n"
				"          <!-- Comments Form -->\n"
				"\n"
				"\n"
				"          <!-- Single Comment -->\n"
				"          <div class=\"media mb-4\">\n"
				"\n"
				"          </div>\n"
				"\n"
				"          <!-- Comment with nested comments -->\n"
				"          <div class=\"media mb-4\">\n"
				"\n"
				"          </div>\n"
				"\n"
				"\n"
				"        <!-- Sidebar Widgets Column -->\n"
				"        <div class=\"col-md-4\">\n"
				"\n"
				"          <!-- Search Widget -->\n"
				"          <div class=\"card my-4\">\n"
				"            <h5 class=\"card-header\">Search</h5>\n"
				"            <div class=\"card-body\">\n"
				"              <div class=\"input-group\">\n"
				"                <input type=\"text\" class=\"form-control\" placeholder=\"Search for...\">\n"
				"                <span class=\"input-group-btn\">\n"
				"                  <button class=\"btn btn-secondary\" type=\"button\">Go!</button>\n"
				"                </span>\n"
				"              </div>\n"
				"            </div>\n"
				"          </div>\n"
				"\n"
				"          <!-- Categories Widget -->\n"
				"          <div class=\"card my-4\">\n"
				"            <h5 class=\"card-header\">Categories</h5>\n"
				"            <div class=\"card-body\">\n"
				"              <div class=\"row\">\n"
				"                <div class=\"col-lg-6\">\n"
				"                  <ul class=\"list-unstyled mb-0\">\n"
				"                    <li>\n"
				"                      <a href=\"#\">C/C++</a>\n"
				"                    </li>\n"
				"                    <li>\n"
				"                      <a href=\"#\">Linux</a>\n"
				"                    </li>\n"
				"                    <li>\n"
				"                      <a href=\"#\">内核</a>\n"
				"                    </li>\n"
				"                  </ul>\n"
				"                </div>\n"
				"                <div class=\"col-lg-6\">\n"
				"                  <ul class=\"list-unstyled mb-0\">\n"
				"                    <li>\n"
				"                      <a href=\"#\">操作系统</a>\n"
				"                    </li>\n"
				"                    <li>\n"
				"                      <a href=\"#\">网络</a>\n"
				"                    </li>\n"
				"                    <li>\n"
				"                      <a href=\"#\">Golang</a>\n"
				"                    </li>\n"
				"                  </ul>\n"
				"                </div>\n"
				"              </div>\n"
				"            </div>\n"
				"          </div>\n"
				"\n"
				"          <!-- Side Widget -->\n"
				"          <div class=\"card my-4\">\n"
				"            <h5 class=\"card-header\">Side Widget</h5>\n"
				"            <div class=\"card-body\">\n"
				"              ...\n"
				"            </div>\n"
				"          </div>\n"
				"\n"
				"        </div>\n"
				"\n"
				"      </div>\n"
				"      <!-- /.row -->\n"
				"\n"
				"    </div>\n"
				"    <!-- /.container -->\n"
				"\n"
				"    <!-- Footer -->\n"
				"    <footer class=\"py-5 bg-dark\">\n"
				"      <div class=\"container\">\n"
				"        <p class=\"m-0 text-center text-white\">Copyright &copy; <a href=\"https://github.com/shelmesky/cppblog\">CPPBlog</a> 2018</p>\n"
				"      </div>\n"
				"      <!-- /.container -->\n"
				"    </footer>\n"
				"\n"
				"    <!-- Bootstrap core JavaScript -->\n"
				"    <script src=\"/file/vendor/jquery/jquery.min.js\"></script>\n"
				"    <script src=\"/file/vendor/bootstrap/js/bootstrap.bundle.min.js\"></script>\n"
				"\n"
				"\n"
				"    <script>\n"
				"        $(document).ready(function() {\n"
				"            $('pre code').each(function(i, block) {\n"
				"                hljs.highlightBlock(block);\n"
				"            });\n"
				"        })\n"
				"    </script>\n"
				"\n"
				"  </body>\n"
				"\n"
				"</html>\n"
				"";
		#line 201 "index.tmpl.html"
		} // end of template render
	#line 202 "index.tmpl.html"
	private:
	#line 202 "index.tmpl.html"
		int _domain_id;
	#line 202 "index.tmpl.html"
	}; // end of class message
#line 203 "index.tmpl.html"
} // end of namespace my_skin
#line 2 "index.tmpl.html"
namespace my_skin {
#line 203 "index.tmpl.html"
} // end of namespace my_skin
#line 203 "index.tmpl.html"
namespace {
#line 203 "index.tmpl.html"
 cppcms::views::generator my_generator; 
#line 203 "index.tmpl.html"
 struct loader { 
#line 203 "index.tmpl.html"
  loader() { 
#line 203 "index.tmpl.html"
   my_generator.name("my_skin");
#line 203 "index.tmpl.html"
   my_generator.add_view<my_skin::message,content::message>("message",true);
#line 203 "index.tmpl.html"
    cppcms::views::pool::instance().add(my_generator);
#line 203 "index.tmpl.html"
 }
#line 203 "index.tmpl.html"
 ~loader() {  cppcms::views::pool::instance().remove(my_generator); }
#line 203 "index.tmpl.html"
} a_loader;
#line 203 "index.tmpl.html"
} // anon 
