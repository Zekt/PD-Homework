#include<iostream>
#include<fstream>
using namespace std;

int main() {
	int times;
	char tmp[10];
	//tmp is used to record the stripped strings.
	string path;
	char c;
	ifstream f;
	int count[5][10] = {};
	/* 
	 * In count, the first index represents the type of customer,
	 * from 0 to 4 they are male, female, member, non-member,
	 * and all customers. Each one has a array records the number of
	 * each item they bought.
	 */
	bool r[5];
	/* 
	 * r is used to record if a transaction record
	 * belongs to that type of customer.
	 */
	cin >> times;
	while(times--) {
		cin >> path;
		f.open(path.c_str());
		while(true) {
			for(int i = 0; i < 4; ++i)
				r[i] = 0;
			r[4] = 1;
			//Initialize r.
			f.getline(tmp, 10, ',');
			if(f.eof())
				break;
			//break if EOF is encountered.
			f.getline(tmp, 10, ',');
			if(tmp[0] != '\0')
				r[2] = 1;
			else
				r[3] = 1;
			f.getline(tmp, 10, ',');
			if(tmp[0] == 'M')
				r[0] = 1;
			else if(tmp[0] == 'F')
				r[1] = 1;
			f.getline(tmp, 10, ',');
			for(int i = 0; i < 10; ++i) {
				do {
					f >> c;
				} while(c == ',');
				//Read char by char to make sure the right one is read.
				if(c == '1')
					for(int j = 0; j < 5; ++j)
						if(r[j])
							++count[j][i];
				//Only count the types of customers this record belongs to.
			}
		}
		f.clear();
		f.close();
	}
	for(int i = 0; i < 5; ++i) {
		int max = 0;
		bool first = 0;
		for(int j = 0; j < 10; ++j)
			if(count[i][j] > max)
				max = count[i][j];
		for(int j = 0; j < 10; ++j)
			if(count[i][j] == max) {
				if(first == 0)
					first = 1;
				else
					cout << " ";
				cout << j+1;
			}
		cout << endl;
	}
}
