#include<iostream>
using namespace std;

int main() {
	int t;
	unsigned long long int n, i, total, l = 5;
	for(int k = 0; k < 26; ++k)
		l *= 5;
	cin >> t;
	while(t--) {
		total = 0;
		cin >> n;
		for(i = 5; i < l && i <= n; i *= 5)	
			total += n/i;
		total += n/l;
		cout << total << endl;
	}
}
