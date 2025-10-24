#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include <memory>

#include "book.h"
#include "user.h"
#include "archive.h"
using namespace std;

class Library {
private:
    vector<unique_ptr<Book>> books;
    vector<unique_ptr<User>> users;
    vector<unique_ptr<Archive>> actionArchive;

public:
    // Constructor and destructor
    Library();
    ~Library() = default;
    
    // Book management
    void addBook(const Book& book);
    bool removeBook(const string& isbn);
    Book* findBookByISBN(const string& isbn);
    vector<Book*> searchBooksByTitle(const string& title);
    vector<Book*> searchBooksByAuthor(const string& author);
    vector<Book*> getAvailableBooks();
    vector<Book*> getAllBooks();
    // Archive management
    void addArchiveAction(const string& action, const string& user);
    vector<Archive*> getAllArchiveActions();
    // User management
    void addUser(const User& user);
    User* findUserById(const string& userId);
    vector<User*> getAllUsers();
    
    // Library operations
    bool checkOutBook(const string& isbn, const string& userId);
    bool returnBook(const string& isbn);
    
    // Display methods
    void displayAllBooks(bool sortByAuthor);
    void displayAvailableBooks(bool sortByAuthor);
    void displayAllUsers();
    void displayAllActions();
    // Statistics
    int getTotalBooks() const;
    int getAvailableBookCount() const;
    int getCheckedOutBookCount() const;
};

#endif
