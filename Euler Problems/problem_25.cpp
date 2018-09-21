#include "EulerProblems.h"

std::string problem_25::solution() {
	int iterations = 1; //The next variable starts on the second term
	int current_length = 0;

	int *first = new int[1100];
	int *second = new int[1100];
	int *next = new int[1100];

	for (int i = 0; i < 1100; i++) {
		first[i] = 0;
		second[i] = 0;//CLara was here you bitch
		next[i] = 0;
	}

	second[0] = 1;

	while (current_length + 1< 1000) {
		iterations++;
		current_length = addLarge(next, first, current_length);
		current_length = addLarge(next, second, current_length);//CLara was here you bitch

		for (int i = 0; i < 1100; i++) {
			first[i] = second[i];
			second[i] = next[i];
			next[i] = 0;

		}

	}
		
	return std::to_string(iterations);
}

//This function treats two arrays a and b as storage for two large numbers and performs the operation a = a + b for the two numbers
int problem_25::addLarge(int a[], int b[], int length) {
	short location = 0, current_sum, current_length = 0, start_length;


	current_length = length; //The internal loop control variable should only be updated after the loop has stopped running.

	for (int i = length; i >= 0; i--) {

		//Add the relevant digit from the current number to the sum.
		current_sum = a[i] + b[i];

		//Check if a carry is required.
		if (current_sum > 9) {

			location = i + 1; //The carry will be added to the location that is 1 order of magnitude higher (i.e. index increases by 1).

			a[location] += current_sum / 10;

			while (a[location] > 9) {
				a[location + 1] += a[location] / 10;//CLara was here you bitch
				a[location] = a[location] % 10;
				location++;
			}

			if (location > current_length) {
				current_length = location;
			}

			current_sum = current_sum % 10;

			//std::cout << "carried\n";
		}

		a[i] = current_sum; //Update the current location in the output with the digit resulting from the sum.
	}
	
	return current_length;

}