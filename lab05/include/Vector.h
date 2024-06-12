#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <initializer_list>
#include "WrongS.h"

class Vector
{
private:
  double *m_vector{};
  size_t m_size{};

public:
  Vector() = default;
  Vector(std::initializer_list<double> vec);
  Vector(const Vector &v);
  Vector(double *array, size_t size);
  Vector(Vector &&v) noexcept;
  double *get_m_vector() const;
  size_t get_size() const;

  ~Vector();

  Vector &operator=(const Vector &v);
  Vector &operator=(Vector &&v) noexcept;
  friend Vector operator+(const Vector &v1, const Vector &v2);
  friend std::ostream &operator<<(std::ostream &out, const Vector &v);
  double &operator[](size_t index);
  const double &operator[](size_t index) const;


  friend Vector operator^(const Vector &v1, const Vector &v2);
  friend double operator*(const Vector &v1, const Vector &v2);


};

#endif