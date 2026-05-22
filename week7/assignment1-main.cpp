#include "Library.h"
#include <iostream>

using namespace std;

int main(){

    Library library("Central City Library");

    int choice;

    do{

        cout << "LIBRARY MANAGEMENT SYSTEM" << endl;
        cout << "-------------------------" << endl;

        cout << "1. Add Book" << endl;
        cout << "2. Display All Books" << endl;
        cout << "3. Search by Author" << endl;
        cout << "4. Search by Title" << endl;
        cout << "5. Show Stats" << endl;
        cout << "6. Exit" << endl;

        cout << "Enter choice: ";
        cin >> choice;

        switch(choice){

            case 1:{
                string title;
                int publicationYear;
                string isbn;
                string authorName;
                int birthYear;

                cin.ignore();

                cout << "Enter title: ";
                getline(cin, title);

                cout << "Enter publication year: ";
                cin >> publicationYear;

                cin.ignore();

                cout << "Enter ISBN: ";
                getline(cin, isbn);

                cout << "Enter author name: ";
                getline(cin, authorName);

                cout << "Enter author birth year: ";
                cin >> birthYear;

                Author author(authorName, birthYear);
                Book book(title, publicationYear, isbn, author);

                library.addBook(book);

                cout << "Book added." << endl;
                break;
            }
            case 2:
                library.displayBooks();
                break;

            case 3:{
                string authorName;

                cout << "Search by author: ";
                cin.ignore();
                getline(cin, authorName);

                library.searchByAuthor(authorName);
                break;
            }
            case 4:{
                string titleKeyword;

                cout << "Search by title: ";
                cin.ignore();
                getline(cin, titleKeyword);

                library.searchByTitle(titleKeyword);
                break;
            }
            case 5:
                library.showStats();
                break;

            case 6:
                cout << "Goodbye!" << endl;
                break;

            default:
                cout << "Invalid choice." << endl;
        }

    } while(choice != 6);

    return 0;
}