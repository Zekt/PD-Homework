#include<iostream>
using namespace std;

class Randomlizer {
	private:
		//a,b,c,cur are private to prevent anyone from changing them.
		int a;
		int b;
		int c;
		int cur;
	public:
		int rand();
		bool srand(int s);
		Randomlizer() {
			//constructer when no parameters are passed.
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

bool Randomlizer::srand(int s) {
	if(s >= 0) {
		cur = s;
		return true;
	} else {
		cur = 0;
		return false;
	}
}


int main() {
	int a,b,c,s,n;
	cin >> a >> b >> c >> s >> n;
	Randomlizer r(a,b,c);
	r.srand(s);
	while(n--) {
		cout << r.rand();
		if(n == 0)
			cout << endl;
		else
			cout << " ";
	}
	return 0;
}
