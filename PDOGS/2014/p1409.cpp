#include<iostream>
using namespace std;

int main() {
	int m[7][7];
	int f[6] = {};
	int max = 1;
	int tmp = 1;
	for(int i = 0; i < 7; ++i)
		for(int j = 0; j < 7; ++j) {
			cin >> m[i][j];
			++f[m[i][j]];
		}
	max = 0;
	for(int i = 1; i <= 5; ++i)
		if(f[i] > max)
			max = f[i];
	cout << max;
	max = 1;
	for(int i = 0; i < 7; ++i) {
		tmp = 1;
		for(int j = 1; j < 7; ++j) {
			if(m[i][j] == m[i][j-1])
				++tmp;
			else {
				if(tmp > max)
					max = tmp;
				tmp = 1;
			}
		}
		if(tmp > max)
			max = tmp;
		tmp = 1;
		for(int j = 1; j < 7; ++j) {
			if(m[j][i] == m[j-1][i])
				++tmp;
			else {
				if(tmp > max)
					max = tmp;
				tmp = 1;
			}
			if(tmp > max)
				max = tmp;
		}
	}
	cout << " " << max << endl;
}
