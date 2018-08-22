#include "EulerProblems.h"

std::string problem_37::solution() {
	int max = 1000000;
	bool *prime = new bool[max + 1];
	std::vector<int> prime_nums = generatePrimes(max, prime);

	auto current = prime_nums.begin();
	int trunc_count = 0, left, right, magnitude_count = 0, sum = 0;
	int powers[] = { 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000 };
	prime[1] = false;

	while (current != prime_nums.end() && trunc_count < 11) {

		left = 0;
		right = 0;
		magnitude_count = 1;

		while (left != *current && prime[left] && prime[right] && magnitude_count < 8) {
			right = *current / powers[magnitude_count]; //Remove digits on the right
			left = *current % powers[magnitude_count]; //Remove digits on the left

			magnitude_count++;
		}
		if (prime[left] && prime[right] && *current > 7) {
			trunc_count++;
			sum += *current;
		}

		++current;
	}
	return std::to_string(sum);
}


std::vector<int> problem_37::generatePrimes(int limit, bool prime[]) {

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