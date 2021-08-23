# C Language Notes

仅资料整理，问题汇总。

Hsiang SHU.   2021-8-1始

---

## 001. char *str与char str[]的区别

C语言中没有特定的字符串类型，常用以下两种方式定义字符串：一种是字符数组，另一种是指向字符串的指针。

两种定义方法：

```c
char str[] = "happy";
char *str = "happy";
```

在修改字符串内容时的区别：

（1）使用字符串数组

```c
char str[20] = "hello";
str[0] = 'H';
printf("%s\n",str);
```

输出结果：

> Hello

（2）使用字符指针

```c
char *str = "hello";
str[0] = 'H';
printf("%s\n",str);
```

输出结果：

> （无打印信息输出）

可见，使用（1）方式定义的字符串其字符是可以修改的，使用（2）方式定义的字符串其字符是不可以修改的。（2）中可以成功编译和链接，但运行时可能会出现错误，我编译与运行的平台是window10平台，运行结果是无打印信息输出，在其他不同的平台运行可能会出现`段错误（Segment Fault）`或者写入位置错误。

这两种表示字符串的方式的主要区别是：

**字符串指针指向的内容是不可修改的，字符数组是可以修改的，即（2）方式定义的字符串保存在常量区，是不可更改的，（1）方式定义的字符串保存在全局数据区或栈区，是可修改的。***

若将这个过程放在函数中，结合局部变量和存储区等知识，可以发现：

```c
char* get_str(void)
{
　　char str[] = {"abcd"};
　　return str;
}
```

char str[] = {"abcd"};**定义了一个局部字符数组，尽管是数组，但它是一个局部变量，**返回它的地址肯定是一个已经释放了的空间的地址。此函数返回的是内部一个局部字符数组str的地址，且函数调用完毕后此数组被销毁，所以你返回的指针也就指向一块被销毁的内存，这种写法是错误的。

```c
char* get_str(void)
{
　　char *str = {"abcd"};
　　return str;
}
```

char* str = {"abcd"};**表示先定义个字符串常量，并将其地址赋给str。**此函数返回的是字符串常量的地址，而像这种字符串都是属于全局的，在编译的时候就已经分配了内存了，只有程序退出的时候才会被销毁，所以返回它的地址是没有问题的，但是你最好返回常量指针，因为你不能去改变字符串常量的值。

```c
char str[] = "abcd"; //sizeof(str) == 5 * sizeof(char)
char* str = "abcd"; //sizeof(str) == 4(x86) or 8(x64)
//sizeof(char) == 1
```

char* str是存储在全局静态存储区，所以虽然是局部变量，但函数返回后依然可以拿到正确的值！
char str[] 是存储在栈上的，local variable ，函数返回后，OS就收回空间了，就不复存在了，所以，拿不到正确的结果！

参考：

[【C语言笔记】char *str与char str[]的区别 ](https://cloud.tencent.com/developer/article/1450996)

[char str[] 与 char *str的区别详细解析](https://www.cnblogs.com/fenghuan/p/4865796.html)

---

## 002. C语言内存分配的方式

内存分配可分为三种：静态存储区、栈区、堆区。

1. `静态存储区`：该内存在程序编译的时候就已经分配好，这块内存在程序的整个运行期间都存在，它主要存放静态数据、全局数据和常量。
2. `栈区`：它的用途是完成函数的调用。在执行函数时，函数内局部变量及函数参数的存储单元在栈上创建，函数调用结束时这些存储单元自动被释放。
3. `堆区`：程序在运行时使用库函数为变量申请内存，在变量使用结束后再调用库函数释放内存。动态内存的生存期是由我们决定的，如果我们不释放内存，就会导致内存泄漏。

C语言一直由下面部分组成：

**正文段**（**code segment/text segment，.text段**）：或称代码段，通常是用来存放程序执行代码的一块内存区域。这部分区域的大小在程序运行前就已经确定，并且内存区域通常属于只读，某些架构也允许代码段为可写，即允许修改程序。在代码段中，也有可能包含一些只读的常数变量，例如字符串常量等。CPU执行的机器指令部分。

**数据段**（**data segment，.data段**）：通常是用来存放程序中已初始化的全局变量的一块内存区域。数据段属于静态内存分配。

**BSS段**（**bss segment，.bss段**）：通常是指用来存放程序中未初始化的全局变量的一块内存区域。BSS是英文Block Started by Symbol的简称。BSS段属于静态内存分配。

**堆**（**heap**）：堆是用于存放进程运行中被动态分配的内存段，它的大小并不固定，可动态扩张或缩减。当进程调用malloc等函数分配内存时，新分配的内存就被动态添加到堆上(堆被扩张)；当利用free等函数释放内存时，被释放的内存从堆上被剔除(堆被缩减)。

**栈**（**stack**）：栈又称堆栈，是用户存放程序临时创建的局部变量，也就是我们函数大括号"{}"中定义的变量(不包括static声明的变量)。除此以外，在函数被调用时，其参数也会被压入发起调用的进程栈中，并且等调用结束后，函数的返回值也会被存放在回栈中。由于栈的先进先出特性，所有栈特别方便用来保存/恢复调用现场。从这个意义上讲，把堆栈看成一个寄存、交换临时数据的内存区。

参考：

[C语言内存空间分布详解](https://blog.csdn.net/z215367701/article/details/75554242)

[C语言存储空间布局以及static解析](https://blog.csdn.net/Sharp_UP/article/details/77104906)

---

## 003. 关于 void*

#### void 的作用

1.对函数返回的限定，这种情况我们比较常见。

2.对函数参数的限定，这种情况也是比较常见的。

一般我们常见的就是这两种情况：

- 当函数不需要返回值值时，必须使用void限定，这就是我们所说的第一种情况。例如：void func（int a,char *b）。
- 当函数不允许接受参数时，必须使用void限定，这就是我们所说的第二种情况。例如：int func(void)。

#### void* 的作用

void 指针可以指向任意类型的数据，就是说可以用任意类型的指针对 void 指针对 void 指针赋值，任何类型的指针都可以直接赋值给它，无需进行强制类型转换。

如果要将 void 指针 p 赋给其他类型的指针，则需要强制类型转换。

```c
int *a;
void *p;
p = a;
a = (int *) p;
```

在 ANSI C 标准中，不允许对 void 指针进行一些算术运算如 p++ 或 p+=1 等，因为既然 void 是无类型，那么每次算术运算我们就不知道该操作几个字节，例如 char 型操作 sizeof(char) 字节，而 int 则要操作 sizeof(int) 字节。而在 GNU 中则允许，因为在默认情况下，GNU 认为 **void \*** 和 **char \*** 一样，既然是确定的，当然可以进行一些算术操作，在这里**sizeof(\*p)==sizeof(char)**。

参考：

[C 语言中 void* 详解及应用](https://www.runoob.com/w3cnote/c-void-intro.html)

***

## 004. 结构体内存大小：字节对齐问题

#### 内存对齐规则

- **变量（结构体变量）的起始地址**能够被其对齐值整除，结构体变量的对齐值为最宽的成员大小
- 结构体每个**成员相对于起始地址**的偏移能够被其自身对齐值整除，如果不能则在前一个成员后面补充字节
- **结构体总体大小**能够被最宽的成员的大小整除，如不能则在后面补充字节

#### 示例

```c
# include <stdio.h>
struct STUDENT
{
    char a;
    char b;
    int c;
}data;
int main(void)
{
    printf("%p, %p, %p\n", &data.a, &data.b, &data.c);  //%p是取地址输出控制符
    printf("%d\n", sizeof(data));
    return 0;
}
```

输出结果是：
00427E68, 00427E69, 00427E6C
8

```
这时我们发现一个问题：所有成员在分配内存的时候都与 4 字节的长度对齐，多个 char 类型时是依次往后填充，但是 char 型后面的 int 型为什么不紧接着后面填充？为什么要另起一行？也就是说，到底什么时候是接在后面填充，什么时候是另起一行填充？
我们说，所有的成员在分配内存时都要与所有成员中占内存最多的数据类型所占内存空间的字节数对齐。假如这个字节数为 N，那么对齐的原则是：理论上所有成员在分配内存时都是紧接在前一个变量后面依次填充的，但是如果是“以 N 对齐”为原则，那么，如果一行中剩下的空间不足以填充某成员变量，即剩下的空间小于某成员变量的数据类型所占的字节数，则该成员变量在分配内存时另起一行分配。
```

（注意上例↑与下例↓的区分）

```c
# include <stdio.h>
struct STUDENT
{
    char a;
    char b;
    char c;
    char d;
    char e;
    int f;
}data;
int main(void)
{
    printf("%p, %p, %p, %p, %p, %p\n", &data.a, &data.b, &data.c, &data.d, &data.e, &data.f);  //%p是取地址输出控制符
    printf("%d\n", sizeof(data));
    return 0;
}
```

输出结果是：
00427E68, 00427E69, 00427E6A, 00427E6B, 00427E6C, 00427E70
12

```c
# include <stdio.h>
struct STUDENT
{
    char name[10];
    int age;
    char sex;
    float score;
}data;
int main(void)
{
    printf("%p, %p, %p, %p, %p, %p, %p, %p, %p, %p, %p, %p, %p\n", &data.name[0], &data.name[1], &data.name[2], &data.name[3], &data.name[4], &data.name[5], &data.name[6], &data.name[7], &data.name[8], &data.name[9], &data.age, &data.sex, &data.score);
    printf("%d\n", sizeof(data));
    return 0;
}
```

输出结果是：
00427E68, 00427E69, 00427E6A, 00427E6B, 00427E6C, 00427E6D, 00427E6E,
00427E6F, 00427E70, 00427E71, 00427E74, 00427E78, 00427E7C
24

（上例注意数组元素是分立来看的，故有如上的输出结果）

参考：

[结构体字节对齐方式](https://www.cnblogs.com/tianzeng/p/9038395.html)

[结构体字节对齐，C语言结构体字节对齐详解](http://c.biancheng.net/view/243.html)

***

## 005. sizeof用法

sizeof的10个特性：

(0)sizeof是运算符，不是函数；

(1)sizeof不能求得void类型的长度；

(2)sizeof能求得void类型的指针的长度；

(3)sizeof能求得静态分配内存的数组的长度!

(4)sizeof不能求得动态分配的内存的大小!

(5)sizeof不能对不完整的数组求长度；

(6)当表达式作为sizeof的操作数时，它返回表达式的计算结果的类型大小，但是它不对表达式求值！

(7)sizeof可以对函数调用求大小，并且求得的大小等于返回类型的大小，但是不执行函数体！

(8)sizeof求得的结构体(及其对象)的大小并不等于各个数据成员对象的大小之和！

(9)sizeof不能用于求结构体的位域成员的大小，但是可以求得包含位域成员的结构体的大小！

```c
int a = 1;
cout << sizeof(a+=1) << endl;
cout << a << endl;
return 0;
```

结果：4，1

参考：

[sizeof的用法](https://blog.csdn.net/cmlxiaogeaaa/article/details/83420440)

***

## 006. 数组与指针的区别

数组：数组在内存中是连续存放的，开辟一块连续的内存空间。数组是根据数组的下进行访问的，多维数组在内存中是按照一维数组存储的，只是在逻辑上是多维的。数组的存储空间，不是在静态区就是在栈上。

指针：指针很灵活，它可以指向任意类型的数据。指针的类型说明了它所指向地址空间的内存。由于指针本身就是一个变量，再加上它所存放的也是变量，所以指针的存储空间不能确定。


#### 指针与静态数组的sizeof操作区别

```c
指针均可看为变量类型的一种。所有指针变量的sizeof 操作结果均为4。
int *p; sizeof(p)=4;

但sizeof(*p)相当于sizeof(int);

对于静态数组，sizeof可直接计算数组大小；
int a[10];char b[]="hello";
sizeof(a)等于4*10=40;
sizeof(b)等于6;
数组的大小：sizeof（数组名）/sizeof（数据类型）

数组做型参时，数组名称当作指针使用！！
void fun(char p[])
{sizeof(p)等于4}  
```

数组传参时，会退化为指针：
（1）退化的意义：C语言只会以值拷贝的方式传递参数，参数传递时，如果只拷贝整个数组，效率会大大降低，并且在参数位于栈上，太大的数组拷贝将会导致栈溢出。
（2）因此，C语言将数组的传参进行了退化。将整个数组拷贝一份传入函数时，将数组名看做常量指针，传数组首元素的地址。

参考：

[sizeof()用法汇总](https://www.cnblogs.com/chengxin1982/archive/2009/01/13/1374575.html)

[数组和指针的区别与联系（详细）](https://blog.csdn.net/cherrydreamsover/article/details/81741459)

***

## 007. 字符数组的溢出（待完善）

```c
#include<stdio.h>
#include<string.h>

int main( int argc, char ** argv)
{
	char str1[9] = {'h', 'e', 'l', 'l', 'o', ' ', '!', '!', '!'};
	char str2[9] = {'h', 'e', 'l', 'l', 'o', ' ', '!', '!'};
	char str3[9] = "hello !!";
	// char str4[9] = "hello !!!";		//error
	char str5[9] = {'h', 'e', 'l', 'l', 'o', '\0', '!', '!'};
	char str6[9] = "hello\0!!";
	
	
	printf("str1 = %s\n", str1);
	printf("str2 = %s\n", str2);
	printf("str3 = %s\n", str3);
	printf("str5 = %s\n", str5);
	printf("str6 = %s\n", str6);
	printf("\n");
	printf("sizeof(str1) = %d\n", sizeof(str1));
	printf("sizeof(str2) = %d\n", sizeof(str2));
	printf("sizeof(str3) = %d\n", sizeof(str3));
	printf("sizeof(str5) = %d\n", sizeof(str5));
	printf("sizeof(str6) = %d\n", sizeof(str6));
	printf("\n");
	printf("strlen(str1) = %d\n", strlen(str1));
	printf("strlen(str2) = %d\n", strlen(str2));
	printf("strlen(str3) = %d\n", strlen(str3));
	printf("strlen(str5) = %d\n", strlen(str5));
	printf("strlen(str6) = %d\n", strlen(str6));
	
	return 0;
} 
```

运行结果：

str1 = hello !!!a
str2 = hello !!
str3 = hello !!
str5 = hello
str6 = hello

sizeof(str1) = 9
sizeof(str2) = 9
sizeof(str3) = 9
sizeof(str5) = 9
sizeof(str6) = 9

strlen(str1) = 12
strlen(str2) = 8
strlen(str3) = 8
strlen(str5) = 5
strlen(str6) = 5



***

## 008. \=\=\=、\=\=与\=

#### 三个等号：等同符

当等号两边的值为相同类型的时候，直接比较等号两边的值，值相同则返回true，若等号两边的值类型不同时直接返回false。（部分已经不支持）

#### 两个等号：等值符

当等号两边的值为相同类型时比较值是否相同，类型不同时会发生类型的自动转换，转换为相同的类型后再作比较。

    类型转换规则：
    1）如果等号两边是boolean、string、number三者中任意两者进行比较时，优先转换为数字进行比较。
    2）如果等号两边出现了null或undefined,null和undefined除了和自己相等，就彼此相等
#### 一个等号：赋值运算符

参考：

[三个等号和两个等号的区别（“==\=”与“\==”的区别）](https://blog.csdn.net/zephyr15/article/details/73864569)

***

## 009. 内存分配函数

#### memset()

```c
#include <string.h>
void *memset(void *s, int c, size_t n);
功能：将s的内存区域的前n个字节以参数c填入
参数：
	s：需要操作内存s的首地址
	c：填充的字符，c虽然参数为int，但必须是unsigned char , 范围为0~255
	n：指定需要设置的大小
返回值：s的首地址
```

#### memcpy()

```c
#include <string.h>
void *memcpy(void *dest, const void *src, size_t n);
功能：拷贝src所指的内存内容的前n个字节到dest所值的内存地址上。
参数：
	dest：目的内存首地址
	src：源内存首地址，注意：dest和src所指的内存空间不可重叠，可能会导致程序报错
	n：需要拷贝的字节数
返回值：dest的首地址
```

#### memmove()

```
memmove()功能用法和memcpy()一样，区别在于：
dest和src所指的内存空间重叠时，memmove()仍然能处理，不过执行效率比memcpy()低些
```

#### memcmp()

```c
#include <string.h>
int memcmp(const void *s1, const void *s2, size_t n);
功能：比较s1和s2所指向内存区域的前n个字节
参数：
	s1：内存首地址1
	s2：内存首地址2
	n：需比较的前n个字节
返回值：
	相等：=0
	大于：>0
	小于：<0
```

#### malloc()

```c
#include <stdlib.h>
void *malloc(size_t size);
功能：在内存的动态存储区(堆区)中分配一块长度为size字节的连续区域，用来存放类型说明符指定的类型。分配的内存空间内容不确定，一般使用memset初始化。
参数：
	size：需要分配内存大小(单位：字节)
返回值：
	成功：分配空间的起始地址
	失败：NULL
```

#### free()

```c
#include <stdlib.h>
void free(void *ptr);
功能：释放ptr所指向的一块内存空间，ptr是一个任意类型的指针变量，指向被释放区域的首地址。对同一内存空间多次释放会出错。
参数：
	ptr：需要释放空间的首地址，被释放区应是由malloc函数所分配的区域。
返回值：无
```

参考：

[C 标准库 - <string.h>](https://www.runoob.com/cprogramming/c-standard-library-string-h.html)

***

## 010. 共用体/联合、位域/位字段、枚举（待完善）

#### union/共用体/联合

```c
union [union tag]
{
   member definition;
   member definition;
   ...
   member definition;
} [one or more union variables];
```



#### 位域/位字段

```c
struct
{
  unsigned int widthValidated;
  unsigned int heightValidated;
} status;
```



#### enum/枚举

```c
enum　枚举名　{枚举元素1,枚举元素2,……};
```



参考：

[C 共用体](https://www.runoob.com/cprogramming/c-unions.html)

[C 位域](https://www.runoob.com/cprogramming/c-bit-fields.html)

[C enum](https://www.runoob.com/cprogramming/c-enum.html)

***

## 011. 库函数sprintf()

#### 描述

C 库函数 **int sprintf(char \*str, const char \*format, ...)** 发送格式化输出到 **str** 所指向的字符串。

#### 声明

下面是 sprintf() 函数的声明。

```
int sprintf(char *str, const char *format, ...)
```

#### 参数

- **str** -- 这是指向一个字符数组的指针，该数组存储了 C 字符串。
- **format** -- 这是字符串，包含了要被写入到字符串 str 的文本。它可以包含嵌入的 format 标签，format 标签可被随后的附加参数中指定的值替换，并按需求进行格式化。

参考：

[C 库函数 - sprintf()](https://www.runoob.com/cprogramming/c-function-sprintf.html)

***

## 0







***

## 0















[length]: 