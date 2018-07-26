#include "EulerProblems.h"

std::string problem_6::solution() {
	int sum = 0, squareSum = 0;

	for (int i = 1; i < 101; i++) {
		squareSum += (i ^ 2);
		sum += i;
	}

	return std::to_string((sum ^ 2) - squareSum);

}