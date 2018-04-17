#include <iostream>
#include <vector>
#include "Record.h"
//#include "converters.h"

using namespace std;

class FileRecords //: public Converters
{

    public:

   // vector <Record> readRecordsFromFile();
    void updateRecordsDataBase(Record, string, string);
    int findCurrentRecordId(string);
    string getXMLPath();
    string pathXML;
    private:

    //virtual string convertIntToString (int);

};
