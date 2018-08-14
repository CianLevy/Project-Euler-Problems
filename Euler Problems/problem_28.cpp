#include "EulerProblems.h"

std::string problem_28::solution() {
	const int dimensions = 1001;
	unsigned long sum = 1;
	int current;

	for (int i = 3; i <= dimensions; i = i + 2) {

		current = i * i;

		for (int j = 0; j < 4; j++) {
			sum += current;

			current -= (i - 1);
		}

	}
	

	return std::to_string(sum);
}