#include "Trojkat.h"

Trojkat::Trojkat(double a, double b, double c)
  : m_a{a}, m_b{b}, m_c{c}
  {}


double Trojkat::obliczObwod () const   {
  return m_a+m_b+m_c;
}
double Trojkat::obliczPole () const  {
  double x = (m_a+m_b+m_c)/2;
  return sqrt(x*(x-m_a)*(x-m_b)*(x-m_c));
}
void Trojkat::wypisz (std::ostream &out) const  {
  out << "Trojkat a=" << m_a << ", b=" << m_b <<  ", c=" << m_c << ", Pole: " << obliczPole() << ", Obwod : " << obliczObwod();
}