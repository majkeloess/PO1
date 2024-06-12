//Jest to nasz ostatni program na ocenę, zatem wykorzystamy cały poznany arsenał umiejętności, w tym stosowanie:
//-dziedziczenia,
//-polimorfizmu,
//-szablonów metod i ich specjalizacji,
//-kontenerów, iteratorów i algorytmów STL (nie używamy standardowych instrukcji sterujących).
//
//Co należy zrobić ?
//Zaimplementuj klasy GroceryItem, ElectronicsItem, ClothingItem właściwie identyfikując relacje między nimi.
//Zaimplementuj klasę ShoppingBasket będącą modelem koszyka na zakupy. Jego motoda addItem powinna być szablonowa z odpowiednimi
//specjalizacjami.
//Z użyciem wyżej wymienionych klas zaimplementuj poniższe operacje.

#include <iostream>
#include "Item.h"
#include "ShoppingBasket.h"
#include "ClothingItem.h"

int main() {
    ShoppingBasket basket;

    //  Dodawanie różnych produktów z użyciem metody szablonowej
    basket.addItem(GroceryItem("Jabłko", 0.99));
    basket.addItem(GroceryItem("Banan", 0.59));
    basket.addItem(ElectronicsItem("Smartfon", 699.99, 24));  // 24 miesiące gwarancji
    basket.addItem(ClothingItem("T-Shirt", 19.99, "L"));

    std::cout << "Produkty w koszyku:" << std::endl;
    basket.displayItems();

    std::cout << "Cena całkowita: zł " << basket.getTotalPrice() << std::endl;

    std::cout << "\nProdukty posortowane po nazwie:" << std::endl;
    basket.sortByName();
    basket.displayItems();

    std::cout << "\nProdukty posortowane po cenie:" << std::endl;
    basket.sortByPrice();
    basket.displayItems();

    return 0;
}

//Produkty w koszyku:
//Produkt spożywczy: Jabłko, Cena: zł 0.99
//Produkt spożywczy: Banan, Cena: zł 0.59
//Produkt elektroniczny: Smartfon, Cena: zł 699.99, Gwarancja: 24 miesiące
//Odzież: T-Shirt, Cena: zł 19.99, Rozmiar: L
//Cena całkowita: zł 721.56
//
//Produkty posortowane po nazwie:
//Produkt spożywczy: Banan, Cena: zł 0.59
//Produkt spożywczy: Jabłko, Cena: zł 0.99
//Produkt elektroniczny: Smartfon, Cena: zł 699.99, Gwarancja: 24 miesiące
//Odzież: T-Shirt, Cena: zł 19.99, Rozmiar: L
//
//Produkty posortowane po cenie:
//Produkt spożywczy: Banan, Cena: zł 0.59
//Produkt spożywczy: Jabłko, Cena: zł 0.99
//Odzież: T-Shirt, Cena: zł 19.99, Rozmiar: L
//Produkt elektroniczny: Smartfon, Cena: zł 699.99, Gwarancja: 24 miesiące