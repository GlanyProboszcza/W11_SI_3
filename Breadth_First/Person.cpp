#include "Person.h"

Person::Person(std::string n, std::string s, int i)
{
	this->name = n;
	this->surname = s;
	this->id = i;
}

void Person::addFriend(Person& f)
{
	friends.push_back(&f);
}

int Person::findBestRoute(Person& f, std::vector<bool> path)
{
	path[id] = 1;
	int length = 99999999999;

	if (f.getId() == this->id) {
		return 0;
	}
	else
		for (auto a : friends) {
			if (path[a->getId()] != 1){ 
				int temp = a->findBestRoute(f, path);
				if (temp < length)
					length = temp;
			}
		}
	return length+1;
}

int Person::getId()
{
	return this->id;
}

std::vector<Person> Person::findFrends(std::vector <Person> listOfFriends, int distance)
{
	if (distance == 0) {
		return listOfFriends;
	}

	for (auto a : friends) {
		bool jest = 0;
		for (auto b : listOfFriends) {
			if (a->getId() == b.getId()) {
				jest = 1;
				break;
			}
		}
		if (jest) {
			continue;
		}
		else {
			listOfFriends.push_back(*a);
			listOfFriends = a->findFrends(listOfFriends, distance - 1);
		}
	}
	
	return listOfFriends;
}
