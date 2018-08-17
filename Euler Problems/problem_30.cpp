#include "EulerProblems.h"

std::string problem_30::solution() {
	const int max = 6 * pow(9, 5);
	int current;
	int sum;
	unsigned int total = 0;


	for (int i = max; i > 2; i--) {
		current = i;
		sum = 0;

		while (current > 0) {
			sum += pow((current % 10), 5);
			current /= 10;

			if (sum > i)
				break;
			else if (current == 0 && sum == i)
				total += i;
		}

	}

	return std::to_string(total);
}