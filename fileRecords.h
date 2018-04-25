#include <iostream>
#include <vector>
#include "Record.h"
#include "dateChecker.h"

using namespace std;

class FileRecords
{

public:

    void updateRecordsDataBase(Record, string, string);
    int findCurrentRecordId(string);
    vector <Record> readRecordsFromFile(vector <int>, vector <int>, string, int, bool);
    string pathXML;
    string getXMLPath();

private:

    bool checkIfDateIsInsideRange(string, vector <int>, vector <int>, bool);
    DateChecker dateChecker;
    bool calculateDays (vector <int>, vector <int>, vector <int>);

};
