#include "EulerProblems.h"

std::string problem_26::solution() {
	int position;
	int pattern_count;
	int current_value;
	int length = 0;

	for (int i = 1000; i > 0; i--) {
		//If a sequence has already been found that is longer than or equal to the current number then no longer sequence will be found
		if (length >= i)
			break;

		int *remainders = new int[i];

		for (int k = 0; k < i; k++)
			remainders[k] = 0;

		current_value = 1;
		position = 0;

		//The loop ends when the same remainder occurs again (indicating the number repeats), or the number evenly divides
		while (current_value != 0 && remainders[current_value] == 0) {
			remainders[current_value] = position;

			current_value *= 10;
			current_value %= i;
			position++;
		}
	
		//The length of the repeating sequence is determined by subtracting the location at which the first repetition occured from the total length
		if (position - remainders[current_value] > length) {
			length = position - remainders[current_value];
		}

	}

	return std::to_string(length);

}