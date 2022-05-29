//
// Created by andro on 26/5/2022.
//

#ifndef AIRBNBPROJECT_ADMIN_H
#define AIRBNBPROJECT_ADMIN_H

#include <vector>
#include "NewUser.h"
#include "Host.h"
#include <bits/stdc++.h>
#include <string>
#include <map>

class Admin: NewUser {
public:
    const string &getUsername() const;
    const string &getPassword() const;
    const string &getFullname() const;

    Admin();
    Admin(string username, string fullname,string password, string email,
          string nationality, char gender, int age);


    void DeleteData();
    void Display(string[]);
    void Edit(string[]);
    map <pair<string , int>, HostsPlaces> RequestHost(queue<HostsPlaces> , Host &host);
};


#endif //AIRBNBPROJECT_ADMIN_H
