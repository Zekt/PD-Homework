#include<iostream>
#include<vector>
#include<cmath>
#define MIN -2147483648
using namespace std;

int state(double r) {
	int s;
	if(abs(r) >= 0.7)
		s = 3;
	else if(abs(r) >= 0.4)
		s = 2;
	else if(abs(r) > 0.000000005)
		s = 1;
	else
		s = 0;
	if(r < 0)
		s *= -1;
	return s;
}

int main() {
	int n, max = MIN;
	double avgX = 0, avgY= 0;
	cin >> n;
	vector<int> x(n);
	vector<int> y(n);
	for(int i = 0; i < n; ++i) {
		cin >> x[i];
		avgX += x[i];
		if(x[i] > max)
			max = x[i];
	}
	avgX /= n;
	for(int i = 0; i < n; ++i) {
		cin >> y[i];
		avgY += y[i];
		if(y[i] > max)
			max = y[i];
	}
	avgY /= n;
	double cov = 0, covX = 0, covY = 0;
	for(int i = 0; i < n; ++i) {
		covX += (x[i] - avgX) * (x[i] - avgX);
		covY += (y[i] - avgY) * (y[i] - avgY);
		cov += (x[i] - avgX) * (y[i] - avgY);
	}
	covX = sqrt(covX / (n-1));
	covY = sqrt(covY / (n-1));
	cov /= n-1;
	double r = cov /(covX*covY);
	cout << max << " " << state(r) << endl;
	return 0;
}
