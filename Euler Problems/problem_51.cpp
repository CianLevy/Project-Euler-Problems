#include "EulerProblems.h"

std::string problem_51::solution() {
	const int max = 1000000;
	bool *prime = new bool[max + 1];
	std::vector<int> primes = generatePrimes(max, prime);
	int digits[7];

	int powers[] = { 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000 };
	int current_length = 1, max_loop, start_digit;

	
	for (auto i : primes) {
		if (powers[current_length] < i)
			current_length++;

		int current = i, count = 1, difference = 0, max_loop = 0;

		for (int j = 0; j < current_length; j++) {
			digits[j] = current / powers[current_length - j - 1]; //Add all the digits into an array
			current %= powers[current_length - j - 1];
		}
		current = i;

		//Check if the digits array contains duplicate 1's 0's
		//In order for there to be 8 primes in the family, the digits being incremented must start at a value <= 1
		for (int j = 0; j < current_length; j++) {
			//When the first 1 or 0 is found initialise the variables so only duplicates of the digit of interest are considered on the next iteration
			if (difference == 0 && (digits[j] == 0 || digits[j] == 1)) {
				difference += powers[current_length - j - 1]; //Update difference sum based on the position of the discovered digit
				start_digit = digits[j]; //Store the digit so duplicates can be discovered
				max_loop = 9 - start_digit;
			}
			else if (difference > 0 && digits[j] == start_digit)
				difference += powers[current_length - j - 1]; //Update difference sum based on the position of the discovered digit
		}

		for (int j = 0; j < max_loop; j++) {
			current += difference; //There is a fixed difference between the values
			if (current < max && prime[current])
				count++;
		}

		if (count == 8)
			return std::to_string(i);

	}

}

std::vector<int> problem_51::generatePrimes(int limit, bool prime[]) {
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