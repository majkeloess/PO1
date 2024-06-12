#include "Mebel.h"

Mebel::Mebel(int sz, int wys, int dl)
  :m_sz{sz}, m_wys{wys}, m_dl{dl}
{}

std::ostream &operator<<(std::ostream &out, const Mebel &m)
{
  out <<  "Mebel: " << m.m_sz << ", " << m.m_wys << ", " << m.m_dl << std::endl; 
  return out;
}

Mebel::~Mebel()
{
  std::cout << "~Mebel\n";
}