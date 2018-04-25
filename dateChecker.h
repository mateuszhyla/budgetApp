#include <iostream>
#pragma once
#include "record.h"

using namespace std;

class DateChecker //: public Converters
{
  public:

     void checkCurrentDate();
     bool checkDate (string &, vector<int>);
     string getFormattedCurrentDate();
     vector <int> getCurrentDate();
    static void divideGivenDateIntoThreeNumbers (string, vector <int>&);
    void sortRecords(vector <Record>&);
   static bool compareDates (Record&, Record&);

  private:
    vector <int> currentDate;
    string formatedCurrentDate;
    string convertIntToString(int);
    static int convertStringToInt (string);
    string addLeadingZero(string);
    bool isLeap(int);
    bool checkIfDateIsValid(vector <int>, vector <int>);
    bool checkDateFormat (string);
};
