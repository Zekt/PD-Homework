#include<iostream>
#include<cmath>
using namespace std;

struct seg {
	int l,r;
};

int cau(seg &s, int x) {
	if(x >= s.l && x <= s.r)
		return 0;
	return min(abs(x-s.l),abs(x-s.r));
}

int main() {
	seg all[1000];
	int t,n,len,min = 2147483647,ans;
	cin >> t;
	while(t--) {
		min = 2147483647;
		cin >> n;
		for(int i = 0; i < n; ++i)
			cin >> all[i].l >> all[i].r;
		for(int i = 0; i < n; ++i) {
			len = 0;
			for(int j = 0; j < n; ++j)
				len += cau(all[j], all[i].l);
			if(len < min) {
				min = len;
				ans = all[i].l;
			}
			len = 0;
			for(int j = 0; j < n; ++j)
				len += cau(all[j], all[i].r);
			if(len < min) {
				min = len;
				ans = all[i].r;
			}
		}
		cout << ans << endl;
	}
}
