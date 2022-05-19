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

public:
	HostsPlaces();
	HostsPlaces(string city, string start, string end,float price);
	~HostsPlaces(void);
};

