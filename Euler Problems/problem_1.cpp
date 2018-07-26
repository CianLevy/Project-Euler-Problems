#include "EulerProblems.h"

std::string problem_1::solution(){

	int result = 0;

	for (int i = 1; i < 1000; i++) 
		result += (i % 3 == 0 || i % 5 == 0) ? i : 0;

	return std::to_string(result);

}