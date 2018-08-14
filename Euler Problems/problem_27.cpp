#include "EulerProblems.h"

std::string problem_27::solution() {
	int limit = 40000;
	bool *primevalue = new bool[limit + 1];
	std::vector<int> primes = generatePrimes(limit, primevalue);

	int best_a, best_b, longest = 0;

	auto current = primes.begin();

	int b, n = 1, value;

	while (*current <= 1000) {

		for (int i = 0; i < 2; i++) {
			(i % 2 == 0) ? b = *current : b = -*current;


			for (int a = -999; a < 1000; a++) {

				value = n * n + a * n + b;
				while (value <= limit && value >= 0 && primevalue[value]) {

					n++;
					value = n * n + a * n + b;

				}
				if (n > longest) {
					best_a = a;
					best_b = b;
					longest = n;
				}

				n = 1;
			}
		}
		++current;

	}

	return std::to_string(best_a * best_b);

}

std::vector<int> problem_27::generatePrimes(int limit, bool prime[]) {

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
