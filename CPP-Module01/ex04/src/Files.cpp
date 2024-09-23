#include "Files.hpp"

Files::Files(const std::string &name): _fileName(name) {}

Files::~Files(void){}

std::string Files::fileReader(void)
{
	std::string		line;
	std::ifstream	file(_fileName.c_str());

	if (!file.is_open()) {
		std::cerr << "Error while opening file" << std::endl;
		return ("");
	}
	while (std::getline(file, line)) {
		_content += line + '\n';
	}
	file.close();
	return (_content);
}

std::string Files::getFileName(void)
{
	return (this->_fileName);
}

std::string Files::getContentFile(void)
{
	return (this->_content);
}