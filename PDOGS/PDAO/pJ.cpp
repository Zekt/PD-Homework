#include<iostream>
#include<cstdio>
using namespace std;
bool apple[1000][1000] = {};
int col[1000][1000] = {};
int row[1000][1000] = {};
int dp[1000][1000] = {};

int main() {
	int t,n,total;
	scanf("%d",&t);
	getchar();
	while(t--) {
		total = 0;
		scanf("%d",&n);
		getchar();
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < n; ++j) {
				apple[i][j] = getchar()-'0';
				dp[i][j] = 0;
			}
			getchar();
		}
		for(int i = 0; i < n; ++i) {
			col[i][0] = apple[i][0];
			row[0][i] = apple[0][i];
			for(int j = 1; j < n; ++j) {
				col[i][j] = (apple[i][j] ? col[i][j-1]+1 : 0);
				row[j][i] = (apple[j][i] ? row[j-1][i]+1 : 0);
			}
			dp[0][i] = row[0][i];
			dp[i][0] = col[i][0];
		}
/*
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < n; ++j)
				cout << apple[i][j];
			cout << endl;
		}
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < n; ++j)
				cout << col[i][j];
			cout << endl;
		}
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < n; ++j)
				cout << row[i][j];
			cout << endl;
		}
*/
		for(int i = 1; i < n; ++i)
			for(int j = 1; j < n; ++j) {
				if(apple[i][j])
					dp[i][j] = min(col[i][j],min(row[i][j],dp[i-1][j-1]+1));
			}
/*		
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < n; ++j)
				cout << dp[i][j];
			cout << endl;
		}
*/		
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < n; ++j)
				total += dp[i][j];
		cout << total << endl;
	}
}
