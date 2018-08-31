#include "EulerProblems.h"

std::string problem_48::solution() {
	unsigned long long answer = 0, current;

	for (int i = 1000; i >= 1; i--) {
		current = i;

		for (int j = 1; j < i; j++) {
			current *= i;

			if (current > 10000000000)
				current = current % 10000000000;

		}
		answer += current;
	}
	answer = answer % 10000000000;

	return std::to_string(answer);
}
