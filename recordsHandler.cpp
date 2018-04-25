#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include "recordsHandler.h"
#include <algorithm>
#include <conio.h>
#include <sstream>
#include <iomanip>
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

void RecordsHandler::askForSummaryDate(vector <int> &startDateForSummary, vector <int> &endDateForSummary)
{
    string startDate, endDate;
    system ("cls");
    do
    {
        cout << endl << endl << "Type start date for summary (YYYY-MM-DD): ";
        cin >> startDate;
    }
    while (!dateChecker.checkDate (startDate, dateChecker.getCurrentDate()));

    dateChecker.divideGivenDateIntoThreeNumbers(startDate, startDateForSummary);
    do
    {
        cout << endl << endl << "Type end date for summary (YYYY-MM-DD): ";
        cin >> endDate;
    }
    while (!dateChecker.checkDate (endDate, dateChecker.getCurrentDate()));

    dateChecker.divideGivenDateIntoThreeNumbers(endDate, endDateForSummary);
}

float RecordsHandler::calculateSum(vector <Record> recordsToSum)
{
    float sum = 0.00;

    for (int i = 0; i < recordsToSum.size(); i++)
    {
        sum += recordsToSum[i].getAmount();
    }
    return sum;
}

void RecordsHandler::showConsoleTextInColor(string text, int color)
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(console, color);
    cout << text;
    SetConsoleTextAttribute(console, 15);
}

void RecordsHandler::displaySummary(vector <Record> incomes, vector <Record> expenditures, float sumIncomes, float sumExpenditures)
{
    float ballance = sumIncomes - sumExpenditures;
    system("cls");
    cout << fixed;
    cout << setprecision(2);

    showConsoleTextInColor("INCOMES", 10);
    cout << endl;

    for (int i = 0; i < incomes.size(); i++)
    {
        cout << incomes[i].getDate() << setw(20) << incomes[i].getCategory() << setw(10) << incomes[i].getAmount() << endl;
    }
    cout << endl << "SUM OF INCOMES:" << setw(25);
    showConsoleTextInColor(convertFloatToString(sumIncomes), 10);
    cout << endl << endl;

    showConsoleTextInColor("EXPENDITURES", 12);
    cout << endl;

    for (int i = 0; i < expenditures.size(); i++)
    {
        cout << expenditures[i].getDate() << setw(20) << expenditures[i].getCategory() << setw(10) << expenditures[i].getAmount() << endl;
    }
    cout << endl << "SUM OF EXPENDITURES:" << setw(20);
    showConsoleTextInColor(convertFloatToString(sumExpenditures), 12);
    cout << endl << endl;

    cout << endl << endl << "PERIOD BALANCE:" << setw(25);
    if (ballance > 0)
    {
        showConsoleTextInColor(convertFloatToString(sumIncomes - sumExpenditures), 10);
    }
    else
    {
        showConsoleTextInColor(convertFloatToString(sumIncomes - sumExpenditures), 12);
    }
    cout << endl << endl;
    system ("pause");
}

void RecordsHandler::manageSummary(string period, int userId)
{
    float sumIncomes, sumExpenditures;
    vector <int> startDateForSummary, endDateForSummary;
    bool custom = false;

    if (period == "current")
    {
        endDateForSummary = dateChecker.getCurrentDate();
        startDateForSummary = endDateForSummary;
        startDateForSummary[2] = 1;
    }
    else if (period == "previous")
    {
        endDateForSummary = dateChecker.getCurrentDate();
        if (endDateForSummary[1] > 1)
        {
            endDateForSummary[1] -= 1;
        }
        else
        {
            endDateForSummary[1] = 12;
            endDateForSummary[0] -= 1;
        }
    }
    else
    {
        askForSummaryDate (startDateForSummary, endDateForSummary);
        custom = true;
    }

    incomes = fileHandler.readRecordsFromFile(startDateForSummary, endDateForSummary, "income", userId, custom);
    expenditures = fileHandler.readRecordsFromFile(startDateForSummary, endDateForSummary, "expenditure", userId, custom);

    dateChecker.sortRecords(incomes);
    dateChecker.sortRecords(expenditures);

    sumIncomes = calculateSum(incomes);
    sumExpenditures = calculateSum(expenditures);

    displaySummary(incomes, expenditures, sumIncomes, sumExpenditures);
}

string RecordsHandler::convertFloatToString(float number)
{
    stringstream ss;
    ss << number;
    return ss.str();
}

