#include <iostream>
using namespace std;

class Test {
    public:
        Test(string* s): p(s) {}    // 此处使用new string(), 而不是直接拷贝指针, 也可以避免自我赋值的情形
        Test& operator=(const Test& s) {
            delete p;
            p = NULL;
            p = new string(*(s.p)); // 此堆不能够被访问, 段错误
            return *this;
        }
    private:
        string *p;
};

int main() {
    string *data = new string("data");
    Test t1(data), t2(data);

    t1 = t2;    // 自我赋值, 行为应该是未知的, 常见是段错误

    return 0;
}
