#include "graphics.h"

void print_sep_line() {
	static std::string s(80, '_');
	std::cout << s << '\n';
}

void print_warning(const std::string& wrn) {
	std::cout << "WARNING! " << wrn << '\n';
	print_sep_line();
}