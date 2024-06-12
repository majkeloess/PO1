#ifndef ELECTRONICSITEM_H
#define ELECTRONICSITEM_H

#include "Item.h"


//Produkt elektroniczny
class ElectronicsItem : virtual public Item {
protected: 
int m_gwar {};
public:
  ElectronicsItem(const std::string &name, double price,int gwar)
    : Item{name, price}, m_gwar{gwar}
  {
  }


//zoverridowana funkcja print 
std::ostream &print(std::ostream &out) const override
{
  out << "Produkt elektroniczny: " << m_name << ", Cena: zł " << m_price <<  ", Gwarancja: " << m_gwar << std::endl;
  return out;
}

virtual ~ElectronicsItem()
{}
};



#endif