#include <iostream>
#include <vector>
#include "Record.h"
//#include "converters.h"

using namespace std;

class FileRecords //: public Converters
{

    public:

   // vector <Record> readRecordsFromFile();
    void updateRecordsDataBase(Record, string);
    int findCurrentRecordId(string);
    string getXMLPath();
    private:
    string pathXML;
    //virtual string convertIntToString (int);

};
