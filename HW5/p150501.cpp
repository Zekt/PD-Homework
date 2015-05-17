#include<iostream>
using namespace std;

void take_coin(int left, int m, int t, int mode[], int count) {
	//take_coin will output the result of every subgame.
	//count will record how many times player 1 has played.
	if(left == 1) {
		cout << 1 << endl;
		return;
	}
	//if there's only 1 coin left, it must be player 1's.
	int take = mode[count%t];
	//player 1 will repeat it's strategy every t times,
	//so for the count-th time, the strategy it take would be mode[count%t].
	for(int i = 0; i < take; ++i)
		cout << 1 << " ";
	for(int i = 0; i < m+1-take; ++i)
		cout << 2 << " ";
	//after player 1 take x coins,
	//player 2 take m+1-x coins to make the coins left in the subgame
	//be (m+1)k+1 for some k and to make itself win.
	take_coin(left-m-1, m, t, mode, count+1);
	//after every round, there are left-m-1 coins left, add one to count.
}

int main() {
	int n,m,t;
	cin >> n >> m >> t;
	int* mode = new int[t];
	for(int i = 0; i < t; ++i)
		cin >> mode[i];
	//mode array record player 1's strategy.
	take_coin(n, m, t, mode, 0);
	return 0;
}
