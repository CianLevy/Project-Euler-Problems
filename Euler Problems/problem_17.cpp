#include "EulerProblems.h"

std::string problem_17::solution() {
	int character_count = 0, current;

	int units[] = { 0, 3, 3, 5, 4, 4, 3, 5, 5, 4 };
	int teens[] = { 3, 6, 6, 8, 8, 7, 7, 9, 8, 8 };
	int tens[] = { 6, 6, 5, 5, 5, 7, 6, 6 };

	for (int i = 1; i <= 1000; i++) {
		current = i;

		if (current >= 1000) {
			character_count += 11;
			current = 0;
		}

		if (current >= 100) {
			if (current % 100 == 0) 
				character_count += units[(current / 100)] + 7; //one hundred
			else 
				character_count += units[(current / 100)] + 10; //x hundred and...

			current = current % 100;
		}

		if (current >= 10) {
			if (current < 20) {
				character_count += teens[current - 10];
				current = 0;
			}
			else
				character_count += tens[(current / 10) - 2];
			current = current % 10;
		}

		character_count += units[current];

	}

	return std::to_string(character_count);

}