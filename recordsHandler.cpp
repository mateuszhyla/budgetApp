#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include "recordsHandler.h"
#include <algorithm>
#include <conio.h>
#include <sstream>


using namespace std;

RecordsHandler::RecordsHandler()
{
    fileHandler.pathXML = fileHandler.getXMLPath();
    newExpenditureId = fileHandler.findCurrentRecordId("expenditure");
    newIncomeId = fileHandler.findCurrentRecordId("income");
    dateChecker.checkCurrentDate();
}

Record RecordsHandler::addRecordDetails()
{
    string date, category, amount;
    Record newRecord;
    float convertedAmount;

    date = dateWindow();

    cout << "Type category: ";
    cin >> category;

        do
        {
            cout << endl << endl << "Type amount: ";
            cin >> amount;
        }
        while (!amountChecker.checkAmount(amount, convertedAmount));


    newRecord.setDate(date);
    newRecord.setCategory(category);
    newRecord.setAmount(convertedAmount);

    return newRecord;
}

string RecordsHandler::dateWindow()
{
    string date;
    char userSelection;

     system("cls");
    cout << "Do you want to add record to database with current date? (y/n)" << endl;
    do
    {
        userSelection = getch();
    }
    while ((userSelection != 'y') && (userSelection != 'n'));

    if (userSelection == 'y')
    {
        date = dateChecker.getFormattedCurrentDate();
    }
    else
    {
        do
        {
            cout << endl << endl << "Type date (YYYY-MM-DD): ";
            cin >> date;
        }
        while (!dateChecker.checkDate (date, dateChecker.getCurrentDate()));
    }
    return date;
}

void RecordsHandler::addRecord(int userId, string recordType)
{
    float convertedAmount;
    Record newRecord;

    newRecord = addRecordDetails();

    if (recordType == "income")
    {
        newIncomeId++;
        newRecord.setId(newIncomeId);
    }
    else
    {
        newExpenditureId++;
        newRecord.setId(newExpenditureId);
    }

    newRecord.setUserId(userId);

    fileHandler.updateRecordsDataBase(newRecord, "addRecord", recordType);

    cout << endl << "Record has been added!" << endl;
    Sleep(1500);
}



/*

string ContactsHandler::convertIntToString (int id)
{
    ostringstream ss;
    ss << id;
    string str =ss.str();

    return str;
}
*/
