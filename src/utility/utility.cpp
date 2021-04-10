#include "utility.h"

//location_t number_of_locations = 1;

void print_locations() {
	for (int i = 0; i < number_of_locations; ++i)
		std::cout << i << ". " << location[i] << '\n';
}