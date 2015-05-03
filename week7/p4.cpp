#include<iostream>
using namespace std;

struct Course {
	char id[3];
	int day;
	int stTime;
	int endTime;
	int score;
};

int main() {
	bool first = 1;
	int n, total = 0;
	bool** calender = new bool*[5];
	for(int i = 0; i < 5; ++i)
		calender[i] = new bool[24];
	for(int i = 0; i < 5; ++i)
		for(int j = 0; j < 24; ++j)
			calender[i][j] = 0;
	cin >> n;
	Course* courses = new Course[n];
	for(int i = 0; i < n; ++i) {
		cin >> courses[i].id >> courses[i].day >> courses[i].stTime >> courses[i].endTime >> courses[i].score;
		for(int j = courses[i].stTime; j < courses[i].endTime; ++j)
			calender[courses[i].day-1][j] = 1;
	}
	for(int i = 0; i < 5; ++i) {
		total = 0;
		for(int j = 8; j < 18; ++j)
			if(!calender[i][j])
				++total;
		if(first) {
			cout << total;
			first = 0;
		} else
			cout << " " << total;
	}
	cout << endl;
	return 0;
}
