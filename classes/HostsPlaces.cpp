#include "HostsPlaces.h"
#include<vector>
availability::availability()
{
	startdate = "1/1/22";
	enddate = "1/1/22";
}

availability::availability(string start, string end)
{
	this->startdate = start;
	this->enddate = end;
}

const string &availability::getStartdate() const {
    return startdate;
}

const string &availability::getEnddate() const {
    return enddate;
}

StayRange availableDays;
int range = 0;
vector<bool> timeline(range,false);
HostsPlaces::HostsPlaces()
{
}

HostsPlaces::HostsPlaces(string hostusername, string city, string start, string end, float price)
{
	availability.startdate=start;
    availability.enddate=end;

}

HostsPlaces::~HostsPlaces(void)
{
}

const string &HostsPlaces::getCity() const {
    return City;
}

float HostsPlaces::getPricepernight() const {
    return pricepernight;
}

const string &HostsPlaces::getHostusername() const {
    return Hostusername;
}

HostsPlaces::HostsPlaces(string hostusername, string city, string start, string end, float price, bool isConfirmed)
{
    Hostusername=hostusername;
    City=city;
    pricepernight=price;
    IsConfirmed=isConfirmed;
    availability.startdate=start;
    availability.enddate=end;
    availableDays=DateConverting(start,end);
    range= NumDays(availableDays);

}


StayRange HostsPlaces::DateConverting(string startdate, string enddate)
{

    string s,e;
    int idx=0;
    StayRange date;
    for(int i=0;i<startdate.size();i++)
    {
        if(startdate[i]!='/' || i!=startdate.size()-1)
        {
            s+=startdate[i];
        }
        else
        {
            if(idx==0)
            {
                date.StartDay=stoi(s);
            }
            else if(idx==1)
            {
                date.StartMonth=stoi(s);
            }
            else if(idx==2)
            {
                date.StartYear=stoi(s);
            }
            idx++;
            s.clear();
        }
    }
    for(int j=0;j<enddate.size();j++)
    {
        if(enddate[j]!='/' || j==enddate.size()-1)
        {
            e+=enddate[j];
        }
        else
        {
            if(idx==3)
            {
                date.EndDay=stoi(e);
            }
            else if(idx==4)
            {
                date.EndMonth=stoi(e);
            }
            else if(idx==5)
            {
                date.EndYear=stoi(e);
            }
            idx++;
            e.clear();
        }
    }

    return date;
}

int HostsPlaces::NumDays(StayRange stayRange)
{
    int days=0;
    days+=(30-stayRange.StartDay)+stayRange.EndDay;
    if (stayRange.EndYear-stayRange.StartYear==1)
    {
        days+=(stayRange.EndMonth-stayRange.StartMonth+12-1)*30;
    }
    else
    {
        days += (abs(stayRange.EndMonth - stayRange.StartMonth - 1)) * 30;
    }

    return days;
}