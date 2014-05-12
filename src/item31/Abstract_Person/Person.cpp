#include "Person.h"
#include "PersonImpl.h"

std::shared_ptr<Person> Person::create(const std::string& date) {
    return std::shared_ptr<Person>(new PersonImpl(date));
}

