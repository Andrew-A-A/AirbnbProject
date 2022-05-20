#include "Travelers.h"

Travelers::Travelers():NewUser()
{
}

Travelers::Travelers(string username, string fullname, string password, string email, string nationality, char gender, int age):NewUser(username, fullname, password, email, nationality, gender, age)
{
}

void Travelers::InsertTrip( string city, string start, string end, float mx, float mn, Travelers traveler)
{
	TravelerTrips trip(traveler.username, city, start, end, mx, mn);
	trips.push(trip);
}
