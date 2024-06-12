#ifndef MATRIX_H
#define MATRIX_H
#include <initializer_list>
#include "WrongS.h"
#include "Vector.h"

class Matrix
{
private:
  Vector *vct{};
  size_t m_row{};
  size_t m_col{};

public:
  Matrix() = default;
  Matrix(std::initializer_list<Vector> M);
  Matrix(const Matrix &M);
  Matrix(Matrix &&M) noexcept;
  ~Matrix();

  double trace();

  Matrix &operator=(const Matrix &M);
  Matrix &operator=(Matrix &&M) noexcept;
  friend Vector operator*(const Vector &v, const Matrix &M);
  friend Vector operator*(const Matrix &M, const Vector &v);

  friend Matrix operator+(const Matrix &M1, const Matrix &M2);
  friend Matrix operator*(const Matrix &M1, const Matrix &M2);
  friend std::ostream &operator<<(std::ostream &os, const Matrix &M);
  Vector &operator[](size_t index);
};

#endif