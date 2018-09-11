#include "EulerProblems.h"
#include <fstream>

std::string problem_54::solution() {
	std::string card;
	int converted_hand[10];
	int count = 0;
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
			count += gameEvaluation(converted_hand);
		}
	}
	return std::to_string(count);
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
bool problem_54::gameEvaluation(int cards[]) {
	int score[2];

	for (int j = 0; j <= 5; j += 5) {

		bool hand_rank[10] = { true };
		hand_rank[0] = false; //Highest card
		hand_rank[1] = false; //One pair
		hand_rank[2] = false; //Two pairs
		hand_rank[3] = false; //Three of a kind
		hand_rank[4] = true; //Straight
		hand_rank[5] = true; //Flush
		hand_rank[6] = false; //Full house
		hand_rank[7] = false; //Four of a kind
		hand_rank[8] = true; //Straight flush
		hand_rank[9] = true; //Royal flush
		bool same_suit = true;
		int card_count[13] = { 0 };

		if (cards[0 + j] / 100 != cards[4 + j] / 100) {
			same_suit = false;
			hand_rank[5] = false;
			hand_rank[9] = false;
		}

		if (cards[0 + j] % 100 != 10 || cards[4 + j] - cards[0] != 4 || !same_suit)
			hand_rank[9] = false;
		else {
			hand_rank[8] = false;
			hand_rank[5] = false;
		}

		if (cards[4 + j] - cards[0 + j] != 4)
			hand_rank[8] = false;

		if (!same_suit)
			hand_rank[5] = false;

		for (int i = 0; i < 5; i++) {
			card_count[cards[i + j] % 100 - 2]++;
		}

		for (int i = 0; i < 13; i++) {
			if (i > 0 && card_count[i - 1] == 1 && card_count[i] != 1)
				hand_rank[4] = false;

			if (card_count[i] == 4)
				hand_rank[7] = true;
			else if (card_count[i] == 3)
				hand_rank[3] = true;
			else if (hand_rank[1] && card_count[i] == 2) {
				hand_rank[2] = true;
				hand_rank[1] = false;
			}
			else if (card_count[i] == 2)
				hand_rank[1] = true;
		}
		if (hand_rank[1] && hand_rank[3]) {
			hand_rank[6] = true;
			hand_rank[1] = hand_rank[3] = false;
		}

		for (int i = 0; i < 10; i++) {
			if (hand_rank[i]) {
				score[j / 5] = i;
				break;
			}
			if (i == 9)
				score[j / 5] = 0;
		}
	}
	if (score[0] == score[1])
		return resolveRankCollision(cards, score[0]);
	else
		return score[0] > score[1];
	//std::cout << score[0] << " " << score[1] << " " << (score[0] > score[1]) << "\n";

}

bool problem_54::resolveRankCollision(int cards[], int rank) {
	int control = rank;
	bool eliminated[13] = { false };
	int count_one[13] = { 0 };
	int count_two[13] = { 0 };

	for (int i = 0; i < 5; i++) {
		count_one[cards[i] % 100 - 2]++;
		count_two[cards[5 + i] % 100 - 2]++;
	}
	retry:

		switch (control) {
		case 0:
			for (int i = 12; i >= 0; i--) {
				if (!eliminated[i] && (count_one[i] == 1 || count_two[i] == 1) && count_one[i] != count_two[i])
					return (count_one[i] == 1);
			}
			break;
		case 1:
			for (int i = 12; i >= 0; i--) {
				if (count_one[i] == 2 && count_two[i] == 2) {
					eliminated[i] = true;
					control = 0;
					goto retry;
				}
				else if (!eliminated[i] && (count_one[i] == 2 || count_two[i] == 2))
					return (count_one[i] == 2);

			}
			break;

		case 2:
			for (int i = 12; i >= 0; i--) {

				if (count_one[i] == 2 && count_two[i] == 2) {
					eliminated[i] = true;
					control = 1;
					goto retry;
				}
				else if (!eliminated[i] && (count_one[i] == 2 || count_two[i] == 2))
					return (count_one[i] == 2);

				}
				break;
		case 3:
			for (int i = 12; i >= 0; i--) {

				if (count_one[i] == 3 && count_two[i] == 3) {
					eliminated[i] = true;
					control = 0;
					goto retry;
				}
				else if (!eliminated[i] && (count_one[i] == 3 || count_two[i] == 3))
					return (count_one[i] == 3);

				}
				break;
		case 4:
			return (cards[0] % 100) > (cards[5] % 100);
			break;

		case 5:
			control = 0;
			goto retry;
			break;
		
		case 6:
			for (int i = 12; i >= 0; i--) {

				if (count_one[i] == 3 && count_two[i] == 3) {
					eliminated[i] = true;
					control = 1;
					goto retry;
				}
				else if (!eliminated[i] && (count_one[i] == 3 || count_two[i] == 3))
					return (count_one[i] == 3);

				}
				break;

		case 7:
			for (int i = 12; i >= 0; i--) {

				if (count_one[i] == 4 && count_two[i] == 4) {
					eliminated[i] = true;
					control = 0;
					goto retry;
				}
				else if (!eliminated[i] && (count_one[i] == 4 || count_two[i] == 4))
					return (count_one[i] == 4);

			}
			break;

		case 8:
			return (cards[0] % 100) > (cards[5] % 100);
			break;

		case 9:
			return true;
			break;
		}
		
		return false;
}