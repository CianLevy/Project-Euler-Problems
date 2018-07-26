#include "EulerProblems.h"
#include <math.h>

std::string problem_4::solution() {
	int product;
	int productArray[6];
	int maximum = 0;

	for (int i = 999; i >= 100; i--) {

		for (int k = i; k >= 100; k--) {

			product = i*k;

			//Breaking the number into an array
			for (int l = 0; l < 6; l++) {
				productArray[l] = product / (10 ^ (5 - l));
				product = product % (10 ^ (5 - l));
			}

			product = i*k;
			int correctNumbers = 0;

			/* if (product < 100000){
			for (int z = 0; z < 2; z++)
			if (productArray[z+1] == productArray[5-z])
			correctNumbers++;
			if (correctNumbers == 2)
			cout << product << " is a palindrome" << endl;

			}*/
			//else{
			for (int z = 0; z < 3; z++)
				if (productArray[z] == productArray[5 - z])
					correctNumbers++;
			if (correctNumbers == 3) {
				//cout << product << " is a palindrome" << endl;
				if (product > maximum)
					maximum = product;
			}



			//  }
			correctNumbers = 0;
		}



	}
	return std::to_string(maximum);
}