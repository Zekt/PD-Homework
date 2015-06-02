#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstdlib>
using namespace std;

int main() {
	ifstream f;
	string s;
	int num, max = 0;
	f.open("test.txt");
	while(getline(f, s)) {
		num = atoi(s.c_str());
		if(num > max)
			max = num;
	}
	cout << max;
}
