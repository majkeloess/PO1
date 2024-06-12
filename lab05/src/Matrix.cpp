#include "Matrix.h"
#include <iostream>
#include <initializer_list>
#include "WrongS.h"

Matrix::Matrix(std::initializer_list<Vector> list)
    : m_row(list.size()), m_col(list.begin()->get_size())
{

  vct = new Vector[m_col];

  for (const auto &vec : list)
  {
    if (vec.get_size() != m_row)
    {
      throw WrongS();
    }
  }
  std::copy(list.begin(), list.end(), vct);
}

Matrix::Matrix(const Matrix &M)
    : m_row(M.m_row), m_col(M.m_col), vct(new Vector[M.m_row])
{
  std::cout << "COPY" << std::endl;
  for (size_t i = 0; i < m_row; ++i)
  {
    vct[i] = M.vct[i];
  }
}

Matrix::Matrix(Matrix &&M) noexcept
    : m_row{M.m_row}, m_col{M.m_col}, vct{M.vct}
{
  std::cout << "MOVE" << std::endl;
  M.vct = nullptr;
  M.m_row = 0;
  M.m_col = 0;
}

Matrix::~Matrix()
{
  delete[] vct;
  m_row = 0;
  m_col = 0;
  vct = nullptr;
}

Matrix &Matrix::operator=(const Matrix &M)
{
  if (this != &M)
  {
    delete[] vct;
    m_row = M.m_row;
    m_col = M.m_col;
    vct = new Vector[m_row];
    for (size_t i = 0; i < m_row; ++i)
    {
      vct[i] = M.vct[i];
    }
  }
  return *this;
}

Matrix &Matrix::operator=(Matrix &&M) noexcept
{
  if (this != &M)
  {
    delete[] vct;
    vct = M.vct;
    m_row = M.m_row;
    m_col = M.m_col;
    M.vct = nullptr;
    M.m_row = 0;
    M.m_col = 0;
  }
  return *this;
}

Matrix operator+(const Matrix &M1, const Matrix &M2)
{
  if (M1.m_row != M2.m_row || M1.m_col != M2.m_col)
  {
    throw WrongS();
  }
  Matrix result;
  result.m_row = M1.m_row;
  result.m_col = M1.m_col;
  result.vct = new Vector[result.m_row];

  for (size_t i = 0; i < result.m_row; ++i)
  {
    result.vct[i] = M1.vct[i] + M2.vct[i];
  }
  return result;
}

Matrix operator*(const Matrix &M1, const Matrix &M2)
{
  if (M1.m_col != M2.m_row)
  {
    throw WrongS();
  }
  Vector *resultVectors = new Vector[M1.m_row];

  for (size_t i = 0; i < M1.m_row; ++i)
  {
    double *resultRow = new double[M2.m_col]();
    for (size_t j = 0; j < M2.m_col; ++j)
    {
      for (size_t k = 0; k < M1.m_col; ++k)
      {
        resultRow[j] += M1.vct[i].get_m_vector()[k] * M2.vct[k].get_m_vector()[j];
      }
    }
    resultVectors[i] = Vector(resultRow, M2.m_col);
    delete[] resultRow;
  }
  Matrix result;
  result.m_row = M1.m_row;
  result.m_col = M2.m_col;
  result.vct = resultVectors;
  return result;
}

std::ostream &operator<<(std::ostream &out, const Matrix &M)
{
  for (size_t i = 0; i < M.m_row; ++i)
  {
    out << M.vct[i] << "\n";
  }
  return out;
}

Vector &Matrix::operator[](size_t index)
{
  if (index >= m_row)
  {
    throw WrongS();
  }
  return vct[index];
}

double Matrix::trace()
{
  double s = 0;

  for (size_t i = 0; i < m_row; ++i)
  {
    s+=vct[i][i];
  }


  return s; 
}


Vector operator*(const Vector &v, const Matrix &M)
{
  Vector result;
  for (size_t i = 0; i < M.m_row; ++i)
  {
    double sum = 0.0;
    for(size_t j = 0; j < M.m_col; ++j)
    {
      sum += M.vct[i][j] * v.get_m_vector()[j];
    }
    result[i] = sum;
  }
  return result;
}


Vector operator*(const Matrix &M, const Vector &v)
{
  Vector result;
  for (size_t i = 0; i < M.m_row; ++i)
  {
    double sum = 0.0;
    for(size_t j = 0; j < M.m_col; ++j)
    {
      sum += M.vct[j][i] * v.get_m_vector()[j];
    }
    result[i] = sum;
  }
  return result;
}

// Vector Matrix::operator*(const Vector& other) const{
//     Vector results_vector;
//     results_vector.size

//     for(size_t i=0;i<size;i++){
//         double suma = 0.0;
//         for(size_t j=0;j<size;j++){ 
//             suma += columns[j][i] * (other[j]);
//         }
//       results_vector[i] = suma;
//     }
//     return results_vector;

// }