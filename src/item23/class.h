#ifndef CLASS_H
#define CLASS_H

namespace test {
    class T {
        public:
            T(int a_, int b_, int c_) {
                a = a_;
                b = b_;
                c = c_;
            }

            void print_a() const {
                std::cout << a << std::endl;
            }

            void print_b() const {
                std::cout << b << std::endl;
            }

            void print_c() const {
                std::cout << c << std::endl;
            }
        private:
            int a;
            int b;
            int c;
    };
};

#endif
