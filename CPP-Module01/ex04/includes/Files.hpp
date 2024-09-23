#ifndef FILES_HPP
#define FILES_HPP

#include <fstream>
#include <string>
#include <iostream>

class Files {
private:
	std::string	_fileName;
	std::string	_content;

public:
	Files(const std::string &name);
	~Files(void);

	std::string getFileName(void);
	std::string getContentFile(void);
	std::string fileReader(void);
};

#endif // FILES_HPP