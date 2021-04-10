#include "registration.h"

user_t::user_t(const std::string& name, date_t date, location_t location) :
		name(name),
		date(date), 
		location(location) {}

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

date_t get_date() {
	date_t date;
	std::cout << "Insert current date: ";
	std::cin >> date;

	if (is_correct_date(date))
		return date;

	print_warning("Wrong date");
	return get_date();	
}

location_t get_location() {
	std::cout << "Insert your current location\n";
	print_locations();
	location_t loc;
	std::cout << "total number: " << get_number_of_locations() << '\n';
	std::cout << "Enter: ";
	std::cin >> loc;

	if (loc < get_number_of_locations())
		return loc;

	print_warning("Wrong location");
	return get_location();
}

user_ptr sign_up(date_t date, location_t loc) {
	std::string name, pwd;
	std::cout << "Insert your nickname: ";
	std::cin >> name;

	if (global_user_base.have_user(name)) {
		print_warning("Unfortunately, nickname is allready taken");
		return std::move(sign_up(date, loc));
	}

	std::cout << "Insert your password: ";
	std::cin >> pwd;

	global_user_base.add_user(name, pwd);

	return user_ptr(new user_t(name, date, loc));
}

user_ptr sign_in(date_t date, location_t loc) {
	std::string name, pwd;
	std::cout << "Insert your nickname: ";
	std::cin >> name;

	if (!global_user_base.have_user(name)) {
		print_warning("Wrong user name");
		return std::move(sign_in(date, loc));
	}

	std::cout << "Insert your password: ";
	std::cin >> pwd;

	if (!global_user_base.is_correct_pwd(name, pwd)) {
		print_warning("Wrong password");
		return std::move(sign_in(date, loc));
	}

	global_user_base.add_user(name, pwd);

	return user_ptr(new user_t(name, date, loc));
}

user_ptr get_user(date_t date, location_t loc) {
	std::cout << "\tRegistration type:\n";
	std::cout << "1. Sign up\n";
	std::cout << "2. Sign in\n";
	std::cout << "Enter: ";
	int tp;
	std::cin >> tp;

	switch (tp) {
		case 1:
			return std::move(sign_up(date, loc));
			break;
		case 2:
			return std::move(sign_in(date, loc));
			break;
		default:
			print_warning();
			return std::move(get_user(date, loc));
	}
}

user_ptr registration() {
	date_t date = get_date();
	location_t loc = get_location();
	return std::move(get_user(date, loc));
}
	