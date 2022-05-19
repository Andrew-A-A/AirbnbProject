#pragma once
#include<string>
#include<iostream>
using namespace std;
class NewUser
{
	public:
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
		~NewUser(void);
};

