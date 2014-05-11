#include <iostream>
#include <memory>
#include <stdexcept>
using namespace std;

void test(shared_ptr<string> &ptr, int num) {
    cout << "pass test:" << *ptr << " " << num << endl;
}

int fun() {
    throw runtime_error("runtime error");
    return 0;
}

int main() {
    
    try {
      //  test(static_cast<shared_ptr<string> >(new string("hello")), fun());
      //  Solution
      shared_ptr<string> sps(new string("h"));
      test (sps, fun());
    } catch (runtime_error &e) {
        cout << e.what() << endl;
    }
    return 0;
}
