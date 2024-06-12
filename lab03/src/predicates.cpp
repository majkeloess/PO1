#include "predicates.h"
#include <iostream>

bool value_between_10_and_20(double val)
{
  if(val > 10 && val < 20)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

bool value_gt_10(double val)
{
  if(val < 10)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}