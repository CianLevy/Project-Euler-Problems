#include "EulerProblems.h"

std::string problem_3::solution() {
	
	long long startValue = 600851475143;

	long long k = pow(startValue, 0.5);

	for (int i = 2; i < k; i++) {

		if (isPrime(i, i / 2) && startValue % i == 0) 
			return std::to_string(i);
	}

}

bool problem_3::isPrime(int num, int halfnum) {
	if (halfnum == 1)
		return true;
	else {
		if (num % halfnum == 0)
			return false;
		else
			isPrime(num, halfnum - 1);

	}

}