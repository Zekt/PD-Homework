#include<iostream>
using namespace std;

int main() {
	int n, tmp, limit, pair = 0, req = 0;
	bool i2j, j2i;
	cin >> n;
	int** users = new int*[n];
	int* birth = new int[n];
	int* r = new int[n];
	int bir[3];
	for(int i = 0; i < n; ++i) {
		cin >> tmp;
		for(int t = 0; t < 3; ++t)
			cin >> bir[t];
		birth[i] = 365*bir[0] + 30*bir[1] + bir[2];
		cin >> r[i];
		users[i] = new int[r[i]];
		for(int j = 0; j < r[i]; ++j)
			cin >> users[i][j];
	}
	for(int t = 0; t < 3; ++t)
		cin >> bir[t];
	limit = 365*bir[0] + 30*bir[1] + bir[2];
	for(int i = 0; i < n-1; ++i)
		for(int j = i+1; j < n; ++j) {
			if(birth[i] > limit || birth[j] > limit)
				continue;
			i2j = j2i = 0;
			for(int k = 0; k < r[i]; ++k)
				if(users[i][k] == j+1) {
					i2j = 1;
					break;
				}
			for(int k = 0; k < r[j]; ++k)
				if(users[j][k] == i+1) {
					j2i = 1;
					break;
				}
			if(i2j && j2i)
				++pair;
			else if(i2j || j2i)
				++req;
		}
	for(int i = 0; i < n; ++i)
		delete[] users[i];
	delete[] users;
	delete[] r;
	cout << pair << " " << req << endl;
	return 0;
}
