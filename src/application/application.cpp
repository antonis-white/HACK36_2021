#include "application.h"

void preparation() {
	std::cin >> global_user_base();
	std::cin >> global_location_base();
	std::cin >> global_square_base();
}

void finish() {
	std::cout << global_user_base();
	std::cout << global_location_base();
	std::cout << global_square_base();
}

void run_app() {
	preparation();

	user_ptr user = registration();
	bool not_exited = true;
	while (not_exited) {
		not_exited = tick(user);
	}

	finish();
}
