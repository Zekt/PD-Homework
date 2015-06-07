#include<iostream>
using namespace std;

int main() {
	int m[26] = {0};
	int item[51] = {0};
	int t, t2, tmp, b, c, d, max1 = 0, max2 = 0, maxi;
	char a, maxm;
	cin >> t;
	while(t--) {
		cin >> t2;
		for(int i = 0; i < 3; ++i)
			cin >> tmp;
		while(t2--) {
			cin >> a >> b >> c >> d;
			m[a-'A'] += c*d;
			item[b] += c*d;
		}
	}
	for(int i = 0; i < 26; ++i)
		if(m[i] > max1) {
			max1 = m[i];
			maxm = i+'A';
		}
	for(int i = 1; i <= 50; ++i)
		if(item[i] > max2) {
			max2 = item[i];
			maxi = i;
		}
	cout << maxm << " " << max1	<< " " << maxi << " " << max2 << endl;
	return 0;
}
