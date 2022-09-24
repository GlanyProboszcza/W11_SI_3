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
	int length = 10;

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
