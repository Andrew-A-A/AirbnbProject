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

