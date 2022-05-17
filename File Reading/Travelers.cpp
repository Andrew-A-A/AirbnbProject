#include "Travelers.h"

Travelers::Travelers():NewUser()
{
}

Travelers::Travelers(string username, string fullname, string password, string email, string nationality, char gender, int age):NewUser(username, fullname, password, email, nationality, gender, age)
{
}
