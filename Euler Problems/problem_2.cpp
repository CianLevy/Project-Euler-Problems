#include "EulerProblems.h"

std::string problem_2::solution() {
	int first = 0;
	int second = 0;
	int third = 1;
	int sum = 0;

	while (second < 1000000) {

		first = second + third;

		if (second % 2 == 0)
			sum += second;

		third = second;
		second = first;

	}

	return std::to_string(sum);
}