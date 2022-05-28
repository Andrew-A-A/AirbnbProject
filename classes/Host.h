#pragma once
#include <string>
#include <iostream>
#include<vector>
#include "NewUser.h"
#include "HostsPlaces.h"
using namespace std;

class Host : public NewUser
{
private:
//	vector<HostsPlaces> places;
public:
    vector<HostsPlaces> places;
	Host();
	Host(string username, string fullname, string password, string email, string nationality, char gender, int age);
	void AddPlaces(Host host, string city, string start, string end, float price);
	~Host(void);
    int countPlaces();
};

