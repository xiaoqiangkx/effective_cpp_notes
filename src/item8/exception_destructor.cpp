#include <iostream>
#include <cstdlib>
#include <stdexcept>

class Test {
    public:
        Test() { closed = false; }
        void close() {
            closed = true;
            throw new std::runtime_error("close exception");
        }

        ~Test() {
            if (!closed) {
                try {
                    throw new std::runtime_error("close ~Test()");
                } catch (std::runtime_error *e) {
                    std::cout << e->what() << std::endl;
                    std::exit(-1);
                }
            }
        }
    private:
        bool closed;
};

int main() {
    Test t2, t1;    // 保证t1的析构函数先被调用

    std::cout << "----------------t1 close()--------------" << std::endl;
    try {
        t1.close();
    } catch (std::runtime_error *e) {
        std::cout << e->what() << std::endl;
    }

    std::cout << "----------------t2--------------" << std::endl;

    return 0;
}
