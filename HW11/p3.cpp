#include<iostream>
#include<fstream>
using namespace std;

int con(int a, int b) {
	int i = ((double)a/b)*1000;
	if(i%10 >= 5)
		return (i/10)+1;
	else
		return i/10;
}

int main() {
	int times;
	char tmp[10];
	string path, date, id;
	char c[10];
	ifstream f;
	int count[10] = {};
	int pair[10][10] = {};
	int a,b;
	cin >> times;
	while(times--) {
		cin >> path;
		f.open(path.c_str());
		while(true) {
			f.getline(tmp, 10, ',');
			if(f.eof())
				break;
			f.getline(tmp, 10, ',');
			f.getline(tmp, 10, ',');
			f.getline(tmp, 10, ',');
			for(int i = 0; i < 10; ++i) {
				do {
					f >> c[i];
				} while(c[i] == ',');
				if(c[i] == '1')
					++count[i];
			}	
			for(int i = 0; i < 10; ++i)
				for(int j = 0; j < 10; ++j)
					if(c[i] == c[j] && c[j] == '1')
						++pair[i][j];
		}
		f.clear();
		f.close();
	}
	cin >> a >> b;
	cout << con(pair[a-1][b-1], count[b-1]) << endl;
}
