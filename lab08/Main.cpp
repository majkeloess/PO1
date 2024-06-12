/* W zadaniu nalezy poprawnie odwzorowac zaleznosci dziedziczenia wielokrotnego między klasami.

   UWAGA: Klasa bazowa NIE dostarcza wspólnego interfejsu.
   UWAGA: Przemyśleć implementację operatora <<.
 */
#include <iostream>
#include "Mebel.h"
#include "Sofa.h"
#include "Lozko.h"
#include "Kanapa.h"



int main() {
  {
    Mebel m(100, 120, 150);
    std::cout << "jakis mebel " << m  << std::endl;
  }

  {
    Sofa* s = new Sofa(90, 100, 200, 180);
    Mebel *x  = s;  
    std::cout << "jakas sofa "  << *x << std::endl;
    delete x;
  }
  
  {
    Lozko* l = new Lozko(90, 100, 200, 190);
    const Mebel* x  = l;  
    std::cout << "king bed "  << *x << std::endl;
    delete x;
  }

  { // wykorzystanie własności wielokrotnego dziedziczenia
    Kanapa* k = new Kanapa( 80, 90, 220, 195, 200);
    Sofa* s = k;
    Lozko* l = k;
//    l = 0;
    
    std::cout << "kanapa z ikei " << *s << std::endl;    
    delete s;    
  }
  
}
/* wynik
jakis mebel Mebel: sz:100 wys:120 dl:150 
~Mebel
jakas sofa Sofa: Mebel: sz:90 wys:100 dl:200  siedzisko: 180
~Sofa
~Mebel
king bed Lozko: Mebel: sz:90 wys:100 dl:200  sz.spania: 190
~Lozko
~Mebel
kanapa z ikei jako Mebel: sz:80 wys:90 dl:220 
 jako Sofa: Mebel: sz:80 wys:90 dl:220  siedzisko: 195
 jako Lozko: Mebel: sz:80 wys:90 dl:220  sz.spania: 200
~Kanapa
~Lozko
~Sofa
~Mebel
   
 */