#ifndef PERSONIMPL_H
#define PERSONIMPL_H

#include <string>
#include "Person.h"

class Date {
    public:
        Date(const std::string& d);
        std::string get() const;
    private:
        std::string date;
};

class PersonImpl: public Person {
    public:
        PersonImpl(const std::string& date);
        virtual std::string get_date() const; 
    private:
       Date d; 
};


#endif
