#include "Person.h"
#include "PersonImpl.h"

Person::Person(const std::string& date): pImpl(new PersonImpl(date)) {

}


std::string Person::get_date() const {
    return pImpl->get_date();
}
