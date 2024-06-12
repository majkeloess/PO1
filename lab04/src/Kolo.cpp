#include "Kolo.h"

Kolo::Kolo(double r)
  : m_r{r}
  {}


double Kolo::obliczObwod () const   {
  return 2*m_r*M_PI;
}
double Kolo::obliczPole () const  {
  return M_PI*m_r*m_r;
}
void Kolo::wypisz (std::ostream &out) const  {
  out << "Kolo r=" << m_r << ", Pole: " << obliczPole() << ", Obwod : " << obliczObwod();
}