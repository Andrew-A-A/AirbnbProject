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
};
class HostsPlaces
{
private:

	string city;
	float pricepernight;
	string Hostusername;

public:
	HostsPlaces();
	HostsPlaces(string hostusername,string city, string start, string end,float price);
	~HostsPlaces(void);
};

