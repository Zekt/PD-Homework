#include<iostream>

using namespace std;

int main(){
	for(int i = 0;i < 10;++i)
		for(int j = 0;j < 10;++j){
			cout << i << "*" << j << "=" << i*j;
			if(j==9) cout << "\n";
			else cout << "\t";
		}
	return 0;
}
