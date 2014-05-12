#include <iostream>
#include "Person.h"
#include "PersonImpl.h"

int main() {
    Person p("hello");
    std::cout << p.get_date() << std::endl;
    return 0;
}
