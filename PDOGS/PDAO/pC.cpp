#include<iostream>
#include<cstdio>
using namespace std;

bool check(char s[], int start, int end) {
	if(start == end)
		return 1;
	int half = (end-start+1)/2;
	if(check(s, start, start+half-1)) {
		for(int i = 0; i < half; ++i) 
			if(s[start+i] != s[end-i])
				return 0;
		return 1;
	}
	return 0;
}

int main() {
	int t, size;
	char s[101];
	char tmp;
	scanf("%d",&t);
	getchar();
	while(t--) {
		size = 0;
		tmp = getchar();
		while(tmp != '\n') {
			s[size++] = tmp;
			tmp = getchar();
		}
		if(size == 0 || check(s,0,size-1))
			cout << "Yes\n";
		else
			cout << "No\n";
	}
}
