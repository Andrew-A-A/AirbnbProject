#pragma once
#include <string>
#include <iostream>
#include<vector>
#include <queue>
#include "NewUser.h"
#include "HostsPlaces.h"
using namespace std;

class Host : public NewUser
{


public:
    queue<HostsPlaces> places;
    vector<HostsPlaces> confirmed_places;

    Host();
    Host(string username, string fullname, string password, string email, string nationality, char gender, int age);
	void AddPlaces(Host host, string city, string start, string end, float price);
	~Host(void);
    int countPlaces();

 /*   static queue<HostsPlaces> getPlaces() ;

    static vector<HostsPlaces> getConfirmedPlaces() ;*/
};


