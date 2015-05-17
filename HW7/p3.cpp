#include<iostream>
using namespace std;

struct Course {
	char id[3];
	int day;
	int stTime;
	int endTime;
	int score;
};

bool fit(Course &c, bool** calender) {
	for(int i = c.stTime; i < c.endTime; ++i)
		if(calender[c.day-1][i] == 1)
			return 0;
	return 1;
}//A function to check if a course can be placed in the calender.

int main() {
	bool** calender = new bool*[5];
	for(int i = 0; i < 5; ++i)
		calender[i] = new bool[24];
	for(int i = 0; i < 5; ++i)
		for(int j = 0; j < 24; ++j)
			calender[i][j] = 0;
	//A calender to record selected hours.
	bool exist[5] = {0};
	bool blank, isFit = 1;
	int n, blankDay = 0, total = 5;
	cin >> n;
	Course* courses = new Course[n];
	for(int i = 0; i < n; ++i) {
		cin >> courses[i].id >> courses[i].day >> courses[i].stTime >> courses[i].endTime >> courses[i].score;
		if(courses[i].score == 10)
			for(int j = courses[i].stTime; j < courses[i].endTime; ++j)
				calender[courses[i].day-1][j] = 1;
	}//Required courses are taken at first.
	for(int i = 0; i < 5; ++i) {
		blank = 1;
		for(int j = 0; j < 24; ++j)
			if(calender[i][j] == 1) {
				blank = 0;
				break;
			}
		if(blank)
			++blankDay;
	}//Cauculate the amount of blank days.
	for(int i = 0; i < n; ++i) {
		if(courses[i].score == 3)
			if(fit(courses[i],calender)) {
				exist[courses[i].day-1] = 1;
				for(int j = courses[i].stTime; j < courses[i].endTime; ++j)
					calender[courses[i].day-1][j] = 1;
			} else
				isFit = 0;
	}
	/* Check every course with score equal to 3, if it can be selected, put it on the calender.
	 * if it can't, record that not all courses with score equal to 3 can be selected.
	 * If one course is selected, record that there's a course selected on that day.
	 */
	cout << blankDay << " " << isFit << " ";
	for(int i = 0; i < 5; ++i)
		total -= exist[i];
	cout << total << endl;
	delete[] courses;
	for(int i = 0; i < 5; ++i)
		delete[] calender[i];
	delete[] calender;
	return 0;
}
