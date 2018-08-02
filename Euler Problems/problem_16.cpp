#include "EulerProblems.h"

std::string problem_16::solution() {

	_int8 result[500] = { 0 };
	result[0] = 2;

	short location = 0, current_sum, current_length = 0, start_length, answer = 0;

	for (int j = 0; j < 999; j++){
		
		start_length = current_length; //The internal loop control variable should only be updated after the loop has stopped running.

		for (int i = start_length; i >= 0; i--) {
			//Add the relevant digit from the current number to the sum.
			current_sum = 2 * result[i];
		
			//Check if a carry is required.
			if (current_sum > 9) {

				//Update the value of current_sum so the correct digit is added to the output after the carry is handled.
				current_sum = current_sum % 10;
		
				location = i + 1; //The carry will be added to the location that is 1 order of magnitude higher (i.e. index increases by 1).

				//Only 1 carry is required and can be performed immediately.
				if (result[location] != 9)
					result[location]++; //Add the new carry.
				else {
					//Continue to loop as further carries are required.
					while (result[location] == 9) {
						result[location] = 0;
						location++; //Update the location tracking variable as the magnitude increases.
						result[location]++; //Add the new carry.
					}

				}

				if (location > current_length)
					current_length = location;
			}

			result[i] = current_sum; //Update the current location in the output with the digit resulting from the sum.
		}
	}

	for (int i = current_length; i >= 0; i--) 
		answer += result[i];
	
	return std::to_string(answer);
}