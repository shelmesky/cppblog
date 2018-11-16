#line 1 "templates/article.tmpl.html"
#include "content_article.h" 
#line 2 "templates/article.tmpl.html"
namespace my_skin {
	#line 3 "templates/article.tmpl.html"
	struct  message_article :public cppcms::base_view
	#line 3 "templates/article.tmpl.html"
	{
	#line 3 "templates/article.tmpl.html"
		content::message_article &content;
	#line 3 "templates/article.tmpl.html"
		message_article(std::ostream &_s,content::message_article &_content): cppcms::base_view(_s),content(_content),_domain_id(0)
	#line 3 "templates/article.tmpl.html"
		{
	#line 3 "templates/article.tmpl.html"
			_domain_id=booster::locale::ios_info::get(_s).domain_id();
	#line 3 "templates/article.tmpl.html"
		}
		#line 4 "templates/article.tmpl.html"
		virtual void render() {
		#line 4 "templates/article.tmpl.html"
			cppcms::translation_domain_scope _trs(out(),_domain_id);

			#line 13 "templates/article.tmpl.html"
			out()<<"\n"
				"<html lang=\"en\">\n"
				"\n"
				"  <head>\n"
				"      <meta http-equiv=\"Content-type\" content=\"text/html; charset=utf-8\" />\n"
				"      <meta name=\"viewport\" content=\"width=device-width, initial-scale=1, shrink-to-fit=no\">\n"
				"    <meta name=\"description\" content=\"\">\n"
				"    <meta name=\"author\" content=\"\">\n"
				"\n"
				"    <title>";
			#line 13 "templates/article.tmpl.html"
			out()<<cppcms::filters::escape(content.title);
			#line 66 "templates/article.tmpl.html"
			out()<<" - 天地孤影任我行</title>\n"
				"\n"
				"    <!-- Bootstrap core CSS -->\n"
				"    <link href=\"/file/static/vendor/bootstrap/css/bootstrap.min.css\" rel=\"stylesheet\">\n"
				"\n"
				"    <!-- Custom styles for this template -->\n"
				"    <link href=\"/file/static/css/blog-post.css\" rel=\"stylesheet\">\n"
				"\n"
				"    <link rel=\"stylesheet\" href=\"/file/static/highlight/styles/github.css\">\n"
				"    <script src=\"/file/static/highlight/highlight.pack.js\"></script>\n"
				"\n"
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
				"              <a class=\"nav-link\" href=\"/\">Home\n"
				"                <span class=\"sr-only\">(current)</span>\n"
				"              </a>\n"
				"            </li>\n"
				"            <li class=\"nav-item\">\n"
				"              <a class=\"nav-link\" href=\"/archives\">Archives</a>\n"
				"            </li>\n"
				"            <li class=\"nav-item\">\n"
				"              <a class=\"nav-link\" href=\"#\">Chat</a>\n"
				"            </li>\n"
				"            <li class=\"nav-item\">\n"
				"              <a class=\"nav-link\" href=\"#\">About</a>\n"
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
				"        <!-- Post Content Column -->\n"
				"        <div class=\"col-lg-8\">\n"
				"\n"
				"          <!-- Title -->\n"
				"          <h1 class=\"mt-4\">";
			#line 66 "templates/article.tmpl.html"
			out()<<cppcms::filters::escape(content.title);
			#line 71 "templates/article.tmpl.html"
			out()<<"</h1>\n"
				"\n"
				"          <!-- Author -->\n"
				"          <p class=\"lead\">\n"
				"              标签:\n"
				"              <a href=\"#\">";
			#line 71 "templates/article.tmpl.html"
			out()<<cppcms::filters::escape(content.keyword);
			#line 82 "templates/article.tmpl.html"
			out()<<"</a>\n"
				"          </p>\n"
				"\n"
				"          <hr>\n"
				"\n"
				"          <!-- Date/Time -->\n"
				"          <p>Posted on January 1, 2018 at 12:00 PM</p>\n"
				"\n"
				"          <hr>\n"
				"\n"
				"          <!-- Post Content -->\n"
				"            ";
			#line 82 "templates/article.tmpl.html"
			out()<<cppcms::filters::raw(content.real_body);
			#line 199 "templates/article.tmpl.html"
			out()<<"\n"
				"          <hr>\n"
				"\n"
				"          <!-- Comments Form -->\n"
				"          <div class=\"card my-4\">\n"
				"            <h5 class=\"card-header\">Leave a Comment:</h5>\n"
				"            <div class=\"card-body\">\n"
				"              <form>\n"
				"                <div class=\"form-group\">\n"
				"                  <textarea class=\"form-control\" rows=\"3\"></textarea>\n"
				"                </div>\n"
				"                <button type=\"submit\" class=\"btn btn-primary\">Submit</button>\n"
				"              </form>\n"
				"            </div>\n"
				"          </div>\n"
				"\n"
				"          <!-- Single Comment -->\n"
				"          <div class=\"media mb-4\">\n"
				"          </div>\n"
				"\n"
				"          <!-- Comment with nested comments -->\n"
				"          <div class=\"media mb-4\">\n"
				"          \n"
				"          </div>\n"
				"\n"
				"        </div>\n"
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
				"        <p class=\"m-0 text-center text-white\">Copyright &copy; <a href=\"https://github.com/shelmesky/cppblog\" target=\"_blank\">CPPBlog</a> 2018</p>\n"
				"      </div>\n"
				"      <!-- /.container -->\n"
				"    </footer>\n"
				"\n"
				"    <!-- Bootstrap core JavaScript -->\n"
				"    <script src=\"/file/static/vendor/jquery/jquery.min.js\"></script>\n"
				"    <script src=\"/file/static/vendor/bootstrap/js/bootstrap.bundle.min.js\"></script>\n"
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
		#line 199 "templates/article.tmpl.html"
		} // end of template render
	#line 200 "templates/article.tmpl.html"
	private:
	#line 200 "templates/article.tmpl.html"
		int _domain_id;
	#line 200 "templates/article.tmpl.html"
	}; // end of class message_article
#line 201 "templates/article.tmpl.html"
} // end of namespace my_skin
#line 2 "templates/article.tmpl.html"
namespace my_skin {
#line 201 "templates/article.tmpl.html"
} // end of namespace my_skin
#line 201 "templates/article.tmpl.html"
namespace {
#line 201 "templates/article.tmpl.html"
 cppcms::views::generator my_generator; 
#line 201 "templates/article.tmpl.html"
 struct loader { 
#line 201 "templates/article.tmpl.html"
  loader() { 
#line 201 "templates/article.tmpl.html"
   my_generator.name("my_skin");
#line 201 "templates/article.tmpl.html"
   my_generator.add_view<my_skin::message_article,content::message_article>("message_article",true);
#line 201 "templates/article.tmpl.html"
    cppcms::views::pool::instance().add(my_generator);
#line 201 "templates/article.tmpl.html"
 }
#line 201 "templates/article.tmpl.html"
 ~loader() {  cppcms::views::pool::instance().remove(my_generator); }
#line 201 "templates/article.tmpl.html"
} a_loader;
#line 201 "templates/article.tmpl.html"
} // anon 
