#include<iostream>
using namespace std;

int main() {
	int t,n;
	cin >> t;
	for(int c = 1; c <= t; ++c) {
		cin >> n;
		if(n < 10) {
			cout << "Case #" << c << ": " << n << " " << n << endl;
			continue;
		}
	}
}
