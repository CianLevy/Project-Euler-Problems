#include "EulerProblems.h"

std::string problem_32::solution() {
	bool digit_used[9];

	std::vector<int> values_found;
	values_found.push_back(0); //In order for the loop on line 54 to run the vector cannot be empty

	int product, combined_num, temp, sum = 0, digit_count = 0;

	for (int l = 0; l < 9; l++)
		digit_used[l] = false;

	int current_digit;
	/*One of the most important elements of this problem is choosing the minimum solution space that will contain all the possible values.
	The maximum number of digits than can result from the product of an n-digit number and m-digit number is m + n digits.
	The minimum number of digits than can result from the product of an n-digit number and m-digit number is m + n - 1 digits.
	Using this information it can be concluded that the number of combined digits in the multiplier and multiplicand must be equal to 5
	*/

	for (int i = 1; i <= 100; i++){
		for (int j = 9999; j >= i; j--) {
			product = i * j;

			for (int l = 0; l < 9; l++)
				digit_used[l] = false;

			digit_count = 0;
			combined_num = 0;

			if (i < 100 && j < 100) //The largest product of any 2 2-digit (or smaller) numbers is 4 digits. Therefore there are no solutions in this range.
				break;

			/*The following if else statements check the size of the multiplier, multiplicand, and product and shift the 
			numbers as required so they form one 9-digit number which can be checked for duplicate digits
			*/
			else if (i < 10 && j < 1000 && product < 100000)
				combined_num = i * 100000000 + j * 100000 + product;
			else if (i < 10 && product < 10000)
				combined_num = i * 100000000 + j * 10000 + product;
			else if (i < 100 && product < 10000)
				combined_num = i * 10000000 + j * 10000 + product;


			temp = combined_num;
			/*This loop checks the number calcualted above for duplicate digits.
			0 is effectively a sentinel here to indicate that the total number of digits is incorrect
			*/
			while (combined_num != 0 && digit_count < 9) {
				current_digit = temp % 10;

				if (current_digit == 0 || digit_used[current_digit - 1])
					break;
				else
					digit_used[current_digit - 1] = true;

				temp /= 10;
				digit_count++;
			}
			//If 9 unique digits are found then the number can be added to the sum (provided it is not a duplicate)
			if (digit_count == 9) {
				auto k = values_found.begin();
				int length = values_found.size() - 1;

				for (int l = 0; l <= length; l++) {

					if (*k == product) //If the number is already in the vector then do not add again
						break;
					else if (l == length) {
						values_found.push_back(product);
						sum += product;
						break;
					}

					++k;
				}

			}

		}
	}


	 return std::to_string(sum);

}