#pragma once
#include <stdint.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <deque>
#include <queue>
#include <memory>
                        

using location_t = uint8_t;

constexpr location_t number_of_locations = 1;

std::string location[number_of_locations] = {"Kuzminki"};

location_t get_number_of_locations();
void print_locations();

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
class comment_t{
public:
	std::string username, text;
	date_t cur_date;
	int rating;
 
	comment_t(std::string nm, date_t dt, std::string tx){
		username = nm;
		cur_date = dt;
		text = tx;
		rating = 0;
	}
 
	void like(){rating ++;}
	void dislike(){rating --;}
	friend std::ostream& operator<< (std::ostream &out, const comment_t &ct){
		out << ct.username << ", " << ct.cur_date << std::endl << "Rating: " << ct.rating << std::endl << ct.text;
		return out; 
	}
};
