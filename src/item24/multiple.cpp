#include <iostream>
using namespace std;

class T {
    public:
        T(int a_=0): a(a_) {}
        int get_a() const { return a; }
    private:
        int a;
}; 

const T operator*(const T& lhs, const T& rhs) {
    T t(lhs.get_a() * rhs.get_a());
    return t;
}


int main() {
    T t1(1);
    t1 * 2;
    2 * t1;
    return 0;
}
