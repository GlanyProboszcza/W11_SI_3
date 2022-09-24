#include "Algorithms.h"

int findBestRoute(std::vector<Person> friends, Person& osoba1, Person& osoba2)
{
    std::vector <bool> visited;
    for (int i = 0; i < friends.size(); i++) {
        visited.push_back(0);
    }
    return osoba1.findBestRoute(osoba2, visited);
}

void makeFriends(Person& p1, Person& p2)
{
    p1.addFriend(p2);
    p2.addFriend(p1);

}
