#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool straight(vector<int> &card) {
	for(int i = 0; i < 4; ++i)
		if(card[i]+1 != card[i+1])
			return 0;
	return 1;
}

bool five(vector<int> &card) {
	for(int i = 0; i < 4; ++i)
		if(card[i] != card[i+1])
			return 0;
	return 1;
}

bool four(vector<int> &card) {
	bool flag = 0;
	for(int i = 0; i < 3; ++i)
		if(card[i] != card[i+1])
			flag = 1;
	if(!flag)
		return 1;
	for(int i = 1; i < 4; ++i)
		if(card[i] != card[i+1])
			return 0;
	return 1;
}

bool odd(vector<int> &card) {
	for(int i = 0; i < 5; ++i)
		if(card[i]%2 == 0)
			return 0;
	return 1;
}

int cal(vector<int> &card) {
	int total = 0;
	if(straight(card))
		total += 100;
	if(five(card))
		total += 80;
	else if(four(card))
		total += 60;
	if(odd(card))
		total += 40;
	for(int i = 0; i < 5; ++i)
		total += card[i];
	return total;
}

int main() {
	int n, size = 0, max = 0;
	cin >> n;
	vector<int> card(5);
	while(n--) {
		for(int i = 0; i < 5; ++i)
			cin >> card[i];
		sort(card.begin(), card.end());
		int rank = cal(card);
		if(rank > max) {
			max = rank;
			size = 1;
		} else if(rank == max)
			++size;
	}
	cout << max << " " << size << endl;
	return 0;
}
