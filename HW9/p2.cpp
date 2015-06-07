#include<iostream>
using namespace std;

/*
 * added is a array to record who has sent a request to this person,
 * addedBy is a member function to record people who had sent a request to this person,
 * and remove is used to remove these requests.
 */
class Person {
	private:
		const int id;
		unsigned int friendCount;
		unsigned int addCount;
		Person** friendList;
		Person** added;
	public:
		Person(int id);
		~Person();
		int getId() const;
		bool isFriend(Person* aPersonPtr);
		void addFriend(Person* aPersonPtr);
		void addedBy(Person* aPersonPtr);
		bool unfriend(int anId);
		int countFriend();
		void remove();
};

Person::Person(int id): id(id) {
	friendCount = 0;
	addCount = 0;
	friendList = new Person*[1000];
	added = new Person*[1000];
}

Person::~Person() {
	delete[] friendList;
	delete[] added;
}

int Person::getId() const {
	return id;
}

bool Person::isFriend(Person* aPersonPtr) {
	for(int i = 0; i < friendCount; ++i)
		if(friendList[i] == aPersonPtr)
			return 1;
	return 0;
}

void Person::addFriend(Person* aPersonPtr) {
	if(id == aPersonPtr->getId())
		return;
	for(int i = 0; i < friendCount; ++i)
		if(friendList[i] == aPersonPtr)
			return;
	friendList[friendCount++] = aPersonPtr;
	aPersonPtr->addedBy(this);
}

void Person::addedBy(Person* aPersonPtr) {
	added[addCount++] = aPersonPtr;
}

bool Person::unfriend(int anId) {
	if(id == anId)
		return 0;
	for(int i = 0; i < friendCount; ++i)
		if(anId == friendList[i]->id) {
			friendList[i] = friendList[--friendCount];
			return 1;
		}
	return 0;
}

//countFriend cauculate the number of real friends this person has.
int Person::countFriend() {
	int total = 0;
	for(int i = 0; i < friendCount; ++i)
		if(friendList[i]->isFriend(this))
			++total;
	return total;
}

void Person::remove() {
	for(int i = 0; i < addCount; ++i)
		added[i]->unfriend(id);
}

int main() {
	char c;
	int a,b,max = 0;
	Person* p[1001];
	bool exist[1001] = {};
	int total[1001] = {};
	while(cin >> c)
		if(c == 'N') {
			cin >> a;
			p[a] = new Person(a);
			exist[a] = 1;
		} else if (c == 'A') {
			cin >> a >> b;
			p[a]->addFriend(p[b]);
		} else if (c == 'R') {
			cin >> a >> b;	
			p[a]->unfriend(b);
		} else {
			cin >> a;
			p[a]->remove();	
			delete p[a];
			exist[a] = 0;
		}
	for(int i = 1; i <= 1000; ++i) {
		if(exist[i]) {
			total[i] = p[i]->countFriend();
			if(total[i] > max)
				max = total[i];
		}
	}
	for(int i = 1; i <= 1000; ++i)
		if(exist[i] && total[i] == max)
			cout << i << " ";
	cout << max << endl;
	return 0;
}
