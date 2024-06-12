# Laboratoria z przedmiotu Programowanie Obiektowe 1

Rozwiązania laboratoriów z Programowania Obiektowego w języku C++. Poniżej załączone są treści, które są odpowiednio `Main.cpp` dla każdego z laboratoriów. 
Maina nie wolno było edytować trzeba było dopisać odpowiednie pliki `.h` i `.cpp` oraz odpowiadające im klasy oraz funkcje.

W trakcie semestru przećwiczono:

1. Przeładowania operatorów
2. Dziedziczenie (zwykłe, wirtualne, wielokrotne)
3. Funkcje wirtualne (polimorfizm, klasy abstrakcyjne)
4. STL
5. Wyrażenia Lambda
6. Szablony
7. Kontenery (std::vector, std:: array, iteratory)
8. Wyjątki 

Foldery z odpowiadających im laboratoriów zawierają moje rozwiązania. Czasem brakowało czasu więc do wszystkich laboratoriów nie ma dokumentacji. 

## LAB01

```cpp

//Zaimplementuj klasę wektora Iwektor3D liczb typu int o rozmiarze 3, które wewnętrznie przechowywane są w postaci alokowanej dynamicznie tablicy (a nie std::vectora !) uwzględniając: konstruktory (w tym kopiujący), destruktor oraz następujące przeładowane operatory: operator przypisania, operatory + i - (dodawanie i odejmowanie wektorów), operator mnożenia przez liczbę całkowitą (powinien umożliwiać mnożenie z obu stron), operator mnożenia wektora przez wektor (iloczyn skalarny), operator [] (powinien umożliwiać zarówno pobieranie jak i ustawienie składowej wektora), jednoargumentowy operator - (zamiana na wektor przeciwny),<< wstawianie wektora do strumienia wyjściowego.
//
//Następnie zainicjuj dwa wektory:
//v1=(2,2,2) i v2=(1,1,1)
//i wypisz na standardowe wyjście wynik następujących operacji (w tej kolejności !):

int main()
{

  Vector v1 = {2, 2, 2};
  Vector v2 = {1, 1, 1};

  std::cout << v1 + v2 << std::endl;
  std::cout << v1 - v2 << std::endl;
  std::cout << v1 * 2 << std::endl;
  std::cout << 2 * v1 << std::endl;
  std::cout << v1 * v2 << std::endl;
  std::cout << (v1[0] == ((v2[0]) = (2 * v2[0]))) << std::endl;
  std::cout << (v1[0] != ((v2[0]) = (2 * v2[0]))) << std::endl;
  std::cout << -v2 << std::endl;

  return 0;
}
```

## LAB02

```cpp
// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal się,
// a wynik jego dzialania byl taki sam jak podany na końcu tego pliku.
//
//Szczegóły:
//W tym zadaniu zaprogramujemy operatory indeksowania [] działające na indeksach całkowitych i typu string.
//Zaprogramuj klasę do operowania na histogramach. Histogram będzie zbiorem obiektów klasy Series mających nazwę
//i zawierających dynamicznie alokowaną tablicę wartości double.
//Do pustego histogramu hist dodajemy serię metodą hist.add_series("nazwa"). Z kolei do serii w histogramie
//dodajemy wiersz metodą hist["nazwa"].apppend(3.1415). Wreszcie, wartość konkretnego wiersza możemy zmodyfikować np.
//wywołaniem hist["nazwa"][3]=2.71 i pobrać np. wywołaniem double x=hist["nazwa"][3]. Ponadto dla obiektów Series
//zaimplementuj operator += umożliwiający dodawanie do siebie zawartości obiektów Series w zaktesie elementów ograniczonym
//mniejszą z nich, tzn. min(hist["seria1"].size(),hist["seria2"].size()).
//Próby sięgania poza zakres Serii lub wierszy powinny się kończyć wyrzuceniem odpowiednich wyjątków. W oparciu o
//pliki nagłówkowe Histogram.h i Series.h zaprogramuj odpowiednie klasy i wykonaj ciąg poniższych operacji tak by uzyskać podany niżej wynik.

//Program (tylko kod źródłowy plus ewentualny skrypt kompilujący) należy umieścić w folderze i spakować przy pomocy zip lub tar.gz.
//Pamiętaj o dokumentacji.
//Powodzenia!

#include "Histogram.h"

int main(int argc, const char * argv[]) {
    // insert code here...
//    std::cout<<"Test"<<std::endl;
    Histogram h1=Histogram();
    h1.add_series("liczby dodatnie");
    h1["liczby dodatnie"].append(10.5);
    h1["liczby dodatnie"].append(11.5);
    h1["liczby dodatnie"].append(12.5);
    std::cout<<"Seria dodatnia"<<std::endl;
    std::cout<<h1["liczby dodatnie"]<<std::endl;

    h1.add_series("liczby ujemne");
    h1["liczby ujemne"].append(-10.5);
    h1["liczby ujemne"].append(-11.5);
    h1["liczby ujemne"].append(-12.5);
    std::cout<<"Seria ujemna"<<std::endl;
    std::cout<<h1["liczby ujemne"]<<std::endl;
    std::cout<<"Ustawiam pierwszy element ujemnych na -10.5"<<std::endl;
    h1["liczby ujemne"][1]=-10.5;


    std::cout<<"Seria dodatnia"<<std::endl;
    std::cout<<h1["liczby dodatnie"]<<std::endl;
    std::cout<<"Seria ujemna"<<std::endl;
    std::cout<<h1["liczby ujemne"]<<std::endl;
    std::cout<<"Nagłówki serii:"<<std::endl;
    for(auto x: h1.get_series_names())
        std::cout<<x<<std::endl;
    std::cout<<"Dodaję serię ujemną do dodatniej"<<std::endl;
    h1["liczby dodatnie"]+=h1["liczby ujemne"];
    std::cout<<h1["liczby dodatnie"]<<std::endl;
    std::cout<<"Dodaję serię dodatnią do ujemnej"<<std::endl;
    h1["liczby ujemne"]+=h1["liczby dodatnie"];
    std::cout<<h1["liczby ujemne"]<<std::endl;
    return 0;
}
/* ---Program powinie
 Konstruktor klasy Histogram
 Kopiujący operator przypisania klasy Series
 Destruktor klasy Series
 Seria dodatnia
 [10.5,11.5,12.5]
 Kopiujący operator przypisania klasy Series
 Kopiujący operator przypisania klasy Series
 Destruktor klasy Series
 Destruktor klasy Series
 Seria ujemna
 [-10.5,-11.5,-12.5]
 Ustawiam pierwszy element ujemnych na -10.5
 Seria dodatnia
 [10.5,11.5,12.5]
 Seria ujemna
 [-10.5,-10.5,-12.5]
 Nagłówki serii:
 liczby dodatnie
 liczby ujemne
 Dodaję serię ujemną do dodatniej
 [0,1,0]
 Dodaję serię dodatnią do ujemnej
 [-10.5,-9.5,-12.5]
 Destruktor klasy Histogram
 Destruktor klasy Series
 Destruktor klasy Series
 */
```

## LAB03

```cpp
//Prosze dopisac kod, w razie potrzeby dodac nowe pliki, tak aby program wykonywal się,
// a wynik jego dzialania byl taki sam jak podany na końcu tego pliku. Proszę nie modyfikować pliku main.cpp !
//
//Rozwijamy kod napisany na ostatnich zajęciach.
//
//Szczegóły:
//1. Uzupełnij klasę Series o konstruktor przenoszący i przypisanie przenoszące (oba w wersji głośnej).
//2. Operator << klasy Series przepisz tak by wypisywał: "nazwa serii: [wartości w wierszach]."
//3. Klasę Histogram uzupełnij o operator()(string name,unsigned row) umożliwiający dostęp (odczyt i zapis) do dowolnego wiersza w dowolnej Serii (tradycyjnie sięganie poza zakres ma się kończyć wyjątkiem).
//4. Klasę Series uzupełnij o metodę vector<double> get_series_view(function<bool(double)>) przyjmującą jako parametr predykat (czyli obiekt klasy function<bool(double)>) i zwracającą vector elementów, dla których predykat jest prawdziwy. Działanie przetestuj na dwóch warunkach:
//    - elementy serii >10
//    - elementy serii >10 i <20.

#include <iostream>
#include "Histogram.h"
#include "predicates.h"

int main(int argc, const char * argv[]) {

    Series s1=Series("Test",2);
    s1[0]=1.2;
    s1[1]=1.3;
    std::cout<<s1<<"\n";
    Series s2=std::move(s1);
    std::cout<<s2<<"\n";
    Series s3;
    s3=std::move(s2);
    s3.append(12);
    s3.append(13);
    s3.append(22);
    std::cout<<s3<<"\n";
    std::cout<<"------------------\n";

    Histogram h1=Histogram();
    h1.add_series("liczby dodatnie");
    h1["liczby dodatnie"].append(1.5);
    h1["liczby dodatnie"].append(11.5);
    h1["liczby dodatnie"].append(12.5);
    std::cout<<h1["liczby dodatnie"]<<"\n";
    h1("liczby dodatnie",2)=22.5;
    std::cout<<h1["liczby dodatnie"]<<"\n";
    h1["liczby dodatnie"].append(22.5);
    h1["liczby dodatnie"].append(32.5);
    h1["liczby dodatnie"].append(17.5);
    std::cout<<h1("liczby dodatnie",4)<<"\n";

    std::cout<<"-------------------\n";
    std::vector<double> gt10=h1["liczby dodatnie"].get_series_view(value_gt_10);
    std::vector<double> btwn10and20=h1["liczby dodatnie"].get_series_view(value_between_10_and_20);
    std::cout<<">10\n";
    for(auto x: gt10)
        std::cout<<x<<"\n";
    std::cout<<">10 <20\n";
    for(auto x: btwn10and20)
        std::cout<<x<<"\n";
    return 0;
}

//Test: [1.2,1.3]
//Konstruktor przenoszący klasy Series
//Test: [1.2,1.3]
//Przenoszący operator przypisania klasy Series
//Test: [1.2,1.3,12,13,22]
//------------------
//Konstruktor klasy Histogram
//Przenoszący operator przypisania klasy Series
//Destruktor klasy Series
//liczby dodatnie: [1.5,11.5,12.5]
//liczby dodatnie: [1.5,11.5,22.5]
//32.5
//-------------------
//>10
//11.5
//22.5
//22.5
//32.5
//17.5
//>10 <20
//11.5
//17.5
//Destruktor klasy Histogram
//Destruktor klasy Series
//Destruktor klasy Series
//Destruktor klasy Series
//Destruktor klasy Series
//Program ended with exit code: 0

```

## LAB04

```cpp
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
```

## LAB05

```cpp
//Proszę nie modyfikować pliku main. Jeśli nazwy Państwa klas są inne to proszę użyć słowa kluczowego typedef by uzgodnić nazwy.
//
//Zaprogramowane wcześniej klasy reprezentujące n-wymiarowe wektory i macierze uzupełnij o metody/operatory umożliwiające
//wykonanie poniższych operacji. Na podstawie klasy n-wymiarowego wektora stwórz klasę 3-wymiarowego wektora wzbogaconą o operator
//obliczania iloczynu wektorowego, oznaczonego poniżej symbolem ^.
//Poprawna implementacja powinna prowadzić do outputu takiego jak ten zamieszczony poniżej.

#include <iostream>
#include "Vector.h"
#include "Matrix.h"
#include "Vector3d.h"

int main() {

    Matrix a1 {{1.,2.,3.},{2.,3.,4.},{4.,0.,6.}};
    std::cout<<"a1:\n"<<a1<<std::endl;
    Matrix a2 {{1.,1.,1.},{1.,0.,1.},{1.,1.,1.}};
    std::cout<<"a2:\n"<<a2<<std::endl;

    std::cout<<"a1+a2:\n"<<a1+a2<<std::endl;
    std::cout<<"a1*a2:\n"<<a1*a2<<std::endl;

    std::cout<<"Ślad: "<<(a1*a2).trace()<<std::endl;
    std::cout<<"Ślad: "<<(a2*a1).trace()<<std::endl;
    a2[1][1]=1;
    std::cout<<"a2:\n"<<a2<<std::endl;

    Vector v0 {1,2,3,4,5,5,6,6,7,8,8};
    std::cout<<"v0: "<<v0<<std::endl;
    Vector v1 {1.,2.,3.};
    std::cout<<"v1: "<<v1<<std::endl;
    //std::cout<<"a2*v1: "<<a2*v1<<std::endl;
    Vector v2 {1.,2.,0.};

    Vector3d d1 {1.,2.,3.};
    Vector3d d2 {1.,2.,0.};
    std::cout<<"(d1xd2): "<<(d1^d2)<<std::endl;
    std::cout<<"(d1xd2)*d1: "<<(d1^d2)*d1<<std::endl;
    std::cout<<"(d1xd2)*d2: "<<(d1^d2)*d2<<std::endl;
    return 0;
}

//a1:
//[[1,2,3],
//[2,3,4],
//[4,0,6]]
//a2:
//[[1,1,1],
//[1,0,1],
//[1,1,1]]
//a1+a2:
//[[2,3,4],
//[3,3,5],
//[5,1,7]]
//a1*a2:
//[[9,6,9],
//[11,8,11],
//[13,12,13]]
//Ślad: 30
//Ślad: 30
//a2:

//[[1,1,1],
//[1,1,1],
//[1,1,1]]
//v1: [1,2,3]

//v0: [1,2,3,4,5,5,6,6,7,8,8]

//a2*v1: [6,6,6]
//(d1xd2): [-6,3,0]
//(d1xd2)*d1: 0
//(d1xd2)*d2: 0


```

## LAB06

```cpp
/* Celem zadania jest odnalezienie hierarchi klas.
   To znaczy nalezy znalezc "czesc wspolna" pewnych obiektow, ktore wystepuja w temacie.
   W szczegolnosci w rozwiazaniu moga wystapic tylko dwie implementacje funkcji eval.

   UWAGA: Prosze zwrocic uwage na argumentowosc operacji logicznych.
   UWAGA: Prosze pamietac ze zachowanie polimorficzne wystepuje tylko z & lub *

 */

#include <iostream>
#include "Logical.h"

void p2(const TwoArg& op) {
  std::cout << "p2  " <<  op.result(true, false) << std::endl;
}

int main() {
  std::cout << "OR   " <<  Logical::eval( OR(), false, false ) << std::endl;
  std::cout << "OR   " <<  Logical::eval( OR(), false, true ) << std::endl;
  std::cout << "AND  " <<  Logical::eval( AND(), false, false ) << std::endl;
  std::cout << "XOR  " <<  Logical::eval( XOR(), true, true ) << std::endl;
  std::cout << "NOT  " <<  Logical::eval( NOT(), false) << std::endl;
  std::cout << "AND  " <<  Logical::eval( AND(), false, Logical::eval(NOT(), false) ) << std::endl;
  std::cout << "AND  " <<  Logical::eval( AND(), Logical::eval(OR(), true, false ), true ) << std::endl;

  p2( OR() );
  p2( AND() );
  p2(XOR());
}
/* wynik
OR   0
OR   1
AND  0
XOR  0
NOT  1
AND  0
AND  1
p2  1
p2  0
p2  1
 */
```

## LAB07

```cpp
/* Celem zadania jest odnalezienie hierarchi klas i wykorzystanie odpowiedniego sposobu rzutowania
 * dla klas polimorficznych.
 * Należy wykonać tylko dwa rzutowania.
 */
#include <iostream>
#include "Widgets.h"
#include <vector>
int main() {

    std::vector<Widget*> widgets;
    widgets.push_back(new Button());
    widgets.push_back(new EditBox());
    widgets.push_back(new RadioButton());
    widgets.push_back(new MaskedEditBox());
    for (auto x: widgets)
        std::cout<<x->widgetDescription()<<std::endl;

    (new WidgetPainter())->paintWidgets(widgets);

    for (auto x: widgets)
         std::cout<<x->widgetDescription()<<std::endl;
     return 0;
}
//Wynik:
//gray button
//gray editbox
//gray radiobutton
//gray maskededitbox

//blue button
//red editbox
//blue radiobutton
//red maskededitbox


```

## LAB08

```cpp
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

```

## LAB10

```cpp
//Zaimplementuj algorytm sortowania szybkiego z procedurami partycjonującymi Lomuto i Hoare. Odpowiednie pseudokody
//znajdziesz na slajdach 21, 22 i 43 załączonego wykładu profesora Gawrońskiego.
//Obie wersje procedur partycjonujacych, jak również wykorzystywana przez nie procedura SWAP powinny być zaimplemenowane
//przy pomocy wyrażeń lambda.
//Ponadto powinny jednocześnie obsługiwać tablice int[] i double[]. Sama procedura QuickSort nie musi być wyrażeniem lambda.

//UWAGI:
//1. Może być potrzebne skorzystanie z RTTI.
//2. Do skompilowania fragmetów kodu wykorzystujących słowo kluczowe auto potrzebne jest C++ 20.

//Wynik działania podano poniżej

int main() {

    int tab1[]={8,7,5,3,2,6,1,4,9};
    int tab2[9];
    std::copy(&tab1[0],&tab1[0]+9,&tab2[0]);
    double tab3[]={2.3,1.4,6.5,0.3,1.1};
    double tab4[5];
    std::copy(&tab3[0],&tab3[0]+5,&tab4[0]);

    std::cout<<"QuickSort tablicy int z partycjonowaniem Lomuto:\n";
    std::cout<<"Przed: ";printArray(tab1,9);std::cout<<std::endl;
    QuickSort(tab1,0,8,lomutoPartition);
    std::cout<<"Po: ";printArray(tab1,9);std::cout<<std::endl;
    std::cout<<"QuickSort tablicy int z partycjonowaniem Hoare:\n";
    std::cout<<"Przed: ";printArray(tab2,9);std::cout<<std::endl;
    QuickSort(tab2,0,8,hoarePartition);
    std::cout<<"Po: ";printArray(tab2,9);std::cout<<std::endl;

    std::cout<<"QuickSort tablicy double z partycjonowaniem Lomuto:\n";
    std::cout<<"Przed: ";printArray(tab3,5);std::cout<<std::endl;
    QuickSort(tab3,0,4,lomutoPartition);
    std::cout<<"Po: ";printArray(tab3,5);std::cout<<std::endl;
    std::cout<<"QuickSort tablicy double z partycjonowaniem Hoare:\n";
    std::cout<<"Przed: ";printArray(tab4,5);std::cout<<std::endl;
    QuickSort(tab4,0,4,hoarePartition);
    std::cout<<"Po: ";printArray(tab4,5);std::cout<<std::endl;

    return 0;
}

```

## LAB11

```cpp
//Stwórz szablon funkcji mnożącej asynchronicznie (z użyciem std::async()) dwie macierze kwadratowe dowolnych rozmiarów.
//Macierze te są reprezentowane przez wektory wektorów.
//Każdy element macierzy wynikowej jest obliczany w oddzielnym wątku, którego zhaszowany identyfikator jest wypisywany na ekran,
// tak jak to pokazano na wydruku poniżej.
//
//Wskazówka:
//Do zhaszowania identyfikatora wątku użyj poniższych instrukcji:
//std::hash<std::thread::id> hasher;
//long id =hasher(std::this_thread::get_id());

#include "MatMulAsync.h"
#include <complex>
using std::complex;
using namespace std::complex_literals;
int main() {
    // Przykładowe macierze
    std::vector<std::vector<int>> matrix1 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    std::vector<std::vector<int>> matrix2 = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};

    // Mnożenie macierzy
    std::vector<std::vector<int>> result_int = multiplyMatrices(matrix1, matrix2);
    // Wyświetlanie wyniku
    std::cout << "Wynik mnożenia macierzy:" << std::endl;
    displayMatrix(result_int);

    std::vector<std::vector<double>> matrix3 = {{1., 0., 0.}, {0., 1., 0.}, {0., 0., 1.}};
    std::vector<std::vector<double>> matrix4 = {{9.1, 8.1, 7.1}, {6.1, 5.1, 4.1}, {3.1, 2.1, 1.1}};

    // Mnożenie macierzy
    std::vector<std::vector<double>> result_double = multiplyMatrices(matrix3, matrix4);
    // Wyświetlanie wyniku
    std::cout << "Wynik mnożenia macierzy:" << std::endl;
    displayMatrix(result_double);

    std::vector<std::vector<complex<double>>> matrix5 = {{0., -1i}, {1i, 0.}};
    std::vector<std::vector<complex<double>>> matrix6 = {{0., -1i}, {1i, 0.}};;

    // Mnożenie macierzy
    std::vector<std::vector<complex<double>>> result_complex = multiplyMatrices(matrix5, matrix6);
    // Wyświetlanie wyniku
    std::cout << "Wynik mnożenia macierzy:" << std::endl;
    displayMatrix(result_complex);

    return 0;
}

//Wątek -1643678212384661549 oblicza element (0,0)
//Wątek 1362080638672535051 oblicza element (2,1)
//Wątek 3734504096879222707 oblicza element (0,2)
//Wątek 7192468387369268874 oblicza element (2,2)
//Wątek 4615549267549480836 oblicza element (0,1)
//Wątek -5993321486016935974 oblicza element (1,1)
//Wątek 34040437824474923 oblicza element (2,0)
//Wątek 2612129187665001469 oblicza element (1,0)
//Wątek -866191707566161087 oblicza element (1,2)
//Wynik mnożenia macierzy:
//30 24 18
//84 69 54
//138 114 90
//Wątek -1643678212384661549 oblicza element (0,0)
//Wątek 4615549267549480836 oblicza element (0,1)
//Wątek 3734504096879222707 oblicza element (0,2)
//Wątek -1643678212384661549 oblicza element (1,0)
//Wątek 2612129187665001469 oblicza element (1,1)
//Wątek 4615549267549480836 oblicza element (1,2)
//Wątek 3734504096879222707 oblicza element (2,0)
//Wątek -1643678212384661549 oblicza element (2,1)
//Wątek -5993321486016935974 oblicza element (2,2)
//Wynik mnożenia macierzy:
//9.1 8.1 7.1
//6.1 5.1 4.1
//3.1 2.1 1.1
//Wątek -1643678212384661549 oblicza element (0,0)
//Wątek 3734504096879222707 oblicza element (0,1)
//Wątek -1643678212384661549 oblicza element (1,0)
//Wątek 4615549267549480836 oblicza element (1,1)
//Wynik mnożenia macierzy:
//(1,0) (0,0)
//(0,0) (1,0)


```

## LAB13

```cpp
//Z użyciem klas Book, BookManager oraz odpowiednich kontenerów zaprogramuj system do zarządzania
// kolekcją książek.
//W operacjach na kontenerach nie wolno wykorzystywać "ifów". Stosujemy wyłącznie iteratory i
// algorytmy STL.
#include "BookManager.h"

int main() {
    BookManager manager;
    manager.addBook("1984", "George Orwell", 1949, 19.84);
    manager.addBook("Brave New World", "Aldous Huxley", 1932, 15.99);
    manager.addBook("Fahrenheit 451", "Ray Bradbury", 1953, 18.99);

    std::cout << "All books:" << std::endl;
    manager.displayAllBooks();

    std::cout << "\nSorted by title:" << std::endl;
    manager.sortBooksByTitle();
    manager.displayAllBooks();

    std::cout << "\nFinding book by title '1984':" << std::endl;
    auto book = manager.findBookByTitle("1984");
    if (book) displayBook(*book);

    std::cout << "\nRemoving book '1984' and displaying all books:" << std::endl;
    manager.removeBook("1984");
    manager.displayAllBooks();

    return 0;
}

//All books:
//Title: 1984, Author: George Orwell, Year: 1949, Price: 19.84
//Title: Brave New World, Author: Aldous Huxley, Year: 1932, Price: 15.99
//Title: Fahrenheit 451, Author: Ray Bradbury, Year: 1953, Price: 18.99
//
//Sorted by title:
//Title: 1984, Author: George Orwell, Year: 1949, Price: 19.84
//Title: Brave New World, Author: Aldous Huxley, Year: 1932, Price: 15.99
//Title: Fahrenheit 451, Author: Ray Bradbury, Year: 1953, Price: 18.99
//
//Finding book by title '1984':
//Title: 1984, Author: George Orwell, Year: 1949, Price: 19.84
//
//Removing book '1984' and displaying all books:
//Title: Brave New World, Author: Aldous Huxley, Year: 1932, Price: 15.99
//Title: Fahrenheit 451, Author: Ray Bradbury, Year: 1953, Price: 18.99

```

## LAB14

```cpp
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

```
