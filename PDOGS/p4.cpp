#include<iostream>

using namespace std;

bool bfs(char** maze,int x,int y,int step){
	if(step >
	if(maze[x][y] == 

int main(){
	int t;
	int m,n;
	cin >> t;
	for(int serial = 1;serial <= m;++serial){
		cin >> n >> m;
		char** maze = new char*[n+2];
		for(int i = 0;i <= n;++i)
			maze[i] = new char[m+2];
		for(int i = 1;i <= n;++i){
			for(int j = 1;j <= m;++j){
				if(i == 0 || i == n+1 || j == 0 || j == n+1)
					maze[i][j] == 0;
				else
					maze[i][j] = getchar();
			}
			getchar();
		}


