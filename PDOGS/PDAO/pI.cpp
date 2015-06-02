#include<iostream>
#include<vector>
using namespace std;

int main() {
	int t,n,m,l,r,min,total;
	cin >> t;
	while(t--) {
		min = 2147483647;
		cin >> n >> m;
		vector<int> input(n);
		vector<int> count(m+1);
		for(int i = 0; i < n; ++i)
			cin >> input[i];
		for(int i = 0; i < m+1; ++i)
			count[i] = 0;
		l = 0;
		++count[input[0]];
		total = 1;
		for(r = 1; r < n; ++r) {
			if(count[input[r]] == 0)
				++total;
			++count[input[r]];
			while(count[input[l]] > 1)
				--count[input[l++]];
			if(total == m && (r-l+1) < min)
				min = r-l+1;
		}
		if(total == m)
			cout << min << endl;
		else 
			cout << "QAQ\n";
	}
}
