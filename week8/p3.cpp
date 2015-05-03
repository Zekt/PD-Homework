#include<iostream>
#include<algorithm>
using namespace std;

class Randomlizer {
	private:
	int a;
	int b;
	int c;
	int cur;
	public:
	int rand();
	bool srand(int s) {
		if(s >= 0) {
			cur = s;
			return true;
		} else {
			cur = 0;
			return false;
		}
	}
	Randomlizer() {
		a = 1001;
		b = 1999;
		c = 32767;
		cur = 0;
	}
	Randomlizer(int _a, int _b, int _c) {
		a = _a;
		b = _b;
		c = _c;
		cur = 0;
	}
};

int Randomlizer::rand() {
	cur = (a * cur + b) % c;
	return cur;	
}

int main() {
	int a,b,c,m,size,total,seed;
	double M;
	bool first = 1;
	int x[1000];
	int sorted[1000];
	bool z[1000];
	cin >> a >> b >> c >> m;
	while(m--) {
		Randomlizer r(a,b,c);
		size = 0;
		total = 1;
		cin >> seed;
		r.srand(seed);
		for(int i = 0; i < 1000; ++i) {
			x[i] = r.rand();
			sorted[i] = x[i];
		}
		sort(sorted,sorted+1000);
		M = (static_cast<double>(sorted[499])+static_cast<double>(sorted[500]))/2;
		for(int i = 0; i < 1000; ++i) {
			if(x[i] > M)
				z[size++] = 1;
			else if(x[i] < M)
				z[size++] = 0;
		}
		for(int i = 1; i < size; ++i)
			if(z[i] != z[i-1])
				++total;
		/*
		cout << "M is " << M << endl;
		for(int i = 0; i < 1000; ++i)
			cout << x[i] << " ";
		cout << endl;
		*/
		if(first)
			first = 0;
		else
			cout << " ";
		cout << total;
	}
	return 0;
}
