#include "BookManager.h"

void BookManager::addBook(const std::string &title,const std::string &author, int year, double price)
{
    books.emplace_back(title, author, year, price);
}

void BookManager::displayAllBooks() const
{
    std::for_each(books.begin(), books.end(), [](const Book& book){ book.display();});
}

    
void BookManager::sortBooksByTitle()
{
    std::sort(books.begin(), books.end(), [](const Book& book1, const Book& book2){ return book1.getTitle() < book2.getTitle(); });
}

const Book* BookManager::findBookByTitle(const std::string &title) const
{
    auto it = std::find_if(books.begin(), books.end(), [&](const Book& book){return book.getTitle() == title; });
    return nullptr;
}


void BookManager::removeBook(const std::string &title)
{
    books.erase(std::remove_if(books.begin(), books.end(), [&title](const Book& book){return book.getTitle() == title; }));
}


void displayBook(const Book &book){
  std::cout << "Title: " << book.getTitle() << ", Author: " << book.getAuthor() << ", Year: " << book.getYear() << ", Price: " << book.getPrice() << std::endl;
}

