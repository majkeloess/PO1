#ifndef VECTOR3D_H
#define VECTOR3D_H

#include <iostream>
#include <initializer_list>
#include "WrongS.h"

class Vector3d
{
private:
  double *m_vector{};
  size_t m_size{};

public:
  Vector3d() = default;
  Vector3d(std::initializer_list<double> vec);
  Vector3d(const Vector3d &v);
  Vector3d(double *array, size_t size);
  Vector3d(Vector3d &&v) noexcept;
  double *get_m_vector() const;
  size_t get_size() const;

  ~Vector3d();

  Vector3d &operator=(const Vector3d &v);
  Vector3d &operator=(Vector3d &&v) noexcept;
  friend Vector3d operator+(const Vector3d &v1, const Vector3d &v2);
  friend std::ostream &operator<<(std::ostream &out, const Vector3d &v);
  double &operator[](size_t index);
  const double &operator[](size_t index) const;


  friend Vector3d operator^(const Vector3d &v1, const Vector3d &v2);
  friend double operator*(const Vector3d &v1, const Vector3d &v2);


};

#endif