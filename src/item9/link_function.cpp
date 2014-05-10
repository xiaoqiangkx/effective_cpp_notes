	#include <iostream>

class Base {
    public:
        Base() {
            init();
      //      log();
        }

        virtual ~Base() {}
        virtual void log() = 0;
    private:
        void init() {
            log();
        }
};

class Derived: public Base {
    virtual void log() {}
};

int main() {
    Derived d;
    return 0;
}
