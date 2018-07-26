#include "EulerProblems.h"

std::string problem_7::solution() {
	int primeCount = 0;
	int counter = 2;

	while (primeCount < 10001) {
		if (isPrime(counter, counter / 2))
			primeCount++;

		counter++;
	}
	return std::to_string(counter - 1);
}

bool problem_7::isPrime(int num, int halfnum) {

	if (halfnum == 1)
		return true;
	else {
		if (num % halfnum == 0)
			return false;
		else
			isPrime(num, halfnum - 1);

	}

}