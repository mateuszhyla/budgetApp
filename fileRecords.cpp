#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include "fileRecords.h"
#include <sstream>
#include "Markup.h"
#include <windows.h>
#include <cstdio>
#include <algorithm>
#include <iomanip>
#include <sstream>

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
void FileRecords::updateRecordsDataBase(Record recordToUpdate, string action, string recordType)
{
    string pathToFile = pathXML + "\\" + recordType + "s.xml";
    std::transform(recordType.begin(), recordType.end(),recordType.begin(), ::toupper);
    bool incomeExists;
    float amount = recordToUpdate.getAmount();
    stringstream stream;
    stream << fixed << setprecision(2) << amount;
    string convertedAmount = stream.str();

    CMarkup xml;
    xml.Load(pathToFile);
    xml.ResetPos();
    incomeExists = xml.FindElem();
    xml.IntoElem();
    xml.IntoElem();


    if (action == "addRecord")
    {
        if (!incomeExists)
        {
            xml.AddElem(recordType + "S");
            xml.IntoElem();
        }
        xml.ResetMainPos();
        xml.InsertElem(recordType);
        xml.IntoElem();
        xml.AddElem( recordType + "ID", recordToUpdate.getId() );
        xml.AddElem( "USERID", recordToUpdate.getUserId() );
        xml.AddElem( "DATE", recordToUpdate.getDate() );
        xml.AddElem( "CATEGORY", recordToUpdate.getCategory() );
        xml.AddElem( "AMOUNT", convertedAmount );
        xml.OutOfElem();
        xml.Save(pathToFile);
    }
    else
    {

    }

}

int FileRecords::findCurrentRecordId(string fileName)
{
    string pathToFile = pathXML + "\\" + fileName + "s.xml";
    std::transform(fileName.begin(), fileName.end(),fileName.begin(), ::toupper);

    int id = 1;
    bool fileExists = false;

    CMarkup xml;
    xml.Load(pathToFile);
    fileExists = xml.FindElem();

    if (!fileExists)
    {
        return 0;
    }

    xml.IntoElem();

  xml.FindChildElem(fileName);

  xml.IntoElem();
        xml.FindElem( fileName + "ID" );
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
