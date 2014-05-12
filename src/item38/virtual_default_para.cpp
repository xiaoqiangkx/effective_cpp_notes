#include <iostream>

class Base {
    public:
        virtual void print(int a=1) {
            std::cout << "Base=" << a << std::endl;
        }
        virtual ~Base() {}
};

class Derived: public Base {
    public:
        virtual void print(int a=2) {
            std::cout << "Derived=" << a << std::endl;
        }
};

int main() {
    Base *b = new Derived();
    b->print();
    delete b;
    return 0;
}
