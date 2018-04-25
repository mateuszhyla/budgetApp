#include <iostream>
#include <vector>
#include "Record.h"
#include "dateChecker.h"
//#include "converters.h"

using namespace std;

class FileRecords //: public Converters
{

    public:

    vector <Record> readRecordsFromFile(vector <int>, vector <int>, string, int, bool);
    void updateRecordsDataBase(Record, string, string);
    int findCurrentRecordId(string);
    string getXMLPath();
    string pathXML;

    private:

    bool checkIfDateIsInsideRange(string, vector <int>, vector <int>, bool);
    DateChecker dateChecker;
    bool calculateDays (vector <int>, vector <int>, vector <int>);
    //virtual string convertIntToString (int);

};
