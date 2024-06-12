#ifndef HISTOGRAM_H
#define HISTOGRAM_H

#include <functional>
#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <unordered_map>
#include <string>

class Series {
private:
    std::vector<double> m_series {};
    std::vector<std::string> m_name {};
public:
    //defaultowy konstruktor Series
    Series();

    //destruktor Series
    ~Series();

    //accesor klasy Series, w tym przypadku getter
    double getSeries(int index);
    
    //konstruktor klasy Series, dzieki ktoremu nadajemy nazwe Serii oraz ilosc potrzebnych dla niej miejsc
    Series(const std::string &str, int val);

    //operator przypisania przenoszacy klasy Series
    Series &operator=(const Series &ser);
    

    //konstruktor przenoszacy klasy Series
    //Series(const Series &&ser);


    //konstruktor kopiujacy klasy Series
    //Series(const Series &ser);

    //dodaje wartosc do Series
    void append(double val);
    
    //przeciazenie operatora tablicowego Series
    double& operator[](int index);
    
    //przeciazenie operatora tablicowego Series
    const double operator[](size_t index) const;
    
    //przeciazenie operatora += dla Series
    Series& operator+=(const Series& s);
    
    //friendowanie operatora wypisywania
    friend std::ostream& operator<<(std::ostream& out, const Series& s);

    //funkcja zwracaja podzbior z wektora m_series, zeby zobaczyc jakies wlasciwosci, funkcja jako parametr uzywa std::function 
    std::vector<double> get_series_view(std::function<bool(double)>);
};


class Histogram {
  private:
    std::unordered_map<std::string, Series> m_map;

  public:
    //konstruktor defaulotwy Histogram
    Histogram();

    //destruktor Histogram
    ~Histogram();


    //dodawanie nowej serii
    void add_series(const std::string& str);
    
    //przeciazanie operatora tablicowego
    Series& operator[](const std::string& str);
    
    //wypisanie nazwy serii
    const std::vector<std::string> get_series_names() const;

    //przeladowanie operatora (), ktory zwraca referencje do konkretnej wartosci w series
    double &operator()(std::string name,int row);
};

#endif