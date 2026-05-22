#include "Library.h"
#include <cctype>
#include <iostream>
using namespace std;

string toLower(string text){
    for (char& c : text){
        c = tolower(c);
    }
    return text;
}

Library::Library(string libraryName){
    name = libraryName;
}

void Library::addBook(Book b){
    books.push_back(b);
}

void Library::displayBooks() const{
    for (const Book& book : books){
        book.display();
        cout << endl;
    }
}

void Library::searchByAuthor(string authorName) const{

    bool found = false;

    for (const Book& book : books){
        if (toLower(book.getAuthor().getName()) == authorName){
            found = true;
            book.display();
            cout << endl;
        }
    }
    if (!found){
        cout << "No books found." << endl;
    }
}

void Library::searchByTitle(string titleKeyword) const{

    bool found = false;
    for (const Book& book : books){
        if (toLower(book.getTitle()) == titleKeyword){
            found = true;
            book.display();
            cout << endl;
        }
    }
    if (!found){
        cout << "No books found." << endl;
    }
}

void Library::showStats() const{
    cout << "Library name: " << name << endl;
    cout << "Total books: " << books.size() << endl;
}