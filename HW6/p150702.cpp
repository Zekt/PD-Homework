#include<iostream>
using namespace std;

int main() {
	int n, tmp, pair = 0, req = 0;
	bool i2j, j2i;
	cin >> n;
	int** users = new int*[n];
	int* r = new int[n];
	//read inputs as described in the problem.
	for(int i = 0; i < n; ++i) {
		cin >> tmp >> r[i];
		users[i] = new int[r[i]];
		for(int j = 0; j < r[i]; ++j)
			cin >> users[i][j];
	}
	//after reading inputs, check the requests between every two users with a double loop.
	for(int i = 0; i < n-1; ++i)
		for(int j = i+1; j < n; ++j) {
			i2j = j2i = 0;
			//i2j and j2i are two flags to record whether a user has sent a request to the other.
			for(int k = 0; k < r[i]; ++k)
				if(users[i][k] == j+1) {
					i2j = 1;
					break;
				}
			for(int k = 0; k < r[j]; ++k)
				if(users[j][k] == i+1) {
					j2i = 1;
					break;
				}
			//if both users have sent a request to each other,
			//increase the number of total pairs of friends by 1.
			if(i2j && j2i)
				++pair;
			//if only one user has done so, add 1 to the number of uncomfirmed friend requests.
			else if(i2j || j2i)
				++req;
		}
	for(int i = 0; i < n; ++i)
		delete[] users[i];
	delete[] users;
	cout << pair << " " << req << endl;
	return 0;
}
