#include "Kwadrat.h"

Kwadrat::Kwadrat(double a)
  : m_a{a}
  {}


double Kwadrat::obliczObwod () const   {
  return 4*m_a;
}
double Kwadrat::obliczPole () const  {
  return m_a*m_a;
}
void Kwadrat::wypisz (std::ostream &out) const  {
  out << "Kwadrat a=" << m_a << ", Pole: " << obliczPole() << ", Obwod : " << obliczObwod();
}