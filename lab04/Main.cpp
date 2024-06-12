// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal się,
// a wynik jego dzialania byl taki sam jak podany na końcu tego pliku.
//
//Szczegóły:
//Na podstawie outputu programu umieszczonego na dole pliku:
//1. Zidentyfikuj potrzebne klasy i ich hierarchię dziedziczenia (w tym klasy abstrakcyjne o ile
// takowe występują).
//2. W maksymalnym stopniu stosuj hermetyzację oraz zasadę "Do not repeat yourself", czyli dziedzicz i stosuj polimorfizm.
//Wskazówka: do obliczania pola trójkąta użyj wzoru x*(x-a)*(x-b)*(x-c), gdzie a, b, c to boki a x to obwód
// trójkąta

//Program (tylko kod źródłowy plus ewentualny skrypt kompilujący) należy
//umieścić w folderze i spakować przy pomocy zip lub tar.gz.
//Pamiętaj o dokumentacji.
//Powodzenia!
#include <iostream>

#include "Prostokat.h"
#include "Kwadrat.h"
#include "Kolo.h"
#include "Trojkat.h"

int main() {
    Prostokat p= Prostokat(1,2);
    Kwadrat kw=Kwadrat(3);
    Trojkat t=Trojkat(3,4,5);
    Kolo ko=Kolo(2);


    std::cout<<p<<std::endl;
    std::cout<<kw<<std::endl;
    std::cout<<t<<std::endl;
    std::cout<<ko<<std::endl;
}

//Prostokąt o bokach a=1.000000, b=2.000000, Pole: 2.000000, Obwód: 6.000000
//Kwadrat o boku a=3.000000, Pole: 9.000000, Obwód: 12.000000
//Trójkąt o bokach a=3.000000, b=4.000000,c =5.000000, Pole: 6.000000, Obwód: 12.000000
//Koło o promieniu 2.000000, Pole: 12.566371, Obwód: 12.566371