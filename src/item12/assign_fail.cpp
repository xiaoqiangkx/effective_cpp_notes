#include <iostream>
using namespace std;

class Base {
    public:
        Base(int a_, int b_): a(a_), b(b_) {}
        Base& operator=(const Base& rhs) {
            a = rhs.a;
            b = rhs.b;
        }

    protected:
        void print() {
            cout << "a=" << a << endl;
            cout << "b=" << b << endl;
        }
    private:
        int a;
        int b;
};

class Derived: public Base {
    public:
        Derived(int a_, int b_, int c_): Base(a_, b_), c(c_) {}
        Derived& operator=(const Derived& rhs) {
//            Base::operator=(rhs);
            c = rhs.c;
        }

        void print() {
            Base::print();
            cout << "c=" << c << endl;
        }
    private:
        int c;

};

int main() {
    Derived d1(1, 2, 3);
    Derived d2(2, 4, 6);
    d1 = d2;
    cout << "d2" << endl;
    d2.print();
    cout << "d1" << endl;
    d1.print();
    return 0;
}
