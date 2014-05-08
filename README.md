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


Item 1: C++是一个语言联邦
=========================

> C++由C, Objected-Oriented C++, Template C++和STL四种次语言组成, 每种次语言都有其守则和范例, 守则都倾向简单, 直观易懂和容易记住. 你需要在四种次语言中进行切换.

> 举个例子, 传递参数使用pass-by-value还是pass-by-reference, C内置类型往往使用值传递, 包括指针; 而迭代器和函数对象基于C指针所以也使用值传递, 但是Object-Oriented C++中的自定义对象使用pass-by-reference-to-const, 从而避免频繁的调用构造函数和析构函数.

本章没有办法举个实际的例子. 

回到前面的问题, 可以对问题3做出一部分解答. 这个应该是C++的知识结构了, 由C, OO C++, 模板以及STL四部分组成. 个人认为C语言为了精简而存在大量的语言缺陷.后面的每个条目中我会记下所有的陷阱问题.


Item 2: 尽量以const, enum, inline替换#define
=============================================

编译错误问题
-------------

P13文中提到包含`#define ASPECT_RATIO 1.653`的代码中, 可能出现一个编译错误信息, 该错误信息包括1.653, 而不包含ASPECT\_RATIO, 此外, 如果define语句在其它的头文件中, 将带来更多的麻烦. 现代编译器不太出现1.653, 往往只是说明变量类型而已, `error: invalid conversion from ‘int’ to ‘int\*’`, 同时gcc编译器选项-g中ASPECT\_RATIO往往也不会被替换为1.653. 所以宏使用起来还是很方便的. 当然考虑到其它编译器可能效果不同, 最后还是使用const常量比较好.


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
#define 

```

注意事项
===============

1. **建议引入C++标准的c文件** 引入C中`.h`文件时, `size\_t`等变量存在global作用域`::`中; 而引入C++的`c\*`文件时, 变量在std::中.
