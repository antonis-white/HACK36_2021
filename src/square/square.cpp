#include "square.h"

void square_base::add_square(const square_t& sq) {
	sb.push_back(sq);
}

square_base::square_base() {}
 
int square_base::count() const {
	return sb.size();
}
 
square_t& square_base::operator[](location_t loc) {
	return sb[loc];
}
 
std::istream& operator>>(std::istream& in_, square_base& base) {
	std::ifstream in("../src/square/square_data_base.txt", std::ios::in);
 	int n;
 	in >> n;
 	base.sb.resize(n);
 	for(int i = 0; i < n; ++i) {
 		for(size_t j = 0; j < square_t::max_cnt; ++j){
 			int score;
 			in >> score;
 			base[i].add_score(score);
 		}
 		int coms;
 		in >> coms;
 		for(int j = 0; j < coms; j++) {
 			std::string name;
 			date_t date;
 			int rating;
 			in >> name >> date >> rating;
 			comment_t t(name, date, rating);
 			in >> t;
 			base[i].comments.push_back(t);
 		}
 	}
	in.close();
	return in_;
}
 
std::ostream& operator<<(std::ostream& out_, const square_base& base){
	std::ofstream out("../src/square/square_data_base.txt", std::ios::out);
	out << base.count() << '\n';
	for (const square_t& square : base.sb) {
		for(int score : square.scores){
			out << score << ' ';
		}
		out << '\n' << square.comments.size() << '\n';
		for(const comment_t& com: square.comments){
			put_comment(out, com);
		}
	}
    	out.close();
	return out_;
}
 
square_base& global_square_base() {
	static square_base base;
	return base;
}