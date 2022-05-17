#include "HostsPlaces.h"

availability::availability()
{
}

availability::availability(string start, string end)
{
}

HostsPlaces::HostsPlaces()
{
	availability();
}

HostsPlaces::HostsPlaces(string city, string start, string end, float price)
{
	availability(start, end);

}
