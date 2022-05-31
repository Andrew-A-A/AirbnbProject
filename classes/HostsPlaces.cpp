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

    string s;
    int idx=0;
    StayRange date;
    for(int i=0;i<startdate.size();i++)
    {
        if(startdate[i]!='/' )
        {
            s+=startdate[i];
        }
        else
        {
            if(idx==0)
            {

                date.StartDay=stoi(s);

            }
            if(idx==1)
            {

                date.StartMonth=stoi(s);

            }
            if (idx!=2)
            {
                s.clear();
            }
            idx++;
            if (idx==2)
            {
                continue;
            }
        }
        if(idx==2)
        {

            date.StartYear=stoi(s);

        }
    }
    s.clear();
    idx++;
    for(int i=0;i<enddate.size();i++)
    {
        if(enddate[i]!='/')
        {
            s+=enddate[i];
        }
        else
        {
            if(idx==3)
            {
                date.EndDay=stoi(s);

            }
            else if(idx==4)
            {
                date.EndMonth=stoi(s);

            }
            if (idx!=5)
            {
                s.clear();
            }
            idx++;
            if (idx==5)
            {
                continue;
            }

        }
        if(idx==5)
        {
            date.EndYear=stoi(s);

        }
    }
    s.clear();
    return date;
}

int HostsPlaces::NumDays(StayRange stayRange)
{
    int days=0;
    if(stayRange.EndMonth-stayRange.StartMonth==0)
    {
        days+=( stayRange.EndDay-stayRange.StartDay);
        return days;
    }
    else {
        days += (30 - stayRange.StartDay) + stayRange.EndDay;
    }
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