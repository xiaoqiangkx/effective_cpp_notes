Effective C++ Notes
====================

Contents
==========

 * [Introduction](#introduction)


Introduction
===============

[Effective C++](http://book.douban.com/subject/1842426/)属于pratice实践类的书籍. 主要传授工程中碰到的问题以及积累的经验. 看这类书是帮你快速成长的重要手段.

正如Scott Meyers在前言中所说的:

> 学习程序语言语法是一回事; 学习如何以某种语言设计并实现**高效程序**则是另一回事. 掌握一般性的**设计策略**和带有**具体细节**的特定语法特性是我的忠告.

同时我也比较赞同刘未鹏大神所说, [学习一个新事物](http://mindhacks.cn/2008/07/08/learning-habits-part1/), 你要问三个问题.

> 1 它的本质是什么? 2 它的第一原则是什么? 3 它的知识结构是什么?

看完Effective后, 希望能够得到这三个答案.


### 第一部分: 让自己习惯C++

Item 1: C++是一个语言联邦
=========================

> C++由C, Objected-Oriented C++, Template C++和STL四种次语言组成, 每种次语言都有其守则和范例, 守则都倾向简单, 直观易懂和容易记住. 你需要在四种次语言中进行切换.

> 举个例子, 传递参数使用pass-by-value还是pass-by-reference, C内置类型往往使用值传递, 包括指针; 而迭代器和函数对象基于C指针所以也使用值传递, 但是Object-Oriented C++中的自定义对象使用pass-by-reference-to-const, 从而避免频繁的调用构造函数和析构函数.

本章没有办法举个实际的例子. 

回到前面的问题, 可以对问题3做出一部分解答. 这个应该是C++的知识结构了, 由C, OO C++, 模板以及STL四部分组成. 个人认为C语言为了精简而存在大量的语言缺陷.后面的每个条目中我会记下所有的陷阱问题.


Item 2-3: 尽量以const, enum, inline替换#define; 尽量使用const
=============================================================

编译错误问题
-------------

P13文中提到包含`#define ASPECT_RATIO 1.653`的代码中, 可能出现一个编译错误信息, 该错误信息包括1.653, 而不包含ASPECT\_RATIO, 此外, 如果define语句在其它的头文件中, 将带来更多的麻烦. 现代编译器不太出现1.653, 往往只是说明变量类型而已, `error: invalid conversion from ‘int’ to ‘int\*’`, 同时gcc编译器选项-g中ASPECT\_RATIO往往也不会被替换为1.653. 所以宏使用起来还是很方便的. 当然考虑到其它编译器可能效果不同, 最后还是使用const常量比较好.

见`define.cpp`

C的缺陷1
---------------

常用字符串允许赋值为char\*-based指针, 从而导致段错误

代码如下:   
```
char *p = "test";
*p = 'A';

```

**编译warning**: warning: deprecated conversion from string constant to ‘char*’

**运行error**: Segmentation fault (core dumped)

缺陷改正方法: 使用const char* 来保存test信息. 如果p唯一指向此字符串, 使用const pointer即可.

见`const\_pointer.cpp`

类的const static变量
--------------------

类内部的const static变量仅仅是声明而已, 可以使用, 但是不同取地址以及赋值给引用. 作用类似于define. 只有在cpp文件中定义此变量后, 才会分配内存空间.

更多看[详情](http://stackoverflow.com/questions/23439848/whether-redeclare-a-const-static-variable-outside-a-class-or-not)

```
// *.h
class GamePlayer {
    private:
        static const int NumTurns = 5;  //声明式
        int scores[NumTurns];           //使用该常量
};

// *.cpp
const int GamePlayer::NumTurns;         //定义式
```

**随想**: C++的本质是什么? C++是一个编译语言, 编译器负责了变量声明以及变量定义, 定义时涉及静态内存分配, 甚至还有模板元编程. 那么哪些是在运行时才知道的呢?

见`const\_member.cpp`

错误代码如下: `undefined reference to `Test::a'`

```
struct Test {
    static const int LEN = 5;
    int a[LEN];
};

// const int Test::LEN;

int main() {
    const int *p = &Test::LEN;
    return 0;
}

```

**解释**: 编译过程中所有的Test::LEN都编译为常量了, 没有没有内存分配. 对于PYTHON这种动态语言, 由于所有的标识符可以会被其它程序加载并改变, 所以没有这种常量类型.

注: 某些编译器不支持类内const static变量声明初始化, 此时使用enum替代即可.


inline函数替代宏函数
--------------------

宏函数缺点: 存在副作用, ++/--等操作被复制, 导致运行多次.

```
#define f(a, b) ((a) > (b) ? (a) : (b))
int a = 2;
f(++a, 10); // a = 3
f(++a, 1);  // a = 4

```

函数返回自定义类型时尽量设置为const
-----------------------------------

**作用**:   
> 帮助编译器侦测出错误信息

P18提到, operator\*相乘应该返回const值, 避免被赋值, 由于内置类型的返回值被赋值是非法的.

问: compare函数应该返回const类型吗? 应该其值不应该被赋值

见`const\_return.cpp`

函数const重载
----------------

* 编译器使用bitwise constness(即不修改变量的每个bit), 而实际中使用logical constness, 使用mutable来实现修改

* const重载可以保证const对象和非const对象的正确调用, 副作用是代码的重复性.

见`const\_function.cpp`

Item 4: 确定对象被使用前已先被初始化
=====================================

> C parts of C++, 仅函数外内置类型会初始化, OO/STL parts of C++, 自定义类型会调用构造函数, 容器会调用元素的函数或者值初始化.

> 如果有多个构造函数, 可以将那些"赋值表现像初始化一样好"的成员变量改用赋值操作, 从而将这些赋值操作移到某个函数中去.

> "成员初始化次序"固定, 先初始化base类, 然后是derived类, class的成员变量按声明顺序进行初始化.

**重点**: 定义于不同编译单元内的non-local static对象(不包括全局作用域static变量), 无法保证初始化顺序. 常用方法是使用单例singleton模式.使用全局函数的local static对象

见`local\_static.cpp`



### 第二部分: 构造/析构/赋值运算


Item 5: 了解C++默认编写并调用哪些构造函数
==========================================

问题: 何时编译器不会生成默认构造函数, 析构函数, 复制拷贝函数以及赋值函数?

    当没有生成对象, 复制或者赋值时; 当base类的相应函数为私有时会报错, 当存在不可赋值的成员,如引用\ostream\const常量等值时, 系统报错; 当自定义了上述函数时, 编译器就不管了

问题: 何时编译器会去生成这些函数?

    一旦创建了对象就会生成构造函数和析构函数, 使用初始化或者赋值就会生成复制或赋值函数.


见`silent\_function.cpp`



Item 6: 若不想使用编译器自动生成的函数, 就该明确拒绝
=====================================================

> 通过Item5中提到了基类private复制和赋值构造方法实现拒绝复制

见`uncopyable.cpp`



Item 7: 为多态基类声明virtual析构函数
========================================


**需求1**: 当基类拥有一个或者多个virtual函数时, 即作为多态使用时, 一定要定义虚析构函数

**方法**: 使用`valgrind`来测试局部销毁, 参见`partial\_delete.cpp`, 顺便提到了对齐问题

**需求2**: 当一个基类需要定义为虚基类时, 没有虚函数可以设置为纯虚函数的话, 可以设置纯虚析构函数并且给出一个定义.

见`pure\_consturctor.cpp`


Item 8: 别让异常逃离析构函数
===============================

**情景**: 如果有一个`vector<Widget> v`, 当它被析构时, 若某个Widget析构报错异常而程序没有终止, 此时大量资源没有析构, 程序行为未定义; 若一个Derived对象析构时出现错误, 报异常, 子类可能没有析构, 此时出现错误. 那么如何处理此类问题呢?

**方法**: 提供一个接口函数来执行有异常的代码, 并在析构函数中吞下它们或者终止程序.

见`exception\_destructor.cpp`


Item 9: 决不在构造函数和析构过程中调用virtual函数
================================================

> 在base class构造期间, virtual函数不是virtual函数. 存在两种解释: 一种是Base类构造函数中, Derived类的成员还没有初始化, 所以调用派生类的虚函数不合适. 另一方面在Base类时, this即表示Base类.


具体见`link\_function.cpp`

> 如果希望在基类中做一些和派生类有关的事情, 通过传参给构造函数来实现.



Item 10: 令operator= 返回一个reference to \*this
=====================================================

> 没什么好说的, 随众吧, 为了支持连锁调用.


Item 11: 在operator=中处理"自我赋值"
=============================================

> 当类中有指针类数据时, 自我赋值时可能删除自己, 导致无法正常赋值.

见`identity\_test.cpp`

解决办法: 

1. 避免在构造函数中使用资源的副本, 而不是引用它.
2. 使用"自我赋值安全性"和"异常安全性"都好的copy-swap或者手工写法

手工写法精巧实用, 喜欢这个

见`identity\_cure.cpp`


Item 12: 复制对象时勿忘其每一个成分
==========================================

> 一旦你自定义了copy复制和赋值函数以及构造函数, 你就承担了初始化, 赋值以及拷贝的重任, 当你添加了新的成员变量时, 你需要主动添加它们, 当然将所有的赋值操作放在一个私有的成员函数里面是极好的; 当我们有了继承类时, 主动调用这些自定义copy方法吧. 赋值构造函数甚至根本就不会调用子类赋值构造函数的哦.

看一下子类为调用父类operator=的情况:

见`assign_fail.cpp`



### 第三部分: 资源管理

> 所谓资源管理就是, 一旦用了它, 将来必须还给系统.资源包括内存, fd, mutex, 图形界面中的字型和笔刷, 数据库连接以及网络socket.


忘记归还资源的几种可能: 忘记delete; 异常; 提前的return.

> 解决方法: 把资源放进对象内, 我们便可依赖C++的"析构函数自动调用机制"确保资源被释放. 从而将手动资源归还变成了**自动化**(诱人的三个字啊)


相对于不同的情形, 处理手段不同

1. 单一区块或函数内的资源分配, 使用智能指针`auto\_ptr`. 例如`std::auto_ptr\<Investment\> pInv(createInvenstment())`
    * 获得资源后立即放到管理对象中 RAII(Resouce Acquisition Is Initialization)
    * 管理对象利用析构函数确保资源被释放
    * 注: 防止多个`auto\_ptr`指向同一对象, 导致多次归还资源. 而多个`auto\_ptr`之间进行复制将导致右操作数置NULL, 从而使左操作数获得资源的唯一拥有权. **STL要求元素具有赋值功能, 所以auto\_ptr不可以使用**

2. 非环状引用下大区域范围使用智慧指针`shared\_ptr`

**注意**: 由于`auto\_ptr`与`shared\_ptr`都使用delete而不是delete\[\], 所以不要出现下面的例子

```
std::auto_ptr<std::string> aps(new std::string[10]);
```

例子见`smart\_ptr.cpp`

















### 第四部分: 设计与声明


### 第五部分: 实现


### 第六部分: 继承和面向对象设计







注意事项
===============

1. **建议引入C++标准的c文件** 引入C中`.h`文件时, `size\_t`等变量存在global作用域`::`中; 而引入C++的`c\*`文件时, 变量在std::中.
