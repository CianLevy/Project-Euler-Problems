#include "EulerProblems.h"
#include <fstream>

std::string problem_42::solution() {
	std::fstream file("p042_words.txt");
	char current;

	bool tri_num[1000] = { false };
	int tri_count = 0, num, sum;

	for (int i = 1; i < 100; i++) {
		num = i * (i + 1) / 2;
		if (num < 1000)
			tri_num[num] = true;
		else
			break;
	}
	int count = 0;

	if (file.is_open()) {
		while (!file.eof()) {

			sum = 0;
			file >> current;

			while (current != '\"' && current != ',' && current != ' ') {
				sum += current - 64;
				file >> current;
				

				if (current == '\"' && tri_num[sum])
					tri_count++;
			}
		}
		
	}
	file.close();

	return std::to_string(tri_count);
}