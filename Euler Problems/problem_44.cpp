#include "EulerProblems.h"

std::string problem_44::solution() {
	bool found = false;
	int i = 1, j, k;

	while (!found) {
		j = i * (3 * i - 1) / 2;

		for (int l = i - 1; l >= 1; l--) {
			k = l * (3 * l - 1) / 2;

			if (pentagonal(j + k) && pentagonal(j - k)) {
				return std::to_string(j - k);
				found = true;
			}

		}


		i++;
	}
}

bool problem_44::pentagonal(int num) {
	double result = (sqrt(24 * num + 1.0) + 1.0) / 6.0;

	return (result == (int)result);

}