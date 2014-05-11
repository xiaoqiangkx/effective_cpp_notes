#include <iostream>
using namespace std;

class T {
    friend const T& operator*(const T& lhs, const T& rhs);
    friend bool operator==(const T& lhs, const T& rhs);
    public:
        T(int a_=0): a(a_) {}
        int get_a() const { return a; }
    private:
        int a;
}; 

const T& operator*(const T& lhs, const T& rhs) {
    static T t;
    t.a = lhs.a + rhs.a;
    return t;
}

bool operator==(const T& lhs, const T& rhs) {
    return lhs.a == rhs.a;
}

int main() {
    T t1(1), t2(2), t3(3), t4(4);
    if ((t1 * t2) == (t3 * t4)) {
        cout << "1 + 2 == 3 + 4" << endl;
    } else {
        cout << "1 + 2 != 3 + 4" << endl;
    }
    return 0;
}
