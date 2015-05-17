#include<iostream>
using namespace std;

void vecXY(int x1, int x2, int y1, int y2, int& d1, int& d2) {
	d1 = y1-x1;
	d2 = y2-x2;
}
//fucntion vecXY with d1 and d2 called by reference just assign the answers to d1 and d2.

void vecXY(int x1, int x2, int y1, int y2, int* d1, int* d2) {
	*d1 = y1-x1;
	*d2 = y2-x2;
}
//and vecXY with d1 and d2 called by pointers assign the answers to the pointed addresses.

int main() {
	int x1, x2, y1, y2, d1, d2;
	cin >> x1 >> x2 >> y1 >> y2;
	vecXY(x1, x2, y1, y2, d1, d2);
	cout << d1 << " " << d2 << endl;
	return 0;
}
