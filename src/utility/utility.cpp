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
	base.add_user("AD", "1967");
	base.add_user("antonis-white", "abacaba");
	return in_;

	std::ifstream in("user_data_base.txt", std::ios::in);

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
	return out_;
	
	std::ofstream out("location_data_base.txt", std::ios::out);

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

void location_base::print() {
	int ind = 0;
	for (auto& s : hv) {
		std::cout << ind << ". " << s << '\n';
		++ind;
       	}
}

std::istream& operator>>(std::istream& in_, location_base& base) {
	base.hv.emplace_back("Kuzminki");
	base.hv.emplace_back("MIPT");
	return in_;

	std::ifstream in("location_data_base.txt", std::ios::in);
    	
    	std::string str;
    	std::getline(in, str);

       	base.hv.resize(transform_string(str));
    	for (auto& it : base.hv)
    		std::getline(in, it);
    	
	in.close();
	return in_;
}

std::ostream& operator<<(std::ostream& out_, const location_base& base){
	return out_;

	std::ofstream out("location_data_base.txt", std::ios::out);
	
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
