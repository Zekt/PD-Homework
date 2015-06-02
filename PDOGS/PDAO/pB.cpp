#include<iostream>
using namespace std;

int main() {
	int t,x1,x2,x3,x4,y1,y2,y3,y4;
	cin >> t;
	while(t--) {
		cin >> x1 >> x2 >> y1 >> y2;
		cin >> x3 >> x4 >> y3 >> y4;
		if(x1 > x4 || x2 < x3 || y1 > y4 || y2 < y3)
			cout << "No\n";
		else
			cout << "Yes\n";
	}
}
