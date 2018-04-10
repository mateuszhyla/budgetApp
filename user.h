#include <iostream>
#pragma once
using namespace std;

class User
{
private:
    int id;
    string login;
    string password;
    string name;
    string surname;

public:
    User (int = 0, string = "Unknown", string = "Unknown", string = "Adam", string = "Nowak");
    void setLogin(string);
    string getLogin();
    void setPassword(string);
    string getPassword();
    void setName(string);
    string getName();
    void setSurname(string);
    string getSurname();
    void setId(int);
    int getId();
};
