#include "EulerProblems.h"

std::string problem_24::solution() {
	int range = 9;
	//int8_t numbers[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int numbers[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	//swap(numbers[4], numbers[3]);
	//for (int j = 0; j < range; j++) {
	//	std::cout << std::to_string(numbers[j]);
	//}
	//std::cout << "\n";


	int permutation_count = 1;
	int previous_swap = 8; //Tracks the magnitude of the previous swap
	int current_swap_index = 8;
	int other_index = 9;

	bool ascending = true;

	int swap_count = 2, max_swap = 9;
	int previous_swap_count = 1;

	int highest_order = 9;

	int j = range - 2;
	int fuck;
	int minimum;
	bool magup = false;

	for (int i = 1; i < 25; i++) {

	

		if (i % 2 == 0) {
			for (int k = 0; k <= range; k++)
				if (numbers[k] == range)
					j = k - 1;

			minimum = 0;
			magup = true;

			for (int k = j; k <= range; k++) {
				if (numbers[j] - numbers[k] < minimum)
					fuck = k;

				if (k >= j + 2 && k < range && numbers[k] < numbers[k + 1])
					magup = false;
			}
	

			if (magup)
				swap(numbers[fuck], numbers[j]);
			else
				j++;

			for (int i = range; i > j + 1; i--)
				swap(numbers[i], numbers[i - 1]);

			if (j % 2 == 0 && magup)
				swap(numbers[range], numbers[range - 1]);
		}
		else
	
			swap(numbers[range], numbers[range - 1]);
	
		std::cout << "magup " << magup << " " << i << ": ";
		for (int a = 0; a <= range; a++) {
			std::cout << std::to_string(numbers[a]);
		}
		std::cout << "\n";
	}




	return "s";
}
/*	if (i % 2 == 1) {
swap(numbers[range], numbers[range - 1]);
}
else {
if (numbers[j] == range)
j--;

while (numbers[fuck] - numbers[j] != 1)
fuck++;

swap(numbers[fuck], numbers[j]);



}
for (int j = 0; j <= range; j++) {
std::cout << std::to_string(numbers[j]);
}
std::cout << "\n";
*/

void problem_24::swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}