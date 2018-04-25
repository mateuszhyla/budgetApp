#include <iostream>
#include <vector>
#include "user.h"
#include "fileUsers.h"

using namespace std;

class UsersHandler
{

public:
    void registerNewUser();
    User logIn ();
    void changePassword (User);
    UsersHandler ();

private:
    vector <User> existingUsers;
    FileUsers fileHandler;

};
