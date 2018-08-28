// EulerProblems.cpp : Defines the entry point for the console application.
//
#include "EulerProblems.h"

int main()
{
	problem_44 problem;

	auto t0 = std::chrono::high_resolution_clock::now();

	std::cout << problem.solution() << std::endl;

	auto t1 = std::chrono::high_resolution_clock::now();
	std::cout << "Solution calculated in " << static_cast<std::chrono::duration<float>>(t1 - t0).count() << " seconds" << std::endl;



    return 0;
}

