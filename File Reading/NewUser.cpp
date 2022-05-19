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

NewUser::~NewUser()
{
}
