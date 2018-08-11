#include "EulerProblems.h"

std::string problem_24::solution() {

	const int range = 9;
	int numbers[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int limit_index;
	int minimum;
	int difference;
	int swap_required;
	std::string answer;

	for (int i = 1; i < 1000000; i++) {

		//Even lexicographic permutations require a number of different operations
		if (i % 2 == 0) {
			/*This for loop searches for a number that ends with a series of descending numbers.
			E.g. 0123456987
			If the the final digits are all descending then the next permutation will require that the number 1 index before
			the series of descending numbers is increased. This for loop searchs for such instances and stores the index of the location
			that must be changed. For the example above the index 7 would be stored, indicating that '6' will have to be increased. No changes
			to the order of the numbers on the left side of the 'limit_index' will occur.
			*/
			for (int j = 0; j < range; j++) 
				if (numbers[j] < numbers[j + 1])
					limit_index = j;

			/*Initialise the minimum to be the worst case scenario. I.e. the next closest value is the maximum difference.
			Note this assumes that the maximum difference between any of the numbers provided is equal to the range. Alternatively
			the minimum could be initialised with any value that is gauranteed to be larger than the maximum variation.
			*/
			minimum = range;

			/*The algorithim must now find the value to the right of the index found above which will increase the digit
			at the stored index location by the minimum amount.
			*/

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

	}

	for (int i = 0; i <= range; i++) 
		answer += numbers[i] + '0';
	
	return answer;
}

void problem_24::swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

void problem_24::bubbleSort(int arr[], int startValue, int endValue) {

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