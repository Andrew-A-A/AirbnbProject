//
// Created by andro on 26/5/2022.
//

#include "Admin.h"
#include "Host.h"
#include "HostsPlaces.h"

Admin::Admin():NewUser() {}

void Admin::DeleteData(string usr,unordered_map<string ,struct NoUserNameData> &map){
    if (map[usr].password.empty()){
        cout<<"There is no user with this name :( ";
    }
    else{
        cout<<"User "<<usr<<" Deleted :> \n";

        map.erase(usr);
    }
}

void Admin::Display() {

}

void Admin::Edit(string *) {

}

Admin::Admin(string username, string fullname, string password, string email, string nationality, char gender, int age)
        : NewUser(username, fullname, password, email, nationality, gender, age) {

}

const string &Admin::getUsername() const {
    return NewUser::getUsername();
}

const string &Admin::getPassword() const {
    return NewUser::getPassword();
}

const string &Admin::getFullname() const {
    return NewUser::getFullname();
}

map <pair<string , int>, HostsPlaces> Admin::RequestHost(queue<HostsPlaces> , Host &host) {
    int size=host.places.size();

    for (int i = 0; i < size ; ++i) {
        cout<< "Host " <<host.places.front().Hostusername <<" wants to add a place in "<< host.places.front().City<< " with price "<<host.places.front().pricepernight<<"L.E. per night \n";
        cout<<"To accept the host's request press 1 \nTo ignore the host's request press 2 ";
        int options;
        cin>>options;
        if (options==1){
            host.confirmed_places.push_back(host.places.front());
            host.places.pop();

        }
        else{
            host.places.pop();
        }
    }
    map <pair<string , int>, HostsPlaces> available_places;
    vector<HostsPlaces>avail=host.confirmed_places;
    for (int i = 0; i < avail.size(); ++i) {
        available_places[{avail[i].City , avail[i].pricepernight}];
    }
    return available_places;
}