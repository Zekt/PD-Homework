#include<iostream>
using namespace std;

/*
 * In class Person, isFriend is a function to determine whether this person 
 * has sent a friend request to the one whose id is passed.
 * And countfriend is to count the real friends this person has.
 */

class Person {
	private:
		const int id;
		unsigned int friendCount;
		int* friendList;
	public:
		Person(int id);
		~Person();
		int getId() const;
		bool isFriend(int anId);
		bool addFriend(int anId);
		bool unfriend(int anId);
		int countFriend(Person* p[]);
};

Person::Person(int id): id(id) {
	friendCount = 0;
	friendList = new int[1000];
}

Person::~Person() {
	delete[] friendList;
}

int Person::getId() const {
	return id;
}

//isFriend is a function to check if this person is in the target's friend list.
bool Person::isFriend(int anId) {
	for(int i = 0; i < friendCount; ++i)
		if(anId == friendList[i])
			return 1;
	return 0;
}

bool Person::addFriend(int anId) {
	if(id == anId || isFriend(anId))
		return 0;
	friendList[friendCount++] = anId;
	return 1;
}

//In unfriend, try to find the target to unfriend in friend list, and replace with the last one.
bool Person::unfriend(int anId) {
	if(id == anId)
		return 0;
	for(int i = 0; i < friendCount; ++i)
		if(anId == friendList[i]) {
			friendList[i] = friendList[--friendCount];
			return 1;
		}
	return 0;
}

/*
 * In countFriend, take the array containing all objects as parameter,
 * check every person that has been sent requests to, and check if it has sent a request back.
 */
int Person::countFriend(Person* p[]) {
	int total = 0;
	int t;
	for(int i = 0; i < friendCount; ++i) {
		t = friendList[i];
		if(isFriend(t) && p[t] &&	p[t]->isFriend(id))
			++total;

	}
	return total;
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
			p[a]->addFriend(b);
		} else {
			cin >> a >> b;	
			p[a]->unfriend(b);
		}
	for(int i = 1; i <= 1000; ++i) {
		if(exist[i]) {
			total[i] = p[i]->countFriend(p);
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
