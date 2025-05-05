#include <iostream>
#include <string>
using namespace std;
const int MAX_BOOKS = 100; 

struct Book {
    string title;
   string author;
    string isbn;
    bool is_available; // true if available, false if borrowed
};
Book library[MAX_BOOKS];
int book_count = 0;


void addBook(const string& title, const string& author, const string& isbn) {
    if (book_count >= MAX_BOOKS) {
        cout << "Library is full. Cannot add more books.\n";
        return;
    }
  
    library[book_count++] = {title, author, isbn, true};
   cout << "Book added successfully.\n";
}


void borrowBook(const string& isbn) {
    for (int i = 0; i < book_count; ++i) {
        if (library[i].isbn == isbn) {
            if (library[i].is_available) {
                library[i].is_available = false;
               cout << "You have successfully borrowed: " << library[i].title << "\n";
                return;
            } else {
                cout << "Book with ISBN " << isbn << " is already borrowed.\n";
                return;
            }
        }
    }
    cout << "Book with ISBN " << isbn << " not found.\n";
}


void returnBook(const string& isbn) {
    for (int i = 0; i < book_count; ++i) {
        if (library[i].isbn == isbn) {
            if (!library[i].is_available) {
                library[i].is_available = true;
                cout << "You have successfully returned: " << library[i].title << "\n";
                return;
            } else {
                cout << "Book with ISBN " << isbn << " was not borrowed.\n";
                return;
            }
        }
    }
    cout << "Book with ISBN " << isbn << " not found.\n";
}


void listAvailableBooks() {
    bool found = false;
    cout << "Available Books:\n";
   cout << "Title\tAuthor\tISBN\n";
    cout << "-----\t------\t----\n";
    for (int i = 0; i < book_count; ++i) {
        if (library[i].is_available) {
            cout << library[i].title << '\t'
                      << library[i].author << '\t'
                      << library[i].isbn << '\n';
            found = true;
        }
    }
    if (!found) {
        cout << "No available books.\n";
    }
}


int main() {
  
    addBook("The Great Gatsby", "F. Scott Fitzgerald", "9780743273565");
    addBook("1984", "George Orwell", "9780451524935");
    addBook("To Kill a Mockingbird", "Harper Lee", "9780060935467");

    listAvailableBooks();

    borrowBook("9780451524935");

 
    listAvailableBooks();

   
    returnBook("9780451524935");


    listAvailableBooks();

    return 0;
}