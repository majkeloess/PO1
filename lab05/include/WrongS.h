#ifndef WRONGS_H
#define WRONGS_H

#include <iostream>
#include <stdexcept>

class WrongS : public std::runtime_error
{
public:
  WrongS();
};

#endif