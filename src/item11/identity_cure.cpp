#include <iostream>
using namespace std;

class Test {
    public:
        Test(string* s): p(s) {}    
        Test& operator=(const Test& rhs) {
            // Method 1
            //string *Orig = p;
            //p = new string(*rhs.p);
            //delete Orig;

            // copy-swap
            Test temp(rhs);
            swap(temp);
            return *this;
        }
    private:
        string *p;
        void swap(Test& t) {
            string *temp = p;
            p = t.p;
            t.p = temp;
        }
};

int main() {
    string *data = new string("data");
    Test t1(data), t2(data);

    t1 = t2;    // 自我赋值, 行为应该是未知的, 常见是段错误

    return 0;
}
