#ifndef GROCERYITEM_H
#define GROCERYITEM_H

#include "Item.h"


//Produkt spozywczy
class GroceryItem : virtual public Item {

public:
  GroceryItem(const std::string &name, double price)
    : Item{name, price}
  {
  }

std::ostream &print(std::ostream &out) const override
{
  out << "Produkt spożywczy: " << m_name << ", Cena: zł " << m_price << std::endl;
  return out;
}

virtual ~GroceryItem()
{}
};

#endif