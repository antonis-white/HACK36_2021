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

std::istream& operator>>(std::istream& in_, user_base& base) {
	std::ifstream in("../src/utility/user_data_base.txt", std::ios::in);

	int n;
	std::string login, password;
	in >> n;
	while (n--) {
		in >> login >> password;
		base.add_user(login, password);
	}
        
	in.close();
	return in_;	
}

std::ostream& operator<<(std::ostream& out_, const user_base& base) {
	std::ofstream out("../src/utility/user_data_base.txt", std::ios::out);

	out << base.name_pwd.size() << '\n';
	for (auto [name, pwd] : base.name_pwd)
		out << name << ' ' << pwd << '\n';
	
	out.close();
	return out_;
}

user_base& global_user_base() {
	static user_base base;
	return base;
}

///-------------------location_base-----------------------------///

location_base::location_base() {}

location_t location_base::count() const {
	return hv.size();
}

const std::string location_base::operator[](location_t loc) const {
	return hv[loc];
}

void location_base::print() {
	int ind = 0;
	for (auto& s : hv) {
		std::cout << ind << ". " << s << '\n';
		++ind;
       	}
}

std::istream& operator>>(std::istream& in_, location_base& base) {
	std::ifstream in("../src/utility/location_data_base.txt", std::ios::in);
    	
    	//std::string str;
    	//std::getline(in, str);
    	//std::cerr << str << ' ' << transform_string(str) << '\n';
	//return in_;
	//base.hv.resize(transform_string(str));
    	int n;
    	in >> n;
    	base.hv.resize(n);

    	for (auto& it : base.hv)
    		std::getline(in, it);
    	
	in.close();
	return in_;
}

std::ostream& operator<<(std::ostream& out_, const location_base& base){
	std::ofstream out("../src/utility/location_data_base.txt", std::ios::out);
	
	out << base.count() << '\n';
	for(auto loc : base.hv)
		out << loc << '\n';
	
	out.close();
	return out_;
}

location_base& global_location_base() {
	static location_base base;
	return base;
}
