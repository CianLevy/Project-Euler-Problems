#include "EulerProblems.h"

std::string problem_14::solution() {

	int *term_count = new int[1000000];

	unsigned long long current_value;
	int maximum = 0, max_start = 0;

	for (int i = 1; i < 1000000; i++) {
		term_count[i] = 0;
		current_value = i;

		while (current_value != 1) {

			if (current_value < i) {

				term_count[i - 1] += term_count[current_value - 1];
				current_value = 1;
			}
			else if (current_value % 2 == 0)
				current_value = current_value / 2;
			else
				current_value = 3 * current_value + 1;

			term_count[i - 1]++;
		}

		if (term_count[i - 1] > maximum) {
			maximum = term_count[i - 1];
			max_start = i;
		}

	}

	return std::to_string(max_start);


}