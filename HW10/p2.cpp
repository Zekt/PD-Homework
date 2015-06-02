#include<iostream>
using namespace std;

class RecylcingVector {
	private:
		int size;
		int* vector;
	public:
		RecylcingVector(): size(0), vector(NULL) {}
		RecylcingVector(int size);
		RecylcingVector(int size, int* m);
		RecylcingVector(const RecylcingVector& v);
		~RecylcingVector() {delete vector;}
		const RecylcingVector& operator=(const RecylcingVector& v);
		const RecylcingVector operator+(const RecylcingVector& v);
		const RecylcingVector operator-(const RecylcingVector& v);
		int& operator[](int index);
		bool operator<(const RecylcingVector& v);
		bool operator>(const RecylcingVector& v);
		bool operator==(const RecylcingVector& v);
		int getSize();
};

//constructor when only given size.
RecylcingVector::RecylcingVector(int size) {
	this->size = size;
	vector = new int[size];
	for(int i = 0; i < size; ++i)
		vector[i] = 0;
}

RecylcingVector::RecylcingVector(int size, int* m) {
	this->size = size;
	vector = new int[size];
	for(int i = 0; i < size; ++i)
		vector[i] = m[i];
}

RecylcingVector::RecylcingVector(const RecylcingVector& v) {
	size = v.size;
	vector = new int[size];
	for(int i = 0; i < size; ++i)
		vector[i] = v.vector[i];
}

const RecylcingVector& RecylcingVector::operator=(const RecylcingVector& v) {
	if(vector != NULL) {
		delete vector;
		vector = NULL;
	}
	size = v.size;
	vector = new int[size];
	for(int i = 0; i < size; ++i)
		vector[i] = v.vector[i];
	return *this;
}

//To add two vectors, take the vector with bigger size, and add the smaller one to it.
const RecylcingVector RecylcingVector::operator+(const RecylcingVector& v) {
	if(v.size == 0)
		return *this;
	if(size == 0)
		return v;
	int s = max(size, v.size);
	RecylcingVector sum(s);
	for(int i = 0; i < s; ++i)
		sum[i] = vector[i%size];
	for(int i = 0; i < s; ++i)
		sum.vector[i%size] += v.vector[i%v.size];
	return sum;
}

//Same in minus.
const RecylcingVector RecylcingVector::operator-(const RecylcingVector& v) {
	if(v.size == 0)
		return *this;
	if(size == 0)
		return v;
	int s = max(size, v.size);
	RecylcingVector sum(s);
	for(int i = 0; i < s; ++i)
		sum[i] = vector[i%size];
	for(int i = 0; i < s; ++i)
		sum.vector[i%size] -= v.vector[i%v.size];
	return sum;
}

int& RecylcingVector::operator[](int index) {
	return vector[index];
}

bool RecylcingVector::operator<(const RecylcingVector& v) {
	int s = max(size, v.size);
	for(int i = 0; i < s; ++i)
		if(vector[i%size] >= v.vector[i%v.size])
			return false;
	return true;
}

bool RecylcingVector::operator>(const RecylcingVector& v) {
	int s = max(size, v.size);
	for(int i = 0; i < s; ++i)
		if(vector[i%size] <= v.vector[i%v.size])
			return false;
	return true;
}

bool RecylcingVector::operator==(const RecylcingVector& v) {
	int s = max(size, v.size);
	for(int i = 0; i < s; ++i)
		if(vector[i%size] != v.vector[i%v.size])
			return false;
	return true;
}

int RecylcingVector::getSize() {
	return size;
}

int main() {
	char e, name, com, com1, com2;
	int n, i, now;
	int* v;
	RecylcingVector* vectors[26] = {};
	while(cin >> e) {
		if(e == 'N') {
			cin >> name >> n;
			v = new int[n];
			for(int i = 0; i < n; ++i)
				cin >> v[i];
			vectors[name-'a'] = new RecylcingVector(n,v);
			delete v;
		} else if(e == 'A') {
			cin >> name >> n;
			v = new int[n];
			for(int i = 0; i < n; ++i)
				cin >> v[i];
			delete vectors[name-'a'];
			vectors[name-'a'] = new RecylcingVector(n,v);
			delete v;
		} else if(e == 'C') {
			cin >> com;
			if(com == 'L') {
				cin >> com1 >> com2;
				cout << (*vectors[com1-'a']<*vectors[com2-'a']) << endl;
			} else if(com == 'G') {
				cin >> com1 >> com2;
				cout << (*vectors[com1-'a']>*vectors[com2-'a']) << endl;
			} else {
				cin >> com1 >> com2;
				cout << (*vectors[com1-'a']==*vectors[com2-'a']) << endl;
			}  
		} else if(e == 'I') {
			cin >> name >> i >> n;
			(*vectors[name-'a'])[i-1] = n;
		} else if(e == 'S') {
			/*
			 * find the one with the max size,
			 * and use it as the one to add and minus.
			 */
			cin >> n >> name;
			now = name-'a';
			int max = 0;
			char* p = new char[n-1];
			for(int i = 0; i < n-1; ++i) {
				cin >> p[i];
				if(vectors[p[i]-'a']->getSize() > max)
					max = vectors[p[i]-'a']->getSize();
			}
			RecylcingVector tmp(max);
			for(int i = 0; i < n-1; ++i)
				tmp = tmp+(*vectors[p[i]-'a']);
			if(vectors[now])
				delete vectors[now];
			vectors[now] = new RecylcingVector(tmp);
			delete p;
		} else if(e == 'M') {
			cin >> n >> name;
			now = name-'a';
			int max = 0;
			char* p = new char[n-1];
			for(int i = 0; i < n-1; ++i) {
				cin >> p[i];
				if(vectors[p[i]-'a']->getSize() > max)
					max = vectors[p[i]-'a']->getSize();
			}
			RecylcingVector tmp(max);
			tmp = tmp+(*vectors[p[0]-'a']);
			for(int i = 1; i < n-1; ++i)
				tmp = tmp-(*vectors[p[i]-'a']);
			if(vectors[now])
				delete vectors[now];
			vectors[now] = new RecylcingVector(tmp);
			delete p;
		} else {
			cin >> name;
			if(vectors[name-'a']) {
				int s = vectors[name-'a']->getSize();
				cout << "Size: " << s << endl;
				for(int i = 0; i < s; ++i) {
					cout << (*vectors[name-'a'])[i] << " ";
					cout << endl;
				}
			} else {
				cout << "Dosen't exist.\n";
			}
		}
	}
}
