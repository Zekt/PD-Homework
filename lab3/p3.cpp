#include<iostream>
#include<cstdlib>
#include<vector>
#include<sstream>
#include<algorithm>
#define MIN -2147483648
using namespace std;

struct input {
	int id, sta, time;
	input(int i, int s, int t) : id(i), sta(s), time(t) {}
};

bool cmp(input a, input b) {
	return a.id < b.id;
}

struct train {
	int id;
	int time[26] = {};
	train(int i, int s, int t) : id(i) {
		time[s] = t;
	}
};

int main() {
	string line;
	string inputArr[4];
	vector<input> sortedIn;
	vector<train> record;
	int totalTrain = 0;
	int best = 2000000000, min = 2000000000;
	while(getline(cin, line)) {
		stringstream ss(line);
		int size = 0;
		while(ss >> inputArr[size++]);
		if(line[0] >= '0' && line[0] <= '9') {
			input in(atoi(inputArr[0].c_str()), inputArr[1][0]-'A',
					atoi(inputArr[2].c_str()));
			sortedIn.push_back(in);
		} else {
			sort(sortedIn.begin(), sortedIn.end(), cmp);
			int lastId = MIN;
			for(int index = 0; index < sortedIn.size(); ++index) {
				if(sortedIn[index].id != lastId) {
					train trainTmp(sortedIn[index].id, sortedIn[index].sta,
							sortedIn[index].time);
					record.push_back(trainTmp);
					lastId = sortedIn[index].id;
				} else {
					record[record.size()-1].time[sortedIn[index].sta] =
						sortedIn[index].time;
				}
			}
			int s = inputArr[0][0]-'A';
			int e = inputArr[1][0]-'A';
			int startT = atoi(inputArr[2].c_str());
			int endT = atoi(inputArr[3].c_str());
			for(int i = 0; i < record.size(); ++i)
				if(record[i].time[s] && record[i].time[e] && (record[i].time[s] < record[i].time[e]))
					if(record[i].time[s] <= endT && record[i].time[s] >= startT) {
						++totalTrain;
						if(record[i].time[s] < min) {
							min = record[i].time[s];
							best = record[i].id;
						}
						else if(record[i].time[s] == min && record[i].id < best)
							best = record[i].id;
					}
		}
	}
	if(totalTrain)
		cout << totalTrain << " " << best << endl;
	else
		cout << totalTrain << endl;
	return 0;
}
