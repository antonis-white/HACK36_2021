#pragma once
#include "graphics.h"
#include <stdint.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <deque>
#include <queue>
#include <memory>

class square_t{
public:
	std::deque<int> scores;
	static size_t const max_cnt = 10;
	int avr_score;
	std::deque<comment_t> comments;
	
	square_t() {
		for(size_t i = 0; i < max_cnt; i++){
			scores.push_front(10);
		}
		avr_score = 10;
	}
		                          
	void calc_average_score() {
		avr_score = 0;
		for(int score: scores)	
			avr_score += score;
		avr_score /= scores.size();
	}

	void add_score(int x) {
		scores.push_front(x);
		if(scores.size() > max_cnt)
			scores.pop_back();
		calc_average_score();
	}

	void add_comment(comment_t x) {
		comments.push_front(x);
		if(comments.size() > max_cnt)
			comments.pop_back();
	}

	int get_average_score() const {
		return avr_score;
	}

	int comment_count() {
		return comments.size();
	}
};

///----------------------square----------------------///

class square_base{
	std::vector <square_t> sb;
public: 
	square_base();
	int count() const;
	friend std::istream& operator>>(std::istream& in, square_base& base);
	friend std::ostream& operator<<(std::ostream& out, const square_base& base);
	square_t& operator[](location_t loc);
	void add_square(const square_t& nw);
};

square_base& global_square_base();
