#include <iostream>
#include <memory>

int main() {
    std::auto_ptr<std::string> aps1(new std::string("hello"));
    std::auto_ptr<std::string> aps2(aps1);

    if (aps1.get() == NULL)
        std::cout << "aps1 is NULL after initial " << std::endl;
    else
        std::cout << "aps1 is not NULL after initial " << std::endl;

    std::shared_ptr<std::string> sps1(new std::string("hello"));
    std::shared_ptr<std::string> sps2(sps1);

    if (sps1.get() == NULL)
        std::cout << "sps1 is NULL after initial " << std::endl;
    else
        std::cout << "sps1 is not NULL after initial " << std::endl;

    return 0;
}
