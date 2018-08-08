#include "EulerProblems.h"
#include <fstream>

std::string problem_22::solution() {
	std::fstream file("p022_names.txt");
	std::string names[5200];
	for (int i = 0; i < 2000; i++)
		names[i] = "";

	unsigned long result = 0;
	int sum = 0, count = 0;

	char current;

	if (file.is_open()) {
		while (!file.eof()) {
			file >> current;

			while (current != '\"' && current != ',' && current !=  ' ' && count < 5200) {
				names[count] += current;
				file >> current;

				if (current == '\"')
					count++;
			}	
		}
	}

	file.close();

	quicksort(names, 0, count);

	for (int i = 0; i < count; i++) {
		for (int j = 0; j < names[i].length(); j++) {

			sum += names[i].at(j) - 64;
		}
		result += sum * (count - i);
		sum = 0;
	}

	return std::to_string(result);
}

//Returns if a > b (lexicographically)
bool problem_22::lexicographic_compare(std::string a, std::string b) {
	int length = a.length(), count = 0;
	
	if (length > b.length())
		length = b.length();

	//std::cout << "length " << length << "\n";

	while (count < length && a.at(count) == b.at(count))
		count++;

	if (count == length)
		return (a.length() < b.length()); //If a contains all the same characters as b but is shorter than return true
	else
		return (a.at(count) < b.at(count)); //The lexicographic difference between the strings is determined by the first character that differs

}

void problem_22::quicksort(std::string data[], int low, int high) {
	int partion_index;

	if (low < high) {
	
		partion_index = partition(data, low, high);

		quicksort(data, low, partion_index - 1);
		quicksort(data, partion_index + 1, high);
	}

}

int problem_22::partition(std::string data[], int low, int high) {
	std::string pivot = data[high];
	std::string temp;
	int start_index = low - 1;

	for (int i = low; i < high; i++) {
		if (lexicographic_compare(pivot, data[i])) {
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