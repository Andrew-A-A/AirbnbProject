#pragma once
#include<string>
#include<iostream>
#include"HostsPlaces.h"
#include"AirbnbHosts.h"
#include<vector>
using namespace std;

class AirbnbPlaces
{
	string HostsUsername;
	availability opendates;
	vector<HostsPlaces>places;
	AirbnbHosts host;
	AirbnbPlaces();
	AirbnbPlaces(AirbnbHosts host, vector<HostsPlaces> places, availability dates);
};