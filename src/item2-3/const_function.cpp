#include <iostream>
#include <cstring>
#include <stdexcept>

class TextBlock {
    public:
    TextBlock(const char* _data = "")
        : size(std::strlen(_data)), data(new char[std::strlen(_data) + 1]) {
            strncpy(data, _data, size);
        }
    const char& operator[] (std::size_t pos) const {
        std::cout << "inside const operator[]" << std::endl;
        if (pos >= size)
            throw new std::out_of_range("position is not valid.");

        return data[pos];
    }

    char& operator[] (std::size_t pos) {
        std::cout << "inside non-const operator[]" << std::endl;
        return const_cast<char&>(
                static_cast<const TextBlock&>(*this)[pos]);
    }

    private:
        int size;
        char* data;
};

int main() {
    TextBlock tb("hello");
    const TextBlock ctb(tb);
    std::cout << "non-const data[0]=" << tb[0] << std::endl;
    std::cout << "const data[0]=" << ctb[0] << std::endl;
    
    try {
        tb[10];
    } catch(std::out_of_range *e) {
        std::cerr << e->what() << std::endl;
    }

    try {
        ctb[10];
    } catch(std::out_of_range *e) {
        std::cerr << e->what() << std::endl;
    }
    return 0;
}
