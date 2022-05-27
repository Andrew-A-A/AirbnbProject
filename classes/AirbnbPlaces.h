#pragma once
#include<string>
#include<iostream>
#include"HostsPlaces.h"
#include"Host.h"
#include<vector>
using namespace std;

class AirbnbPlaces
{
	string HostsUsername;
	availability opendates;
	vector<HostsPlaces>places;
	Host host;
	AirbnbPlaces();
	AirbnbPlaces(Host host, vector<HostsPlaces> places, availability dates);
};