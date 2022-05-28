#pragma once
#include<string>
#include<iostream>
using namespace  std;

struct availability
{

	string startdate;
	string enddate;
	availability();
	availability(string start, string end);

    const string &getStartdate() const;

    const string &getEnddate() const;
};
class HostsPlaces
{
private:

    bool IsConfirmed;
	string City;
	float pricepernight;
	string Hostusername;

public:
    availability availability;
	HostsPlaces();
	HostsPlaces(string hostusername,string city, string start, string end,float price);

    HostsPlaces(string hostusername,string city, string start, string end,float price,bool isConfirmed);
	~HostsPlaces(void);

    const string &getCity() const;

    float getPricepernight() const;

    const string &getHostusername() const;

};

