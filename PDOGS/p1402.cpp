#include<iostream>
#include<vector>

using namespace std;

bool notprime[100001] = {};

int main(){
	int n;
	bool first;
	vector<int> primes;
	notprime[0] = notprime[1] = 1;
	for(int i = 2;i < 100001;++i){
		if(!notprime[i])
			primes.push_back(i);
		for(int j = 0;j < primes.size() && i*primes[j] < 100001;++j){
			notprime[i*primes[j]] = 1;
			if(i%primes[j] == 0)
				break;
		}
	}
	while(cin >> n && n){
		if(n == 1)
			continue;
		first = 1;
		for(int i = 0;i < primes.size() && primes[i] < n;++i)
			if(n%primes[i] == 0){
				if(first) first = 0;
				else cout << " ";
				cout << primes[i];
			}
		if(!notprime[n])
			cout << n << endl;
		else
			cout << "\n";
	}
	return 0;
}
