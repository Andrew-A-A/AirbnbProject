#pragma once
#include <string>
#include <iostream>
#include<vector>
#include "NewUser.h"
#include "HostsPlaces.h"
using namespace std;

class AirbnbHosts :public NewUser
{
private:
	vector<HostsPlaces> places;
public:
	AirbnbHosts();
	AirbnbHosts(string username, string fullname, string password, string email, string nationality, char gender, int age);
	void AddPlaces(AirbnbHosts host, string city, string start, string end, float price);
	~AirbnbHosts(void);
};

