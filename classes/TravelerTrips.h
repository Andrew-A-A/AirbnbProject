#pragma once
#include<string>
#include<iostream>
using namespace std;
struct StayRange{
    int StartDay;
    int StartMonth;
    int StartYear;
    int EndDay;
    int EndMonth;
    int EndYear;
};
class TravelerTrips
{
private:
	string Travelerusername;
	string city;
	string startdate;
	string enddate;
	float mxprice, mnprice;
public:
    StayRange stayRange;
    TravelerTrips();

    TravelerTrips(string Tusername, string city, string start, string end, float mx, float mn);

};

