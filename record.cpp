#include <iostream>
#include "record.h"

using namespace std;

Record:: Record (int recordId, int recordUserId, string recordDate, string recordCategory, double recordAmount)
{
    id = recordId;
    userId = recordUserId;
    date = recordDate;
    category = recordCategory;
    amount = recordAmount;
}

void Record::setId(int recordId)
{
    id = recordId;
}

int Record::getId()
{
    return id;
}

void Record::setUserId(int recordUserId)
{
    userId = recordUserId;
}


int Record::getUserId()
{
    return userId;
}

void Record::setDate(string recorDate)
{
    date = recorDate;
}


string Record::getDate()
{
    return date;
}

void Record::setCategory(string recordCategory)
{
    category = recordCategory;
}


string Record::getCategory()
{
    return category;
}

void Record::setAmount(double recordAmount)
{
    amount = recordAmount;
}


double Record::getAmount()
{
    return amount;
}
