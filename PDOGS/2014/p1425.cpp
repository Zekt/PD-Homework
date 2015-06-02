#include<iostream>
using namespace std;

int main() {
	long long int f[41];
	f[0] = 0;
	f[1] = f[2] = 1;
	for(int i = 3; i < 41; ++i)
		f[i] = f[i-1]+f[i-2];
	long long int n;
	while(cin >> n)
		cout << f[n] - n*n << endl;
}
