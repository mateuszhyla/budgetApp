#include <iostream>
#pragma once
using namespace std;

class Record
{
private:
    int id;
    int userId;
    string date;
    string category;
    double amount;

public:
    Record (int = 0, int =0, string = "2000-01-01", string = "Unknown", double = 0.00);
    void setId(int);
    int getId();
    void setUserId(int);
    int getUserId();
    void setDate(string);
    string getDate();
    void setCategory(string);
    string getCategory();
    void setAmount(double);
    double getAmount();
};
