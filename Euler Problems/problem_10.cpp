#include "EulerProblems.h"
#include <vector>

std::string problem_10::solution() {
	unsigned long sum = 0;

	/*for (int i = 2000000; i > 0; i--) {
		if (isPrime(i))
			sum += i;
	}
	
	Start from smallest work up
	Check to see if already discovered primes are a factor
	*/
	std::vector<int> primes;
	primes.push_back(2);
	sum += 2;
	

	for (int i = 3; i < 2000000; i++) {

		//std::cout << i << std::endl;

		for (auto a = primes.begin(); a != primes.end(); ++a) {
			//std::cout << "ran";

			if (a == primes.end() || *a > i / 2) {
				primes.push_back(i);
				sum += i;
				//std::cout << "added " << i << std::endl;
				//std::cout << "Size " << primes.size();
				break;

			}
			else if (i % *a == 0)
				break;

		}
	}

	return std::to_string(sum);
}

bool problem_10::isPrime(int num) {

	for (int i = 2; i < num / 2; i++) {
		if (num % i == 0)
			return false;
	}

	return true;
}