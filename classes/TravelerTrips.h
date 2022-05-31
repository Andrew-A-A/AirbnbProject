#pragma once
#include<string>
#include<iostream>
using namespace std;
struct StayRange{
    int StartDay=0;
    int StartMonth=0;
    int StartYear=0;
    int EndDay=0;
    int EndMonth=0;
    int EndYear=0;
};
class TravelerTrips
{
private:
	string Travelerusername;
	string city;
	string startdate;
	string enddate;
//    int StartDay;
//    int StartMonth;
//    int StartYear;
//    int EndDay;
//    int EndMonth;
//    int EndYear;
	float mxprice, mnprice;
public:
    const string &getTravelerusername() const;

    const string &getCity() const;

    const string &getStartdate() const;

    const string &getEnddate() const;

    float getMxprice() const;

    float getMnprice() const;

public:

    StayRange stayRange;
    TravelerTrips();

    TravelerTrips(string Tusername, string city, string startdate, string enddate
                  , float mx, float mn);
    StayRange DateConverting( string startdate,string enddate);
    int NumDays(StayRange stayRange);
};

