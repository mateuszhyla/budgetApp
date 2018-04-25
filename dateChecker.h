#include <iostream>
#pragma once
#include "record.h"

using namespace std;

class DateChecker
{
public:

    static void divideGivenDateIntoThreeNumbers (string, vector <int>&);
    void checkCurrentDate();
    string getFormattedCurrentDate();
    vector <int> getCurrentDate();
    bool checkDate (string &, vector<int>);
    void sortRecords(vector <Record>&);

private:
    vector <int> currentDate;
    string formatedCurrentDate;
    string convertIntToString(int);
    string addLeadingZero(string);
    bool isLeap(int);
    bool checkIfDateIsValid(vector <int>, vector <int>);
    bool checkDateFormat (string);
    static int convertStringToInt (string);
    static bool compareDates (Record&, Record&);
};
