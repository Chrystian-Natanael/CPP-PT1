#ifndef INLINEFUNC_HPP
#define INLINEFUNC_HPP

#include <string>

/**
 * @name getFileName
 * @param char *argv[] - list of arguments
 * @return return argv[1] or NULL if argv[1] is empty
 */
inline std::string getFileName(char *argv[]) {
	return (argv[1]);
}

/**
 * @name getOldString
 * @param char *argv[] - list of arguments
 * @return return argv[2] or NULL if argv[2] is empty
 */
inline std::string getOldString(char *argv[]) {
	return (argv[2]);
}

/**
 * @name getNewString
 * @param char *argv[] - list of arguments
 * @return return argv[3] or NULL if argv[3] is empty
 */
inline std::string getNewString(char *argv[]) {
	return (argv[3]);
}

/**
 * @name getEmptyMessage
 * @details This function return a message to use where string is empty
 * @return std::string with contain "Empty strings not allowed.\n"
 */
inline std::string getEmptyMessage() {
	return ("Empty strings not allowed.\n");
}

/**
 * @name getUsageMessage
 * @details This function return a message to use where has invalid number of arguments
 * @return std::string with contain "3 arguments needed: <file> <old string> <new string>.\n"
 */
inline std::string getUsageMessage() {
	return ("3 arguments needed: <file> <old string> <new string>.\n");
}

#endif // INLINEFUNC_HPP