#pragma once
#include<string>
#include<iostream>
using namespace std;
class TravelerTrips
{
private:
	string Travelerusername;
	string city;
	string startdate;
	string enddate;
	float mxprice, mnprice;
public:
    TravelerTrips();

    TravelerTrips(string Tusername, string city, string start, string end, float mx, float mn);

};

