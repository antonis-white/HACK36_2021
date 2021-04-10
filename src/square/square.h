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
		size_t max_cnt = 10;
		int avr_score;
		std::deque<comment_t> comments;
		
		square_t() {
			for(size_t i = 0; i < max_cnt; i++){
				scores.push_front(10);
			}
			avr_score = 10;
		}
		                          
		void get_average_score() {
			avr_score = 0;
			for(auto it = scores.begin(); it != scores.end(); it++)
				avr_score += *it;
			avr_score /= scores.size();
		}

		void add_score(int x) {
			scores.push_front(x);
			if(scores.size() > max_cnt)
				scores.pop_back();
			fnd_average_score();
		}

		void add_comment(comment_t x) {
			comments.push_front(x);
			if(comments.size() > max_cnt)
				comments.pop_back();
		}

		size_t comment_count() {
			return comments.size();
		}
};
