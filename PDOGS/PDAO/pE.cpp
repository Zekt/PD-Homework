#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	long long int t,n,L,R,mid,tmp,min,ans;
	cin >> t;
	while(t--) {
		min = 1000000000;
		min *= 2000*2000;
		cin >> n;
		vector<long long int> l(n);
		vector<long long int> lsuf(n);
		vector<long long int> r(n);
		vector<long long int> rpre(n);
		for(long long int i = 0; i < n; ++i)
			cin >> l[i] >> r[i];
		sort(l.begin(),l.end());
		sort(r.begin(),r.end());
		lsuf[n-1] = rpre[0] = 0;
		for(long long int i = 1; i < n; ++i) {
			lsuf[n-i-1] = lsuf[n-i]+(l[n-i]-l[n-i-1])*i;
			rpre[i] = rpre[i-1]+(r[i]-r[i-1])*i;
		}
/*
		cout << "l: \n";
		for(long long int i = 0; i < n; ++i) {
			cout << l[i] << " ";
		} cout << endl;
		cout << "r: \n";
		for(long long int i = 0; i < n; ++i) {
			cout << r[i] << " ";
		} cout << endl;
		cout << "lsuf: \n";
		for(long long int i = 0; i < n; ++i) {
			cout << lsuf[i] << " ";
		} cout << endl;
		cout << "rpre: \n";
		for(long long int i = 0; i < n; ++i) {
			cout << rpre[i] << " ";
		} cout << endl;
*/
		for(long long int i = 0; i < n; ++i) {
			L = 0;
			R = n-1;
			while(R-L > 1) {
				mid = (R+L)/2;
				if(r[mid] > l[i]) R = mid;
				else L = mid;
			}
			tmp = lsuf[i]+rpre[L];
			if(l[i] > r[0])	
				tmp +=(l[i]-r[L])*(L+1);
//			cout << "for l" << i << ": " << l[i] << " total is " << tmp << endl;
			if(tmp < min || (tmp == min && l[i] < ans)) {
				min = tmp;
				ans = l[i];
			}
			L = 0;
			R = n-1;
			while(R-L > 1) {
				mid = (R+L)/2;
				if(l[mid] >= r[i]) R = mid;
				else L = mid;
			}
			tmp = rpre[i]+lsuf[R];
			if(r[i] < l[n-1])
				tmp += (l[R]-r[i])*(n-R);
//			cout << "for r" << i << ": " << r[i] << " total is " << tmp << endl;
			if(tmp < min || (tmp == min && r[i] < ans)) {
				min = tmp;
				ans = r[i];
			}
		}
		cout << ans << endl;
	}
}
