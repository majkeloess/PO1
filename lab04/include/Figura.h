#ifndef FIGURA_H
#define FIGURA_H
#include <iostream>
#include <cmath>

class Figura {
public:
  //funkcja virtualna do liczenia obwodu
  virtual double obliczObwod () const = 0;
  
  //funkcja virtualna do liczenia pola
  virtual double obliczPole () const = 0;
  
  //funkcja virtualna do wypisywania
  virtual void wypisz (std::ostream &out) const = 0;

  //zaprzyjazniony operator ostream do wypisywania 
  friend std::ostream &operator<<(std::ostream &out, const Figura &f);
  
};



#endif