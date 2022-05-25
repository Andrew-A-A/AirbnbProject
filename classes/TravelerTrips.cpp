#include "TravelerTrips.h"

TravelerTrips::TravelerTrips(string Tusername, string city, string start, string end, float mx, float mn)
{
	this->Travelerusername = Tusername;
	this->city = city;
	this->startdate = start;
	this->enddate = end;
	this->mxprice = mx;
	this->mnprice = mn;
}

TravelerTrips::TravelerTrips() {}
