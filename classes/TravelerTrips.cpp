#include "TravelerTrips.h"

TravelerTrips::TravelerTrips(string Tusername, string city, string start, string end, float mx, float mn)
{
	this->Travelerusername = Tusername;
	this->city = city;
	this->startdate = start;
	this->enddate = end;
	this->mxprice = mx;
	this->mnprice = mn;
}
TravelerTrips::TravelerTrips() {}

StayRange TravelerTrips::DateConverting(string startdate, string enddate)
{

    string s;
    int idx=0;
    StayRange date;
    for(int i=0;i<startdate.size();i++)
    {
        if(startdate[i]!='/')
        {
            s+=startdate[i];
        }
        else
        {
            if(idx==0)
            {
                date.StartDay=stoi(s);
                cout<<date.StartDay;
            }
            else if(idx==1)
            {
                date.StartMonth=stoi(s);
                cout<<date.StartMonth;
            }
            else if(idx==2)
            {
                date.StartYear=stoi(s);
                cout<<date.StartYear;
            }
            idx++;
            s.clear();
        }
    }
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
                cout<<date.EndDay;
            }
            else if(idx==4)
            {
                date.EndMonth=stoi(s);
                cout<<date.EndMonth;
            }
            else if(idx==5)
            {
                date.EndYear=stoi(s);
                cout<<date.EndYear;
            }
            idx++;
            s.clear();
        }
    }

    return date;
}

int TravelerTrips::NumDays(StayRange stayRange)
{
    int days=0;
    days+=(30-stayRange.StartDay)+stayRange.EndDay;
    if(stayRange.EndMonth-stayRange.StartMonth>1)
    {
        days+=(stayRange.EndMonth-stayRange.StartMonth)*30;
    }
    if(stayRange.EndYear-stayRange.StartYear>=1)
    {
        days+=(stayRange.EndYear-stayRange.StartYear)*365;
    }
    return days;
}

const string &TravelerTrips::getTravelerusername() const {
    return Travelerusername;
}

const string &TravelerTrips::getCity() const {
    return city;
}

const string &TravelerTrips::getStartdate() const {
    return startdate;
}

const string &TravelerTrips::getEnddate() const {
    return enddate;
}

float TravelerTrips::getMxprice() const {
    return mxprice;
}

float TravelerTrips::getMnprice() const {
    return mnprice;
}







