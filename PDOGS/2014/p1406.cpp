#include<iostream>
#include<cstdio>
using namespace std;

int main() {
	int v[5] = {};
	char c;
	while(true){
		for(int i = 0; i < 5; ++i)
			v[i] = 0;
		c = getchar();
		if(c == EOF)
			break;
		while(c != '\n') {
			if(c == 'a' || c == 'A')
				++v[0];
			else if(c == 'e' || c == 'E')
				++v[1];
			else if(c == 'i' || c == 'I')
				++v[2];
			else if(c == 'o' || c == 'O')
				++v[3];
			else if(c == 'u' || c == 'U')
				++v[4];
			c = getchar();
		}
		cout << v[0];
		for(int i = 1; i < 5; ++i)
			cout << " " << v[i];
		cout << endl;

	}
}
