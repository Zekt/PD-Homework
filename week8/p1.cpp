#include<iostream>
#include<cstdlib>
using namespace std;

struct LotteryMachine {
	int tokenCount;
	int* tokens;
	int outcomeCount;
	int* outcomes;
	void initialize();
	void initialize(int n, int t[]);
	bool draw(int m);
	void release();
};

void LotteryMachine::initialize() {
	tokenCount = outcomeCount = 0;
	tokens = outcomes = NULL;
}

void LotteryMachine::initialize(int n, int t[]) {
	tokenCount = n;
	outcomeCount = 0;
	tokens = new int[n];
	for(int i = 0; i < n; ++i)
		tokens[i] = t[i];
	outcomes = NULL;
}

void LotteryMachine::release() {
	delete[] tokens;
	delete[] outcomes;
}

bool LotteryMachine::draw(int m) {
	if(m <= 0 || m > tokenCount)
		return false;
	delete[] outcomes;
	outcomeCount = m;
	outcomes = new int[outcomeCount];
	int* pop = new int[tokenCount];
	for(int i = 0; i < tokenCount; ++i)
		pop[i] = tokens[i];
	int size = tokenCount;
	int tmp;
	int it = 0;
	srand(time(0));
	do {
		tmp = rand()%(size--);
		outcomes[it++] = pop[tmp];
		pop[tmp] = pop[size];
	} while(it < m);
	delete[] pop;
	return true;
}

int main() {
	int n[10] = {1,2,3,4,5,6,7,8,9,0};
	LotteryMachine l;
	l.initialize(10,n);
	l.draw(5);
	for(int i = 0; i < 5; ++i)
		cout << l.outcomes[i] << " ";
	return 0;
}
