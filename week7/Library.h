#ifndef LIBRARY_H
#define LIBRARY_H
#include "Book.h"
#include <vector>
using namespace std;

class Library{
private:
    string name;
    vector<Book>books;

public:
    Library(string libraryName);

    void addBook(Book b);
    void displayBooks() const;
    void searchByAuthor(string authorName) const;
    void searchByTitle(string titleKeyword) const;
    void showStats() const;
};

#endif
