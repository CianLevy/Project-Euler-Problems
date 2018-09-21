#include "EulerProblems.h"

std::string problem_55::solution() {
	int lyrchel_count = 9999;
	int current_length = 1;
	int powers[] = { 1, 10, 100, 1000, 10000 };
	int number[50];
	bool isPalindrome;

	for (int i = 1; i < 10000; i++) {

		if (i >= powers[current_length])
			current_length++;

		int temp = i;

		for (int j = current_length - 1; j >= 0; j--) {
			number[j] = temp % 10;
			temp /= 10;
		}
		number[current_length] = 0;

		int temp_length = current_length;
		isPalindrome = false;

		for (int j = 0; j < 50; j++) {

			if (isPalindrome) {
				lyrchel_count--;
				break;
			}
	
			temp_length = addLarge(number, temp_length);
			number[temp_length] = 0;

			isPalindrome = true;
			for (int k = 0; k < temp_length; k++)
				if (number[k] != number[temp_length - 1 - k])
					isPalindrome = false;

		}

	}

	return std::to_string(lyrchel_count);

}

//This function treats two arrays a and b as storage for two large numbers and performs the operation a = a + b for the two numbers
int problem_55::addLarge(int a[], int length) {
	short location = 0, current_sum, current_length = 0, start_length;
	int *temp = new int[length + 1];
	int max_length = length;
	
	//Copy the array so sum remains unaffected by changes to digits
	for (int i = 0; i < length; i++)
		temp[i] = a[i];

	current_length = length; //The internal loop control variable should only be updated after the loop has stopped running.
	
	for (int i = length - 1; i >= 0; i--) {
		//std::cout << temp[i] << " " << temp[length - i - 1] << "\n";
		//Add the relevant digit from the current number to the sum
		current_sum = temp[i] + temp[length - i - 1];

		//Check if a carry is required.
		if (current_sum > 9) {

			location = i + 1; //The carry will be added to the location that is 1 order of magnitude higher (i.e. index increases by 1).

			a[location] += current_sum / 10;

			while (a[location] > 9) {
				a[location + 1] += a[location] / 10;
				a[location] = a[location] % 10;
				location++;
			}

			if (location > current_length)
				current_length = location;
			 if (location >= length)
				 max_length = length + 1;

			current_sum = current_sum % 10;

		}

		a[i] = current_sum; //Update the current location in the output with the digit resulting from the sum.


	}


	return max_length;

}