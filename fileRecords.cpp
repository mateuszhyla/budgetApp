#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include "fileRecords.h"
#include <sstream>
#include "Markup.h"
#include <windows.h>
#include <cstdio>

using namespace std;
/*
vector <Record> FileRecords::readRecordsFromFile()
{
    vector <Record> existingRecords;
    Record recordInfo;
    CMarkup xml;

    pathXML = getXMLPath();

    xml.Load(pathXML);
    xml.FindElem();
    xml.IntoElem();

    while ( xml.FindElem("USER") )
    {
        xml.IntoElem();
        xml.FindElem( "ID" );
        recordInfo.setId(atoi(MCD_2PCSZ (xml.GetData())));
        xml.FindElem( "LOGIN" );
        recordInfo.setLogin(xml.GetData());
        xml.FindElem( "PASSWORD" );
        recordInfo.setPassword(xml.GetData());
        xml.FindElem( "NAME" );
        recordInfo.setName(xml.GetData());
        xml.FindElem( "SURNAME" );
        recordInfo.setSurname(xml.GetData());
        xml.OutOfElem();

        existingRecords.push_back(recordInfo);
    }

    return existingRecords;
}
*/
void FileRecords::updateRecordsDataBase(Record recordToUpdate, string action)
{
    bool incomeExists;
    CMarkup xml;
    xml.Load(pathXML);
    xml.ResetPos();
    incomeExists = xml.FindElem();
    xml.IntoElem();
    xml.IntoElem();


    if (action == "addRecord")
    {
        if (!incomeExists)
        {
            xml.AddElem("INCOMES");
            xml.IntoElem();
        }
        xml.AddElem( "INCOME" );
        xml.IntoElem();
        xml.AddElem( "INCOMEID", recordToUpdate.getId() );
        xml.AddElem( "USERID", recordToUpdate.getUserId() );
        xml.AddElem( "DATE", recordToUpdate.getDate() );
        xml.AddElem( "CATEGORY", recordToUpdate.getCategory() );
        xml.AddElem( "AMOUNT", recordToUpdate.getAmount() );
        xml.OutOfElem();
        xml.Save(pathXML);
    }
    else
    {

    }

}

int FileRecords::findCurrentRecordId(string fileName)
{
    string pathToFile = pathXML + "\\" + fileName + ".xml";
    int id = 1;
    bool fileExists = false;

    CMarkup xml;
    xml.Load(pathXML);
    fileExists = xml.FindElem();

    if (!fileExists)
    {
        return 1;
    }

    xml.IntoElem();

  xml.FindChildElem("Record");

  xml.IntoElem();
        xml.FindElem( "ID" );
        return atoi(MCD_2PCSZ (xml.GetData()));

}

/*string FileUsers::convertUserStructureToSingleLine(User userToConvert)
{
    string convertedUser;

    convertedUser = convertIntToString(userToConvert.getId()) + "|";
    convertedUser += userToConvert.getNickname()+ "|";
    convertedUser += userToConvert.getPassword() + "|";

    return convertedUser;

}*/

/*string FileUsers::convertIntToString (int id)
{

    ostringstream ss;
    ss << id;
    string str =ss.str();

    return str;
}
*/
string FileRecords::getXMLPath ()
{
    string directory, path;

    char buffer[ MAX_PATH ];
    ::GetModuleFileNameA( NULL, buffer, MAX_PATH );
    directory = buffer;
    size_t found = directory.find_last_of("/\\");
    path = directory.substr(0, found);

    return path;
}
