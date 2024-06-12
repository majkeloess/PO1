#ifndef SHOPPINGBASKET_H
#define SHOPPINGBASKET_H

#include "Item.h"
#include "ClothingItem.h"
#include "ElectronicsItem.h"
#include "GroceryItem.h"
#include <vector>
#include <algorithm>

//Koszyk na przedmioty 
class ShoppingBasket {
protected:  
  std::vector <Item*> bas {};


public:
  ShoppingBasket() = default;
  
  //tworzenie nowego przedmiotu na koncu koszyka
  template <typename T>
  void addItem(const T&item)
  {
    bas.emplace_back(new T(item));
  }
  
  //printowanie koszyka za pomoca przeladowanego operatora <<
  void displayItems()
  {
    for(size_t i = 0; i < bas.size(); i++)
    {
      std::cout << *(bas[i]);
    }
  }
  
  //cena totalna calego koszyka
  double getTotalPrice()
  {
    double sum = 0;
    for(size_t i = 0; i < bas.size(); i++)
    {
      sum += bas[i]->getPrice();
    }
    return sum;

  }
  //sortowanie po nazwie
  void sortByName()
  {
    std::sort(bas.begin(), bas.end(), [](Item *i1, Item *i2)
    { 
      return i1->getName() < i2->getName(); 
    });
  }


  //sortowanie po cenie
  void sortByPrice()
  {
    std::sort(bas.begin(), bas.end(), [](Item *i1, Item *i2)
    { 
      return i1->getPrice() < i2->getPrice(); 
    });
  }
  
  //destruktor koszyka
  ~ShoppingBasket(){}

};


#endif
