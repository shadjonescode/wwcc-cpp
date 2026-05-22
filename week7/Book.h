#ifndef BOOK_H
#define BOOK_H
#include <string>
#include "Author.h"
using namespace std;

class Book{
private:
    string title;
    int publicationYear;
    string isbn;
    Author author;

public:
    Book(string t, int pubYear, string bookNumber, Author a);

    string getTitle() const;
    int getPublicationYear() const;
    string getIsbn() const;
    Author getAuthor() const;

    void setPublicationYear(int year);
    void display() const;
};

#endif