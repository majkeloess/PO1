#ifndef BOOKMANAGER_H
#define BOOKMANAGER_H

#include "Book.h"
#include <vector>
#include <algorithm>

class BookManager {
private:
  std::vector<Book> books {};


public:
  BookManager() = default;
  void addBook(const std::string &title,const std::string &author, int year, double price); 
  void displayAllBooks() const;
  const Book* findBookByTitle(const std::string &title) const;
  void sortBooksByTitle();
  void removeBook(const std::string &title);


};

void displayBook(const Book &book);

#endif