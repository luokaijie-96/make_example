补充：gcc使用技巧
gcc是GNU Compiler Collection（GNU编译器套件）的缩写，是一个广泛使用的编程语言编译器。它支持多种编程语言，包括C、C++、Objective-C、Fortran、Ada和Go等。下面是gcc的常用参数和其作用的简要说明：

-c：只编译源文件，生成目标文件（.o文件），不进行链接操作。
-o：指定输出文件的名称。
-I：指定头文件的搜索路径。
-L：指定库文件的搜索路径。
-l：链接时使用的库文件。
-g：生成调试信息，用于调试程序。
-Wall：开启所有警告信息。
-Werror：将警告视为错误。
-std：指定使用的C或C++标准。
-O：优化级别，包括-O0（无优化）、-O1（基本优化）、-O2（更多优化）和-O3（最大优化）等。
-shared：生成一个共享库文件（动态库）。
-fPIC：生成位置无关的代码，用于生成动态库。
-pthread：链接多线程库。


gcc常用参数
-v 查看gcc版本号, --version也可以
-E 生成预处理文件
-S 生成汇编文件
-c 只编译, 生成.o文件, 通常称为目标文件
-I （大写 i, include的第一个字母 ）指定头文件所在的路径
-L （libarary）指定库文件所在的路径
-l （小写的 L,link ）指定库的名字
# -l参数(小写)就是用来指定程序要链接的库，-l参数紧接着就是库名
# 在/lib和/usr/lib和/usr/local/lib里的库直接用-l参数就能链接
# 链接glog库 g++ -lglog test.cpp

# 如果库文件没放在上面三个目录里，需要使用-L参数(大写)指定库文件所在目录
# -L参数跟着的是库文件所在的目录名
-o 指定生成的目标文件的名字
-g 包含调试信息, 使用gdb调试需要添加-g参数
-On n=0∼3 编译优化,n越大优化得越多
## 所谓优化，例如省略掉代码中从未使用过的变量、直接将常量表达式用结果值代替等等，
这些操作会缩减目标文件所包含的代码量，提高最终生成的可执行文件的运行效率。

# -O 选项告诉 g++ 对源代码进行基本优化。这些优化在大多数情况下都会使程序执行的更快。如-O2，-O3，-On（n 常为0–3）
# -O 同时减小代码的长度和执行时间，其效果等价于-O1
# -O0 表示不做优化
# -O1 为默认优化
# -O2 除了完成-O1的优化之外，还进行一些额外的调整工作，如指令调整等。
# -O3 则包括循环展开和其他一些与处理特性相关的优化工作。
# 选项将使编译的速度比使用 -O 时慢， 但通常产生的代码执行速度会更快。
# 使用 -O2优化源代码，并输出可执行文件
-Wall 提示更多警告信息（例如提醒一些没有使用的变量）
-w 关闭警告提示





3、静态库（static library）
静态库按照习惯, 一般以.a做为文件后缀名.静态库的命名一般分为三个部分：

前缀：lib
库名称：自定义即可, 如test
后缀：.a
所以最终的静态库的名字应该为：libtest.a

1 静态库的制作
1) 将.c文件编译成.o文件

gcc -c fun1.c fun2.c

//或者分别生成.o文件:
gcc -c fun1.c -o fun1.o
gcc -c fun2.c -o fun2.o
2) 使用打包工具ar(archive)将准备好的.o文件打包为.a文件( rcs-- r更新、c创建、s建立索引)

    ar rcs libtest1.a fun1.o fun2.o





4、共享库（shared library）/动态库
按照习惯, 一般以”.so”做为文件后缀名. 共享库的命名一般分为三个部分：

前缀：lib
库名称：自己定义即可, 如test
后缀：.so
所以最终的静态库的名字应该为：libtest.so


1 动态库的制作
//1 将.c文件编译成.o文件
gcc -fpic -c fun1.c fun2.c
//参数：-fpic创建与地址无关的编译程序(pic, position independent code), 目的就是为了能够在多个应用程序间共享.
//2 使用gcc将.o文件编译成库文件
gcc -shared fun1.o fun2.o -o libtest2.so
2 动态库的使用
gcc -o main2 main.c -I./include -L./lib -ltest2

用到的参数：

-I: （大写 i,include的第一个字母 ）指定main.c文件用到的头文件head.h所在的路径
-L：（libarary）指定要连接的库的所在目录
-l：（小写的 L,link ）指定链接时需要的静态库, 去掉前缀和后缀




objdump -t app.1.0.0.0 > app.symbol.txt
objdump -d -S  app.1.0.0.0 > app.lst












查看.a文件方法
要查看.a文件的内容，可以使用ar命令。下面是一些常见的用法：

列出.a文件中包含的所有文件：
ar t <filename.a>
1、提取.a文件中的单个文件：
ar x <filename.a> <filename.o>

2、将.a文件中的所有文件提取到当前目录：
ar x <filename.a>

3、在.a文件中添加新文件：
ar r <filename.a> <filename.o>

4、替换.a文件中的现有文件：
ar r <filename.a> <filename.o>

请注意，.a文件通常是静态库文件，包含编译后的目标文件。如果您想查看目标文件的内容，可以使用objdump或readelf等工具。

SO文件查询
要查看.so文件的内容，你可以使用以下命令：

列出.so文件中包含的符号表：
nm -D <filename.so>

1、列出.so文件中包含的所有函数和变量：
objdump -T <filename.so>

2、查看.so文件中某个函数的汇编代码：
objdump -d -M intel <filename.so> | grep <function_name>

3、查看.so文件的头部信息：
readelf -h <filename.so>

请注意，.so文件通常是共享库文件，包含已编译的可重定位目标文件。这些命令将允许查看.so文件中的各种元素，例如符号表、函数、变量和汇编代码。

命令介绍
nm是"Symbol table Namer"的缩写。nm命令可以列出目标文件中定义和引用的符号，并且可以根据不同的选项以不同的格式显示这些符号信息。在Linux系统上，nm命令通常与C/C++编译器一起使用，用于查看编译后的二进制文件（例如可执行文件、静态库文件、共享库文件）中的符号表信息。



nm libmylib.a 

mylib.o:
0000000000000000 T mylib
U puts

mylib_test1.o:
0000000000000010 r __func__.2286
0000000000000000 T mylib_test1
U printf

mylib_test2.o:
0000000000000010 r __func__.2286
0000000000000000 T mylib_test2
U printf

