#include <sstream>
#include "book.h"
using namespace std;

Book::Book() : title(""), author(""), isbn(""){

}
Book::Book(const string& title, const string& author, const string& isbn){
}
Book::~Book(){}
string Book::getTitle() const {
    return title;
}
string Book::getAuthor() const{
    return author;
}
string Book::getISBN() const{
    return isbn;
}
bool Book::getAvailability() const{
    return isAvailable;
}
string Book::getBorrowerName() const{
    return borrowerName;
}
void Book::setTitle(const string& title){
    this->title = title;
}
void Book::setAuthor(const string& author){
    this->author = author;
}
void Book::setISBN(const string& isbn){
    this->isbn = isbn;
}
void Book::setAvailability(bool available){
    this->isAvailable = available;
}
void Book::setBorrowerName(const string& name){
    this->borrowerName = name;
}
void Book::checkOut(const string& borrower){
    this->borrowerName = borrower;
    this->isAvailable = false;
}
void Book::returnBook(){
    this->isAvailable = true;
    this->borrowerName = "";
}
string Book::toString() const{
    string result = "Titre :" + title + "\nAutheur :" + author + "\nISBN" + isbn + "\n"; 
    if (isAvailable)
    {
        result += "Il est disponible";
    } else {
        result += "Il est emprunté par " + borrowerName;
    }
    return result;
    
}
string Book::toFileFormat() const{
  string result = title + "|" + author + "|" + isbn + "|"; 
    if (isAvailable)
    {
        result += "1|";
    } else {
        result += "0|" + borrowerName;
    }
    return result;
}
void Book::fromFileFormat(const string& line) {
    stringstream ss(line);
    string token;
    getline(ss,title,'|');
    getline(ss,author,'|');
    getline(ss,isbn,'|');
    string availability;
    getline(ss,availability,'|');
    if (availability == "0")
    {
        this->isAvailable = 0;
        getline(ss,author,'|');

    } else {
        this->isAvailable = 1;
    }
    

}