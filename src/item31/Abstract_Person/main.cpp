#include <iostream>
#include <memory>
#include "Person.h"

int main() {
    std::shared_ptr<Person> p(Person::create("hello"));
    std::cout << p->get_date() << std::endl;
    return 0;
}
