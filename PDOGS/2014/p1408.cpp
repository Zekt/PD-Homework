#include<iostream>
using namespace std;

int main() {
	int t,k;
	int inter[10] = {};
	cin >> t;
	while(t--) {
		cin >> k;
		if(k == 100)
			++inter[9];
		else
			++inter[k/10];
	}
	for(int i = 0; i < 10; ++i)
		cout << inter[i] << (i == 9 ? "\n" : " ");
}
