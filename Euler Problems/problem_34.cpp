#include "EulerProblems.h"

std::string problem_34::solution() {
	const int factorial[10] = { 1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880 }; //Storing the factorial values for each digit is substancially faster
	//than recalculating the values in the loop
	unsigned long total_sum = 0;
	int current_sum;
	int current;
	int max = factorial[9] * 7; //9! * 8 produces a 7 digit number not an 8 digit number and as a result the maximum number of digits is 7

	for (int i = 3; i < max; i++) {
		current_sum = 0;
		current = i;

		while (current > 0) {
			current_sum += factorial[current % 10];

			current /= 10;

		}
		if (current_sum == i)
			total_sum += i;

	}
	return std::to_string(total_sum);
}