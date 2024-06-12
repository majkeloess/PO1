#include "Logical.h"

bool Logical::eval(const OneArg& op, bool val1) {
    return op(val1);
}

bool Logical::eval(const TwoArg& op, bool val1, bool val2) {
    return op.result(val1, val2);
}

bool NOT::operator()(bool val1) const
{
  return !val1;
}

bool OR::result(bool val1, bool val2) const
{
    return val1 || val2;
}

bool AND::result(bool val1, bool val2) const
{
    return val1 && val2;
}

bool XOR::result(bool val1, bool val2) const
{
    return val1 ^ val2;
}