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


Item 8
--------------
 * exception\_destructor.cpp
    * 析构函数中异常控制-双重保险: 将异常代码分离为用户可调用可控制的接口, 或者在析构函数中吞下它们或者直接中止程序


Item 9
--------------
 * link\_function.cpp
    * 在派生类中构造函数和析构函数调用虚函数是错误的设计, 在构造函数中通过函数调用虚函数行为是未知的.


Item 11
--------------
 * indentity\_test.cpp
    * 自我赋值将产生段错误
 * identity\_cure.cpp
    * 自我赋值的解决办法: copy-and-swap或者手工保存

Item 12
--------------
 * assign\_fail.cpp
    * 赋值拷贝函数, 不会调用默认赋值构造函数的哦. 不像拷贝构造函数.


Item 13
------------ 
 * smart\_ptr.cpp
    * auto\_ptr和shared\_ptr的例子


Item 14
------------
 * mutex.cpp
    * 使用mutex管理类来自动unlock mutex. `g++ -std=c++0x mutex.cpp -lpthread`
    * 补充Uncopyable类的定义: 为了防止外界初始化此类, 构造函数和析构函数定义为为protected,拷贝构造函数和赋值构造函数定义为private且不实现防止用户和友元访问(用户编译就不通过, 由于无法调用私有拷贝函数, 友元在链接时才有错误.). 继承时使用private继承可以防止子类继续被继承. 


Item 15
------------
 * smart\_get.cpp
    * 测试c++11中的get, `-\>`, `\*`方法. 命令`g++ -std=c++0x smart\_get.cpp`


Item 16
-------------
 * delete\_array.cpp
    * delete动态数组产生了segment fault


Item 17
-------------
 * newed\_exception.cpp
    * 提倡使用独立语句来生成newed对象并放入智能指针中.


Item 21
--------------
 * static\_return.cpp
    * 使用local static变量时不支持多次修改此变量作为返回比较的情况.


Item 23
--------------
 * class.cpp
    * 教你如何将不同template分割开来.


Item 24
--------------
 * multiple.cpp
    * member函数的对立面是non-member. friend函数能够不用就不用吧.


Item 27
--------------
 * static\_cast.cpp
    * static\_cast无法将Derived类进行向上转型.


Item 28
---------------
 * handle\_dangling.cpp
    * 返回寿命比对象长的handle就是一种错误. 


Item 31
----------------
 * Person.h, PersonImpl.h(Person.cpp依存PersonImpl.h)
    * Person接口类中使用pimpl(pointer to implementation)和类声明机制. 放弃inline来实现编译弱依存. 众多文件依赖Person.h, 所以尽量减少重编译.

```
g++ -std=c++0x -o PersonImpl.o -c PersonImpl.cpp
g++ -o main Person.Person.cpp Person.h Person.o
g++ -o main Person.o  PersonImpl.o main.cpp -std=c++0x
```
或者
`g++ -std=c++0x main.cpp Person.cpp PersonImpl.cpp`

 * abstract\_Person.h
    * 通过虚拟基类和虚函数来引用派生类. 从而将类实现隐藏起来.


Item 33
--------------
 
 * hide\_fun.cpp
    * 使用using实现子类和父类的函数重载. 使用private继承和转交函数实现单一函数继承.
