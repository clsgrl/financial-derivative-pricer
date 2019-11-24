#include "Option.h"

Option::Option(double _K, double _r, double _T, PayOff* _payoff) :
  K(_K), r(_r), payoff(_payoff) {}

Option::~Option() {}

