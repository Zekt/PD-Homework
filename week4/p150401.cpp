#include<iostream>
using namespace std;

int knapsackValue(const int value[], const int weight[], int B, int n, const bool sol[]){
	int w_total = 0, v_total = 0;
	for(int i = 0;i < n;++i){
		w_total += sol[i]*weight[i];
		v_total += sol[i]*value[i];
	}
	if(w_total <= B)
		return v_total;
	else
		return -1;
}

int main(){
	int n,limit,tmp,max,ans = -1;
	//let max be the value of the solution,
	//and ans be the one should be changed in the best neighbor of the given solution,
	//if ans=-1 means the original one is the best solution.
	cin >> n >> limit;
	int* weight = new int[n];
	int* value = new int[n];
	bool* sol = new bool[n];
	for(int i = 0;i < n;++i)
		cin >> weight[i];
	for(int i = 0;i < n;++i)
		cin >> value[i];
	for(int i = 0;i < n;++i)
		cin >> sol[i];
	max = knapsackValue(value,weight,limit,n,sol);
	for(int i = 0;i < n;++i)
		if(!sol[i]){
			//if sol[i]=1, it must not be the index to be changed in the answer because if so,
			//the value would only decrease, so only test the neighbor if it's 0.
			sol[i] = 1;
			//change sol[i] to 1 and try this neighbor.
			tmp = knapsackValue(value,weight,limit,n,sol);
			if(tmp > max){
				max = tmp;
				ans = i;
			}
			//if the value of this neighbor is greater than max, record the index.
			sol[i] = 0;
			//change sol[i] back to 0.
		}
	if(ans != -1)
		sol[ans] = 1;
	cout << sol[0];
	for(int i = 1;i < n;++i)
		cout << " " << sol[i];
}
