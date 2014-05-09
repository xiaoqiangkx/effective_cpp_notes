#include <iostream>

class Uncopyable {
    private:
        Uncopyable(const Uncopyable&);
        Uncopyable& operator=(const Uncopyable&);
};

class Test1: public Uncopyable {
};

class Test2 {
    friend void try_copy(const Test2&);
    public:
        Test2() {}
    private:
        Test2(const Test2&) {}
        Test2& operator=(const Test2&) { return *this; }
};

void try_copy(const Test2& val) {
    Test2 t(val);
    t = val;
}

class Test3 {
    friend void try_copy(const Test3&);
    public:
        Test3() {}
    private:
        Test3(const Test3&);
        Test3& operator=(const Test3&) { return *this; }
};

void try_copy(const Test3& val) {
    Test3 t(val);
    t = val;
}

int main() {
//    Test1 t1, t2;     //编译时, 由于无法生成拷贝函数和赋值函数, 编译报错
//    t1 = t2;

//    Test2 t3, t4;     // 用户无法访问
//    t3 = t4;
    Test2 t5;
    try_copy(t5);
    
//    Test3 t6;
//    try_copy(t6);       // 链接寻找函数定义时报错, 链接错误.
    return 0;
}
