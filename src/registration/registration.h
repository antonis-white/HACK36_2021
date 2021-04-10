#pragma once
#include "square.h"
#include <stdint.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <deque>
#include <queue>
#include <memory>

date_t get_date();
location_t get_location();

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

void print_cap(user_ptr& user);
