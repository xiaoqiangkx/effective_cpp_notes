#ifndef PERSONIMPL_H
#define PERSONIMPL_H

#include <string>

class Date {
    public:
        Date(const std::string& d);
        std::string get() const;
    private:
        std::string date;
};

class PersonImpl {
    public:
        PersonImpl(const std::string& date);
        std::string get_date() const; 
    private:
       Date d; 
};


#endif
