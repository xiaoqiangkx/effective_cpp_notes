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
