#include "EulerProblems.h"

std::string problem_38::solution() {
	int current = 0;
	int powers[] = { 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000 };
	int max = 0;
	bool valid = true;
	int multiplier;

	int numbers[9];
	for (int j = 0; j < 9; j++)
		numbers[j] = 0;

	int product, length, digit;

	for (int i = 10000; i >= 1; i--) {

		multiplier = 2;
		current = 0;

		while (current < 987654321) {
			current = 0;
			valid = true;
			length = 0;

			for (int j = multiplier; j >= 1; j--) {
				product = j * i;

				while (product > 0 && length < 9) {

					digit = product % 10;

					if (numbers[digit - 1] == 0 && digit != 0)
						numbers[digit - 1] = length;
					else 
						valid = false;
	
					current += digit * powers[length];
					product = product / 10;
					length++;


				}
				if ((length == 9 && product != 0) || (length < 9 && j == 1))
					valid = false;

			}

			//Reset array
			for (int j = 0; j < 9; j++)
				numbers[j] = 0;

			if (valid && current > max)
				max = current;
			else if (length < 9)
				multiplier++;
			else
				break;


		}
	}

	return std::to_string(max);
}