#include <iostream>
using namespace std;

struct Test {
    static const int LEN = 5;
    int a[LEN];
};

// const int Test::LEN;

int main() {
    const int *p = &Test::LEN;
    return 0;
}
