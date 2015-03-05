#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	int input,limit,m,n,num;
	bool found;
	while(cin >> input && input)
	{
		if(input > 0)
		{
			limit = sqrt(input)+1;
			found = 0;
			for(m = 2;m < limit && !found;++m)
				for(n = 2,num = m;num < input;++n)
				{
					num *= m;
					if(num == input)
					{
						found = 1;
						cout << m << " " << n << endl;
						break;
					}
				}
			if(!found)
				cout << "-1\n";
		}
		else
			cout << "Please input a positive integer!\n";
	}
	return 0;
}
