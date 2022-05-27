#include "Host.h"

Host::Host(): NewUser()
{
	
}
Host::Host(string username, string fullname, string password, string email, string nationality, char gender, int age): NewUser(username, fullname, password, email, nationality, gender, age)
{
}
void Host::AddPlaces(Host host, string city, string start, string end, float price)
{
	HostsPlaces place(host.username,city,start,end,price);
	places.push_back(place);
}

Host::~Host(void)
{
}
