#include "EulerProblems.h"

std::string problem_18::solution() {
	int tree_rows = 15, current_location;

	int tree[] = { 75, 95, 64, 17, 47, 82, 18, 35, 87, 10,
		20, 04, 82, 47, 65, 19, 01, 23, 75, 03,
		34, 88, 02, 77, 73, 07, 63, 67, 99, 65,
		04, 28, 06, 16, 70, 92, 41, 41, 26, 56,
		83, 40, 80, 70, 33, 41, 48, 72, 33, 47,
		32, 37, 16, 94, 29, 53, 71, 44, 65, 25,
		43, 91, 52, 97, 51, 14, 70, 11, 33, 28,
		77, 73, 17, 78, 39, 68, 17, 57, 91, 71,
		52, 38, 17, 14, 91, 43, 58, 50, 27, 29,
		48, 63, 66, 04, 68, 89, 53, 67, 30, 73,
		16, 69, 87, 40, 31, 04, 62, 98, 27, 23,
		9, 70, 98, 73, 93, 38, 53, 60, 04, 23 };

	/*The algorithim below is based on a dynamic programming approach which iteratively reduces the size of the tree by considering
	the tree as a whole to be a combination of smaller problems involving 3 values. There are only two possible pathes from any location
	in the tree (excluding values on the last row). To find the maximum at such a location the value of the two pathes must be considered.
	The larger of the two values is added to the value of the point of interest. Starting from the second to bottom row of the table and
	repeatedly adding the larger of the two possible pathes to the number analysed the algorithim eventually reaches the top of the tree,
	at which point the maximum has been calculated.
	*/

	for (int i = tree_rows - 1; i > 0; i--) {

		current_location = (i + 1) * i / 2 - 1; //The index of the value at the end of any given row i is equal to (i + 1) * i / 2 - 1

		for (int j = current_location; j >= current_location - i + 1; j--) 
			(tree[j + i] > tree[j + i + 1]) ? tree[j] += tree[j + i] : tree[j] += tree[j + i + 1];
		

	}

	return std::to_string(tree[0]);
}