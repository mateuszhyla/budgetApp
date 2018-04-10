#include <iostream>
#include "user.h"

using namespace std;

User::User(int number, string userLogin, string pass, string userName, string userSurname)
{
    id = number;
    login = userLogin;
    password = pass;
    name = userName;
    surname = userSurname;
}

void User::setLogin(string userLogin)
{
    login = userLogin;
}

string User::getLogin()
{
    return login;
}

void User::setPassword(string pass)
{
    password = pass;
}


string User::getPassword()
{
    return password;
}

void User::setName(string userName)
{
    name = userName;
}


string User::getName()
{
    return name;
}

void User::setSurname(string userSurname)
{
    surname = userSurname;
}


string User::getSurname()
{
    return surname;
}

void User::setId(int number)
{
    id = number;
}


int User::getId()
{
    return id;
}
