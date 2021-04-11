#include "comment.h"


void comment_reader(user_ptr& user, int index) {
	square_t& square = global_square_base()[user->location];
	if (square.comment_count() == 0) {
		print_warning("No comments to read");
		return;
	}

	print_cap(user);
	std::cout << "Comment index: " << index + 1 << '/' << square.comment_count() << "\n\n";
	std::cout << square.comments[index];

	std::cout << "\tChoose your action:\n";
	std::cout << "Q. Left reader section\n";
	std::cout << "L. Move to previous comment\n";
	std::cout << "R. Move to next comment\n";
	std::cout << "x. Move to x-th comment (x - integer in [1; " << square.comment_count() << "])\n";
	std::cout << "+. Like comment\n";
	std::cout << "-. Dislike comment\n";

	std::string s;
	std::cin >> s;
	if (s.size() != 1) {
		print_warning();
		return comment_reader(user, index);
	}

	switch (s[0]) {
		default:
			print_warning();
	}
}

void comment_writer(user_ptr& user) {}
