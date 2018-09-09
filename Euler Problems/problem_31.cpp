#include "EulerProblems.h"

std::string problem_31::solution() {
	const int total = 200;
	int possibilities[total + 1];
	int coins[] = { 1, 2, 5, 10, 20, 50, 100, 200 };

	for (int i = 0; i <= total; i++)
		possibilities[i] = 0;

	possibilities[0] += 1;

	for (int i = 0; i < 8; i++) {
		for (int j = coins[i]; j <= total; j++)
			possibilities[j] += possibilities[j - coins[i]];

	}
	return std::to_string(possibilities[total]);

}