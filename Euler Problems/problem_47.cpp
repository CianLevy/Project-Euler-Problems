#include "EulerProblems.h"

std::string problem_47::solution() {
	const int max = 20000;
	int count = 0;
	int target = 4;

	std::vector<int> primes = generatePrimes(max);

	for (int i = 640; i < 30 * max; i++) {
		int maxFactor = i / 30; //The minimum product produced by the other 3 factors is 30 because 2 x 3 x 5 = 30,
		//when the other 3 factors are minimised the last factor is maximised
		int factor_count = 0;
		int remainder = i;

		for (auto j : primes) {
			int power = 0;

			if (remainder == 1)
				break;
			else if (j > maxFactor || factor_count > target) {
				count = 0;
				break;
			}

			while (remainder % j == 0) {
				if (power == 0) //The power variable is used only to prevent the same factor being counted more than once
					factor_count++;

				remainder = remainder / j;
				power++;
			}
		}

		if (factor_count == target) {
			count++;

			//It's slightly faster to contain this if statement here because it can only be true directly after the count has increased
			if (count == target)
				return std::to_string(i - target + 1);
		}
		else
			count = 0;
	}
}

std::vector<int> problem_47::generatePrimes(int limit) {
	bool *prime = new bool[limit + 1];

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