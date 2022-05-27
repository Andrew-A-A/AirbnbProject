//
// Created by andro on 26/5/2022.
//

#include "Admin.h"

Admin::Admin():NewUser() {}

void Admin::DeleteData() {

}

void Admin::Display(string *) {

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

