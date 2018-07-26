#include "EulerProblems.h"

std::string problem_9::solution() {
	int c;

	for (int b = 1000; b > 0; b--) {

		for (int a = 0; a < 1000; a++) {

			if (a > b)
				break;

			c = 1000 - a - b;

			if (a * a + b * b == c * c && c > b && b > a)
				return std::to_string(a * b * c);
		
		}
	}

}