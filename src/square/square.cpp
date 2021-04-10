#include "square.h"

void square_base::add_square(const square_t& sq) {
	sb.push_back(sq);
}

square_base::square_base() {}
 
int square_base::count() const {
	return sb.size();
}
 
const std::string square_base::operator[](location_t loc) const {
	return sb[loc];
}
 
std::istream& operator>>(std::istream& in_, square_base& base) {
	std::ifstream in("../src/square/square_data_base.txt", std::ios::in);
 
    	std::string kostyl__;
    	int n;
    	in >> n;
    	base.sb.resize(n);
    	std::getline(in, kostyl__);
 
    	for (auto& it : base.sb)
    		std::getline(in, it);
 
	in.close();
	return in_;
}
 
std::ostream& operator<<(std::ostream& out_, const square_base& base){
	std::ofstream out("../src/square/square_data_base.txt", std::ios::out);
 
	out << base.count() << '\n';
	for(auto it : base.sb)
		out << it << '\n';
	out.close();
	return out_;
}
 
square_base& global_square_base() {
	static square_base base;
	return base;
}