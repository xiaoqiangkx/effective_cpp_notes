#include <iostream>
#include <memory>

int main() {
    std::shared_ptr<std::string> sps(new std::string("hello"));

    std::cout << sps->data() << " " << *sps << " " << *sps.get() << std::endl;
    return 0;
}
