#include "NewUser.h"

NewUser::NewUser()
{
	age = 18;

}

NewUser::NewUser(string username, string fullname, string password, string email, string nationality, char gender, int age)
{
	this->username = username;
	this->email = email;
	this->password = password;
	this->fullname = fullname;
	this->age = age;
	this->gender = gender;
	this->nationality = nationality;
}

const string &NewUser::getUsername() const {
    return username;
}

const string &NewUser::getPassword() const {
    return password;
}

const string &NewUser::getFullname() const {
    return fullname;
}

const string &NewUser::getEmail() const {
    return email;
}

const string &NewUser::getNationality() const {
    return nationality;
}

char NewUser::getGender() const {
    return gender;
}

int NewUser::getAge() const {
    return age;
}
