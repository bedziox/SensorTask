#include "Util.h"

std::string Util::checkColor(const std::string message) {
	std::string result;
	if (message == "ALARM") {
		result = RED;
	}
	else if (message == "WARNING") {
		result = YELLOW;
	}
	else if (message == "NORMAL") {
		result = GREEN;
	}
	return result;
}
