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
    void displaySummary(string, int);

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

};
