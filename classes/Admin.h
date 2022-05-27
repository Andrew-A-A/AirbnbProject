//
// Created by andro on 26/5/2022.
//

#ifndef AIRBNBPROJECT_ADMIN_H
#define AIRBNBPROJECT_ADMIN_H
#include "NewUser.h"
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
};


#endif //AIRBNBPROJECT_ADMIN_H
