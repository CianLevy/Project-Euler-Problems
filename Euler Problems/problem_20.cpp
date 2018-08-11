#include "EulerProblems.h"

std::string problem_20::solution() {

	int result[500] = { 0 };
	result[0] = 1;

	short location = 0, current_sum, current_length = 0, start_length, answer = 0;

	for (int j = 100; j >= 2; j--) {

		start_length = current_length; //The internal loop control variable should only be updated after the loop has stopped running.

		for (int i = start_length; i >= 0; i--) {

			//Add the relevant digit from the current number to the sum.
			current_sum = j * result[i];

			//Check if a carry is required.
			if (current_sum > 9) {
								
				location = i + 1; //The carry will be added to the location that is 1 order of magnitude higher (i.e. index increases by 1).

				result[location] += current_sum / 10;

				while (result[location] > 9) {
					result[location + 1] += result[location] / 10;
					result[location] = result[location] % 10;
					location++;
				}

				if (location > current_length) {
					current_length = location;
				}

				current_sum = current_sum % 10;
			}

			result[i] = current_sum; //Update the current location in the output with the digit resulting from the sum.
		}

	}

	for (int i = current_length; i >= 0; i--)
		answer += result[i];


	return std::to_string(answer);
}