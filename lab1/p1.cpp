#include<iostream>
using namespace std;

int pow(int a,int b) {
	if(b == 0) return 1;
	int tmp = a;
	while(--b)
		tmp *= a;
	return tmp;
}

int compute(int n, int poly[], int x) {
	int total = 0;
	for(int i = 0;i <= n; ++i)
		total += poly[i] * pow(x,i);
	return total;
}

int main() {
	int n,b,c,total,sol,min = 2147483647;
	cin >> n;
	int* input = new int[n+1];
	for(int i = n; i >= 0; --i)
		cin >> input[i];
	cin >> b >> c;
	for(int i = b; i <= c; ++i) {
		total = compute(n,input,i);
		if(total < min) {
			sol = i;
			min = total;
		}
	}
	cout << sol << " " << min << endl;
	return 0;
}
