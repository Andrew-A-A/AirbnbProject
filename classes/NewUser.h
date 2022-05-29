#pragma once
#include<string>
#include<iostream>
#include "HostsPlaces.h"
#include <queue>
using namespace std;
struct NoUserNameData
{
    string fullname;
    string password;
    string email;
    string nationality;
    char gender{};
    int age{};
    queue<HostsPlaces> places;
    NoUserNameData();

    NoUserNameData(const string &fullname, const string &password, const string &email, const string &nationality,
                   char gender, int age);
};
class NewUser
{
public:

    const string &getUsername() const;

    const string &getPassword() const;

    const string &getFullname() const;

    const string &getEmail() const;

    const string &getNationality() const;


    char getGender() const;

    int getAge() const;

    string username;
		string fullname;
		string password;
		string email;
		string nationality;
		char gender;
		int age;
	public:
		NewUser();
		NewUser(string username, string fullname, string password, string email, string nationality, char gender, int age);

};

