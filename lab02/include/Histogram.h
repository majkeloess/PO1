#ifndef HISTOGRAM_H
#define HISTOGRAM_H

#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <unordered_map>
#include <string>

class Series {
private:
    std::vector<double> m_series {};

public:
    //defaultowy konstruktor Series
    Series();

    //destruktor Series
    ~Series();

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
};

#endif