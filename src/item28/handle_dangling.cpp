#include <iostream>
#include <memory>
using namespace std;

class Test {
    public:
       Test(): sps(new string("hello")) {} 
       const string* get_data() { return sps.get(); }
    private:
        shared_ptr<string> sps;
};

const string* get() {
    Test t;
    return t.get_data();
}
int main() {
    const string* data = get();
//    cout <<  *data << endl; // dangling

    return 0;
}
