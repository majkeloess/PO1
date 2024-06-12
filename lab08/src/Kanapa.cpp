#include "Kanapa.h"

Kanapa::Kanapa(int sz, int wys, int dl, int siedzisko, int spanie)
  : Sofa{sz, wys, dl, siedzisko}, Lozko{sz, wys, dl, spanie}
{}


std::ostream &operator<<(std::ostream &out, const Kanapa &k)
{
  out << dynamic_cast<const Sofa&> (k) << ", " << k.m_siedzisko << std::endl;
  out << dynamic_cast<const Lozko&> (k) << ", " << k.m_spanie << std::endl;
  return out;
}

Kanapa::~Kanapa()
{
  std::cout << "~Kanapa\n";
}