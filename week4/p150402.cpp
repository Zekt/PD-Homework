#include<iostream>
using namespace std;

int knapsackValue(const int value[], const int weight[], int B, int n,
		const bool sol[]){
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

int best(const int value[], const int weight[], int B, int n,
		const bool sol[]){
	bool* sol_tmp = new bool[n];
	for(int i = 0;i < n;++i)
		sol_tmp[i] = sol[i];
	//copy sol to sol_tmp to perform operations for safe.
	int tmp,ans = -1;
	int max = knapsackValue(value,weight,B,n,sol_tmp);
	for(int i = 0;i < n;++i)
		if(!sol_tmp[i]){
			sol_tmp[i] = 1;
			tmp = knapsackValue(value,weight,B,n,sol_tmp);
			if(tmp > max){
				max = tmp;
				ans = i;
			}
			sol_tmp[i] = 0;
		}
	//do operations as commented in p150401.cpp.
	return ans;
}

int main(){
	int n,limit,ans;
	cin >> n >> limit;
	int* weight = new int[n];
	int* value = new int[n];
	bool* sol = new bool[n]();
	for(int i = 0;i < n;++i)
		cin >> weight[i];
	for(int i = 0;i < n;++i)
		cin >> value[i];
	while(true){
		ans = best(value,weight,limit,n,sol);
		if(ans == -1)
			break;
		sol[ans] = 1;
	}
	cout << sol[0];
	for(int i = 1;i < n;++i)
		cout << " " << sol[i];
}
