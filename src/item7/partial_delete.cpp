#include <iostream>

class Base {
    public:
        virtual ~Base() {}
        virtual void test() {}
    private:
      static int a;
      int b;   // 一旦添加这个后, sizeof(Base) 成为了16, 由于必须对齐为8的倍数
};

// int Base::a = 1;

class Derived: public Base {
    public:
        Derived(): p(new char[10]) {}
        ~Derived() { delete [] p; }
    private:
    int c;  // 即使不调用本析构函数, c也是会被调用的.
    char *p;
};

int main() {

    // 虚函数指针是每个对象独有的.
    std::cout << "size of empty Base is " << sizeof(Base) << std::endl;
    Base b;
    std::cout << "size of empty Base object is " << sizeof(b) << std::endl;
    std::cout << "size of empty Derived is " << sizeof(Derived) << std::endl;
    Derived d;
    std::cout << "size of empty Derived object is " << sizeof(d) << std::endl;
   

    // 局部销毁现象, 使用valgrind来说明.
    Base *base = new Derived();
    delete base;
    return 0;
}
