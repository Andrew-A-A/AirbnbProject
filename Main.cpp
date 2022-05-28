#include<iostream>
#include<fstream>
#include<string>
#include <cstring>
#include<sstream>
#include<vector>
#include<unordered_map>
#include <ctime>
//including all the classes created
#include"classes/Host.h"
#include"classes/AirbnbPlaces.h"
#include"classes/HostsPlaces.h"
#include"classes/NewUser.h"
#include"classes/Travelers.h"
#include"classes/TravelerTrips.h"
#include "classes/Admin.h"
using namespace std;

vector<string> read;//vector to write into the data you read from the file
vector<string> write;//vector to write into the data you need to write in your file

string filePaths[5] =
{
    "..\\Data\\Traveler.txt",
    "..\\Data\\Hosts.txt",
    "..\\Data\\Trips.txt",
    "..\\Data\\Places.txt",
    "..\\Data\\Admins.txt"
};
//These are the file paths to the text files 

//struct hostData
//{
//    string fullname;
//    string password;
//    string email;
//    string nationality;
//    char gender;
//    int age;
//};
//struct travelerData
//{
//    string fullname;
//    string password;
//    string email;
//    string nationality;
//    char gender;
//    int age;
//};
struct NoUserNameData
{
    string fullname;
    string password;
    string email;
    string nationality;
    char gender{};
    int age{};
};


unordered_map<string, NoUserNameData>hostMap;
unordered_map<string, NoUserNameData>travelerMap;
unordered_map<string, Admin>adminMap;
/* created the struct so that to pass the map objects of structured the key will be the username
the value will be the struct which contains the rest of the data in the object */

// User-defined functions
void stringop(string curr, int num);
void InsertTraveler(Travelers& traveler);
void InsertHost(Host& host);
Travelers ReadTraveler();
Host ReadHosts();
Admin ReadAdmin();
int countLine(string path, ifstream& file);
void readfile(string path, ifstream& file, int y);
void writefile(string path, ofstream& file);
void Signup(int torh);
int main() {
    ofstream enterData;
    ifstream readData;
    int y = countLine(filePaths[0], readData);
    readfile((filePaths[0]), readData, y);
    int x = countLine(filePaths[1], readData);
    readfile((filePaths[1]), readData, x);
    int z = countLine(filePaths[4], readData);
    readfile((filePaths[4]), readData, z);
    //Fill up the map from the text files
    int sorl, torh;//sign up or login , traveler or host
    bool signup = false, login = false, traveler = false, host = false, place = false, trip = false;
    cout << "==========================[Welcome to Simplified Airbnb]==========================" << endl;
    cout << "\t\t\t Do You want to signup or login ?" << endl;
    cout << "To signup press 1 \nTo login press 2" << endl;
    cin >> sorl;
    if (sorl == 1) {
        Signup(torh);
    } else if (sorl == 2) {
        login = true;
        signup = false;
        cout << "Do you want to login as a traveler or as a host or Admin?" << endl;
        cout << "To Login as a traveler press 1. \nTo Login as a host press 2.\nTo Login as a Admin press 3. \n"
             << endl;
        cin >> torh;
        if (torh == 1) {

            cout << "Please enter your username: " << endl;
            string usrname;
            cin >> usrname;
            if (!travelerMap[usrname].password.empty()) {
                jumpA:
                cout << "Enter your password: " << endl;
                string pswrd;
                cin >> pswrd;
                if (travelerMap[usrname].password == pswrd) {
                    cout << "Hello " << travelerMap[usrname].fullname << " :) Would you like to book a new trip? "
                         << endl;
                    cout << "To book a new trip press ";
                } else {
                    cout << "Incorrect password please enter the correct password " << endl;
                    goto jumpA;
                }
            } else {
                cout << "Please sign up first to be able to book a trip :( " << endl;
            }

        }
        if (torh == 2) {

            cout << "Please enter your username: " << endl;
            string usrname;
            cin >> usrname;
            if (!hostMap[usrname].password.empty()) {
                jumpB:
                cout << "Enter your password: " << endl;
                string pswrd;
                cin >> pswrd;
                if (hostMap[usrname].password == pswrd) {
                    cout << "Hello " << hostMap[usrname].fullname << " :) Would you like to add new place? " << endl;
                    cout << "To add a place press ";
                } else {
                    cout << "Incorrect password please enter the correct password " << endl;
                    goto jumpB;
                }
            } else {
                cout << "Please sign up first to be able to add place :( " << endl;
            }

        }
        if (torh == 3) {

            cout << "Please enter your username: " << endl;
            string usrname;
            cin >> usrname;
            if (!adminMap[usrname].getUsername().empty()) {
                jumpC:
                cout << "Enter your password: " << endl;
                string pswrd;
                cin >> pswrd;
                if (adminMap[usrname].getPassword() == pswrd) {
                    cout << "Hello " << adminMap[usrname].getFullname() << " :) " << endl;
                    cout << "To edit data press : 1\nTo View Data press : 2\n ";
                } else {
                    cout << "Incorrect password please enter the correct password " << endl;
                    goto jumpC;
                }
            } else {
                cout << "There is no admin with this user name " << endl;
            }

        }

    }
}
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
            if (curr[i] == '%' || i == curr.size())
            {
                read.push_back(s);
                s.clear();
                continue;
            }
            else
                s += curr[i];
        }
        return;
    }
}

/* Gets the line from file and divides the line into the fields that the object needs*/

void InsertTraveler(Travelers& traveler)
{
    NoUserNameData data;
    data.fullname = traveler.fullname;
    data.age = traveler.age;
    data.email = traveler.email;
    data.gender = traveler.gender;
    data.nationality = traveler.nationality;
    data.password = traveler.password;
    travelerMap[traveler.username] = data;
}
void InsertHost(Host& host)
{
    NoUserNameData data;
    data.fullname = host.fullname;
    data.age = host.age;
    data.email = host.email;
    data.gender = host.gender;
    data.nationality = host.nationality;
    data.password = host.password;
    hostMap[host.username] = data;
}
/*both insert functions create the struct objects and pushes them to the map*/
Travelers ReadTraveler()
{
    int x = stoi(read[6]);
    Travelers traveler(read[0], read[1], read[3], read[2], read[4], read[5][0], x);
    /* traveler.username = read[1];
     traveler.fullname = read[2];
     traveler.email = read[3];
     traveler.password = read[4];
     traveler.nationality = read[5];
     traveler.gender = read[6][0];
     traveler.age = stoi(read[7]);*/
    return traveler;
}
Admin ReadAdmin()
{
    int x = stoi(read[6]);
    Admin admin(read[0], read[1], read[3], read[2], read[4], read[5][0], x);
    /* traveler.username = read[1];
     traveler.fullname = read[2];
     traveler.email = read[3];
     traveler.password = read[4];
     traveler.nationality = read[5];
     traveler.gender = read[6][0];
     traveler.age = stoi(read[7]);*/
    return admin;
}
Host ReadHosts()
{
    Host host(read[0], read[1], read[3], read[2], read[4], read[5][0], stoi(read[6]));
    /* host.username = read[1];
     host.fullname = read[2];
     host.email = read[3];
     host.password = read[4];
     host.nationality = read[5];
     host.gender = read[6][0];
     host.age = stoi(read[7]);*/
    return host;
}
/*both functions take the data read from the file and uses it to create the objects that are to be
passed to the insert functions*/
int countLine(string path, ifstream& file)
{
    int x = 0;
    string line;
    file.open(path, ios::in);
    if (file.is_open())
    {
        while (!file.eof())
        {
            getline(file, line);
            x++;
        }
    }
    else
    {
        cout << "Error! did not open file";
    }
    file.close();
    return x;
}
/*countLine gets the number of lines inside the text file*/
void readfile(string path, ifstream& file, int y)
{
    string line;
    file.open(path, ios::in);
    if (file.is_open())
    {
        int countlines = 0;
        while (!file.eof())
        {
            if (!(countlines == y - 1) && countlines != 0)
            {
                read.clear();
            }
            getline(file, line);
            stringop(line, countlines);
            if (path == filePaths[0] && countlines > 0)
            {
                Travelers trav = ReadTraveler();
                InsertTraveler(trav);
            }
            else if (path == filePaths[1] && countlines > 0)
            {
                Host hos = ReadHosts();
                InsertHost(hos);
            }
            else if (path == filePaths[4] && countlines > 0)
            {
              Admin admin=ReadAdmin();
              adminMap[admin.getUsername()]=admin;
            }
            countlines++;
        }

    }
    else
    {
        cout << "Error! did not open file";
    }

    file.close();
}
/*readfile reads from the file a line that is to be passed to be operated on*/
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
    file.close();
}
/*writefile writes in the file*/
void Signup(int torh){
    ofstream enterData;
    cout << "Do you want to signup as a traveler or as a host?" << endl;
    cout << "To signup as a traveler press 1 \nTo signup as a host press 2" << endl;
    cin >> torh;
    if (torh == 1) {
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
        InsertTraveler(traveler);
        string currstring = filePaths[0];
        writefile(currstring.c_str(), enterData);

    } else if (torh == 2) {
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
        Host host(usrname, flname, pswrd, mail, nationalty, gndr, year);
        InsertHost(host);
        writefile(filePaths[1], enterData);
    }
}
