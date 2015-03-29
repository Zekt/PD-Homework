#include<iostream>
using namespace std;

int main(){
	int sum,total = 0;
	int input[9][9] = {0};
	int prefix[9][9] = {0};
	for(int i = 1;i < 9;++i)
		for(int j = 1;j < 9;++j)
			cin >> input[i][j];
	for(int i = 1;i < 9;++i)
		for(int j = 1;j < 9;++j)
			prefix[i][j] = prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1] + input[i][j];
	for(int i = 0;i < 8;++i)
		for(int x = 1;x < 9-i;++x)
			for(int y = 1;y < 9-i;++y){
				sum = prefix[x+i][y+i] - prefix[x-1][y+i] - prefix[x+i][y-1] + prefix[x-1][y-1];
				if(sum == 0) ++total;
			}
	cout << total << endl;
	return 0;
}
