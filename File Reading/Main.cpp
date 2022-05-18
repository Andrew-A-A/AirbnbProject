#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<vector>
#include<unordered_map>

#include"AirbnbHosts.h"
#include"AirbnbPlaces.h"
#include"HostsPlaces.h"
#include"NewUser.h"
#include"Travelers.h"
#include"TravelerTrips.h"

using namespace std;
vector<string> read;
vector<string> write;
string filepaths[5] =
{
    "D:\\University\\2nd Year\\2nd Year 2nd Term\\Data Structures\\Project\\File Reading\\File Reading\\Traveler.txt",
    "D:\\University\\2nd Year\\2nd Year 2nd Term\\Data Structures\\Project\\File Reading\\File Reading\\Hosts.txt",
    "D:\\University\\2nd Year\\2nd Year 2nd Term\\Data Structures\\Project\\File Reading\\File Reading\\Trips.txt",
    "D:\\University\\2nd Year\\2nd Year 2nd Term\\Data Structures\\Project\\File Reading\\File Reading\\Places.txt"
};

void stringop(string curr, int num)
{
    string s;
    if (num == 0)
    {
        return;
    }
    else
    {
        for (int i = 0; i <= curr.size(); i++)
        {
            if (curr[i] == '%' ||i==curr.size())
            {
                read.push_back(s);
                s.clear();
                continue;
            }
            else
                s += curr[i];
        }
    }
}
void readfile(string path,ifstream& file) 
{
    string line;
    file.open(path, ios::in);
    if (file.is_open())
    {
        int countlines = 0;
        while (!file.eof())
        {

            getline(file, line);
            stringop(line, countlines);
            countlines++;
        }

    }
    else
    {
        cout << "Error! did not open file";
    }
    file.close();
}

void writefile(string path, ofstream& file)
{
    string line;
    file.open(path, ios::app);
    if (file.is_open())
    {
        for (int i = 0; i < write.size(); i++) 
        {
            if (i == 0) 
            {
                continue;
            }
            else
            {
                line += write[i];
                line += "%";
                if (i != write.size() - 1)
                {
                    line += " ";
                }
            }
        }
        file << line << endl;
    }
    else 
    {
        cout << "Error! Could not open file" << endl;
    }
}
struct hostdata
{
    string fullname;
    string password;
    string email;
    string nationality;
    char gender;
    int age;
};

struct travelerdata 
{
    string fullname;
    string password;
    string email;
    string nationality;
    char gender;
    int age;
};
unordered_map<string, hostdata>hostmap;
unordered_map<string, travelerdata>travelermap;

void inserttraveler(Travelers& traveler) 
{
    travelerdata data;
    data.fullname = traveler.fullname;
    data.age = traveler.age;
    data.email = traveler.email;
    data.gender = traveler.gender;
    data.nationality = traveler.nationality;
    data.password = traveler.password;
    travelermap[traveler.username] = data;
}
void inserthost(AirbnbHosts& host)
{
    hostdata data;
    data.fullname = host.fullname;
    data.age = host.age;
    data.email = host.email;
    data.gender = host.gender;
    data.nationality = host.nationality;
    data.password = host.password;
    hostmap[host.username] = data;
}
int main()
{
    ofstream enterdata;
    int sorl, torh;
    bool signup = false, login = false, traveler = false, host = false, place = false, trip = false;
    cout << "Do You want to signup or login?" << endl;
    cout << "To signup press 1 to login press 2" << endl;
    cin >> sorl;
    if (sorl == 1) 
    {
        signup = true;
        login = false;
        cout << "Do you want to signup as a traveler or as a host?" << endl;
        cout << "To signup as a traveler press 1 to signup as a host press 2" << endl;
        cin >> torh;
        if (torh == 1) 
        {
            host = false;
            traveler = true;
            write.push_back("Traveler");
            string usrname;
            string flname;
            string pswrd;
            string mail;
            string nationalty;
            char gndr;
            int year;
            cout << "Enter your username: " << endl;
            cin >> usrname;
            write.push_back(usrname);
            cout << "Enter your fullname: " << endl;
            cin.ignore();
            getline(cin, flname);
            write.push_back(flname);
            cout << "Enter your email: " << endl;
            cin >> mail;
            write.push_back(mail);
            cout << "Enter your password: " << endl;
            cin >> pswrd;
            write.push_back(pswrd);
            cout << "Enter your nationality: " << endl;
            cin >> nationalty;
            write.push_back(nationalty);
            cout << "Enter your gender (no offense M|F): " << endl;
            cin >> gndr;
            string gender;
            gender += gndr;
            write.push_back(gender);
            cout << "Enter your age: " << endl;
            cin >> year;
            string age;
            age = to_string(year);
            write.push_back(age);
            Travelers traveler(usrname, flname, pswrd, mail, nationalty, gndr, year);
            inserttraveler(traveler);
            string currstring = filepaths[0];
            writefile(currstring.c_str(), enterdata);

        }
        else if (torh == 2) 
        {
            host = true;
            traveler = false;
            write.push_back("Host");
            string usrname;
            string flname;
            string pswrd;
            string mail;
            string nationalty;
            char gndr;
            int year;
            cout << "Enter your username: " << endl;
            cin >> usrname;
            write.push_back(usrname);
            cout << "Enter your fullname: " << endl;
            cin.ignore();
            getline(cin,flname);
            write.push_back(flname);
            cout << "Enter your email: " << endl;
            cin >> mail;
            write.push_back(mail);
            cout << "Enter your password: " << endl;
            cin >> pswrd;
            write.push_back(pswrd);
            cout << "Enter your nationality: " << endl;
            cin >> nationalty;
            write.push_back(nationalty);
            cout << "Enter your gender (no offense M|F): " << endl;
            cin >> gndr;
            string gender;
            gender += gndr;
            write.push_back(gender);
            cout << "Enter your age: " << endl;
            cin >> year;
            string age;
            age = to_string(year);
            write.push_back(age);
            AirbnbHosts host(usrname, flname, pswrd, mail, nationalty, gndr, year);
            inserthost(host);
            writefile(filepaths[1], enterdata);
        }
    }
    else if (sorl == 2) 
    {
        login = true;
        signup = false;
    }

}