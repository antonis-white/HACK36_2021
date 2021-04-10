#include "application.h"

void preparation() {
	std::cin >> global_user_base;
}

void finish() {
	std::cout << global_user_base;
}

void run_app() {
	preparation();

	user_ptr user = registration();

	finish();
}