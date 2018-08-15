#include "EulerProblems.h"

std::string problem_29::solution() {
	const int max = 100;
	bool checked[max];
	int current;

	int count = 0;

	bool power_checked[1000];

	for (int i = 0; i < 1000; i++)
		power_checked[i] = false;

	for (int i = 0; i < max; i++)
		checked[i] = false;

	for (int a = 2; a <= max; a++) {

		if (!checked[a - 1]) {
			for (int p = 1; p <= 6; p++) {

				current = pow(a, p);

				if (current > max)
					break;

				if (!checked[current - 1]) {
					for (int b = 2; b <= max; b++) {
						if (!power_checked[b * p]) {
							power_checked[b * p] = true;
							count++;	}

					}

					checked[current - 1] = true;
				}
			}
		}
		for (int i = 0; i < 1000; i++)
			power_checked[i] = false;
	}

	return std::to_string(count);

}