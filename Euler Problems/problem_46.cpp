#include "EulerProblems.h"

std::string problem_46::solution() {
	int max = 10000;
	bool *prime = new bool[max + 1];
	std::vector<int> primes = generatePrimes(max, prime);
	double test;

	for (int i = 35; i < max; i += 2) {

		if (!prime[i]) {

			for (auto j = primes.begin(); j != primes.end(); ++j) {

				test = sqrt((i - *j) / 2.0);

				if (*j + 2 > i)
					return std::to_string(i);
				else if (test == (int)test) {
					break;

				}
			}
		}

		
	}

}
std::vector<int> problem_46::generatePrimes(int limit, bool prime[]) {

	for (int i = 0; i < limit; i++)
		prime[i] = true;

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