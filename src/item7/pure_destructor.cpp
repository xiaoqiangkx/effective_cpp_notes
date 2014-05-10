#include <iostream>

class Base {
    public:
        virtual ~Base() = 0;
};

Base::~Base() {}        // undefined reference to `Base::~Base()'

class Derived: public Base {
    
};

int main() {
    Derived d;
    return 0;
}
