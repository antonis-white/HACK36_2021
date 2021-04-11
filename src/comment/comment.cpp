#include "comment.h"


void comment_reader(user_ptr& user, int index) {
	square_t& square = global_square_base()[user->location];
	if (square.comment_count() == 0) {
		print_warning("No comments to read");
		return;
	}

	print_cap(user);
	std::cout << "Comment index: " << index << '/' << square.comment_count() << "\n\n";
	std::cout << square.comments[index - 1];

	std::cout << "\tChoose your action:\n";
	std::cout << "Q. Left reader section\n";
	std::cout << "L. Move to previous comment\n";
	std::cout << "R. Move to next comment\n";
	std::cout << "x. Move to x-th comment (x - integer in [1; " << square.comment_count() << "])\n";
	std::cout << "+. Like comment\n";
	std::cout << "-. Dislike comment\n";

	std::cout << "Enter: ";
	std::string s;
	std::cin >> s;
	
	switch (s[0]) {
		case 'Q':
			return; break;
		case 'L':
			comment_reader(user, std::max(index - 1, 1)); 
			return; break;
		case 'R':
			comment_reader(user, std::min(index + 1, square.comment_count())); 
			return; break;
	       	case '+':
	       		square.comments[index - 1].like();
	       		comment_reader(user, index);
	       		return; break;
	       	case '-':
	       		square.comments[index - 1].dislike(); 
	       		comment_reader(user, index);
	       		return; break;
	}
	for (char c : s)
		if (!isdigit(c)) {
			print_warning();
			comment_reader(user, index);
			return;
		}

	int new_index = transform_string(s);
	if (new_index < 1 || new_index > square.comment_count()) {
		print_warning("Wrong index");
		comment_reader(user, index);
		return;
	}
	comment_reader(user, new_index);
}

void comment_writer(user_ptr& user) {}
