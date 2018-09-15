#include "EulerProblems.h"
#include <fstream>

std::string problem_54::solution() {
	std::string card;
	int converted_hand[10];
	int count = 0;
	int temp = 0;
	//This switch statement will attribute integer values to cards such that:
	//1. The % 100 operation will yield the same value for cards of the same value but different suits
	//2. The / 100 operation will yield the same value for cards of the same suit

	std::ifstream file("p054_poker.txt");

	if (file.is_open()) {

		while (!file.eof() && temp < 1000) {

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
			temp++;
			count += (int)(gameEvaluation(converted_hand));
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
		bool hand_rank[10] = { false };
		hand_rank[5] = true; //Flush
		bool same_suit = true;

		int card_count[13] = { 0 };

		if (cards[0 + j] / 100 != cards[4 + j] / 100) {
			same_suit = false;
			hand_rank[5] = false;
		}

		if (cards[0 + j] % 100 == 10 && cards[4 + j] - cards[0] == 4)
			hand_rank[9] = true;

		if (cards[4 + j] - cards[0 + j] == 4)
			hand_rank[8] = true;

		for (int i = 0; i < 5; i++)
			card_count[(cards[i + j] % 100) - 2]++;
		
		int continuous = 0;

		for (int i = 0; i < 13; i++) {
			if (i > 0 && card_count[i - 1] == 1 && card_count[i] == 1)
				continuous++;

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
		if (hand_rank[1] && hand_rank[3])
			hand_rank[6] = true;
		if (continuous == 4)
			hand_rank[4] = true;

		for (int i = 9; i >= 0; i--) {
			if (hand_rank[i]) {
				score[j / 5] = i;
				break;
			}
			if (i == 0)
				score[j / 5] = 0;
		}
	}
	if (score[0] == score[1]) {
		return resolveRankCollision(cards, score[0]);
	}
	else
		return score[0] > score[1];
}
//If both players hands are the same rank determine the winner by comparing the two cases
bool problem_54::resolveRankCollision(int cards[], int rank) {
	bool eliminated[13] = { false };
	int count_one[13] = { 0 };
	int count_two[13] = { 0 };

	for (int i = 0; i < 5; i++) {
		count_one[(cards[i] % 100) - 2]++;
		count_two[(cards[5 + i] % 100) - 2]++;
	}

	if (rank == 4)
		return (cards[0] % 100) > (cards[5] % 100);
	else if (rank == 8)
		return (cards[0] % 100) > (cards[5] % 100);
	else
		return compareRank(rank, count_one, count_two, eliminated);
}


bool problem_54::compareRank(int rank, int count_one[], int count_two[], bool eliminated[]) {
	int repeatRank[] = { 0, 0, 1, 0, 0, 0, 1, 0 };
	int temp = rank;

	if (temp == 1)
		temp = 2;
	else if (temp == 6)
		temp = 3;
	else if (temp == 7)
		temp = 4;

	if (rank == 0) {
		for (int i = 12; i >= 0; i--) {
			if (!eliminated[i] && (count_one[i] == 1 || count_two[i] == 1) && count_one[i] != count_two[i])
				return (count_one[i] == 1);
		}
	}
	else if (temp <= 4) {
		for (int i = 12; i >= 0; i--) {

			if (count_one[i] == temp && count_two[i] == temp) {
				eliminated[i] = true;
				return compareRank(repeatRank[rank], count_one, count_two, eliminated);
			}
			else if (!eliminated[i] && (count_one[i] == temp || count_two[i] == temp))
				return (count_one[i] == temp);

		}
	}
	if (rank == 5)
		return compareRank(0, count_one, count_two, eliminated);
}
