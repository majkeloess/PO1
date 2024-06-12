#include "Figura.h"


std::ostream &operator<<(std::ostream &out, const Figura &f){

  f.wypisz(out);
  return out;
}

