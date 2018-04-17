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

private:
    Record addRecordDetails();
    string dateWindow();
    vector <Record> expenditures;
    vector <Record> incomes;
    FileRecords fileHandler;
    DateChecker dateChecker;
    AmountChecker amountChecker;
    //DateHandler dateHandler;
    int newIncomeId;
    int newExpenditureId;

};
