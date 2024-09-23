#include <iostream>
#include <cstdlib>
#include "inlineFunc.hpp"
#include "Files.hpp"
#include "Replace.hpp"

static bool is_empty_or_whitespace(const std::string str)
{
	if (str.empty()) {
		return true;
	}
	for (std::string::const_iterator it = str.begin(); it != str.end(); ++it) {
		if (!std::isspace(*it)) {
			return false;
		}
	}
	return true;
}

static bool checkArgs(char *argv[])
{
	if (is_empty_or_whitespace(getFileName(argv))
		|| is_empty_or_whitespace(getOldString(argv))
		|| is_empty_or_whitespace(getNewString(argv))) {
		std::cerr << getEmptyMessage() << getUsageMessage();
		return (false);
	}
	else
		return (true);
}

int	main(int argc, char *argv[])
{
	if (argc != 4)
		std::cout << getUsageMessage();
	else if (checkArgs(argv)) {
		Files file(getFileName(argv));
		Replace replace(file, getOldString(argv), getNewString(argv));
		replace.replaceOut();
	}
	return (EXIT_SUCCESS);
}