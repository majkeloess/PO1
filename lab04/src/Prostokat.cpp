#include "Prostokat.h"

Prostokat::Prostokat(double a, double b)
  : m_a{a}, m_b{b}
  {}


double Prostokat::obliczObwod () const   {
  return 2*(m_a+m_b);
}
double Prostokat::obliczPole () const  {
  return m_a*m_b;
}
void Prostokat::wypisz (std::ostream &out) const  {
  out << "Prostokat a=" << m_a << ", b=" << m_b << ", Pole: " << obliczPole() << ", Obwod : " << obliczObwod();
}