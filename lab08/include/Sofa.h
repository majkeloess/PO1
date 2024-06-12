#ifndef SOFA_H
#define SOFA_H

#include "Mebel.h"

//klasa pochodna Sofa dziedziczy po Meblu bo jest Meblem
class Sofa : public Mebel {
protected:
  //Sofa oprocz posiadania wymaiarow ma jeszcze siedzisko
  int m_siedzisko{};
public:
  //konstruktor Sofa
  Sofa(int sz, int wys, int dl, int siedzisko);
  friend std::ostream &operator<<(std::ostream &out, const Sofa &s);
  
  //destruktor Sofa
  ~Sofa();
};


#endif