#include "Host.h"
#include<vector>
#include <queue>

Host::Host(): NewUser()
{
	
}
Host::Host(string username, string fullname, string password, string email, string nationality, char gender, int age): NewUser(username, fullname, password, email, nationality, gender, age)
{
}
void Host::AddPlaces(Host host, string city, string start, string end, float price)
{
	HostsPlaces place(host.username,city,start,end,price);
	places.push(place);
}

Host::~Host(void)
{
}

/*queue<HostsPlaces> Host::getPlaces()  {
    return places;
}
vector<HostsPlaces> Host::getConfirmedPlaces() {
    return confirmed_places;
}*/

int Host::countPlaces() {
    return places.size();
}









