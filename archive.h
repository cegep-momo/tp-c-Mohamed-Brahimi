#ifndef ARCHIVE_H
#define ARCHIVE_H

#include <string>

using namespace std;

class Archive {
private:
    string timeStamp;
    string action;
    string user;
    

public:
    // Constructors
    Archive();
    Archive(const string& action, const string& user);
    
    // Getters
    string getUser() const;
    string getAction() const;
    string getTimeStamp() const;

    // Setters
    void setAction(const string& action);
    void setUser(const string& user);
    void setTimeStamp(const string& timeStamp);

    // Methods
    string toString() const;
    string toFileFormat() const;
    void fromFileFormat(const string& line);
};

#endif
