#ifndef LOZKO_H
#define LOZKO_H

#include "Mebel.h"


//klasa pochodna Lozko dziedziczy wymiary po klasy Mebel, oprocz 3 wymiarow ma jeszcze powierzchnie do spania
class Lozko : public Mebel {
protected:
  int m_spanie{};
public:
  //konstruktor Lozko
  Lozko(int sz, int wys, int dl, int spanie);

  //operator wypisywania Lozko
  friend std::ostream &operator<<(std::ostream &out, const Lozko &l);
  
  //destruktor Lozko
  ~Lozko();
};


#endif