#include "EulerProblems.h"

std::string problem_39::solution() {
	int count, max = 0, best_p;

	for (int p = 1000; p >= 1; p--) {

		count = 0;

		for (int a = 1; a < p; a++) {

			for (int b = p - 1; b >= a; b--)

				if (a + b < p && (a * a + b * b) == (p - a - b) * (p - a - b))
					count++;
		}
		if (count > max) {
			max = count;
			best_p = p;
		}

	}
	return std::to_string(best_p);
}