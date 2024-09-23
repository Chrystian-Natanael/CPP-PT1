#ifndef REPLACE_HPP
#define REPLACE_HPP

#include <fstream>
#include <string>
#include "Files.hpp"

class Replace{
private:
	std::string	_search;
	std::string	_replace;
	Files		&_file;
	std::string	_content;

public:
	Replace(Files &filename, std::string search, std::string replace);
	~Replace(void);

	void replaceOut(void);
};

#endif // REPLACE_HPP