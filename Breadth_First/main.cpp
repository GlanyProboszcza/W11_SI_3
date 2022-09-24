#include "Library.h"
#include "Person.h"
#include "Algorithms.h"

int main()
{
	int id = 0;
	Person osoba1("zaneta","kowal",id++);
	Person osoba2("zaneta2", "kowal2", id++);
	Person osoba3("zaneta3", "kowal3", id++);
	Person osoba4("zaneta4", "kowal4", id++);

	makeFriends(osoba1, osoba2);
	makeFriends(osoba2, osoba4);
	makeFriends(osoba2, osoba3);
	makeFriends(osoba4, osoba3);

	std::vector <Person> society;
	society.push_back(osoba1);
	society.push_back(osoba2);
	society.push_back(osoba3);
	society.push_back(osoba4);
	
	std::cout <<"Distance: "<< findBestRoute(society, osoba1, osoba4);

}