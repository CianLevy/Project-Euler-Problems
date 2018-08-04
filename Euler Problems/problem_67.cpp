#include "EulerProblems.h"
#include <fstream>

std::string problem_67::solution() {

	int tree_rows = 100, current_location, tree_length = (tree_rows + 1) * tree_rows / 2;

	int *tree = new int[tree_length];

	std::fstream data("p067_triangle.txt");

	if (data.is_open()) {
		for (int i = 0; i < tree_length; i++)
			data >> tree[i];
	}
	data.close();

	for (int i = tree_rows - 1; i > 0; i--) {

		current_location = (i + 1) * i / 2 - 1; //The index of the value at the end of any given row i is equal to (i + 1) * i / 2 - 1

		for (int j = current_location; j >= current_location - i + 1; j--)
			(tree[j + i] > tree[j + i + 1]) ? tree[j] += tree[j + i] : tree[j] += tree[j + i + 1];
		
	}

	return std::to_string(tree[0]);

}