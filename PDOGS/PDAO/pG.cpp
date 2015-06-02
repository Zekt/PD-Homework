#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

struct lava {
	int x,y;
};

bool live(int x, int y, int time, vector<lava> &l) {
	for(int i = 0; i < l.size(); ++i)
		if(max(abs(x-l[i].x),abs(y-l[i].y)) <= time)
				return 0;
	return 1;
}

int find(vector<lava> &l, int n) {
	bool s = 1;
	int time;
	for(time = 0; time <= 200 && s; ++time) {
		s = 0;
		for(int x = (time*-1 < n*-1 ? n*-1 : time*-1); x <= time && x <= n && !s; ++x)
			for(int y = (time*-1 < n*-1 ? n*-1 : time*-1); y <= time && y <= n && !s; ++y) {
//				cout << "time: " << time << endl;
//				cout << "x: " << x << " y: " << y << endl;
				if(live(x,y,time,l))
					s = 1;
			}
	}
	return time-1;
}

int main() {
	int t,n,m;
	cin >> t;
	while(t--) {
		cin >> n >> m;
		vector<lava> l(m);
		for(int i = 0; i < m; ++i)
			cin >> l[i].x >> l[i].y;
		cout << find(l,n) << endl;
	}
}
