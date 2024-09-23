#include "Replace.hpp"

Replace::Replace(Files &filename, std::string search, std::string replace)
	:_search(search), _replace(replace), _file(filename) {}

Replace::~Replace(void) {}

void Replace::replaceOut(void)
{
	size_t	pos = 0;

	if (_file.getContentFile().empty())
		_file.fileReader();
	_content = _file.getContentFile();

	while ((pos = _content.find(_search, pos)) != std::string::npos) {
		_content = _content.substr(0, pos) + _replace + _content.substr(pos + _search.length());
		pos += _replace.length();
	}

	std::ofstream outputFile((_file.getFileName() + ".replace").c_str());
	if (outputFile.is_open()) {
		outputFile << _content;
		outputFile.close();
	} else {
		std::cerr << "Error: Unable to open file for writing." << std::endl;
	}
}