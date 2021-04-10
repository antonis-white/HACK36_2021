#pragma once
#include "square.h"
#include <string>
#include <memory>
#include <map>

date_t get_date();
uint8_t get_location();

class user_t {
public:
	std::string name;
	date_t date;
	location_t location;
	
	user_t(const std::string& name, date_t date, location_t location);
};

using user_ptr = std::unique_ptr<user_t>;

user_ptr get_user(date_t date, location_t loc);
                                        
user_ptr sign_in(date_t date, location_t loc);

user_ptr sign_up(date_t date, location_t loc);

user_ptr registration();

class user_base {
private:
	std::map<std::string, std::string> name_pwd;
	
public:
	bool have_user(const std::string& name);
	bool is_correct_pwd(const std::string& name, const std::string& pwd);
	void add_user(const std::string& name, const std::string& pwd);
	friend std::istream& operator>>(std::istream& in, user_base& base);
	friend std::ostream& operator<<(std::ostream& out, const user_base& base);
} global_user_base;

std::istream& operator>>(std::istream& in, user_base& base);
std::ostream& operator<<(std::ostream& out, const user_base& base);
