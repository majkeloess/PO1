#include "Vector3d.h"

// KONSTRUKCJA

Vector3d::Vector3d(std::initializer_list<double> vec)
    : m_vector{new double[vec.size()]}, m_size{vec.size()}
{
  std::copy(vec.begin(), vec.end(), m_vector);
}

Vector3d::Vector3d(const Vector3d &v)
{
  std::cout << "COPY" << std::endl;
  m_size = v.m_size;
  m_vector = new double[m_size];
  for (size_t i = 0; i < m_size; i++)
    m_vector[i] = v.m_vector[i];
}

Vector3d::Vector3d(Vector3d &&v) noexcept
{
  std::cout << "MOVE" << std::endl;
  m_size = v.m_size;
  m_vector = v.m_vector;

  v.m_vector = nullptr;
  v.m_size = 0;
}

// OPERATORY

Vector3d &Vector3d::operator=(const Vector3d &v)
{
  if (this != &v)
  {

    m_size = v.m_size;
    m_vector = new double[m_size];
    for (size_t i = 0; i < m_size; i++)
      m_vector[i] = v.m_vector[i];
  }
  return *this;
}
Vector3d &Vector3d::operator=(Vector3d &&v) noexcept
{
  if (this != &v)
  {
    m_size = v.m_size;
    m_vector = v.m_vector;

    v.m_size = 0;
    v.m_vector = nullptr;
  }
  return *this;
}

Vector3d operator+(const Vector3d &v1, const Vector3d &v2)
{
  if (v1.m_size != v2.m_size)
    throw WrongS();

  Vector3d v3;
  v3.m_size = v1.m_size;
  v3.m_vector = new double[v3.m_size];

  for (size_t i = 0; i < v3.m_size; i++)
    v3.m_vector[i] = v1.m_vector[i] + v2.m_vector[i];

  return v3;
}

std::ostream &operator<<(std::ostream &out, const Vector3d &v)
{
  // out << "[";
  for (size_t i = 0; i < v.m_size; i++)
    out << v.m_vector[i] << "\t";
  // out << "]";
  return out;
}
const double &Vector3d::operator[](size_t index) const
{
  if (index >= m_size)
  {
    throw WrongS();
  }
  return m_vector[index];
}


double &Vector3d::operator[](size_t index)
{
  if (index >= m_size)
  {
    throw WrongS();
  }
  return m_vector[index];
}

size_t Vector3d::get_size() const
{
  return m_size;
}

double *Vector3d::get_m_vector() const
{
  return m_vector;
}

Vector3d::Vector3d(double *array, size_t size) : m_size(size), m_vector(new double[size])
{
  std::copy(array, array + size, m_vector);
}

// DESTRUKCJA

Vector3d::~Vector3d()
{
  delete[] m_vector;
  m_size = 0;
  m_vector = nullptr;
}



Vector3d operator^(const Vector3d &v1, const Vector3d &v2)
{
  Vector3d v3;
  v3.m_size = 3;
  v3.m_vector = new double[v3.m_size];

  v3[0] = v1[1]*v2[2] - v2[1]*v1[2]; 
  v3[1] = -(v1[0]*v2[2]-v1[2]*v2[0]);
  v3[2] = v1[0]*v2[1]-v1[1]*v2[0];


  return v3;

}
double operator*(const Vector3d &v1, const Vector3d &v2)
{
  double res =0.0;

  for (size_t i = 0; i < v1.m_size; i++)
  {
    res += v1[i] * v2[i];
  }

  return res;
}