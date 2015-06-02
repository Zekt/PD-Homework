#include<iostream>

using namespace std;

int main(){
	int n;
	while(cin >> n && n){
		for(int i = 1;i < n;++i)
			if(n%i == 0)
				cout << i << " ";
		cout << n << endl;
	}
	return 0;
}
