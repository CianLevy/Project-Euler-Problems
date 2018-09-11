#include "EulerProblems.h"
#include <fstream>

std::string problem_54::solution() {
	std::string card;
	int converted_hand[10];
	//This switch statement will attribute integer values to cards such that:
	//1. The % 15 operation will yield the same value for cards of the same value but different suits
	//2. The / 100 operation will yield the same value for cards of the same suit

	std::ifstream file("p054_poker.txt");

	if (file.is_open()) {

		while (!file.eof()) {
			for (int i = 0; i < 10; i++) {
				file >> card;

				switch (card[1]) {

				case 'C':
					converted_hand[i] = 100 + cardValue(card[0]);
					break;
				case 'D':
					converted_hand[i] = 200 + cardValue(card[0]);
					break;
				case 'H':
					converted_hand[i] = 300 + cardValue(card[0]);
					break;
				case 'S':
					converted_hand[i] = 400 + cardValue(card[0]);
					break;
				}
			}
			quicksort(converted_hand, 0, 4);
			quicksort(converted_hand, 5, 9);

			for (int i = 0; i < 10; i++)
				std::cout << converted_hand[i] << " ";

			std::cout << "\n";
		}
	}
	return " ";
}
int problem_54::cardValue(char c) {
	if (c <= '9')
		return c - '0';
	else if (c == 'T')
		return 10;
	else if (c == 'J')
		return 11;
	else if (c == 'Q')
		return 12;
	else if (c == 'K')
		return 13;
	else if (c == 'A')
		return 14;
}

void problem_54::quicksort(int data[], int low, int high) {
	int partion_index;

	if (low < high) {

		partion_index = partition(data, low, high);

		quicksort(data, low, partion_index - 1);
		quicksort(data, partion_index + 1, high);
	}

}

int problem_54::partition(int data[], int low, int high) {
	int pivot = data[high];
	int temp;
	int start_index = low - 1;

	for (int i = low; i < high; i++) {
		if (pivot > data[i]) {
			start_index++;

			//Swap values
			temp = data[start_index];
			data[start_index] = data[i];
			data[i] = temp;
		}
	}
	temp = data[start_index + 1];
	data[start_index + 1] = data[high];
	data[high] = temp;

	return start_index + 1;
}

//Return if player 1 (first 5 cards) beat player 2 (last 5 cards)
int problem_54::handValue(int cards[]) {
	bool pair = true;
	bool tofk = true;
	bool straight = true;
	bool flush = true;




}