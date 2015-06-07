#include<iostream>
#include<fstream>
using namespace std;

const int MAX_ITEM_COUNT = 10;

class AbstractTSN
{
	protected:
		string memberID;
		char gender;
		int age;
		int itemCount;
	public:
		void setID(char* id);
		void setGender(bool g);
		void setAge(int age);
};


class FirstTSN : public AbstractTSN
{
	private:
		bool items[MAX_ITEM_COUNT];
	public:
		FirstTSN(char* id);
};

void AbstractTSN::setID(char* id) {
	memberID = id;
}

class SecondTSN : public AbstractTSN
{
	private:
		int* items;
	public:
};

int main() {
	int times, mode, sizeF = 0, sizeS = 0;
	char tmp[10];
	char c;
	string path;
	ifstream f;
	int count[5][10] = {};
	bool r[5];
	FirstTSN* first[24000];
	SecondTSN* second[24000];
	cin >> times;
	while(times--) {
		cin >> mode;
		cin >> path;
		f.open(path.c_str());
		if(mode == 1)
			first[sizeF] = new FirstTSN;
		else
			second[sizeS] = new SecondTSN;
		while(true) {
			f.getline(tmp, 10, ',');
			if(f.eof())
				break;
			first[size].
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
			for(int i = 0; i < 4; ++i)
				r[i] = 0;
			r[4] = 1;
			for(int i = 0; i < 10; ++i) {
				do {
					f >> c;
				} while(c == ',');
				if(c == '1')
					for(int j = 0; j < 5; ++j)
						if(r[j])
							++count[j][i];
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
