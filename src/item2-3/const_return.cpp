#include <iostream>

int compare(int a, int b) {
    if (a < b)  return 1;
    if (b < a)  return -1;
    return 0;
}

struct num {
    friend num plus(const num&, const num&);
    friend const num minus(const num&, const num&);
    num() {}
    num(int _a) : a(_a) {}
    operator bool () {
        return (a != 0);
    }
    private:
        int a;
};


num plus(const num& lhs, const num &rhs) {
    num sum;
    sum.a = lhs.a + rhs.a;
    return sum;
}

const num minus(const num& lhs, const num &rhs) {
    num diff;
    diff.a = lhs.a - rhs.a;
    return diff;
}

int main() {
    // compare(2, 1) = 3;   // 函数返回值只能作为右值
    // if (compare(2, 1) = 3) ;

    num n1(1), n2(-1);
    if (plus(n1, n2) = 1)
        std::cout << "sum 1 + (-1) is 1" << std::endl;

    num n3(1), n4(1);
    if (const_cast<num&>(static_cast<const num&>(minus(n3, n4))) = 1)
        std::cout << "minus 1 - 1 is 1" << std::endl;
    return 0;
}
