#include <iostream>
#include <vector>
#include "user.h"

using namespace std;

class FileUsers
{

public:
    vector <User> readUsersDataFromFile();
    void updateUsersDataBase(User, string);

private:
    string pathXML;
    virtual string convertIntToString (int);
    string getXMLPath();
};
