#include <iostream>

using namespace std;

class AmountChecker //: public Converters
{
  public:
    bool checkAmount(string, float &);

  private:
    bool isPositive (float);
 float convertAmountToDouble(string);

};
