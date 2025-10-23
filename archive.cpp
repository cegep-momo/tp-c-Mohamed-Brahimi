#include <sstream>
#include "archive.h"
#include <ctime>
using namespace std;

Archive::Archive() : action(""), user(""), timeStamp(""){

}
Archive::Archive(const string& action, const string& user){
this->action = action;
this->user = user;
this->timeStamp = asctime(localtime(new time_t(time(0))));
}
string Archive::getAction() const {
    return action;
}
string Archive::getUser() const{
    return user;
}
string Archive::getTimeStamp() const{
    return timeStamp;
}
void Archive::setAction(const string& action){
    this->action = action;
}
void Archive::setUser(const string& user){
    this->user = user;
}
string Archive::toString() const{
    string result = "Action : " + this->action + "\nUtilisateur : " + this->user + "\nTimestamp : " + this->timeStamp + "\n"; 
    return result;
    
}
string Archive::toFileFormat() const{
  string result = this->action + "|" + this->user + "|" + this->timeStamp + "|"; 
    return result;
}
void Archive::fromFileFormat(const string& line) {
    stringstream ss(line);
    string token;
    getline(ss,action,'|');
    getline(ss,user,'|');
    

}