#include "EulerProblems.h"

std::string problem_19::solution() {

	int week_day = 1, current_month = 0, month_day = 1, year_length, solution_count = 0;
	int month_lengths[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	for (int year = 1900; year <= 2000; year++) {

		//Checking if the year is a leap year or not
		if ((year % 100 != 0 && year % 4 == 0) || (year % 100 == 0 && year % 400 == 0)) {
			year_length = 366;
			month_lengths[1] = 29;
		}

		else {
			year_length = 365;
			month_lengths[1] = 28;
		}


		for (int day = 1; day <= year_length; day++) {
			if (month_day > month_lengths[current_month]) {
				current_month++;
				month_day = 1;
			}

			if (week_day > 7)
				week_day = 1;
			else if (week_day == 7 && month_day == 1 && year >= 1901)
				solution_count++;

			week_day++;
			month_day++;


		}

		current_month = 0;
		month_day = 1;
	}

	return std::to_string(solution_count);
}