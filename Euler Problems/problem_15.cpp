#include "EulerProblems.h"
#include <fstream>

std::string problem_15::solution() {

	int x, y, x_dimension = 20, y_dimension = 20, total_locations;

	total_locations = (x_dimension + 1) * (y_dimension + 1);

	unsigned long long *grid = new unsigned long long[total_locations];
	
	for (int i = 0; i < total_locations; i++)
		grid[i] = 1;

	for (int i = total_locations - x_dimension - 3; i >= 0; i--) {
		if ((i - x_dimension) % (x_dimension + 1) != 0)
			grid[i] = grid[i + 1] + grid[i + x_dimension + 1];
		
	}

	return std::to_string(grid[0]);
}