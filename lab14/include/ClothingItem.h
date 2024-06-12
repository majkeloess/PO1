#ifndef CLOTHINGITEM_H
#define CLOTHINGITEM_H

#include "Item.h"

//Odziez
class ClothingItem : virtual public Item {
protected: 
  std::string m_size {};
public:
  ClothingItem(const std::string &name, double price,const std::string &size)
    : Item{name, price}, m_size{size}
  {
  }

//zoverridowana funkcja print
std::ostream &print(std::ostream &out) const override
{
  out << "Odzież: " << m_name << ", Cena: zł " << m_price <<  ", Rozmiar: " << m_size << std::endl;
  return out;
}

virtual ~ClothingItem()
{}
};



#endif