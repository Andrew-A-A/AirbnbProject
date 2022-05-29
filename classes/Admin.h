//
// Created by andro on 26/5/2022.
//

#ifndef AIRBNBPROJECT_ADMIN_H
#define AIRBNBPROJECT_ADMIN_H
#include "NewUser.h"
#include "Host.h"
#include "HostsPlaces.h"
#include<unordered_map>
#include <map>

class Admin: NewUser {
public:
    Admin();
    Admin(string username, string fullname,string password, string email,
          string nationality, char gender, int age);


    static void DeleteData(string usr ,unordered_map<string,NoUserNameData> &map);
    static void Display();
    void Edit(string[]);
    map <pair<string , int>, HostsPlaces> RequestHost(queue<HostsPlaces> , Host &host);
    //Getters
    const string &getUsername() const;
    const string &getPassword() const;
    const string &getFullname() const;

};


#endif //AIRBNBPROJECT_ADMIN_H
