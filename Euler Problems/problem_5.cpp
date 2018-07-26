#include "EulerProblems.h"

std::string problem_5::solution() {

	int testNumber = 40;

	while (testNumber % 10 != 0 || testNumber % 11 != 0 || testNumber % 12 != 0 || testNumber % 13 != 0 ||
		testNumber % 14 != 0 || testNumber % 15 != 0 || testNumber % 16 != 0 || testNumber % 17 != 0 ||
		testNumber % 18 != 0 || testNumber % 19 != 0 || testNumber % 20 != 0)
		testNumber++;


	return std::to_string(testNumber);
}