#include "interface.h"

void new_location(user_ptr& user) {
	print_sep_line();
		
}

void location_changer(user_ptr& user) {
	print_sep_line();
	std::cout << "Do you want to add new location (Y/N)?: ";
	std::string s;
	std::cin >> s;

	if (s.size() != 1) {
		print_warning();
		location_changer(user);
		return;
	}
	
	switch (s[0]) {
		case 'Y':
			new_location(user);
			break;
		case 'N':
			user->location = get_location();
			break;	
		default:
			print_warning();
			location_changer(user);
	}
}

void allert_button_click(user_ptr& user) {
	print_sep_line();
	std::cout << "\t\tALLERT!!\n";
	std::cout << user->name << " asked for help\n";
	std::cout << "When: " << user->date << '\n';
	std::cout << "Where: " << global_location_base()[user->location] << '\n';
}

bool tick(user_ptr& user) {
	print_cap(user);
	std::cout << "\tChoose your action:\n";
	std::cout << "E. Exit\n";
	std::cout << "Q. Log out\n";
	std::cout << "L. Change location\n";
	std::cout << "R. Read comments\n";
	std::cout << "W. Write comment\n";
	std::cout << "A. Allert button\n";
	std::cout << "Enter: ";
	
	std::string tps;
	std::cin >> tps;

	if (tps.size() != 1) {
		print_warning();
		return tick(user);	
	}

	switch(tps[0]) {
		case 'E':
			return false; break;
		case 'Q':
			print_sep_line();
			user = std::move(registration()); 
			break;
		case 'L':
			location_changer(user); break;
		case 'R':
			comment_reader(user); break;
		case 'W':
			comment_writer(user); break;
		case 'A':
			allert_button_click(user); break;
		default:
			print_warning();
			return tick(user);
			break;		 	
	}
	return true;
}