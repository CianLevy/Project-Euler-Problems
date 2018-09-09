#include "EulerProblems.h"

std::string problem_43::solution() {

	const int range = 9;
	int numbers[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int dividers[] = { 2, 3, 5, 7, 11, 13, 17 };
	unsigned long long powers[] = { 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000 };
	int limit_index, minimum, difference, swap_required, sub_sum, permutation_count = 1;
	unsigned long long current = 123456789;
	unsigned long long sum = 0;
	bool stop_flag = false;

	while (!stop_flag) {

		for (int j = 0; j < 7; j++) {
			sub_sum = 0;

			for (int k = 0; k < 3; k++)
				sub_sum += numbers[1 + j + k] * powers[2 - k];

			if (sub_sum % dividers[j] != 0)
				break;
			else if (j == 6) {

				for (int j = 0; j < 10; j++)
					sum += numbers[j] * powers[9 - j];
			}

		}
		if (permutation_count % 2 == 0) {

			limit_index = -1; //-1 serves as a flag to indicate the program has run out of permutations to consider

			for (int j = 0; j < range; j++)
				if (numbers[j] < numbers[j + 1])
					limit_index = j;

			if (limit_index == -1) {
				stop_flag = true;
				break;
			}

			minimum = range;

			for (int j = limit_index; j <= range; j++) {

				difference = numbers[j] - numbers[limit_index];

				if (difference > 0 && difference < minimum) {
					swap_required = j; //Storing the index of the nearest value to the value contained at index limit_index
					minimum = difference;
				}
			}

			swap(numbers[swap_required], numbers[limit_index]); //The value at limit_index is increased as required
			bubbleSort(numbers, limit_index + 1, range); //The remaining values to the right of the limit_index must be ordered in ascending order

		}
		//All odd lexicographic permutations are the same as the previous permutation with the last 2 numbers swapped
		else
			swap(numbers[range], numbers[range - 1]);

		permutation_count++;
	}

	return std::to_string(sum);
}

void problem_43::swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

void problem_43::bubbleSort(int arr[], int startValue, int endValue) {

	int length = endValue;

	int new_length = 1;

	while (new_length != 0) {
		new_length = 0;

		for (int i = startValue + 1; i <= length; i++) {
			if (arr[i - 1] > arr[i]) {
				swap(arr[i - 1], arr[i]);
				new_length = i;
			}
		}
		length = new_length;
	}
}