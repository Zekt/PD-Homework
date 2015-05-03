#include<iostream>
#include<cmath>
using namespace std;

struct Point {
	int x;
	int y;
};

struct Triangle {
	Point p1;
	Point p2;
	Point p3;
	double area();
};

double Triangle::area() {
	double d1,d2,d3,d4;
	d1 = static_cast<double>(p2.x-p1.x);
	d2 = static_cast<double>(p3.y-p1.y);
	d3 = static_cast<double>(p3.x-p1.x);
	d4 = static_cast<double>(p2.y-p1.y);
	cout << d1 << d2 << d3 << d4 << endl;
	return abs(0.5 * (d1*d2-d3*d4));
}

int main() {
	Triangle a;
	cin >> a.p1.x >> a.p1.y >> a.p2.x >> a.p2.y >> a.p3.x >> a.p3.y;
	cout << a.area() << endl;
	return 0;
}
