#ifndef MEBEL_H
#define MEBEL_H

#include <iostream>

//klasa bazowa Mebel, posiada wymiary
class Mebel {
protected:
  int m_sz{};
  int m_wys{};
  int m_dl{};
public:
  //konstruktor mebel
  Mebel(int sz, int wys, int dl);

  //operator wypisywania mebel
  friend std::ostream &operator<<(std::ostream &out, const Mebel &m);

  //destruktor mebel
  ~Mebel();
};






#endif