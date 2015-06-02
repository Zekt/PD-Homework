#include<iostream>
#include<fstream>
using namespace std;

int main() {
	ifstream f;
	char tmp[10];
	char c;
	int times;
	string path;
	cin >> times;
	while(times--) {
		cin >> path;
		f.open(path.c_str());
		while(true) {
			f.getline(tmp, 10, ',');
			cout << tmp << endl;
			if(f.eof())
				break;
			f.getline(tmp, 10, ',');
			cout << tmp << endl;
			f.getline(tmp, 10, ',');
			cout << tmp << endl;
			f.getline(tmp, 10, ',');
			cout << tmp << endl;
			for(int i = 0; i < 10; ++i) {
				do {
					f >> c;
				} while(c == ',');
				cout << c;
			}
			cout << endl;
		}
	}
}
