
#ifndef UTIL_H
#define UTIL_H

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define YELLOW  "\033[33m"
#define GREEN   "\033[32m"

#include <iostream>

class Util {
public:
	static std::string checkColor(std::string message);
};

#endif // !UTIL_H