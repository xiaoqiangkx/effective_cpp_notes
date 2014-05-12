#ifndef PERSON_H
#define PERSON_H

#include <memory>
#include <string>

class PersonImpl;

class Person {
    public:
        ~Person() {}
        virtual std::string get_date() const = 0;
        static std::shared_ptr<Person> create(const std::string&);
};

#endif 


