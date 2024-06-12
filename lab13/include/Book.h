#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>
#include <optional>


class Book {
private:
  std::string m_title{};
  std::string m_author{};
  int m_year {};
  double m_price {};
public:
  Book(const std::string &title,const std::string &author, int year, double price);
  const std::string &getTitle() const;
  const std::string &getAuthor() const;
  int getYear() const;
  double getPrice() const;
  void display() const;


};


#endif