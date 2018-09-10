#include "EulerProblems.h"

std::string problem_53::solution() {
	long long current = 3921225;
	int n = 100, r = 4, permutations = n - 2 * r + 1;

	while (n > 23) {

		current = (current * (n - r) / n);
		n--;

		while (current < 1000000) {
			current = (current * (n - r) / (r + 1));
			r++;
		}
		permutations += n - 2 * r + 1;
	}
	return std::to_string(permutations);
}