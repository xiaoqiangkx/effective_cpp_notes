#include <iostream>
#include <vector>
using namespace std;

int main() {
    typedef int* int_ptr;
    int a = 2;
    const int_ptr ip = &a;
    ++*ip;
    //  ip++;   // const指针


    vector<int> ivec(10, 1);
    const vector<int>::iterator iter = ivec.begin();
    ++*iter;
    // iter = ivec.end();  // const迭代器

    vector<int>::const_iterator citer = ivec.begin();
    // ++*citer;
    citer = ivec.end();

    const int *p = &a;
    // ++*p;
    p++;    // 指向常量的指针
    return 0;
}
