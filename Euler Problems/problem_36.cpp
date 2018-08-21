#include "EulerProblems.h"

std::string problem_36::solution() {
	int powers[7] = { 1, 10, 100, 1000, 10000, 100000, 1000000 };
	int sum = 0, current_length = 1;

	for (int i = 1; i < 1000000; i++) {
		if (i > powers[current_length])
			current_length++;

		if (decimalPalindrome(i, current_length, powers) && binaryPalindrome(i))
			sum += i;

	}
	return std::to_string(sum);
}

bool problem_36::decimalPalindrome(int num, int length, int powers[]) {
	int halflength;
	if (length % 2 == 1)
		halflength = length / 2 + 1;
	else
		halflength = length / 2;

	int *digits = new int[halflength];
	int digit_count = 0;
	int sum = 0;

	int temp = num;

	while (digit_count < halflength) {
		digits[digit_count] = temp % 10;
		temp = temp / 10;
		sum += digits[digit_count] * powers[halflength - digit_count - 1];
		digit_count++;

	}
	if ((num / powers[halflength - (length % 2 == 1)]) == sum)
		return true;
	else
		return false;

}

bool problem_36::binaryPalindrome(int num) {
	unsigned int a = 0b1000000000000000000000000000000;
	int count = 0, length, halflength, temp;

	while ((num & a) == 0) {
		a = a / 2;
		count++;
	}

	length = 31 - count;

	halflength = length / 2;
	bool odd_length = length % 2;

	for (int i = 0; i < halflength; i++) {
		if (((num >> length - i - 1) & 0b1) != ((num >> i) & 0b1))
			return false;
	}

	return true;

}