#include <iostream>
#include <vector>
#include "record.h"
#include "fileRecords.h"


using namespace std;

class RecordsHandler
{

private:

    vector <Record> expenditures;
    vector <Record> incomes;
    FileRecords fileHandler;
    //DateHandler dateHandler;
    int newIncomeId;
    int newExpenditureId;

public:

    void addRecord(Record, int);
    RecordsHandler();

};
