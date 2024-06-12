#include <iostream>
#include <vector>
#include <array>
#include <string>
#include "Histogram.h"


//Series
Series::Series() = default;
Series::~Series() 
{
  std::cout << "Destruktor klasy series" << std::endl;
}

double Series::getSeries(int index)
{
  return m_series[index];
}

// Series::Series(const Series &&ser)
// {
//   std::cout << "Konstruktor przenoszacy klasy Series" << std::endl;
//   for(int i=0; i < m_series.size(); i++)
//   {
//     m_series = ser.m_series;
//   }
// }

// Series::Series(const Series &ser)
// {
//   std::cout << "Konstruktor kopiujacy klasy Series" << std::endl;
//   for(int i=0; i < m_series.size(); i++)
//   {
//     m_series = ser.m_series;
//   }
// }

 Series &Series::operator=(const Series &ser)
 {
  std::cout << "Przenoszacy operator przypisania klasy Series" << std::endl;
  for(int i=0; i < m_series.size(); i++)
  {
    m_series = ser.m_series;
  }
  return *this;
 }



Series::Series(const std::string &str, int val)
{
  for(int i=0; i < val; i++)
  {
    m_series.push_back(0.0);
  }
  m_name.push_back(str);


}

std::vector<double> Series::get_series_view(std::function<bool(double)> fun)
{
  std::vector<double> ret_vec;
  for(int i=0; i < m_series.size();i++)
  {
    if(fun(m_series[i]))
    {
      ret_vec.push_back(m_series[i]);
    }
  }

  return ret_vec;
}


void Series::append(double val)
{
  m_series.push_back(val);
}

double& Series::operator[](int index)
{
  return m_series[index];
}

const double Series::operator[](size_t index) const
{
  return m_series[index];
}

Series& Series::operator+=(const Series& s)
{
  
  for (int i =0 ; i < s.m_series.size(); i++)
  {
    m_series[i] += s.m_series[i];
  }

  return *this;
}

std::ostream& operator<<(std::ostream &out, const Series &s)
{ 
  int i;
  out << "[";
  for(i=0; i < s.m_series.size()-1; i++)
  {
    out << s.m_series[i] <<", ";
  }
  out << s.m_series[i];
  out << "]";
  out << std::endl;
  return out;
}


//Histo
Histogram::Histogram() = default;

Histogram::~Histogram()
{
  std::cout << "Destruktor klasy histogram" << std::endl;
}


void Histogram::add_series(const std::string &str)
{
  m_map[str] = {};
}
const std::vector<std::string> Histogram::get_series_names() const
{
  std::vector<std::string> vec;
  return vec;
}


Series& Histogram::operator[](const std::string& str)
{
  return m_map[str];
}

double &Histogram::operator()(std::string name, int row)
{
  return  m_map[name][row];
}