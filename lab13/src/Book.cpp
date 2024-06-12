#include "Book.h"

Book::Book(const std::string &title,const std::string &author, int year, double price)
  :m_title{title}, m_author{author}, m_year{year}, m_price{price}
{}


const std::string &Book::getTitle() const
{
  return m_title;
}

const std::string &Book::getAuthor() const
{
  return m_author;
}

int Book::getYear() const
{
  return m_year;
}

double Book::getPrice() const{
  return m_price;
}

void Book::display() const{
    std::cout << "Title: " << m_title << ", Author: " << m_author << ", Year: " << m_year << ", Price: " << m_price << std::endl;
}