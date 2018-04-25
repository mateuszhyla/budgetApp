#include <iostream>
#include <vector>
#include "record.h"
#include "fileRecords.h"
#include "dateChecker.h"
#include "amountChecker.h"


using namespace std;

class RecordsHandler
{
public:

    void addRecord(int, string);
    RecordsHandler();
    void manageSummary(string, int);

private:
    Record addRecordDetails();
    string dateWindow();
    vector <Record> expenditures;
    vector <Record> incomes;
    FileRecords fileHandler;
    DateChecker dateChecker;
    AmountChecker amountChecker;
    int newIncomeId;
    int newExpenditureId;
    void askForSummaryDate(vector <int>&, vector <int>&);
    float calculateSum (vector <Record>);
    void displaySummary (vector <Record>, vector <Record>, float, float);
    void showConsoleTextInColor(string, int);
    string convertFloatToString(float);
};
