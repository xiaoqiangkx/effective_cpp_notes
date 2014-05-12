#include <iostream>
using namespace std;

class Base {
    public:
        virtual void fly() = 0;
        virtual ~Base() {}
};

void Base::fly() {
    cout << "Base" << endl;
};

class BaseX: public Base {
    public:
        virtual void fly() {
            Base::fly();
        }
};

int main() {
    Base *b = new BaseX();
    b->fly();
    b->Base::fly();
//    Base b1;  //  cannot declare variable ‘b1’ to be of abstract type ‘Base’
    return 0;
}
