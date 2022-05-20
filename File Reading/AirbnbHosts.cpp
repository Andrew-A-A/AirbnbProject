#include "AirbnbHosts.h"

AirbnbHosts::AirbnbHosts():NewUser()
{
	
}
AirbnbHosts::AirbnbHosts(string username, string fullname, string password, string email, string nationality, char gender, int age):NewUser(username, fullname, password, email, nationality, gender, age)
{
}
void AirbnbHosts::AddPlaces(AirbnbHosts host, string city, string start, string end, float price) 
{
	HostsPlaces place(host.username,city,start,end,price);
	places.push_back(place);
}

AirbnbHosts::~AirbnbHosts(void)
{
}
