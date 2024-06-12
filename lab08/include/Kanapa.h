#ifndef KANAPA_H
#define KANAPA_H
#include "Lozko.h"
#include "Sofa.h"


//klasa pochodna kanapa dziedziczy po Lozko oraz Sofie poniewaz moze byc jednoczesnie tym i tym
class Kanapa : public Sofa, public Lozko{
  public:
  //konstruktor Kanapa
  Kanapa(int sz, int wys, int dl, int siedzisko, int spanie);

  //operator wypisania kanapa
  friend std::ostream &operator<<(std::ostream &out, const Kanapa &k);
  
  //destruktor Kanapa
  ~Kanapa();
};

#endif