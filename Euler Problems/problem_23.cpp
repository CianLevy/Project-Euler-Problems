#include "EulerProblems.h"

std::string problem_23::solution() {
	const int max = 28123;
	prime_numbers = generatePrimes(10000);
	long answer = 0;
	bool *abundant_sum = new bool[max]; //Array used to indicate whether or not a number has been found to be a sum of abundant numbers
	int abundant_numbers[10000]; //Array used to store abundant numbers discovered so far
	int abundant_count = 0; //Int to track size of abundant numbers array
	int index; //Storing the current index (sum of abundant numbers) instead of recalculating

	for (int i = 0; i < max; i++)
		abundant_sum[i] = false;


	for (int i = 1; i < max; i++) {
		answer += i;

		if (i < sum_divisors(i)) {

			abundant_numbers[abundant_count] = i;


			for (int j = 0; j <= abundant_count; j++) {
				index = abundant_numbers[j] + i;

				if (index < max && !abundant_sum[index]) {
					abundant_sum[index] = true;
					answer -= (index);
				}
			}
			abundant_count++;
		}
	}

	return std::to_string(answer);

}

std::vector<int> problem_23::generatePrimes(int limit) {
	bool *prime = new bool[limit + 1];

	for (int i = 0; i < limit; i++) {
		prime[i] = true;
	}

	std::vector<int> prime_nums;

	for (int i = 2; i < limit; i++) {
		if (prime[i]) {

			for (int j = i * i; j < limit; j += i) {
				prime[j] = false;
			}
			prime_nums.push_back(i);
		}
	}

	return prime_nums;
}

int problem_23::sum_divisors(int value) {
	int exponent = 1, remaining_value = value; //number of divisors of value
	std::vector<int> divisors;
	std::vector<int> exponents;

	int sum = 1, divisor, other_divisor, temp;

	int j;

	for (auto i = prime_numbers.begin(); i != prime_numbers.end(); ++i) {

		if (remaining_value % *i == 0) {

			j = *i * *i;
			remaining_value = remaining_value / *i;

			while (remaining_value % *i == 0) {
				j = j * *i;
				remaining_value = remaining_value / *i;
			}
			sum = sum * (j - 1) / (*i - 1);
		}



		if (*i * *i > remaining_value || remaining_value <= 1)
			break;
	}
	if (remaining_value > 1)
		sum *= remaining_value + 1;

	return sum - value;
}