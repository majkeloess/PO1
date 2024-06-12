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
  for(int i=0; i < s.m_series.size(); i++)
    out << s.m_series[i] << std::endl;
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

