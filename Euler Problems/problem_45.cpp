#include "EulerProblems.h"

std::string problem_45::solution() {
	int n = 144;
	unsigned long h;

	while (true) {
		h = n * (2 * n - 1); //Note this calculates the next hexagonal number not triagonal. Every second triagonal number is hexagonal,
		//and all hexagonal numbers are triagonal.

		if (pentagonal(h)) 
			return std::to_string(h);

		n++;
	}
}

bool problem_45::pentagonal(long num) {
	double result = (sqrt(24.0 * num + 1.0) + 1.0) / 6.0; //All values must be floats to force float multiplication. Failure to do so will result in overflow during the calculation


	return (result == (long)result);

}