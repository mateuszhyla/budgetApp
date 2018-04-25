#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include "fileUsers.h"
#include <sstream>
#include "Markup.h"
#include <windows.h>
#include <cstdio>

using namespace std;

vector <User> FileUsers::readUsersDataFromFile()
{
    vector <User> existingUsers;
    User userInfo;
    CMarkup xml;

    pathXML = getXMLPath();

    xml.Load(pathXML);
    xml.FindElem();
    xml.IntoElem();

    while ( xml.FindElem("USER") )
    {
        xml.IntoElem();
        xml.FindElem( "ID" );
        userInfo.setId(atoi(MCD_2PCSZ (xml.GetData())));
        xml.FindElem( "LOGIN" );
        userInfo.setLogin(xml.GetData());
        xml.FindElem( "PASSWORD" );
        userInfo.setPassword(xml.GetData());
        xml.FindElem( "NAME" );
        userInfo.setName(xml.GetData());
        xml.FindElem( "SURNAME" );
        userInfo.setSurname(xml.GetData());
        xml.OutOfElem();

        existingUsers.push_back(userInfo);
    }

    return existingUsers;
}

void FileUsers::updateUsersDataBase(User userToUpdate, string action)
{
    bool userExist;
    CMarkup xml;
    xml.Load(pathXML);
    xml.ResetPos();
    userExist = xml.FindElem();
    xml.IntoElem();
    xml.IntoElem();


    if (action == "addUser")
    {
        if (!userExist)
        {
            xml.AddElem("USERS");
            xml.IntoElem();
        }
        xml.AddElem( "USER" );
        xml.IntoElem();
        xml.AddElem( "ID", userToUpdate.getId() );
        xml.AddElem( "LOGIN", userToUpdate.getLogin() );
        xml.AddElem( "PASSWORD", userToUpdate.getPassword() );
        xml.AddElem( "NAME", userToUpdate.getName() );
        xml.AddElem( "SURNAME", userToUpdate.getSurname() );
        xml.OutOfElem();
        xml.Save(pathXML);
    }
    else if (action == "changeUserPassword")
    {
        while ( xml.FindElem("USER") )
        {
            xml.IntoElem();
            xml.FindElem("ID");
            int id = atoi (MCD_2PCSZ (xml.GetData()));
            cout << id << endl;
            cout << userToUpdate.getId() << endl;
            if(id == userToUpdate.getId())
            {
                xml.FindElem("PASSWORD");
                xml.SetData(userToUpdate.getPassword());
                xml.Save(pathXML);
                break;
            }
            xml.OutOfElem();
        }
    }
}

string FileUsers::convertIntToString (int id)
{

    ostringstream ss;
    ss << id;
    string str =ss.str();

    return str;
}

string FileUsers::getXMLPath ()
{
    string directory, path;

    char buffer[ MAX_PATH ];
    ::GetModuleFileNameA( NULL, buffer, MAX_PATH );
    directory = buffer;
    size_t found = directory.find_last_of("/\\");
    path = directory.substr(0, found) + "\\users.xml";

    return path;
}
