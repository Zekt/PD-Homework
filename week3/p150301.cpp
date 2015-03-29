#include<iostream>
using namespace std;

int main(){
	int n,b,k,v_tmp,w_tmp,tmp;
	//n,b,k are the same in the problem.
	//v_tmp and w_tmp are used to record weight and value of every candidate.
	int index,v_ans = -1,w_ans;
	//these three vaiables are answers to be output.
	cin >> n >> b;
	int *w = new int[n];
	int *v = new int[n];
	for(int i = 0;i < n;++i)
		cin >> w[i];
	for(int i = 0;i < n;++i)
		cin >> v[i];
	cin >> k;
	for(int i = 0;i < k;++i){
		w_tmp = v_tmp = 0;
		cin >> tmp;
		//because indeces are sorted, the first input of every candidate can be ignored. 
		for(int j = 0;j < n;++j){
			cin >> tmp;
			w_tmp += w[j]*tmp;
			v_tmp += v[j]*tmp;
		}
		//for every input after that are ethier 1 or 0,
		//so you can calculate the sum of weight and value of each candidate
		//by simply adding the weight and value of each item mutiplies tmp.
		if(w_tmp <= b && v_tmp > v_ans){
			index = i+1;
			w_ans = w_tmp;
			v_ans = v_tmp;
		}
		//if the total weight of the candidate is smaller than the knapsack value,
		//and total value is greater than the greatest one before,
		//them record this candidate as the currently best answer.
		//v_ans is initialized as -1 so the answer can be correctly recorded even if it's 0.
	}
	cout << index << " " << w_ans << " " << v_ans << endl;
	return 0;
}
