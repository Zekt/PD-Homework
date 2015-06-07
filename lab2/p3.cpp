#include<iostream>
using namespace std;

bool invalid(int a, int b, int c) {
	if(a+b <= c || b+c <= a || a+c <= b)
		return 1;
	return 0;
}

int main() {
	int net[100][100];
	int n, count = 0;
	cin >> n;
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			cin >> net[i][j];
	for(int i = 0; i < n-2; ++i)
		for(int j = i+1; j < n-1; ++j)
			for(int k = j+1; k < n; ++k)
				if(invalid(net[i][j], net[j][k], net[i][k]))
					++count;
	cout << count << endl;
	return 0;
}
