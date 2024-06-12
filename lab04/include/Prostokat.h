#ifndef PROSTOKAT_H
#define PROSTOKAT_H
#include "Figura.h"

class Prostokat : public Figura {
private:

  //boki prostokata
  double m_a {}, m_b {};
public:

  //konstruktor prostokata
  Prostokat(double a, double b);

  //funkcja liczaca obwod trojkata
  double obliczObwod () const override;
  
  //funkcja liczaca pole prostokata
  double obliczPole () const override;

    //funkcja wypisujaca dane prostokata
  void wypisz (std::ostream &out) const override;

};

#endif