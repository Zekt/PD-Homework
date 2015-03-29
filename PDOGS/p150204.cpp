#include<iostream>

using namespace std;

int main(){
	int n,m;
	cin >> n >> m;
	for(int i = n;i <= m;++i)
		for(int j = n;j <= m;++j){
			if(j >= i)
				cout << i << "*" << j << "=" << i*j;
			if(j==m) cout << "\n";
			else cout << "\t";
		}
	return 0;
}
