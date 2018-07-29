#include "EulerProblems.h"
#include <vector>

std::string problem_10::solution() {
	unsigned long long sum = 0;

	const int max = 2000000;

	//For increased clarity the array is made 1 size larger than necessary. This allows index 2 to correspond to the value 2.
	bool* prime = new bool[max + 1];

	for (int i = 0; i < max + 1; i++)
		prime[i] = true;

	//The largest factor of any number (excluding itself) is the square root of the number
	for (int i = 2; i <= sqrt(max); i++) {

		if (prime[i]) {
			//If a number is prime then all the multiples of that number can be eliminated 
			for (int j = i * i; j <= max; j += i) {
				prime[j] = false;
			}

		}
	}

	for (int i = 2; i < max + 1; i++)
		if (prime[i]) {
			sum += i;
		}

	return std::to_string(sum);
}
