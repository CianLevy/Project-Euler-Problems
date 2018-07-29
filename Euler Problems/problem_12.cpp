#include "EulerProblems.h"

std::vector<int> prime_numbers;

std::string problem_12::solution() {

	prime_numbers = generatePrimes(1000);

	/*Initial observations:
		triangular numbers increase in defined series and can be calculated using a formula rather than actually adding all the previous numbers
		problem is essentially reduced to finding an efficient method of determining the number of factors a number has
		an initial boundary must be selected for minimum size. A number with 500 divisors will be very large

	*/
	int number = 1;
	int i = 2;
	int divisors_of_number = 2;
	int divisors_odd = 2;
	int divisors_even = 2;

	while (divisors_of_number < 500) {

		if (i % 2 == 0) {
			divisors_even = num_divisors(i + 1);
			divisors_of_number = divisors_even * divisors_odd;
		}
		else {
			divisors_odd = num_divisors((i + 1) / 2);
			divisors_of_number = divisors_even * divisors_odd;
		}
		i++;
	}


	return std::to_string(i * (i - 1) / 2);
}

std::vector<int> problem_12::generatePrimes(int limit) {
	bool *prime = new bool[limit + 1];

	for (int i = 0; i < limit; i++)
		prime[i] = true;

	std::vector<int> prime_nums;

	prime_nums.push_back(2);

	for (int i = 2; i < sqrt(limit); i++) {
		if (prime[i]) {
			for (int j = i * i; j < i; j += i) {
				prime[j] = false;
			}
			prime_nums.push_back(i);
		}
	}

	return prime_nums;
}

int problem_12::num_divisors(int value) {
	int nod = 1, exponent = 1, remaining_value = value; //number of divisors of value

	for (auto i = prime_numbers.begin(); i != prime_numbers.end(); ++i) {
		while (remaining_value % *i == 0) {
			exponent++;
			remaining_value = remaining_value / *i;
		}

		nod *= exponent;
		exponent = 1;

		if (remaining_value == 1)
			return nod;
	}
}

