#include <iostream>
using namespace std;

int main() {

    typedef string AddressLines[4];
    string *pal = new AddressLines;

    // delete pal; // sometimes segment fault
    delete [] pal;
    return 0;
}
