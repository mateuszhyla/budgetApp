#include <ctime>
#include <iostream>
#include <cstdio>
#include <sstream>
#include <cstdlib>
#include <ctype.h>
#include <vector>
#include <regex>
#include "dateChecker.h">

using namespace std;

string DateChecker::convertIntToString (int number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();

    return str;
}

int DateChecker::convertStringToInt (string number)
{
    return atoi(number.c_str());
}

string DateChecker::addLeadingZero(string inputNumber)
{
    string formattedNumber;
    formattedNumber = "0" + inputNumber;
    return formattedNumber;
}

void DateChecker::checkCurrentDate()
{

    string day, month, year;
    string buforForZero;

    time_t t = time(0);
    tm* now = localtime(&t);
    year = convertIntToString(now->tm_year + 1900);
    month = convertIntToString(now->tm_mon + 1);
    day = convertIntToString(now->tm_mday);

    currentDate.push_back(convertStringToInt(year));
    currentDate.push_back(convertStringToInt(month));
    currentDate.push_back(convertStringToInt(day));

    if (month.length() == 1 )
    {
        month = addLeadingZero (month);
    }

    if (day.length() == 1)
    {
        day = addLeadingZero (day);
    }

    formatedCurrentDate = year + "-" + month + "-" + day;
}

void DateChecker::divideGivenDateIntoThreeNumbers (string givenDate, vector <int> &givenDateMembers)
{
    string temp;
    int convertedMember;

    for (int i = 0; i < givenDate.size(); i++)
    {
        if ((givenDate[i] >= '0') && (givenDate[i] <= '9'))
        {
            temp += givenDate[i];
        }
        else
        {
            convertedMember = convertStringToInt(temp);
            givenDateMembers.push_back(convertedMember);
            temp = "";
        }
    }
    convertedMember = convertStringToInt(temp);
    givenDateMembers.push_back(convertedMember);
}

bool DateChecker::isLeap(int year)
{
    return (((year%4 == 0) && (year%100 != 0)) ||(year%400 == 0));
}

bool DateChecker::checkIfDateIsValid(vector <int> givenDateMembers, vector <int> currentDateMembers)
{
    int year = givenDateMembers[0];
    int month = givenDateMembers[1];
    int day = givenDateMembers[2];

    if (year > currentDateMembers[0] || year < 2000)
    {
        return false;
    }

    if (year == currentDateMembers[0] && month > currentDateMembers[1])
    {
        return false;
    }

    if (month < 1 || month > 12)
    {
        return false;
    }

    if (day < 1 || day > 31)
    {
        return false;
    }

    if (month == 2)
    {
        if (isLeap(year))
        {
            return (day <= 29);
        }
        else
        {
            return (day <= 28);
        }
    }


    if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        return (day <= 30);
    }

    return true;
}

bool DateChecker::checkDateFormat (string givenDate)
{
    regex pattern("\\d{4}-((\\d{1})|(\\d{2}))-((\\d{1})|(\\d{2}))");

    if( regex_match(givenDate, pattern))
    {
        cout << "date format is correct" << endl;
        return true;
    }
    else
    {
        cout << "date format is incorrect" << endl;
        return false;
    }

}
bool DateChecker::checkDate (string &date, vector<int> currentDate)
{
    string day, month, year;
    vector<int> givenDateMembers;

    if (!checkDateFormat(date))
    {

        return false;
    }
    divideGivenDateIntoThreeNumbers(date, givenDateMembers);

    year = convertIntToString(givenDateMembers[0]);
    month = convertIntToString(givenDateMembers[1]);
    day = convertIntToString(givenDateMembers[2]);

    if (month.length() == 1 )
    {
        month = addLeadingZero (month);
    }

    if (day.length() == 1)
    {
        day = addLeadingZero (day);
    }

    date = year + "-" + month + "-" + day;

    if (!checkIfDateIsValid(givenDateMembers, currentDate))
    {
       cout << "date is not valid" <<endl;
        return false;
    }
    return true;
}

string DateChecker::getFormattedCurrentDate()
{
    return formatedCurrentDate;
}

vector <int> DateChecker::getCurrentDate()
{
    return currentDate;
}
/*
int main()
{
    vector <int> currentDate;
    string date;
   cout << "Current date: " << showCurrentDate(currentDate);

    do
    {
        cout << endl << endl << "Type date (YYYY-MM-DD): ";
        cin >> date;
    }
    while (!checkDate (date, currentDate));





    return 0;
}
*/
