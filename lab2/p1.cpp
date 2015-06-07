#include<iostream>
using namespace std;

int main() {
	int n, K, t = 0, ansp, ansk, max = 0;
	cin >> n >> K;
	int* s = new int[n];
	for(int i = 0; i < n; ++i)
		cin >> s[i];
	for(int i = 0; i < K; ++i)
		for(int j = i+1; j <= K; ++j) {
			int total = 0;
			for(int p = i; p < n; p += j) {
				total += s[p];
			}
			if(total > max) {
				ansp = i;
				ansk = j;
				max = total;
			}
		}
	cout << ansk << " " << ansp+1 << " " << max << endl;
	return 0;
}
