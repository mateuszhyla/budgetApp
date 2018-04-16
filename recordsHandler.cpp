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
    fileHandler.getXMLPath();
    newExpenditureId = fileHandler.findCurrentRecordId("expenditures");
    newIncomeId = fileHandler.findCurrentRecordId("incomes");
}

void RecordsHandler::addRecord(Record newRecord, int userId)
{

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
