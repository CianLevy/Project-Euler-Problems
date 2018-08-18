#include "EulerProblems.h"

std::string problem_33::solution() {

	double digits[4];
	int numerator = 1, denominator = 1;
	int LCF; //Largest common factor

	for (int i = 10; i <= 99; i++) {
		for (int j = 99; j > i; j--) {
			digits[0] = i / 10;
			digits[1] = i % 10;
			digits[2] = j / 10;
			digits[3] = j % 10;

			if (digits[1] != 0 && digits[3] != 0) {
				if (digits[1] == digits[2] && i / digits[0] == j / digits[3]) {
					numerator *= digits[0];
					denominator *= digits[3];
				}
			}
		}
	}

	//Due to the definition of the problem the numerator must be the smallest number
	for (int i = numerator; i >= 2; i--) {
		if (numerator % i == 0 && denominator % i == 0) {
			LCF = i;
			break; //As the loop control variable decreases it follows that the first number to be a factor of both the numerator and
			//denominator must be the largest common factor
		}
	}

	return std::to_string(denominator / LCF);
}