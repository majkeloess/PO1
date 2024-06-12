#include "Lozko.h"

Lozko::Lozko(int sz, int wys, int dl, int spanie)
  : Mebel{sz, wys, dl}, m_spanie{spanie}
{}

std::ostream &operator<<(std::ostream &out, const Lozko &l)
{
  out << dynamic_cast<const Mebel&> (l) << ", " << l.m_spanie << std::endl;
  return out;
}


Lozko::~Lozko()
{
  std::cout << "~Lozko\n";
}