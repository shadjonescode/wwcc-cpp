#include "Book.h"
#include <iostream>
using namespace std;

Book::Book(string t, int pubYear, string bookNumber, Author a) : author(a){
    title = t;
    publicationYear = pubYear;
    isbn = bookNumber;
    author = a;
}

string Book::getTitle() const{
    return title;
}

int Book::getPublicationYear() const{
    return publicationYear;
}

string Book::getIsbn() const{
    return isbn;
}

Author Book::getAuthor() const{
    return author;
}

void Book::setPublicationYear(int year){
    if (year > 0){
        publicationYear = year;
    }
}

void Book::display()const{
    cout << "\"" << title << "\" (" << publicationYear << ")" << endl;
    cout << "ISBN: " << isbn << endl;
    author.display();
}