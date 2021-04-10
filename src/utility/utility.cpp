#include "utility.h"

///-------------------user base------------------///

bool user_base::have_user(const std::string& name) {
	return name_pwd.count(name);
}

bool user_base::is_correct_pwd(const std::string& name, const std::string& pwd) {
	return have_user(name) && name_pwd[name] == pwd;
}

void user_base::add_user(const std::string& name, const std::string& pwd) {
	if (have_user(name))
		return;
	name_pwd[name] = pwd;
}

std::istream& operator>>(std::istream& in, user_base& base) {
        base.add_user("AD", "1967");
        base.add_user("antonis_white", "abacaba");
	return in;	
}

std::ostream& operator<<(std::ostream& out, const user_base& base) {
	return out;
}

user_base& global_user_base() {
	static user_base base;
	return base;
}

///-------------------location_base-----------------------------///

location_base::location_base() {}

size_t location_base::count() {
	return number;
}

void location_base::print() {
	int ind = 0;
	for (auto& s : hv)
		std::cout << ind << ". " << s << '\n';
}

std::istream& operator>>(std::istream& in, location_base& base) {
	base.number = 1;
	base.hv.emplace_back("Kuzminki");
	return in;
}

std::ostream& operator<<(std::ostream& out, const location_base& base) {
	return out;
}

location_base& global_location_base() {
	static location_base base;
	return base;
}
