#include <iostream>
#include "class.h"
#include "more_print.h"

int main() {
    test::T t(1, 2, 3);
    test::print_more(t);
    return 0;
}
