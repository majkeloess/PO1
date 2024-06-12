# Laboratoria z przedmiotu Programowanie Obiektowe 1

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

## LAB05

## LAB06

## LAB07

## LAB08

## LAB10

## LAB11

## LAB13

## LAB14
