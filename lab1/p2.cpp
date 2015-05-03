#include<iostream>
using namespace std;

int main() {
	int n,b,ans_q,ans_p,spend,tmp;
	cin >> n >> b;
	int* q = new int[n];
	int* p = new int[n];
	for(int i = 0;i < n;++i)
		cin >> q[i];
	for(int i = 0;i < n;++i)
		cin >> p[i];
	if(b <= q[0]*p[0]) {
		ans_q = b/p[0];
		ans_p = ans_q*p[0];
	} else {
		ans_q = q[0];
		ans_p = q[0]*p[0];
		b -= ans_p;
		for(int i = 1;i < n;++i) {
			spend = (q[i]-q[i-1])*p[i];
			if(b <= spend) {
				ans_q += b/p[i];
				tmp = b/p[i];	
				ans_p += tmp*p[i];
				break;
			} else {
				ans_q = q[i];
				ans_p += spend;
				b -= spend;
			}
		}
	}
	cout << ans_q << " " << ans_p << endl;
	return 0;
}
