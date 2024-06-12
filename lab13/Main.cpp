//Z użyciem klas Book, BookManager oraz odpowiednich kontenerów zaprogramuj system do zarządzania
// kolekcją książek.
//W operacjach na kontenerach nie wolno wykorzystywać "ifów". Stosujemy wyłącznie iteratory i
// algorytmy STL.
#include "BookManager.h"

int main() {
    BookManager manager;
    manager.addBook("1984", "George Orwell", 1949, 19.84);
    manager.addBook("Brave New World", "Aldous Huxley", 1932, 15.99);
    manager.addBook("Fahrenheit 451", "Ray Bradbury", 1953, 18.99);

    std::cout << "All books:" << std::endl;
    manager.displayAllBooks();

    std::cout << "\nSorted by title:" << std::endl;
    manager.sortBooksByTitle();
    manager.displayAllBooks();

    std::cout << "\nFinding book by title '1984':" << std::endl;
    auto book = manager.findBookByTitle("1984");
    if (book) displayBook(*book);

    std::cout << "\nRemoving book '1984' and displaying all books:" << std::endl;
    manager.removeBook("1984");
    manager.displayAllBooks();

    return 0;
}

//All books:
//Title: 1984, Author: George Orwell, Year: 1949, Price: 19.84
//Title: Brave New World, Author: Aldous Huxley, Year: 1932, Price: 15.99
//Title: Fahrenheit 451, Author: Ray Bradbury, Year: 1953, Price: 18.99
//
//Sorted by title:
//Title: 1984, Author: George Orwell, Year: 1949, Price: 19.84
//Title: Brave New World, Author: Aldous Huxley, Year: 1932, Price: 15.99
//Title: Fahrenheit 451, Author: Ray Bradbury, Year: 1953, Price: 18.99
//
//Finding book by title '1984':
//Title: 1984, Author: George Orwell, Year: 1949, Price: 19.84
//
//Removing book '1984' and displaying all books:
//Title: Brave New World, Author: Aldous Huxley, Year: 1932, Price: 15.99
//Title: Fahrenheit 451, Author: Ray Bradbury, Year: 1953, Price: 18.99