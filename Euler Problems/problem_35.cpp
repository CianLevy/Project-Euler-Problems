#include "EulerProblems.h"

std::string problem_35::solution() {
	int max = 1000000;
	bool *prime = new bool[max + 1];
	std::vector<int> primes = generatePrimes(max, prime);
	int current;
	int digits[6]; //below 1000000 max is 6 digits
	int digit_count;
	int count = 0;



	for (auto i = primes.begin(); i != primes.end(); ++i) {
		current = *i;
		digit_count = 0;

		//Break the number into the component digits
		while (current > 0) {
			digits[digit_count] = current % 10;
			current /= 10;
			digit_count++;
		}
		//1 digit numbers are circular but will not be considered by the loop below
		if (digit_count == 1)
			count++;

		//For an x digit number there are x rotations of the number, however the number itself is already know to be prime
		//hence the loop only needs to run x - 1 times
		for (int j = 0; j < digit_count - 1; j++) {
			current = 0;

			for (int k = digit_count - 1; k >= 1; k--) {
				swap(digits[k], digits[k - 1]);
				current += digits[k] * pow(10, k);
			}
			current += digits[0];

			if (!prime[current]) //The loop can break as soon as a non prime rotation is found
				break;
			else if (j == digit_count - 2) {
				count++;
				break;
				/*Note at this point it is know that the number is circular and as a result its rotations could also be counted.
				However tracking rotations that have already been considered would require another bool array of size max and does not
				result in any noticable performance increase. For this reason i have chosen not to do this as it only further complicates
				the code.
				*/
			}
		}
		

	}

	return std::to_string(count);

}

std::vector<int> problem_35::generatePrimes(int limit, bool prime[]) {

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
					j = limit + 1;
			}
			prime_nums.push_back(i);
		}
	}

	return prime_nums;
}


void problem_35::swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}
