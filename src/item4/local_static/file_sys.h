#ifndef FILE_SYS_H
#define FILE_SYS_H

#include <string>

struct FileSystem {
    FileSystem(const std::string name_=""): name(name_) {}
    std::string name;
};

FileSystem& get_filesys();
#endif
