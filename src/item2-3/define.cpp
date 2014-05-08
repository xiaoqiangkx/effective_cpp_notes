#include <iostream>
using namespace std;

#define DATA 1.63

int main() {
//    int p[DATA]; 
//    int *q = DATA;
//    char *str = "DATA"; *str = 'a';   // 段错误, 由于在修改代码段
    const char * const str = "DATA";
    int r = DATA;
    return 0;
}
