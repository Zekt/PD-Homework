#include<iostream>
using namespace std;

int main() {
	int b,tmp,box = 0,count,used = 0,size = 0,max = -1;
	int w[100001];
	cin >> b;
	do {
		cin >> w[size++];
	} while(w[size-1] != -1);
	--size;
	for(int i = size-1; i > 0; --i)
		for(int j = 0; j < i; ++j)
			if(w[j] < w[j+1]) {
				tmp = w[j];
				w[j] = w[j+1];
				w[j+1] = tmp;
			}
	bool* taken = new bool[size];
	for(int i = 0;i < size;++i)
		taken[i] = 0;
	while(box < b) {
		box = b;
		for(count = 0; count < size; ++count)
			if(w[count] <= box && taken[count] == 0) {
				box -= w[count];
				taken[count] = 1;
			}
		if(box < b) {
			++used;
			if(box > max)
				max = box;
		}
	}
	cout << used << " " << max << endl;
	return 0;
}

