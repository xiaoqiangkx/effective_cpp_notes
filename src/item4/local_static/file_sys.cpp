#include "file_sys.h"

FileSystem& get_filesys() {
    static FileSystem fs("name");
    return fs;
}
