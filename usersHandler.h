#include <iostream>
#include <vector>
#include "user.h"
#include "fileUsers.h"

using namespace std;

class UsersHandler
{

private:

    vector <User> existingUsers;
    FileUsers fileHandler;

public:
    void registerNewUser();
    User logIn ();
    void changePassword (User);
    UsersHandler ();
};
