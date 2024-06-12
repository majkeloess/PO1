#include "Sofa.h"

Sofa::Sofa(int sz, int wys, int dl, int siedzisko)
  : Mebel{sz, wys, dl}, m_siedzisko{siedzisko}
{}

std::ostream &operator<<(std::ostream &out, const Sofa &s)
{
  out << dynamic_cast<const Mebel&> (s) << ", " << s.m_siedzisko << std::endl;

  return out;
}


Sofa::~Sofa()
{
  std::cout << "~Sofa\n";
}