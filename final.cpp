#include<iostream>
#include<fstream>
#include<cstdlib>
#include<vector>
#include<cmath>
#include<sstream>
#define MIN -2000000000
#define FILENUM 1
using namespace std;
 
vector<int> setM[500];
vector<int> setF[500];
vector<int> setA[500];
 
struct ans {
    double con, sup;
    int id;
    ans(double c, double s, int i): con(c), sup(s), id(i) {}
    void init() {
        con = MIN;
        sup = MIN;
        id = 0;
    }
};
 
inline bool cmp(ans &a, ans &b) {
    return abs(a.con-b.con) > 0.0000005 ? a.con > b.con : (abs(a.sup-b.sup) > 0.0000005 ? a.sup > b.sup : a.id < b.id);
}
 
ans maxx(MIN, 0, 0);
vector<int>* target;
int* targetTotal;
int supMin, transCount = 0, transCountF = 0, transCountM = 0;
 
inline void join(vector<int> &answer, vector<int> &a, vector<int> &b) {
    int it_a = 0, it_b = 0;
    while(it_a < a.size() && it_b < b.size())
        if(a[it_a] == b[it_b]) {
            answer.push_back(a[it_a]);
            ++it_a;
            ++it_b;
        } else if(a[it_a] < b[it_b])
            ++it_a;
        else
            ++it_b;
}

int total = 0;
 
void travel(vector<int> &items, int pos, vector<int> &inter, bool exclude[]) {
    for(int next = pos; next < items.size(); ++next) {
		for(int i = 0; i < pos; ++i)
			cout << " ";
		cout << items[next] << " " << total++ << endl;
        vector<int> interNew;
        if(pos == 0)
            interNew = target[items[next]];
		else
			join(interNew, inter, target[items[next]]);
		//if(interNew.empty()) {
		//   continue;
		//}
		double sup = ((double)interNew.size()*100)/(*targetTotal);
		if(supMin-sup > 0.0000005)
			continue;
		for(int item = 0; item < 5; ++item)
			if(!exclude[item]) {
				vector<int> interItem;
				join(interItem, interNew, target[item]);
				/*
				   cout << "interNew: \n";
				   for(int i = 0; i < interNew.size(); ++i)
				   cout << interNew[i] << " ";
				   cout << endl;
				   cout << " item number (1-based)"  << item + 1 <<endl; 
				   cout << " inter trans number " << interItem.size() << endl;
				   */
				sup = ((double)interItem.size()*100)/(*targetTotal);
				double con = ((double)interItem.size()*100)/interNew.size();
				if(supMin-sup > 0.0000005 || interNew.empty())
					continue;
				ans tmp(con, sup, item);
				if(cmp(tmp, maxx))
					maxx = tmp;
			}
		travel(items, next+1, interNew, exclude);
	}
}

int main() {
	string filePath, line;
	int lastTrans = -1;
	for(int fileCount = 0; fileCount < FILENUM; ++fileCount) {
		getline(cin, filePath);
		ifstream inFile(filePath);
		while(getline(inFile, line)) {
			vector<string> infor;
			stringstream ss(line);
			while(getline(ss, line, ','))
				infor.push_back(line);
			vector<int> items;
			for(int i = 5; i < infor.size(); ++i)
				items.push_back(atoi(infor[i].c_str()));
			int transID = atoi(infor[0].c_str());
			if(transID != lastTrans) {
				if(infor[3][0] == 'M')
					++transCountM;
				else if (infor[3][0] == 'F')
					++transCountF;
				++transCount;
			}
			lastTrans = transID;
			bool sex = 1;
			if(infor[3][0] == 'M') {
				target = setM;
			} else if(infor[3][0] == 'F') {
				target = setF;
			} else
				sex = 0;
			//cout << "Size: " << infor.size() << endl;
			if(items.size() == 500 && (items[2] == 0 || items[2] == 1) && (items[3] == 0 || items[3] == 1)) {
				//cout << "transID: " << transID << endl;
				for(int i = 0; i < items.size(); ++i)
					if(items[i] == 1) {
						if(sex) {
							target[i].push_back(transID);
						}
						setA[i].push_back(transID);
					}
			} else {
				for(int i = 0; i < items.size(); ++i) {
					if(sex) {
						target[items[i]-1].push_back(transID);
					}
					setA[items[i]-1].push_back(transID);
				}
			}
		}
		inFile.close();
	}
	/*  print out the sets.
		for(int it = 0; it < 5; ++it) {
		for(int i = 0; i < setM[it].size(); ++i)
		cout << " " << setM[it][i];
		cout << endl;
		}
		for(int it = 0; it < 5; ++it) {
		for(int i = 0; i < setF[it].size(); ++i)
		cout << " " << setF[it][i];
		cout << endl;
		}
		for(int it = 0; it < 5; ++it) {
		for(int i = 0; i < setA[it].size(); ++i)
		cout << " " << setA[it][i];
		cout << endl;
		}
		cout << "transCount: " << transCount << endl;
		*/
	getline(cin, filePath);
	getline(cin, filePath);
	ifstream inFile(filePath);
	while(getline(inFile, line, ';')) {
		stringstream ss(line);
		vector<string> infor;
		while(getline(ss, line, ','))
			infor.push_back(line);
		if(infor[2][0] == 'M') {
			target = setM;
			targetTotal = &transCountM;
		} else if(infor[2][0] == 'F') {
			target = setF;
			targetTotal = &transCountF;
		} else {
			target = setA;
			targetTotal = &transCount;
		}
		vector<int> items(infor.size()-4);
		bool exclude[500] = {0};
		for(int i = 4; i < infor.size(); ++i) {
			items[i-4] = atoi(infor[i].c_str())-1;
			exclude[items[i-4]] = 1;
		}
		getline(inFile, line);
		supMin = atoi(line.c_str());
		maxx.init();
		travel(items, 0, items, exclude);
		if(maxx.con == MIN)
			cout << "-1\n";
		else
			cout << maxx.id+1 << " " << round(maxx.sup) << " " << round(maxx.con) << endl;
	}
	return 0;
}
