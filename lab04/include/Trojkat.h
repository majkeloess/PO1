#ifndef TROJKAT_H
#define TROJKAT_H
#include "Figura.h"

class Trojkat : public Figura {
private:
  //boki trojkata
  double m_a {}, m_b {}, m_c{};
public:
  //konstruktor trojkata z bokami
  Trojkat(double a, double b, double c);
  
  //funkcja liczaca obwod trojkata
  double obliczObwod () const override;
  
  //funkcja liczacza pole trojkata
  double obliczPole () const override;
  
  //funkcja wypisujaca dane trojkata
  void wypisz (std::ostream &out) const override;

};

#endif