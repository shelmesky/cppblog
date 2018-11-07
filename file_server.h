#ifndef CPPBLOG_FILE_SERVER_H
#define CPPBLOG_FILE_SERVER_H

#include <cppcms/application.h>
#include <cppcms/applications_pool.h>
#include <string>
#include <map>

	class file_server : public cppcms::application
	{
	public:
		
		static void normalize_path(std::string &path);
		file_server(cppcms::service &srv,bool async=false);
		~file_server();
		virtual void main(std::string file_name);

	private:
		void list_dir(std::string const &url,std::string const &path);
		void show404();
		void load_mime_types(std::string);
		bool canonical(std::string normal,std::string &real);
		bool is_in_root(std::string const &normal,std::string const &root,std::string &real);
		bool check_in_document_root(std::string normal,std::string &real);
		int file_mode(std::string const &path);

		bool allow_deflate_;
		std::string document_root_;
		std::vector<std::pair<std::string,std::string> > alias_;
		typedef std::map<std::string,std::string> mime_type;
		mime_type mime_;
		bool list_directories_;
		bool check_symlinks_;
		bool async_;
		std::string index_file_;
	};

#endif