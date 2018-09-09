#include "EulerProblems.h"

std::string problem_50::solution() {
	const int max = 1000000;
	bool *prime = new bool[max + 1];
	std::vector<int> primes = generatePrimes(max, prime);
	int *sums = new int[max];

	int reduction = 1; //This variable tracks the reduction in the maximum sequence length required for the result to be prime
	int length = 1;
	sums[0] = 0; //This value must be initialised in order for the correct sum to be produced when the for loop below first runs

	for (auto i : primes) {
		if (sums[length - 1] + i > max)
			break;

		sums[length] = sums[length - 1] + i;

		length++;
	}
	length--;

	while (true) {
		//This for loop subtracts values from both ends of the sequence until a prime is found
		//The number of terms in the sum remains constant as the for loop runs
		for (int i = 0; i <= reduction; i++) {
			if (prime[sums[length - i] - sums[reduction - i]])
				return std::to_string(sums[length - i] - sums[reduction - i]);
		}
		reduction++;
	}
}


std::vector<int> problem_50::generatePrimes(int limit, bool prime[]) {
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