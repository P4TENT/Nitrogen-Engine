#pragma once

#include <iostream>

enum Colors {
	Black,
	Red,
	Green,
	Yellow,
	Blue,
	Magenta,
	Cyan,
	White
};

#define BLACK "\u001b[30m"
#define RED "\u001b[31m"
#define GREEN "\u001b[32m"
#define YELLOW "\u001b[33m"
#define BLUE "\u001b[34m"
#define MAGENTA "\u001b[35m"
#define CYAN "\u001b[36m"
#define WHITE "\u001b[37m"
#define RESET "\u001b[0m"

namespace Output {
	void info(std::string message);
	void error(std::string message);
	void custom(Colors color, std::string header, std::string message);
}