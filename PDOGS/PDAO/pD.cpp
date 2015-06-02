#include<iostream>
using namespace std;

int exc[30] = {0, -1,  1,  7,  4,  2,
				   6,  8, 10, 18, 22,
				  20, 28, 68, 88,108,
				 188,200,208,288,688,
				 888};

int main() {
	int t,n,x;
	cin >> t;
	while(t--) {
		cin >> x;
		n = x;
		if(n == 6) {
			cout << 0 << endl;
		} else if(n <= 21) {
			cout << exc[n] << endl;
		} else {
			for(int i = 21; i > 0; --i) {
				if((n-i)%7 == 0) {
					cout << exc[i];
					n -= i;
					break;
				}
			}
			while(n > 0) {
				cout << "8";
				n -= 7;
			}
			cout << endl;
		}
		if(x == 1) {
			cout << "-1\n";
		} else {
			if(x%2 && x >= 3) {
				cout << 7;
				x -= 3;
			}
			while(x) {
				cout << 1;	
				x -= 2;
			}
			cout << endl;
		}
	}
}
