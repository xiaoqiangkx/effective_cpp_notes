#include <iostream>
#include "file_sys.h"

struct Directory {
    Directory(): dir(get_filesys().name) {
    }

    std::string dir; 
};


Directory& get_dir() {
    static Directory td;
    return td;
}

Directory temp;
int main() {
    std::cout << temp.dir << std::endl;
    std::cout << get_dir().dir << std::endl;
    return 0;
}
