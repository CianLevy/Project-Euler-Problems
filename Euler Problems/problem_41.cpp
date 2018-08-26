#include "EulerProblems.h"

std::string problem_41::solution() {
	bool digit_used[9];
	int powers[] = { 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000 };
	int digit_sums[] = { 1, 3, 6, 10, 15, 21, 28, 36, 45 };
	int current_size = 6, current, digit, temp_size, digit_sum;

	std::vector<int> primes = generatePrimes(7654321);

	for (auto i = primes.end() - 1; i != primes.begin(); --i) {

		for (int j = 0; j < 9; j++)
			digit_used[j] = false;

		if (*i < powers[current_size])
			current_size--;

		temp_size = current_size;
		current = *i;
		digit_sum = 0;

		while (current > 0) {
			digit = current / powers[temp_size];
			current %= powers[temp_size];

			if (!digit_used[digit - 1])
				digit_used[digit - 1] = true;
			else
				break;

			temp_size--;
			digit_sum += digit;

		}
		if (current == 0 && digit_sums[current_size] == digit_sum)
			return std::to_string(*i);

	}

}

std::vector<int> problem_41::generatePrimes(int limit) {
	bool *prime = new bool[limit + 1];

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