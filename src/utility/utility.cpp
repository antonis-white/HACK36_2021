#include "utility.h"

location_t get_number_of_locations() {
	return number_of_locations;
}

void print_locations() {
	for (int i = 0; i < number_of_locations; ++i)
		std::cout << i << ". " << location[i] << '\n';
}