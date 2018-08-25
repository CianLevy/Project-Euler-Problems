#include "EulerProblems.h"

std::string problem_40::solution() {
	int sum = 1, current, limit, remainder, digit, number;
	int ranges[] = { 9, 180, 2700, 36000, 450000, 5400000}; //Number of digits in ranges 1 - 9, 10 - 99, 100 - 999, 1000 - 9999, 10000 - 99999, 100000 - 999999
	int powers[] = { 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000 }; //Cached powers of 10 for improved performance

	for (int i = 10; i <= 1000000; i *= 10) {
		limit = 0;
		current = i;

		while (current - ranges[limit] > 0) {
			current -= ranges[limit];
			limit++;
		}

		remainder = current % (limit + 1); //Location of the digit in the next number
		number = powers[limit] + current / (limit + 1) + 1; //The number that contains the digit of interest

		for (int j = 0; j <= remainder; j++) {
			digit = number / powers[limit + 1];
			number %= powers[limit + 1];
			limit--;
		}
		sum *= digit;
	}

	return std::to_string(sum);
}