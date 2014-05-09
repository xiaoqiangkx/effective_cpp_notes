#include <iostream>
#include <fstream>

class Base1 {
    private:
        Base1() {}
        Base1(const Base1 &base) {}
        Base1& operator=(const Base1 &base) {}
        ~Base1() {}
};

class Derived1: public Base1 {
};

class Base2 {
};

class Derived2: public Base2 {
    public:
        Derived2(int& a_): ofs("test.file"), a(a_), b(1) {}
    private:
        std::ofstream ofs;
        int& a;
        const int b;
};

int main() {
    //Derived1 d1;    // 无法生成默认的构造函数,析构函数
    int data = 0;
    Derived2 d2(data);
    Derived2 d3(data);
  //  Derived2 d4(d2);  // ostream 无法复制
  //  d3 = d2;          // int&和const int无法赋值
    return 0;
}
