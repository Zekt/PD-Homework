#include<iostream>
#include<cstdio>
using namespace std;

bool isv(char c){
	char v[10] = {'a','A','e','E','i','I','o','O','u','U'};
	for(int i = 0; i < 10; ++i)
		if(c == v[i])
			return 1;
	return 0;
}

int main() {
	char c;
	char ans[1000];
	char tmp[1000];
	int len,max;
	while(true){ 
		c = getchar();
		max = len = 0;
		if(c == EOF)
			break;
		while(c != '\n') {
			if(isv(c)){
				tmp[len++] = c;
			} else {
				if(len > max) {
					max = len;
					for(int i = 0; i < len; ++i)
						ans[i] = tmp[i];
				}
				len = 0;
			}
			do {
				c = getchar();
			}while(c == ' ');
		}
		for(int i = 0; i < max; ++i)
			cout << ans[i];
		cout << endl;
	}
}
