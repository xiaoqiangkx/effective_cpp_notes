#ifndef PERSON_H
#define PERSON_H

#include <memory>
#include <string>

class PersonImpl;

class Person {
    public:
        Person(const std::string& date);

        std::string get_date() const;
    private:
        std::shared_ptr<PersonImpl> pImpl;
};

#endif 


