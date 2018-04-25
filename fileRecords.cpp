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

vector <Record> FileRecords::readRecordsFromFile(vector <int> startDateForSummary, vector <int> endDateForSummary, string fileName, int userId, bool custom)
{
    vector <Record> existingRecords;
    Record recordInfo;
    int tempId;
    string tempDate;
    string pathToFile = pathXML + "\\" + fileName + "s.xml";
    std::transform(fileName.begin(), fileName.end(),fileName.begin(), ::toupper);

    CMarkup xml;
    xml.Load(pathToFile);

    xml.FindElem();
    xml.IntoElem();

    while ( xml.FindElem(fileName) )
    {
        xml.IntoElem();
        xml.FindElem( fileName + "ID" );
        recordInfo.setId(atoi(MCD_2PCSZ (xml.GetData())));
        xml.FindElem( "USERID" );
        tempId = atoi(MCD_2PCSZ (xml.GetData()));
        if (tempId = userId)
        {
            recordInfo.setId(userId);
            xml.FindElem( "DATE" );
            tempDate = xml.GetData();
            if (checkIfDateIsInsideRange(tempDate, startDateForSummary, endDateForSummary, custom))
            {
                recordInfo.setDate(tempDate);
                xml.FindElem( "CATEGORY" );
                recordInfo.setCategory(xml.GetData());
                xml.FindElem( "AMOUNT" );
                recordInfo.setAmount(atof(MCD_2PCSZ (xml.GetData())));

                existingRecords.push_back(recordInfo);
            }
        }
          xml.OutOfElem();
    }

    return existingRecords;
}

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

bool FileRecords::calculateDays (vector <int> recordDate, vector <int> startDate, vector <int> endDate)
{
    int daysForRecordDate, daysForStartDate, daysForEndDate;

    daysForRecordDate = recordDate[0] * 365 + recordDate [1] * 30 + recordDate [2];
    daysForStartDate = startDate[0] * 365 + startDate [1] * 30 + startDate [2];
    daysForEndDate = endDate[0] * 365 + endDate [1] * 30 + endDate [2];

    if ((daysForStartDate <= daysForRecordDate) && (daysForEndDate >= daysForRecordDate))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool FileRecords::checkIfDateIsInsideRange(string dateFromRecord, vector <int> startDate, vector <int> endDate, bool custom)
{
    bool meetRequirements = false;
    vector <int> convertedDateFromRecord;
    dateChecker.divideGivenDateIntoThreeNumbers(dateFromRecord, convertedDateFromRecord);

    if (!custom)
    {
        if ((convertedDateFromRecord[0] == endDate[0]) && (convertedDateFromRecord[1] == endDate[1]))
        {
            meetRequirements = true;
        }
    }
    else
    {
        meetRequirements = calculateDays(convertedDateFromRecord, startDate, endDate);
    }

    return meetRequirements;
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
