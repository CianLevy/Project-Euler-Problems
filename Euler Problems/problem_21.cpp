#include "EulerProblems.h"
#include <vector>
#include <cmath>



std::string problem_21::solution() {
	int divisor_sum;
	const int limit = 10000;

	prime_numbers = generatePrimes(limit);

	int amicable_sum = 0;

	bool amicable[limit + 1];

	for (int i = 0; i < limit; i++)
		amicable[i] = false;


	for (int i = 2; i < limit; i++){

		if (!amicable[i]){
			divisor_sum = sum_divisors(i);

			if (i == sum_divisors(divisor_sum) && divisor_sum < limit && i != divisor_sum){

				amicable_sum += i + divisor_sum;
				amicable[i] = true;
				amicable[divisor_sum] = true;

			}
		}

	}

	return std::to_string(amicable_sum);

}


std::vector<int> problem_21::generatePrimes(int limit) {
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

int problem_21::sum_divisors(int value) {
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

	
	/*
	while (p * p <= n && n > 1 && i < primelist.Length) {
		p = primelist[i];
		i++;

		if (n % p == 0) {

			j = p * p;
			n = n / p;

			while (n % p == 0) {
				j = j * p;
				n = n / p;
			}
			sum = sum * (j - 1) / (p - 1);
		}
	} //A prime factor larger than the square root remains 
	if (n > 1) {
		sum *= n + 1;
	}

	

	for (auto i = prime_numbers.begin(); i != prime_numbers.end(); ++i) {

		divisor = *i;

		while (divisor < value && remaining_value % *i == 0) {
			divisor = pow(*i, exponent);
			divisors.push_back(divisor);

			other_divisor = value / divisor;
			divisors.push_back(other_divisor);

			for (auto a = divisors.begin(); a != divisors.end(); ++a) {
				if (other_divisor == *a)
					break;

				temp = other_divisor % *a;

				if (temp == 0) {
					sum += other_divisor / *a;
					std::cout << other_divisor / *a << "\n";
					//divisors.push_back(other_divisor / *a);
				}
			}

			std::cout << value / divisor << "\n";
			sum += divisor +  value / divisor;
			

			std::cout <<  divisor << "\n";
			exponent++;
			remaining_value = remaining_value / *i;
		}
		remaining_value = value;

		exponent = 1;

		//std::cout << "i " << *i << "\n";

		if (*i >= value) {
			std::cout << "returning\n";
			return sum;
		}
	}
	


*/
}