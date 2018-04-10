#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include "usersHandler.h"


using namespace std;

UsersHandler::UsersHandler()
{
    existingUsers = fileHandler.readUsersDataFromFile();
}

void UsersHandler::registerNewUser()
{
    existingUsers = fileHandler.readUsersDataFromFile();
    string login, password, name, surname;
    User newUser;
    int i = 0, contactId = 1;

    cout << endl << "Type new username: ";
    cin >> login;

    while (i < existingUsers.size())
    {
        if (existingUsers[i].getLogin() == login)
        {
            cout << "Username already exists. Type different username: ";
            cin >> login;
            i = 0;
        }
        else
        {
            i++;
        }
    }

    cout << "Type a password: ";
    cin >> password;

      cout << "Type your name: ";
    cin >> name;

      cout << "Type your surname: ";
    cin >> surname;

    if (existingUsers.size()>0)
    {
        contactId = existingUsers.back().getId() + 1;
    }
    newUser.setId (contactId);
    newUser.setLogin (login);
    newUser.setPassword (password);
    newUser.setName (name);
    newUser.setSurname (surname);

    fileHandler.updateUsersDataBase(newUser, "addUser");

    cout << endl << "User's account has been created!" << endl;
    Sleep(1500);
}

User UsersHandler::logIn ()
{
    existingUsers = fileHandler.readUsersDataFromFile();
    string login, password;
    User matchedUser;
    matchedUser.setId(0);
    system("cls");
    cout << "Write your username: ";
    cin >> login;
    int i = 0;

    while (i < existingUsers.size())
    {
        if (existingUsers[i].getLogin() == login)
        {
            for (int attempts = 0; attempts < 3; attempts++)
            {
                cout << "Write your password. Login attempts remaining: " << 3-attempts << ": ";
                cin >> password;
                if (existingUsers[i].getPassword() == password)
                {
                    matchedUser = existingUsers[i];
                    cout << "Logged in correctly!";
                    Sleep(1000);
                    return existingUsers[i];
                }
            }
            cout << "3 logon attempts failed. Please wait 5 seconds until next try" << endl;
            Sleep(5000);
            return matchedUser;
        }
        i++;
    }
    cout << "There is no such username in database. Check your credentials" << endl;
    Sleep(1500);
    return matchedUser;

}

void UsersHandler::changePassword (User loggedUser)
{
    string oldPassword, newPassword;
    system ("cls");
    cout << "Type old password: ";

    cin >> oldPassword;
    while (oldPassword != loggedUser.getPassword())
    {
        system("cls");
        cout << "Password is incorrect. Please type again: ";
        cin >> oldPassword;
    }
    cout << endl << "Type new password: ";
    cin >> newPassword;

    loggedUser.setPassword(newPassword);
    fileHandler.updateUsersDataBase(loggedUser, "changeUserPassword");
    cout << endl << "New password has been set" << endl;
    Sleep(1500);
}

