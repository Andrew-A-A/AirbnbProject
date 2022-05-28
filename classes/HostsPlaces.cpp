#include "HostsPlaces.h"

availability::availability()
{
	startdate = "1/1/22";
	enddate = "1/1/22";
}

availability::availability(string start, string end)
{
	this->startdate = start;
	this->enddate = end;
}

const string &availability::getStartdate() const {
    return startdate;
}

const string &availability::getEnddate() const {
    return enddate;
}

HostsPlaces::HostsPlaces()
{
}

HostsPlaces::HostsPlaces(string hostusername, string city, string start, string end, float price)
{
	availability.startdate=start;
    availability.enddate=end;

}

HostsPlaces::~HostsPlaces(void)
{
}

const string &HostsPlaces::getCity() const {
    return City;
}

float HostsPlaces::getPricepernight() const {
    return pricepernight;
}

const string &HostsPlaces::getHostusername() const {
    return Hostusername;
}

HostsPlaces::HostsPlaces(string hostusername, string city, string start, string end, float price, bool isConfirmed) {
Hostusername=hostusername;
City=city;
pricepernight=price;
IsConfirmed=isConfirmed;
availability.startdate=start;
availability.enddate=end;
}
