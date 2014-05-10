Code 说明
=============

Code 列表
============

Item 2-3
------------

 * define.cpp
    * 使用const变量,而不是宏定义变量, 方便调试
 * const\_member.cpp
    * 类中const member的定义.
 * const\_pointer.cpp
    * 如何修饰一个指针或者迭代器
 * const\_return.cpp
    * 自定义类型的函数返回值可以作为左值, 使用const类禁止. 保证和内置类型一致
 * const\_function.cpp
    * const重载问题以及非const版本调用const版本函数

Item 4
------------
 
 * local\_static.cpp + file\_sys.cpp
    * 避免两个不同编译单元内两个non-local static对象互相调用, 通过local static对象来实现


Item 5
------------
 * silent\_function.cpp
    * 编译器只有用到函数时才会生成, 继承关系以及不可赋值\复制的变量都引入了特殊化


Item 6
------------
 * test.cpp\main.cpp
    * 函数未定义错误在连接器时报错
 * uncopyable.cpp
    * 通过base类的private方法, 将错误提前到编译期, 由于无法生成拷贝函数而出错.

 注: 通过`g++ -o main.o -c uncopyable.cpp` 和 `g++ -o main main.o` 来测试.


Item 7
-------------
 * partial\_delete.cpp
    * 局部销毁,其实派生类的非指针类数据依旧会被销毁掉. 
 * pure\_destructor.cpp
    * 包含纯虚函数的类不能被创建, 同时又能够被子类调用析构函数, 一举两得啊.
