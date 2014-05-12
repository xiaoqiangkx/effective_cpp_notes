#include <iostream>
using namespace std;

class Base {
    public:
        void f1() { cout << "Base f1()" << endl; }
        void f1(int m) { cout << "Base f1() "<< m << endl; }
        void f2() { cout << "Base f2()" << endl; }
        void f2(int m) { cout << "Base f2() "<< m << endl; }
        virtual void f3() { cout << "Base f3()" << endl; }
        void f3(int m) { cout << "Base f3() "<< m << endl; }
};

class Derived: public Base {
    public:
        void f1() { cout << "Derived f1()" << endl; }
        using Base::f2;
        void f2() { cout << "Derived f2()" << endl; }

};

// public继承肯定会直接继承并可以调用f3()所有方法,只能使用private继承
class Base3: private Base {
    public:
        // 仅继承f3, 而不要其它的
        virtual void f3() {
            Base::f3();
        };

};
int main() {
    Derived d;
    d.f1();
    d.f2(); // 不会引发二义性. derived类级别更高, 直接覆盖了base类.
    d.f2(1);

    Base3 b;
    d.f3();
    return 0;
}
