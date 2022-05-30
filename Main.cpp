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

vector<string> read;        //vector to write into the data you read from the file
vector<string> write;       //vector to write into the data you need to write in your file


//These are the file paths to the text files
string filePaths[5] =
{
    "..\\Data\\Traveler.txt",
    "..\\Data\\Hosts.txt",
    "..\\Data\\Trips.txt",
    "..\\Data\\Places.txt",
    "..\\Data\\Admins.txt"
};

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
//struct NoUserNameData
//{
//    string fullname;
//    string password;
//    string email;
//    string nationality;
//    char gender{};
//    int age{};
//    queue<HostsPlaces> places;
//};

/* created the struct so that to pass the map objects of structured the key will be the username
the value will be the struct which contains the rest of the data in the object */
unordered_map<string, Host>hostMap;
unordered_map<string, Travelers>travelerMap;
unordered_map<string, Admin>adminMap;


// User-defined functions' signature
void stringop(string curr, int num);
void InsertTraveler(Travelers& traveler);
void InsertHost(Host& host);
Travelers ReadTraveler();
Host ReadHosts();
Admin  ReadAdmin();
HostsPlaces ReadPlaces();
TravelerTrips Readtrips();
int countLine(string path, ifstream& file);
void readfile(string path, ifstream& file, int y);
void writefile(string path, ofstream& file);
void Signup(int torh);
Travelers StructToTraveler(string UserName,Travelers Struct);
Host StructToHost(string UserName,Host Struct);
void Login(int torh);


int main() {
    //Created stream to read data from file
    ifstream readData;
    //Reading data from files and filling the maps
    int tLines = countLine(filePaths[0], readData);
    readfile((filePaths[0]), readData, tLines);
    int hLines = countLine(filePaths[1], readData);
    readfile((filePaths[1]), readData, hLines);
    int aLines = countLine(filePaths[4], readData);
    readfile((filePaths[4]), readData, aLines);
    int pLines = countLine(filePaths[3], readData);
    readfile((filePaths[3]), readData, pLines);
    int triplines= countLine( filePaths[2],readData);
    readfile(filePaths[2],readData, triplines);


    int sorl, torh;             //sign up or login , traveler or host

    cout << "==========================[Welcome to Simplified Airbnb]==========================" << endl;
    cout << "\t\t\t Do You want to signup or login ?" << endl;
    cout << "To signup press 1 \nTo login press 2" << endl;
    cin >> sorl;
    if (sorl == 1) {
        Signup(torh);                   //signup and get data from user (Both travelers and hosts)
    } else if (sorl == 2) {

        cout << "Do you want to login as a traveler or as a host or Admin?" << endl;
        cout << "To Login as a traveler press 1. \nTo Login as a host press 2.\nTo Login as an Admin press 3. \n"
             << endl;
        cin >> torh;
        Login(torh);

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


/*both insert functions create the struct objects and pushes them to the map*/
void InsertTraveler(Travelers& traveler)
{
    Travelers data;                //Declare struct object
    data.fullname = traveler.fullname;
    data.age = traveler.age;
    data.email = traveler.email;
    data.gender = traveler.gender;
    data.nationality = traveler.nationality;
    data.password = traveler.password;
    travelerMap[traveler.username] = data; //Add the struct object as a value for the map (Key :username)
}
void InsertHost(Host& host)
{
    Host data;      //Declare struct object
    data.fullname = host.fullname;
    data.age = host.age;
    data.email = host.email;
    data.gender = host.gender;
    data.nationality = host.nationality;
    data.password = host.password;
    data.places=host.places;
    hostMap[host.username] = data; //Add the struct object as a value for the map (Key :username)
}

/*Following Functions take the data read from the file and uses it to create the objects that are to be passed to the insert functions*/
Travelers ReadTraveler()
{
    Travelers traveler(read[0], read[1], read[3], read[2], read[4], read[5][1], stoi(read[6]));
    /* username = read[0]
     fullname = read[1]
     email = read[2]
     password = read[3]
     nationality = read[4]
     gender = read[5][0]
     age = String To Integer(read[6])*/
    return traveler;
}

TravelerTrips Readtrips()
{
    TravelerTrips trips(read[0],read[1],read[2],read[3],stof(read[4]), stof(read[5]));
    return trips;
}
Admin ReadAdmin()
{
    Admin admin(read[0], read[1], read[3], read[2], read[4], read[5][1], stoi(read[6]));
    return admin;
}
Host ReadHosts()
{
    Host host(read[0], read[1], read[2], read[3], read[4], read[5][1], stoi(read[6]));
    return host;
}
HostsPlaces ReadPlaces()
{
    bool isConfirmed;
    if(read[5]=="0"){
        isConfirmed= false;
    }
    else if(read[5]=="1"){
        isConfirmed= true;
    }
    else{
      cout<< " Error !";
    }
float x= stof(read[4]);
    HostsPlaces place(read[0], read[1], read[2], read[3],stoi(read[4]),isConfirmed);
    if(isConfirmed!=1)
    hostMap[place.getHostusername()].places.push(place);
    else
        hostMap[place.getHostusername()].confirmed_places.push_back(place);
    return place;
}

/*countLine gets the number of lines inside the text file*/
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

/*readfile reads from the file a line that is to be passed to be operated on*/
void readfile(string path, ifstream& file, int y)
{
    string line;
    file.open(path, ios::in);
    if (file.is_open())
    {
        int countlines = 0;
        while (!file.eof())
        {
            if (countlines != y - 1 && countlines != 0)
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
            else if (path == filePaths[3] && countlines > 0)
            {
               HostsPlaces place = ReadPlaces();
              // hostMap[place.Hostusername].places.push(place);

            }
            else if (path == filePaths[4] && countlines > 0)
            {
              Admin admin=ReadAdmin();
              adminMap[admin.getUsername()]=admin;
            }
            else if(path== filePaths[2] && countlines>0) {
                TravelerTrips trips= Readtrips();
                travelerMap[trips.getTravelerusername()];
               // Travelers travelers(trips.getTravelerusername(),travelerMap[trips.getTravelerusername()].fullname,travelerMap[trips.getTravelerusername()].password,travelerMap[trips.getTravelerusername()].email,travelerMap[trips.getTravelerusername()].nationality,travelerMap[trips.getTravelerusername()].gender,travelerMap[trips.getTravelerusername()].age);
                travelerMap[trips.getTravelerusername()].pushtrip(trips);
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

/*writefile writes in the file*/
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

//Signup as Traveler or Host
void Signup(int torh){
    ofstream enterData;    //Created stream to write data in file
    cout << "Do you want to signup as a traveler or as a host?" << endl;
    cout << "To signup as a traveler press 1 \n"
            "To signup as a host press 2" << endl;
    cin >> torh;             //Aka : Traveler or Host

    //Traveler case
    if (torh == 1) {
        write.push_back("Traveler");

        //Declare Entered data (Data types)
        string usrname;
        string flname;
        string pswrd;
        string mail;
        string nationalty;
        char gndr;
        int year;

        EnterUserNameTraveler:
        cout << "Enter your username: " << endl;
        cin >> usrname;
        if(travelerMap.count(usrname)==1 || hostMap.count(usrname)==1)
        {
            cout<<"Please enter a new username this one has been already used\n";
            goto EnterUserNameTraveler;
        }
        write.push_back(usrname);               //add username to write vector
        cout << "Enter your fullname: " << endl;
        cin.ignore();
        getline(cin, flname);              //add Fullname to write vector
        write.push_back(flname);
        cout << "Enter your email: " << endl;
        cin >> mail;
        write.push_back(mail);                  //add Mail to write vector
        cout << "Enter your password: " << endl;
        cin >> pswrd;
        write.push_back(pswrd);                 //add Password to write vector
        cout << "Enter your nationality: " << endl;
        cin >> nationalty;
        write.push_back(nationalty);            //add Nationality to write vector
        cout << "Enter your gender (no offense M|F): " << endl;
        cin >> gndr;
        string gender;
        gender += gndr;
        write.push_back(gender);                //add Gender to write vector
        cout << "Enter your age: " << endl;
        cin >> year;
        string age;
        age = to_string(year);
        write.push_back(age);               //add Age to write vector
        //Create traveler object with given data
        Travelers traveler(usrname, flname, pswrd, mail, nationalty, gndr, year);

        //Insert traveler (NoUserName Struct) into The travelers map
        InsertTraveler(traveler);

        //Call writefile function to write entered data into travelers.txt
        writefile(filePaths[0], enterData);

    }
    //Host case
    else if (torh == 2) {
        write.push_back("Host");

        //Declare Entered data (Data types)
        string usrname;
        string flname;
        string pswrd;
        string mail;
        string nationalty;
        char gndr;
        int year;

        EnterUserNameHost:
        cout << "Enter your username: " << endl;
        cin >> usrname;
        if(travelerMap.count(usrname)==1 || hostMap.count(usrname)==1)
        {
            cout<<"Please enter a new username this one has been already used\n";
            goto EnterUserNameHost;
        }
        write.push_back(usrname);                //add username to write vector
        cout << "Enter your fullname: " << endl;
        cin.ignore();
        getline(cin, flname);
        write.push_back(flname);                 //add Full Name to write vector
        cout << "Enter your email: " << endl;
        cin >> mail;
        write.push_back(mail);                   //add Mail to write vector
        cout << "Enter your password: " << endl;
        cin >> pswrd;
        write.push_back(pswrd);                     //add Password to write vector
        cout << "Enter your nationality: " << endl;
        cin >> nationalty;
        write.push_back(nationalty);                 //add Nationality to write vector
        cout << "Enter your gender (no offense M|F): " << endl;
        cin >> gndr;
        string gender;
        gender += gndr;
        write.push_back(gender);                     //add Gender to write vector
        cout << "Enter your age: " << endl;
        cin >> year;
        string age;
        age = to_string(year);
        write.push_back(age);           //add Year to write vector

        //Create Host object with given data
        Host host(usrname, flname, pswrd, mail, nationalty, gndr, year);

        //Insert Host (NoUserName Struct) into The Hosts map
        InsertHost(host);

        //Call writefile function to write entered data into Hosts.txt
        writefile(filePaths[1], enterData);
    }
}

//Functions convert NoUserNamedData Struct Objects To Object of classes (Traveler & Host)
Travelers StructToTraveler(string UserName,Travelers Struct){

    //Get Data From Struct and give it to Traveler constructor

    Travelers traveler = Travelers(UserName,Struct.fullname,
                                   Struct.password,Struct.email,
                                   Struct.nationality,Struct.gender,Struct.age);
    return traveler;
}
Host StructToHost(string UserName,Host Struct){
    //Get Data From Struct and give it to Host constructor
    Host host = Host(UserName,Struct.fullname,
                                   Struct.password,Struct.email,
                                   Struct.nationality,Struct.gender,Struct.age );
    int size = Struct.places.size();
    for (int i = 0; i < size ; ++i) {
        host.places.push(Struct.places.front());
        Struct.places.pop();
    }
    return host;
}

//Login into program and start using its functionality (For Host , Traveler and Admin)
void Login(int torh  ) {
    //Created stream to write data in file
    ofstream enterData;
    int op;                     //Operations Selector

    //Traveler Case
    if (torh == 1) {

        cout << "Please enter your username: " << endl;
        string usrname;
        cin >> usrname;

        //Check that the traveler has an account
        if (!travelerMap[usrname].password.empty()) {
            jumpA:
            cout << "Enter your password: " << endl;
            string pswrd;
            cin >> pswrd;

            //Check that the user entered his password correctly
            if (travelerMap[usrname].password == pswrd) {
                cout << "Hello " << travelerMap[usrname].fullname << " :) Would you like to book a new trip? "
                     << endl;
//                Travelers t (usrname, travelerMap[usrname].fullname, travelerMap[usrname].password,
//                                    travelerMap[usrname].email, travelerMap[usrname].nationality,
//                                    travelerMap[usrname].gender, travelerMap[usrname].age);

               // cout<< travelerMap[usrname].top().getCity()<<endl;
               cout<<travelerMap[usrname].trips.empty()
               <<endl;
                int triporback;
                cout << "To book a new trip press 1 / To go back press 0" << endl;
                cin >> triporback;

                //Allow the user to book a new trip and get the details of the trip from the user
                if (triporback == 1) {
                    write.push_back("Trips");
                    write.push_back(usrname);
                    cout << "Write down your dream city :" << endl;
                    string city;
                    cin >> city;
                    write.push_back(city);
                    cout << "Enter your start and end dates :" << endl;
                    cout << "Start date : " << endl;
                    string start;
                    cin >> start;
                    write.push_back(start);
                    cout << "End date :" << endl;
                    string end;
                    cin >> end;
                    write.push_back(end);
                    cout << "EMPTY YOUR POCKETS HERE and write down the maximum and minimum budget for your trip : "
                         << endl;
                    cout << " Maximum price  : " << endl;
                    float mx;
                    cin >> mx;
                    string maxnum;
                    maxnum = to_string(mx);
                    write.push_back(maxnum);
                    cout << " Minimum price : " << endl;
                    float mn;
                    cin >> mn;
                    string minnum;
                    minnum = to_string(mn);
                    write.push_back(minnum);

                    //Create Travelers object to be albe to call the InsertTrip function
                    Travelers travelerr(usrname, travelerMap[usrname].fullname, travelerMap[usrname].password,
                                        travelerMap[usrname].email, travelerMap[usrname].nationality,
                                        travelerMap[usrname].gender, travelerMap[usrname].age);

                    //Call the InsertTrip function and pass the needed parameters to instantiate a new object of TravelerTrips class
                    travelerr.InsertTrip(city, start, end, mx, mn, usrname);
                    writefile(filePaths[2], enterData);
                } else {
                    cout << "Incorrect password please enter the correct password " << endl;
                    goto jumpA;
                }
            }
            else {
                //For new users allow them to sing up/create an account first
                cout << "Please sign up first to be able to book a trip :( " << endl;
            }

        }
    }
        //Host Case
    if (torh == 2) {
            //Allow the host to login to add a new place
            cout << "Please enter your username: " << endl;
            string usrname;
            cin >> usrname;

            //Check that the host has an account
            if (!hostMap.count(usrname)==0) {
                jumpB:
                cout << "Enter your password: " << endl;
                string pswrd;
                cin >> pswrd;

                //Check that the host has entered the correct password
                if (hostMap[usrname].password == pswrd) {
                    cout << "Hello " << hostMap[usrname].fullname << " :) Would you like to add new place? " << endl;
                    cout << "To add a place press 1\n";
                    cin >> op;
                    if (op == 1) {

                        //Create an object from Host Class to be able to call AddPlaces function
                        Host host(usrname, hostMap[usrname].fullname,
                                  hostMap[usrname].password,
                                  hostMap[usrname].email, hostMap[usrname].nationality,
                                  hostMap[usrname].gender, hostMap[usrname].age);
                        cout << "-------------------<Enter Place Data>-------------------" << endl;
                        write.push_back("HostPlace");
                        write.push_back(usrname);
                        cout << "Where place is ? : \n";
                        string city;
                        cin >> city;
                        write.push_back(city);
                        cout << "When will your place be available ? : \n";
                        string startDate;
                        cin >> startDate;
                        write.push_back(startDate);
                        cout << "When won't your place be available ? : \n";
                        string endDate;
                        cin >> endDate;
                        write.push_back(endDate);
                        cout << "Set Rent Price : \n";
                        float price;
                        cin >> price;
                        write.push_back(to_string(price));
                        write.push_back("0");

                        //Call of AddPlaces Function
                        host.AddPlaces(host, city, startDate, endDate, price);
                        string currstring = filePaths[3];
                        writefile(currstring.c_str(), enterData);
                    }
                } else {
                    cout << "Incorrect password please enter the correct password " << endl;
                    goto jumpB;
                }
            } else {
                //For new hosts allow them to sing up/create an account first
                cout << "Please sign up first to be able to add place :( " << endl;
                Signup(2);
            }

        }
        //Admin Case
    if (torh == 3) {
            //Allow the Admin to login and give access to alter data
            cout << "Please enter your username: " << endl;
            string usrname;
            cin >> usrname;
            if (!adminMap.count(usrname)==0) {
                jumpC:
                cout << "Enter your password: " << endl;
                string pswrd;
                cin >> pswrd;

                //Check for the Admin's password has been entered correctly
                if (adminMap[usrname].getPassword() == pswrd) {
                    cout << "Hello " << adminMap[usrname].getFullname() << " :) " << endl;
                    helloAdmin:
                    cout << "To View data press : 1\n";
                    cin >> op;
                    if (op == 1) {
                        cout << "Enter Username of User You want to view : ";
                        cin >> usrname;

                        //Get the data of the entered username to allow admin to apply some changes for this account
                        if (travelerMap.count(usrname)!=0) {
                            Travelers traveler = StructToTraveler(usrname, travelerMap[usrname]);
                            torh = 1;

                            cout << "-----------------------( Traveler Data )-----------------------" << endl;
                            cout << "1) Full Name  : " << traveler.getFullname() << endl;
                            cout << "2) Email : " << traveler.getEmail() << endl;
                            cout << "3) Gender : " << traveler.getGender() << endl;
                            cout << "4) Age : " << traveler.getAge() << endl;
                            cout << "5) Nationality : " << traveler.getNationality() << endl;
                            cout << "--------------------------------------------------------" << endl;

                        }
                        else if (hostMap.count(usrname)!=0) {
                            Host host = StructToHost(usrname, hostMap[usrname]);
                            torh = 2;

                            cout << "-----------------------( Host Data )-----------------------" << endl;
                            cout << "1) Full Name  : " << host.getFullname() << endl;
                            cout << "2) Email : " << host.getEmail() << endl;
                            cout << "3) Gender : " << host.getGender() << endl;
                            cout << "4) Age : " << host.getAge() << endl;
                            cout << "5) Nationality : " << host.getNationality() << endl;
                            cout << "6) Number of Places : " << host.countPlaces() << endl;
                            cout << "--------------------------------------------------------" << endl;
                        } else {
                            cout << " There is no user with this username :< " << endl;
                            goto helloAdmin;
                        }
                        if (torh == 1 || torh == 2)  //Check if User is Host or Traveler
                        {
                            cout << "To Delete User press 2 \nTo Edit User press 3\n";
                            if (torh == 2) {
                                cout << "To Handle host's request press 4\n";
                            }
                            cin >> op;
                            //op=2 allows admin to delete data the selected user
                            if (op == 2) {
                                if (torh == 2) //User is host
                                {
                                    Admin::DeleteData(usrname, hostMap);
                                } else if (torh == 1) // user is taveler
                                {
                                    Admin::DeleteData(usrname, travelerMap);
                                } else
                                    cout << "Error While Deleting!";
                            } else if (op == 4 && torh == 2) {
                                Host host = StructToHost(usrname, hostMap[usrname]);
                                Admin admin = adminMap[usrname];
                                multimap<string , HostsPlaces>  wezza =  admin.RequestHost(hostMap[usrname].places, host);
                            }
                            else if (op == 3 && torh ==1) //the user is traveller and the operation is editing (editing host)
                            {
                                int numofdata ;
                                cout << "Enter the number of the required data to be edited : " << endl ;
                                cin >> numofdata;
                                if (numofdata == 1 ) // the admin wants to edit the traveller's name (editing full name data )
                                {
                                    cout << " Enter the new name : " << endl ;
                                    string newname ;
                                    cin >> newname ;
                                    travelerMap[usrname].fullname = newname;
                                }
                                if (numofdata == 2) // the admin wants to edit the traveller's emails (editing email data )
                                {
                                    cout << " Enter the new email : " << endl ;
                                    string newemail ;
                                    cin >> newemail ;
                                    travelerMap[usrname].email = newemail;
                                }
                                if (numofdata == 3) // the admin wants to edit the traveller's gender (editing gender data )
                                {
                                    cout << " Enter the updated gender : " << endl ;
                                    char newgender;
                                    cin >> newgender ;
                                    travelerMap[usrname].gender = newgender;
                                }
                                if (numofdata == 4) // the admin wants to edit the traveller's age (editing age data )
                                {
                                    cout << " Enter the updated age : " << endl ;
                                    int newage ;
                                    cin >> newage ;
                                    travelerMap[usrname].age = newage;
                                }
                                if (numofdata == 5 ) // the admin wants to edit the traveller's nationality (editing nationality data )
                                {
                                    cout << " Enter the new nationality : " << endl ;
                                    string newnation ;
                                    cin >> newnation ;
                                    travelerMap[usrname].nationality = newnation;

                                }
                                cout << "The traveller's data has been edited SUCCESSFULLY '') " << endl;

                            }
                            else if (op == 3 && torh ==2) //the user is host and the operation is editing (editing host)
                            {
                                int numofdata ;
                                cout << "Enter the number of the required data to be edited : " << endl ;
                                cin >> numofdata;
                                if (numofdata == 1 ) // the admin wants to edit the host's name (editing full name data )
                                {
                                    cout << " Enter the new name : " << endl ;
                                    string newname ;
                                    cin >> newname ;
                                    hostMap[usrname].fullname = newname;
                                }
                                if (numofdata == 2) // the admin wants to edit the host's emails (editing email data )
                                {
                                    cout << " Enter the new email : " << endl ;
                                    string newemail ;
                                    cin >> newemail ;
                                    hostMap[usrname].email = newemail;
                                }
                                if (numofdata == 3) // the admin wants to edit the host's gender (editing gender data )
                                {
                                    cout << " Enter the updated gender : " << endl ;
                                    char newgender;
                                    cin >> newgender ;
                                    hostMap[usrname].gender = newgender;
                                }
                                if (numofdata == 4) // the admin wants to edit the host's age (editing age data )
                                {
                                    cout << " Enter the updated age : " << endl ;
                                    int newage ;
                                    cin >> newage ;
                                    hostMap[usrname].age = newage;
                                }
                                if (numofdata == 5 ) // the admin wants to edit the hosts's nationality (editing nationality data )
                                {
                                    cout << " Enter the new nationality : " << endl ;
                                    string newnation ;
                                    cin >> newnation ;
                                    hostMap[usrname].nationality = newnation;

                                }
                                cout << "The Host's data has been edited SUCCESSFULLY '') " << endl;


                            }

                        }
                    }
                else {
                    cout << "Incorrect password please enter the correct password " << endl;
                    goto jumpC;
                }

            }
            else {
                cout << "There is no admin with this user name " << endl;
            }
        }


        }
    }
