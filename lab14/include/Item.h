#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <iostream>

class Item{
protected:
  double m_price{};
  std::string m_name{};
public:
  Item(const std::string &name, double price)
    :m_name{name}, m_price{price}
  {
  }

  //funkcja print do przeladowanego operatora << 
  virtual std::ostream &print(std::ostream &out) const 
  {
    out << "Produkt" << std::endl;
    return out; 
  }

  //getter, m_name
  std::string getName() const 
  {
    return m_name;
  }

  //getter, m_price
  double getPrice() const
  {
    return m_price;
  }

  //virtualny destruktor item
  virtual ~Item()
  {
  }

  friend std::ostream &operator<<(std::ostream &out, const Item &i);

};


//funkcja printujaca na wyjscie klase Item oraz jej pochodne klasy 
std::ostream &operator<<(std::ostream &out, const Item &i)
{
  return i.print(out);
}

#endif