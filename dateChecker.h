#include <iostream>

using namespace std;

class DateChecker //: public Converters
{
  public:

     void checkCurrentDate();
     bool checkDate (string &, vector<int>);
     string getFormattedCurrentDate();
     vector <int> getCurrentDate();

  private:
    vector <int> currentDate;
    string formatedCurrentDate;
    string convertIntToString(int);
    int convertStringToInt (string);
    string addLeadingZero(string);
    void divideGivenDateIntoThreeNumbers (string, vector <int>&);
    bool isLeap(int);
    bool checkIfDateIsValid(vector <int>, vector <int>);
    bool checkDateFormat (string);
};
