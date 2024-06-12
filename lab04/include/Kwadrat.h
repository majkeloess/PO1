#ifndef KWADRAT_H
#define KWADRAT_H
#include "Figura.h"

class Kwadrat : public Figura {
private:
  //bok kwadratu
  double m_a {};
public:
  //konstruktor kwadratu inicjalizujacy jego bok
  Kwadrat(double a);

  //funkcja liczaca obwod kwadratu
  double obliczObwod () const override;
  
  //funkcja liczacza pola kwadratu
  double obliczPole () const override;

  //funkcja wypisujaca dane kwadratu
  void wypisz (std::ostream &out) const override;

};

#endif