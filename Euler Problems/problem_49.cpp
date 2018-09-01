#include "EulerProblems.h"

std::string problem_49::solution() {
	bool *prime = new bool[100001];
	std::vector<int> primes = generatePrimes(10000, prime);
	int previous_digits[4];
	int powers[] = { 1, 10, 100, 1000};

	int count, digit;
	bool valid;

	for (auto i : primes) {

		if (i > 1487) {
			int current = i;
			count = 1;
			valid = true;

			do {
				for (int j = 3; j >= 0; j--) {
					digit = current / powers[j];
					current = current % powers[j];

					if (count == 1) //If the loop has not run before initialise the digits array
						previous_digits[j] = digit;
					//Otherwise, check the current value to confirm it is a permutation of the previous digits
					else {

						for (int k = 0; k < 4; k++) {
							if (digit == previous_digits[k])
								break;
							else if (k == 3) //If the loop has not been broken yet then the digit is absent, and the number invalid
								valid = false;
						}
					}
				}
				current = i + count * 3330;
				count++;

				if (count == 3 && valid && prime[current]) 
					return std::to_string(i) + std::to_string(i + 3300) + std::to_string(i + 6600);

			} while (prime[current] && valid);

		}

	}
}

std::vector<int> problem_49::generatePrimes(int limit, bool prime[]) {
	for (int i = 0; i < limit; i++) {
		prime[i] = true;
	}

	std::vector<int> prime_nums;

	for (int i = 2; i < limit; i++) {
		if (prime[i]) {

			for (int j = i * i; j < limit; j += i) {
				if (j > 0)
					prime[j] = false;
				else
					j = limit + 1; //End the loop when overflow occurs
			}
			prime_nums.push_back(i);
		}
	}

	return prime_nums;
}