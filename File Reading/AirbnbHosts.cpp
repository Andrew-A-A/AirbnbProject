#include "AirbnbHosts.h"

AirbnbHosts::AirbnbHosts():NewUser()
{
	
}
AirbnbHosts::AirbnbHosts(string username, string fullname, string password, string email, string nationality, char gender, int age):NewUser(username, fullname, password, email, nationality, gender, age)
{
}
