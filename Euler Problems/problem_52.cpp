#include "EulerProblems.h"

std::string problem_52::solution() {
	int factor = 1;
	int digits[10];
	int new_digits[10];
	int current = 0;
	bool reset = true;

	while (factor < 6) {
		if (reset) {
			factor = 1;
			reset = false;
			current++;

			for (int i = 0; i < 10; i++)
				digits[i] = 0;
		}
		else
			factor++;

		int temp = current * factor;

		for (int i = 0; i < 10; i++)
			new_digits[i] = 0;


		if (factor == 1) {
			while (temp > 0) {
				digits[temp % 10]++;
				temp /= 10;
			}
		}
		else {
			while (temp > 0) {
				new_digits[temp % 10]++;
				temp /= 10;
			}

			for (int i = 0; i < 10; i++) {
				if (new_digits[i] != digits[i]) {
					reset = true;
					break;
				}
			}
		}


	}
	return std::to_string(current);

}