#include <iostream>

class Base {
    public:
        Base(int a_=0): a(a_) {}
        virtual void change() { a++; }
        void print() {
            std::cout << "a=" << a << std::endl;
        }
    private:
        int a;
};

class Derived: public Base {
    public:
        Derived(int a_, int b_): Base(a_), b(b_) {}
        virtual void change() { static_cast<Base>(*this).change(); b++; }
        // static_cast得到的是*this的Base部分的一个副本而已. 所以不改变a值. this依旧指向Derived class, 所以拷贝了一份而已.
        void print() {
            Base::print();
            std::cout << "b=" << b << std::endl;
        };
    private:
        int b;
};

int main() {
    Derived d(2, 2);
    d.change();
    d.print();
    return 0;
}
