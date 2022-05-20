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

HostsPlaces::HostsPlaces()
{
	availability();
}

HostsPlaces::HostsPlaces(string hostusername, string city, string start, string end, float price)
{
	availability(start, end);

}

HostsPlaces::~HostsPlaces(void)
{
}
