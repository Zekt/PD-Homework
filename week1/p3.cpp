#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	int input,limit,m,n,num;
	bool found;
	while(cin >> input && input){
		if(input > 0){
			limit = sqrt(input)+3;
			for(m = 2,found = 0;m < limit && !found;++m)
				for(n = 2,num = m*m;num < limit;++n){
					num *= m;
					if(num == input){
						found = 1;
						break;
					}
				}
			if(found)
				cout << num << " " << m << " " << n << endl;
			else
				cout << "-1\n";
		}
		else
			cout << "Please input a positive integer!\n";
	}
	return 0;
}
