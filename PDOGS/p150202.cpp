#include<iostream>

using namespace std;

int main(){
	int a,b;
	int count = 0;
	while(count < 3){
		cin >> a >> b;
		if(a == b){
			cout << "correct\n";
			break;
		}
		++count;
	}
	if(count == 3)
		cout << "fail\n";
	return 0;
}
