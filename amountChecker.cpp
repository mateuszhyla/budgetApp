#include <iostream>
#include "amountChecker.h"
#include <stdlib.h>
#include <cstdlib>
#include <algorithm>
#include <string>


using namespace std;

bool AmountChecker::checkAmount(string givenAmount, float & convertedAmount)
{
    replace(givenAmount.begin(), givenAmount.end(), ',', '.');

    convertedAmount = convertAmountToDouble(givenAmount);

    if (isPositive(convertedAmount))
    {
        return true;
    }
    else
    {
        return false;
    }
}

float AmountChecker::convertAmountToDouble(string givenAmount)
{
    return atof(givenAmount.c_str());
}

bool AmountChecker::isPositive (float convertedAmount)
{
    if (convertedAmount > 0.00)
    {
        return true;
    }
    return false;
}
