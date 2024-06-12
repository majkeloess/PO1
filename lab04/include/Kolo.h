#ifndef KOLO_H
#define KOLO_H
#include "Figura.h"

class Kolo : public Figura {
private:

  //promien kola
  double m_r {};
public:

  //konstruktor kola z inicjalizacja promienia
  Kolo(double r);

  //funkcja licxzacza obwod kola
  double obliczObwod () const override;

  //funkcja liczaca pole kola
  double obliczPole () const override;

  //funkcja wypisujaca dane kola
  void wypisz (std::ostream &out) const override;

};

#endif