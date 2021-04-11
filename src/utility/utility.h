#pragma once
#include <stdint.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <deque>
#include <queue>
#include <memory>
#include <fstream>


class user_base {
private:
	std::map<std::string, std::string> name_pwd;
	
public:
	bool have_user(const std::string& name);
	bool is_correct_pwd(const std::string& name, const std::string& pwd);
	void add_user(const std::string& name, const std::string& pwd);
	friend std::istream& operator>>(std::istream& in, user_base& base);
	friend std::ostream& operator<<(std::ostream& out, const user_base& base);
};

user_base& global_user_base();

///---------------------location base----------------------------------///               

using location_t = unsigned int;

class location_base {
	std::vector<std::string> hv;
public:
	location_base();
	location_t count() const;
	void print();
	void add_location(const std::string& name);
	friend std::istream& operator>>(std::istream& in, location_base& base);
	friend std::ostream& operator<<(std::ostream& out, const location_base& base);
	const std::string& operator[](location_t loc) const;
};

location_base& global_location_base();

///---------------------date----------------------------///

using date_t = std::string;
int transform_string(const std::string& s){
	int res = 0, p = 1;
	for(int i = s.size() - 1; i >= 0; i--){
		res += int(s[i] - '0') * p;
		p *= 10;
	}
	return res;
}

bool is_year_leap(int y){
	if(y % 400 == 0) return 1;
	else{
		if(y % 100 == 0) return 0;
		else{
			if(y % 4 == 0) return 1;
			else return 0;
		}
	}
}

bool is_correct_date(date_t cur_date){
	std::vector <std::string> cur;
	cur.resize(3);
	int d, m, y;
	int j = 0, cnt_of_points = 0;
	for(size_t i = 0; i < cur_date.size(); i++){
		if((cur_date[i] >= '0' && cur_date[i] <= '9') || cur_date[i] == '.'){
			if(cur_date[i] == '.'){
				cnt_of_points++;
				if(cnt_of_points > 2) return 0;
 
				if(cur[j].size() == 0) return 0;
 
				j++;
			}else{
				cur[j] += cur_date[i];
			}
		}
		else return 0;
	}

	if(cnt_of_points < 2) return 0;
	
	d = transform_string(cur[0]);
	m = transform_string(cur[1]);
	y = transform_string(cur[2]);
 
	if(m < 1 || m > 12) return 0;
 
	if(m == 2){
		if(is_year_leap(y)){
			if(d < 1 || d > 29) return 0;
		}
		else{
				if(d < 1 || d > 28) return 0;
		}
	} 
	else{
		if(m == 4 || m == 6 || m == 9 || m == 11){
			if(d < 1 || d > 30) return 0;
		}
		else{
			if(d < 1 || d > 31) return 0;
		}
 
	}
	return 1;
}

const std::string& end_sep() {
	static std::string sep = "</end/>";
	return sep;
}

class comment_t{
public:
	std::string username, text;
	date_t cur_date;
	int rating;
 
        comment_t(const std::string& nm,date_t dt, int rating = 0) :
        	username(nm),
        	cur_date(dt),
        	rating(rating) {}
	comment_t(const std::string& nm, date_t dt, const std::string& tx) :
		username(nm),
		text(tx),
		cur_date(dt),
		rating(0) {}
 
	void like() { ++rating; }
	void dislike(){ --rating; }
	friend std::istream& operator>>(std::istream& in, comment_t& ct) {
		std::string cur = "", res = "";
		std::getline(in, cur);
		while(cur != end_sep()){
			res += cur;
			res += '\n';
			std::getline(in, cur);
		}	
		ct.text = res;
	}
	void put_comment(std::ostream& out, const comment_t& ct) {
		out << ct.username << " " << ct.cur_date << " " << ct.rating << '\n' << ct.text << end_sep();
	}
	friend std::ostream& operator<< (std::ostream &out, const comment_t &ct){
		out << '\t' << ct.cur_date << '\n';
		if (ct.rating > 0) out << '+';
		out << ct.rating << " | " << ct.username << '\n';
		out << ct.text;
		return out; 
	}
};
