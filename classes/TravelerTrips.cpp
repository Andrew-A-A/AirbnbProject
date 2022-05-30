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






const string &TravelerTrips::getTravelerusername() const {
    return Travelerusername;
}

const string &TravelerTrips::getCity() const {
    return city;
}

const string &TravelerTrips::getStartdate() const {
    return startdate;
}

const string &TravelerTrips::getEnddate() const {
    return enddate;
}

float TravelerTrips::getMxprice() const {
    return mxprice;
}

float TravelerTrips::getMnprice() const {
    return mnprice;
}
