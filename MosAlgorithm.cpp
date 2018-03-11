1 更严格的类型检查
1.1 问题
C++在类型检查上比C语言要严格。主要表现在增加了字符常量类型，强化了枚举类型，对指针运算要求更严格等。
1.2 步骤
实现此案例需要按照如下步骤进行。
步骤一：增加了字符常量类型
代码如下：
#include <iostream>
int main(int argc, const char* argv[]) {
    std::cout << sizeof('x') << std::endl;
    return 0;
}
上述代码中，以下代码：
std::cout << sizeof('x') << std::endl;
输出结果为1，而在C语言中，用printf函数输出结果则为sizeof（int）的值。
步骤二：强化了枚举类型
代码如下：
#include <iostream>
int main(int argc, const char* argv[]) {
    std::cout << sizeof('x') << std::endl;
    enum Color {
        RED, YELLOW, BLUE, WHITE, BLACK
    };
    Color color = RED;
    int n;
    n = YELLOW;
    return 0;
}
上述代码中，以下代码：
int n;
n = YELLOW;
是错误的。在C++中不能将枚举常量直接赋值给一个整型变量。
步骤三：对指针运算要求更严格
代码如下：
#include <iostream>
int main(int argc, const char* argv[]) {
    std::cout << sizeof('x') << std::endl;
    enum Color {
        RED, YELLOW, BLUE, WHITE, BLACK
    };
    Color color = RED;
    int n;
    n = YELLOW;
    int* p;
    void* a = NULL;
    p = a;
    a = a + 1;
    return 0;
}
上述代码中，以下代码：
p = a;
是错误的。因为C++中不允许将void*类型的指针赋值给其它类型的指针。
上述代码中，以下代码：
a = a + 1;
也是错误的。因为C++中void*类型的指针不能进行运算。
2 Hello, World !
2.1 问题
使用vi编写HelloWorld.cpp程序，运行后，在控制台输出“Hello World！”
2.2 步骤
实现此案例需要按照如下步骤进行。
步骤一：打开vi，编辑源程序
代码如下：
#include <iostream>
int main(int argc, const char* argv[]) {
    std::cout << "Hello World!" << std::endl;
    return 0;
}
上述代码中，以下代码：
std::cout << "Hello World!" << std::endl;
是在控制台上输出字符串“Hello World！”，其中std::cout是一个对象，在本语句中相当于C语言中的printf函数。<<为输出流控制符。std：：endl表示输出一个换行符，相当于C语言中的\n。
步骤二：使用g++进行编译链接
在控制台使用g++编译器对源代码进行编译链接，生成可执行文件。运行查看结果。
3 名字空间的定义与合并
3.1 问题
大型程序中往往会使用多个独立开发的库，库中不可避免的出现同名的变量、函数或类、模板等，造成名称的冲突。名字空间是为了防止名字冲突提供的一种机制。通过使用namespace XXX可以将你所使用的库的变量、函数、类放入名字空间中，形成自己的作用域，避免名字冲突。
3.2 步骤
实现此案例需要按照如下步骤进行。
步骤一：名字空间的定义
语法格式：
namespace 名字空间名{
    名字空间成员1;
    名字空间成员2;
}
其中：
1)namespace是定义名字空间的关键字。
2)名字空间名与变量名一样是一个标识符，在定义它的作用域内必须保持唯一。
3)名字空间成员可以是能出现在全局作用域中的任何声明，包括：变量、函数、结构体、类、模板及其他名字空间等。
注意：
1)名字空间结束后无需分号。
2)名字空间可以在全局作用域内，也可以在其它名字空间中，但不能在函数或类的定义中。
代码如下：
namespace ns {
    int var = 0;
    void fun(void) {
        int a = 10;
        std::cout << "a = " << a << std::endl;
    }
} //注意此处无分号
int main(int argc, const char* argv[]) {
    std::cout << "ns::var = " << ns::var << std::endl;
    ns::fun();
    return 0;
}
上述代码中，定义了一个名字空间ns，其中包含两个成员，一个是整型变量var，另一个是函数fun。
步骤二：名字空间的合并
命名空间可以定义在几个不同的部分。
代码如下：
#include <iostream>
namespace ns {
    int var = 0;
    void fun(void) {
        int a = 10;
        std::cout << "a = " << a << std::endl;
    }
}
namespace ns {
    struct type {
        int a;
        float b;
    };
}
int main(int argc, const char* argv[]) {
    ns::type st = {10, 20.5};
    std::cout << "st.a = " << st.a << std::endl;
    std::cout << "st.b = " << st.b << std::endl;
    return 0;
}
上述代码中，名字空间ns被分在两个部分。第一部分之前没有ns的名字空间，所以会创建一个新的名字空间，但第二部分为已经存在的名字空间，所以不会新建名字空间，只是在已有的空间内添加成员。
本案例中名字空间定义的完整代码如下所示：
namespace ns {
    int var = 0;
    void fun(void) {
        int a = 10;
        std::cout << "a = " << a << std::endl;
    }
} //注意此处无分号
int main(int argc, const char* argv[]) {
    std::cout << "ns::var = " << ns::var << std::endl;
    ns::fun();
    return 0;
}
本案例中名字空间合并的完整代码如下所示：
#include <iostream>
namespace ns {
    int var = 0;
    void fun(void) {
        int a = 10;
        std::cout << "a = " << a << std::endl;
    }
}
namespace ns {
    struct type {
        int a;
        float b;
    };
}
int main(int argc, const char* argv[]) {
    ns::type st = {10, 20.5};
    std::cout << "st.a = " << st.a << std::endl;
    std::cout << "st.b = " << st.b << std::endl;
    return 0;
}
4 名字空间的声明与定义可以分开
4.1 问题
名字空间的声明和定义可以分开，但是定义部分需要借助作用域限定操作符“::”指明所定义的成员隶属于哪个名字空间。
4.2 步骤
实现此案例需要按照如下步骤进行。
步骤一：名字空间的声明
代码如下：
#include <iostream>
namespace ns {
    extern int var;
    void fun(void);
}
上述代码中，整型变量var前面加extern表示此变量将在名字空间外定义。
步骤二：名字空间的定义
代码如下：
#include <iostream>
namespace ns {
    extern int var;
    void fun(void);
}
int ns::var = 10;
void ns::fun(void) {
    int a = 10;
    std::cout << "a = " << a << std::endl;
}
上述代码中由于是在名字空间外定义，所以必须使用名字空间名加作用域运算符ns：：指明变量或函数是哪一个名字空间的。
5 作用域限定符
5.1 问题
作用域限定符为两个冒号::，其作用是通知编译器应从作用域限定符左侧的名字所示的作用域中寻找右侧那个名字，即指定访问哪个名字空间的哪个成员。
5.2 步骤
实现此案例需要按照如下步骤进行。
步骤一：使用作用域限定符
代码如下所示：
#include <iostream>
namespace ns {
    int var = 0;
    void fun(void) {
        int a = 10;
        std::cout << "a = " << a << std::endl;
    }
}
int main(int argc, const char* argv[]) {
    std::cout << "ns::var = " << ns::var << std::endl;
    ns::fun();
    return 0;
}
上述代码中，std：：cout表示是使用标准库名字空间std中的成员cout；ns：：var表示使用自定义名字空间ns中的成员var。
5.3 完整代码

6 名字空间指令
6.1 问题
名字空间指令表示在当前作用域中对某个名字空间的所有成员可见，而外层作用域的同名实体将被隐藏。
6.2 步骤
实现此案例需要按照如下步骤进行。
步骤一：使用名字空间指令
代码如下所示：
#include <iostream>
namespace ns {
    int var = 0;
    void fun(void) {
        int a = 10;
        std::cout << "a = " << a << std::endl;
    }
}
using namespace ns;
int main(int argc, const char* argv[]) {
    std::cout << "ns::var = " << var << std::endl;
    fun();
    return 0;
}
上述代码中，以下代码：
using namespace ns;
指定ns名字空间中的所有成员，在该行语句以下的所有语句中均可直接使用。
上述代码中，以下代码：
std::cout << "ns::var = " << var << std::endl;
变量var是ns名字空间中的变量，由于使用了名字空间指令，所以可以直接使用，其前面无需添加作用域限定符ns::。
步骤二：使用名字空间指令引发的冲突
代码如下所示：
#include <iostream>
namespace ns {
    int var = 0;
    void fun(void) {
        int a = 10;
        std::cout << "a = " << a << std::endl;
    }
}
namespace ns1 {
    int var = 0;
}
如果有两个名字空间，ns和ns1，其中都有整型变量var，此时对它们同时使用名字空间指令using将引发冲突。代码如下所示：
#include <iostream>
namespace ns {
    int var = 0;
    void fun(void) {
        int a = 10;
        std::cout << "a = " << a << std::endl;
    }
}
namespace ns1 {
    int var = 0;
}
using namespace ns;
using namespace ns1;
int main(int argc, const char* argv[]) {
    std::cout << "ns::var = " << var << std::endl;
    fun();
    return 0;
}
上述代码中，以下代码：
using namespace ns;
using namespace ns1;
指定ns名字空间和ns1名字空间中的所有成员，在该行语句以下的所有语句中均可直接使用。这样就导致以下语句：
std::cout << "ns::var = " << var << std::endl;
中的变量var无法确定是ns中的还是ns1中的，而引发冲突。此时只能在变量前添加作用域限定符，代码如下：
std::cout << "ns::var = " << ns：：var << std::endl;
或
std::cout << "ns::var = " << ns1：：var << std::endl;

7 名字空间声明
7.1 问题
名字空间声明表示在当前作用域中对某个名字空间的指定成员可见，而外层作用域的同名实体将被隐藏。
7.2 步骤
实现此案例需要按照如下步骤进行。
步骤一：使用名字空间声明
代码如下所示：
#include <iostream>
namespace ns {
    int var = 0;
    void fun(void) {
        int a = 10;
        std::cout << "a = " << a << std::endl;
    }
}
using ns::var;
int main(int argc, const char* argv[]) {
    std::cout << "ns::var = " << var << std::endl;
    fun();
    return 0;
}
上述代码中，以下代码：
using ns::var;
指定ns名字空间中的变量成员var，在该行语句以下的所有语句中均可直接使用。
上述代码中，以下代码：
std::cout << "ns::var = " << var << std::endl;
变量var是ns名字空间中的变量，由于使用了名字空间声明，所以可以直接使用，其前面无需添加作用域限定符ns::。
上述代码中，以下代码：
fun();
由于没有使用名字空间声明，所以报错，不能使用。
步骤二：使用名字空间声明引发的冲突
代码如下所示：
#include <iostream>
namespace ns {
    int var = 0;
    void fun (void){
        int a = 10;
        std::cout << "a = " << a << std::endl;
    }
}
namespace ns1 {
    int var = 0;
}
using ns::var;
using ns1::var;
上述代码中，以下代码：
using ns::var;
using ns1::var;
由于第一行使用名字空间声明已经在当前作用域内声明了变量var，所以第二行试图再在当前作用域内声明另一个名字空间的同名变量时将报错。

8 名字空间声明与指令的区别
8.1 问题
名字空间声明将所声明的标识符引入当前作用域，就如同该标识符在当前作用域中被声明一样，是针对名字空间中的某个成员而言的。
名字空间指令只是将该名字空间指定为可见，并不对作用域构成任何影响，是针对名字空间中的所有成员而言的。
8.2 步骤
实现此案例需要按照如下步骤进行。
步骤一：名字空间声明与指令的区别
代码如下所示：
#include <iostream>
namespace ns {
    int var = 10;
    void fun(void) {
        int a = 10;
        std::cout << "a = " << a << std::endl;
    }
}
namespace ns1 {
    int var = 0;
}
using ns::fun;
using namespace ns1;
上述代码中，以下代码：
using ns::fun;
是名字空间声明，其作用仅是使名字空间ns中的fun函数成员在当前作用域有效。
上述代码中，以下代码：
using namespace ns1;
是名字空间指令，其作用是使名字空间ns1中的所有成员在当前作用域有效。

9 无名名字空间
9.1 问题
无名名字空间，又称为全局名字空间，不属于任何有名名字空间的标识符，都隶属于无名命名空间。全局作用域中定义的标识符被隐式地添加到无名名字空间中。
9.2 步骤
实现此案例需要按照如下步骤进行。
步骤一：在无名名字空间中定义成员
代码如下所示：
#include <iostream>
int var = 100;
int main(int argc, const char* argv[]) {
    std::cout << "var = " << var << std::endl;
    return 0;
}
上述代码中，全局变量var就定义在无名名字空间中。
步骤二：使用无名名字空间中成员的冲突
代码如下所示：
#include <iostream>
namespace ns {
    int var = 10;
    void fun(void) {
        int a = 10;
        std::cout << "a = " << a << std::endl;
    }
}
int var = 100;
int main(int argc, const char* argv[]) {
    int var = 200;
    std::cout << "var = " << var << std::endl;
    std::cout << "::var = " << ::var << std::endl;
    std::cout << "ns::var = " << ns::var << std::endl;
    return 0;
}
上述代码中，以下代码：
std::cout << "var = " << var << std::endl;
变量var为局部变量，因为局部变量会隐藏全局变量，此时如果想要使用全局变量，需要在变量var前加作用域限定符：：。
代码如下所示：
std::cout << "::var = " << ::var << std::endl;

10 多层名字空间
10.1 问题
多层名字空间，又称为名字空间的嵌套，是指定义在其他名字空中的名字空间。
10.2 步骤
实现此案例需要按照如下步骤进行。
步骤一：定义多层名字空间
代码如下所示：
#include <iostream>
namespace ns1 {
    int var = 10;
    namespace ns2 {
        int var = 20;
        void fun(void) {
            std::cout << "ns2::var = " << var << std::endl;
        }
    }
}
int main(int argc, const char* argv[]) {
    std::cout << "ns1::var = " << ns1::var << std::endl;
    ns1::ns2::fun();
    return 0;
}
上述代码中，以下代码：
void fun(void) {
    std::cout << "ns2::var = " << var << std::endl;
}
中的变量var是名字空间ns2中的整型变量成员var，因为内层空间中的同名成员会隐藏外层空间中的同名成员。
上述代码中，以下代码：
ns1::ns2::fun();
对于内层名字空间中的成员的引用，需要通过作用域限定操作符逐层的分解。

11 C++的结构
11.1 问题
结构体是一种由用户定义的数据类型。在C和C++中都有结构体，但C++中的结构体对C语言中的结构体概念进行了扩充，主要表现在两个方面：首先在定义结构体变量时，C++的结构体可以省略struct关键字；第二点，C++中的结构体可以有函数成员。
11.2 步骤
实现此案例需要按照如下步骤进行。
步骤一：定义C++结构
代码如下所示：
#include <iostream>
struct User {
    char name[256];
    int age;
    void who(void) {
        std::cout << "我是" << name << "，今年" << age << "岁。" << std::endl;
    }
};
int main(int argc, const char* argv[]) {
    User user = {"张飞", 25};
    user.who();
    return 0;
}
上述代码中，以下代码：
void who(void) {
    std::cout << "我是" << name << "，今年" << age << "岁。" << std::endl;
}
是定义在结构体User中的函数，在C++中这样定义是合法的。
上述代码中，以下代码：
User user = {"张飞", 25};
是定义结构体变量，并进行初始化。在定义变量时，C++允许省略关键字struct，直接使用结构体名做数据类型。
上述代码中，以下代码：
user.who();
是对结构体中函数的调用，其方法与引用数据成员相同。

12 C++的匿名联合
12.1 问题
联合可以没有名字，被称为匿名联合。匿名联合仅仅通知编译器它的成员变量共同享一个地址，而变量本身是直接引用的，不使用通常的点号运算符语法。
12.2 步骤
实现此案例需要按照如下步骤进行。
步骤一：定义匿名联合
代码如下所示：
#include <iostream>
int main(int argc, const char* argv[]) {
    union {
        int n;
        char c[sizeof(n)];
    };
    n = 0x12345678;
    for (size_t i = 0; i < sizeof(c); ++i)
        printf("%#x ", c[i]);  // 0x78 0x56 0x34 0x12
    printf("\n");
    return 0;
}
上述代码中，以下代码：
union {
    int n;
    char c[sizeof(n)];
};
定义了一个匿名联合，因为整型变量n占4个字节，而字符数组c的元素个数为sizeof (n)，即也是4个字节，所以整型变量n与字符数组c共用4个字节的地址空间。
上述代码中，以下代码：
n = 0x12345678;
将整型变量n赋值为0x12345678，而这个16进制数刚好占4个字节，由于整型变量n在内存中是倒着存放的，所以n所占的4个字节中第一个存放了十六进制数0x78，第二个存放的是0x56，第三个存放的是0x34，第四个存放的是0x12。又由于字符数组c与整型变量n共用4个字节，所以，以下代码：
for (size_t i = 0; i < sizeof(c); ++i)
printf("%#x ", c[i]);  // 0x78 0x56 0x34 0x12
printf("\n");
将字符数组c逐个输出时，得到的结果是0x78 0x56 0x34 0x12。

13 C++的枚举
13.1 问题
枚举是一种由用户定义的数据类型。在C和C++中都有枚举，但C++中的枚举对C语言中的枚举概念进行了扩充，主要表现在两个方面：首先在定义枚举变量时，C++的枚举可以省略enum关键字；第二点，C++中的枚举是一种独立的数据类型。
13.2 步骤
实现此案例需要按照如下步骤进行。
步骤一：定义匿名联合
代码如下所示：
#include <iostream>
enum Color {
    RED, YELLOW, BLUE, WHITE, BLACK
};
int main(int argc, const char* argv[]) {
    Color color = RED;
    int n;
    n = YELLOW;
    return 0;
}
上述代码中，以下代码：
Color color = RED;
定义了一个枚举类型Color的变量color，并初始化为RED。在C++中，定义是可以省略关键字enum。
上述代码中，以下代码：
int n;
n = YELLOW;
是错误的。在C++中不能将枚举常量直接赋值给一个整型变量。
14 字符串的基本用法
14.1 问题
字符串的基本用法主要是指字符串类对象的定义与初始化方法。
14.2 步骤
实现此案例需要按照如下步骤进行。
步骤一：字符串的实例化
代码如下所示：
#include <iostream>
int main(int argc, const char* argv[]) {
    std::string str;
    std::string str1("Hello World!");
    std::string str2 = std::string();
    std::string str3 = std::string("Hello World!");
    std::string* pstr = new std::string;
    std::string* pstr1 = new std::string();
    std::string* pstr2 = new std::string("Hello World!");
    return 0;
}
上述代码中，以下代码：
std::string str;
std::string str1("Hello World!");
是在栈中隐式实例化字符串类，第一条语句在栈上定义了一个空的字符串对象；第二条语句在栈上定义了一个字符串对象，然后调用构造函数对其进行初始化。
上述代码中，以下代码：
std::string str2 = std::string();
std::string str3 = std::string("Hello World!");
是在栈中显式实例化字符串类，第一条语句在栈上定义了一个空的字符串对象，然后将一个空的字符串临时对象初始化给它；第二条语句同样在栈上定义了一个空的字符串对象，然后将一个初始化好的临时字符串对象赋值给它。
上述代码中，以下代码：
std::string* pstr = new std::string;
std::string* pstr1 = new std::string();
std::string* pstr2 = new std::string("Hello World!");
是在堆中实例化字符串类，然后用字符串指针指向它。
步骤二：C++字符串与C字符串关系
代码如下所示：
#include <iostream>
int main(int argc, const char* argv[]) {
    std::string str;
    std::string str1("Hello World!");
    std::string str2 = std::string();
    std::string str3 = std::string("Hello World!");
    std::string* pstr = new std::string;
    std::string* pstr1 = new std::string();
    std::string* pstr2 = new std::string("Hello World!");
    std::string str4 = "Hello World!";
    char const* pc = "Hello World!";
    std::string str5 = pc;
    char sa[] = "Hello World!";
    std::string str6 = sa;
    char const* pc1 = str6.c_str();
    return 0;
}
上述代码中，以下代码：
std::string str4 = "Hello World!";
可以将一个C语言的字符串直接赋值给一个C++的字符串。
上述代码中，以下代码：
char const* pc = "Hello World!";
std::string str5 = pc;

char sa[] = "Hello World!";
std::string str6 = sa;
可以将一个字符指针或一个字符数组赋值给一个C++的字符串。
上述代码中，以下代码：
char const* pc1 = str6.c_str();
如果希望用字符指针指向C++的字符串，则需要调用字符串类中的c_str()函数，该函数能够返回字符串对象中所存储的字符串数据在内存的地址。
15 字符串的基本运算
15.1 问题
字符串的基本运算主要包括字符串的拼接、赋值和关系运算。
15.2 步骤
实现此案例需要按照如下步骤进行。
步骤一：字符串的拼接
代码如下所示：
#include <iostream>
int main(int argc, const char* argv[]) {
    std::string str1 = "Hello ";
    std::string str2 = "World!";
    std::string str3 = str1 + str2;
    return 0;
}
上述代码中，以下代码：
std::string str3 = str1 + str2;
是将字符串str2的内容拼接到字符串str1的最后一个字符后面，形成一个更大的字符串，赋值给str3。
步骤二：字符串的赋值
代码如下所示：
#include <iostream>
int main(int argc, const char* argv[]) {
    std::string str1 = "Hello ";
    std::string str2 = "World!";
    std::string str3 = str1 + str2;
    std::string str4 = "Hello ";
    std::string str5 = "World!";
    std::string str6;
    str6 = str5;
    str4 += str5;
    return 0;
}
上述代码中，以下代码：
str6 = str5;
是实现字符串对象间的相互赋值，将str5赋值给str6。
上述代码中，以下代码：
str4 += str5;
是实现字符串对象间的复合赋值，本语句实现的是将str4与str5拼接后在赋值给str4。
步骤三：字符串的关系运算
代码如下所示：
#include <iostream>
int main(int argc, const char* argv[]) {
    std::string str1 = "Hello ";
    std::string str2 = "World!";
    std::string str3 = str1 + str2;
    std::string str4 = "Hello ";
    std::string str5 = "World!";
    std::string str6;
    str6 = str5;
    str4 += str5;
    std::string str7 = "zhangfei";
    std::string str8 = "zhaoyun";
    if (str7 == str8)
        std::cout << str7 << "==" << str8 << std::endl;
    else if (str7 < str8)
        std::cout << str7 << "<" << str8 << std::endl;
    else
        std::cout << str7 << ">" << str8 << std::endl;
    return 0;
}
上述代码中，以下代码：
if (str7 == str8)
是判断字符串str7与str8是否相等，其判断的方法是将两个字符串的对应字符进行比较，如果相同则比较下一个对应字符，直到有不同或两个字符串同时结束为止。本例中str7与str8的第一对对应字符是z，第二对对应字符是h，第三对对应字符是a，第四对对应字符是n和o，依次类推。
注意：对应字符进行比较时，是区分大小写的，即a和A是两个不同的字符。
16 字符串的大小和容量
16.1 问题
字符串的大小或长度是指该字符串实际容纳的字符数，而字符串的容量是该字符串最多容纳的字符数。
16.2 步骤
实现此案例需要按照如下步骤进行。
步骤一：字符串的大小
代码如下所示：
#include <iostream>
int main(int argc, const char* argv[]) {
    std::string str1 = "Hello World!";
    std::cout << str1.size() << std::endl;
    std::cout << str1.length() << std::endl;
    str1.resize(20, 'a');
    std::cout << str1 << std::endl;
    return 0;
}
上述代码中，以下代码：
std::cout << str1.size() << std::endl;
std::cout << str1.length() << std::endl;
中的size()和length()成员函数都能获得字符串实际容纳的字符数，length()函数是较早版本的，size()是为了和容器类保持一致新添加的。
上述代码中，以下代码：
str1.resize(20, 'a');
是用来更改字符串实际容纳的字符数的，当第一个参数小于原字符串实际容纳的字符数时，字符串将只保留第一个参数指定的前几个字符，当第一个参数大于原字符串实际容纳的字符数时，字符串多出来的空间将有第二个参数填补。
步骤二：字符串的容量
代码如下所示：
#include <iostream>
int main(int argc, const char* argv[]) {
    std::string str1 = "Hello World!";
    std::cout << str1.size() << std::endl;
    std::cout << str1.length() << std::endl;
    str1.resize(20, 'a');
    std::cout << str1 << std::endl;
    std::cout << str1.capacity() << std::endl;
    str1.reserve(50);
    std::cout << str1.capacity() << std::endl;
    return 0;
}
上述代码中，以下代码：
std::cout << str1.capacity() << std::endl;
获取的是字符串最多容纳的字符数。由于字符串可以动态改变，所以在向字符串添加字符时，字符串会变长，但不是添加一个字符就只变长一个字节，而是变长单位长度的字节数，这样做的好处是避免频繁内存操作，提高效率。
上述代码中，以下代码：
str1.reserve(50);
可以指定字符串的容量。
17 字符串拼接
17.1 问题
字符串拼接是指将两个字符串连接在一起，形成一个更长的字符串。
17.2 步骤
实现此案例需要按照如下步骤进行。
步骤一：字符串拼接
代码如下所示：
#include <iostream>
int main(int argc, const char* argv[]) {
    std::string str1 = "Hello ";
    std::string str2 = "World!";
    str1.append(str2);
    std::cout << str1 << std::endl;
    std::string str3 = "Hello ";
    std::string str4 = "Hello World!";
    str3.append(str4, 6, 6);
    std::cout << str3 << std::endl;
    std::string str5 = "Hello ";
    str5.append(10, 'A');
    std::cout << str5 << std::endl;
    return 0;
}
上述代码中，以下代码：
str1.append(str2);
将字符串str2拼接到字符串str1的后面。
上述代码中，以下代码：
str3.append(str4, 6, 6);
将字符串str4的第6字符开始的连续6个字符，拼接到字符串str3的后面。该函数的第二个参数是从第一个参数的第几个字符开始计算，注意从0开始计算；第三个参数是从第二个参数开始的连续几个字符被拼接。
上述代码中，以下代码：
str5.append(10, 'A');
将10个A拼接到字符串str5的后面。
18 在字符串中搜索特定字符
18.1 问题
在字符串中搜索特定字符是指在字符串中寻找是否存在指定的字符或字符集。
18.2 步骤
实现此案例需要按照如下步骤进行。
步骤一：正向查找
代码如下所示：
#include <iostream>
int main(int argc, const char* argv[]) {
    std::string str1 = "Hello World!";
    std::cout << str1.find_first_of('o') << std::endl;
    std::string str2 = "World!";
    std::cout << str1.find_first_of(str2) << std::endl;
    std::cout << str1.find_first_not_of('o') << std::endl;
    std::cout << str1.find_first_not_of(str2) << std::endl;
    return 0;
}
上述代码中，以下代码：
std::cout << str1.find_first_of('o') << std::endl;
是在字符串str1中查找是否存在字符o，如果存在，则返回字符串中第一个o的位置。
上述代码中，以下代码：
std::cout << str1.find_first_of(str2) << std::endl;
是在字符串str1中查找是否存在字符集str2中的字符，如果存在，则返回字符串中第一个字符集str2中有的字符的位置。
上述代码中，以下代码：
std::cout << str1.find_first_not_of('o') << std::endl;
是在字符串str1中查找第一个与字符o不相同的字符的位置。
上述代码中，以下代码：
std::cout << str1.find_first_not_of(str2) << std::endl;
是在字符串str1中查找第一个与字符集str2中字符不相同的字符的位置。
步骤二：反向查找
代码如下所示：
#include <iostream>
int main(int argc, const char* argv[]) {
    std::string str1 = "Hello World!";
    std::cout << str1.find_first_of('o') << std::endl;
    std::string str2 = "World!";
    std::cout << str1.find_first_of(str2) << std::endl;
    std::cout << str1.find_first_not_of('o') << std::endl;
    std::cout << str1.find_first_not_of(str2) << std::endl;
    std::cout << str1.find_last_of('o') << std::endl;
    std::cout << str1.find_last_of(str2) << std::endl;
    std::cout << str1.find_last_not_of('o') << std::endl;
    std::cout << str1.find_last_not_of(str2) << std::endl;
    return 0;
}
上述代码中，以下代码：
std::cout << str1.find_last_of('o') << std::endl;
是在字符串str1中查找是否存在字符o，如果存在，则返回字符串从后向前查找的第一个o的位置。
上述代码中，以下代码：
std::cout << str1.find_first_of(str2) << std::endl;
是在字符串str1中查找是否存在字符集str2中的字符，如果存在，则返回字符串中从后向前查找的第一个字符集str2中有的字符的位置。
上述代码中，以下代码：
std::cout << str1.find_first_not_of('o') << std::endl;
是在字符串str1中从后向前查找的第一个与字符o不相同的字符的位置。
上述代码中，以下代码：
std::cout << str1.find_first_not_of(str2) << std::endl;
是在字符串str1中从后向前查找的第一个与字符集str2中字符不相同的字符的位置。
19 从字符串中提取子字符串
19.1 问题
从字符串中提取子字符串是指将一个字符串中的一部分截取下来形成一个新的字符串。
19.2 步骤
实现此案例需要按照如下步骤进行。
步骤一：截取子串
代码如下所示：
#include <iostream>
int main(int argc, const char* argv[]) {
    std::string str1 = "Hello World!";
    std::string str2(str1, 0, 6);
    std::cout << str2 << std::endl;
    std::string str3 = str1.substr(6, 6);
    std::cout << str3 << std::endl;
    return 0;
}
上述代码中，以下代码：
std::string str2(str1, 0, 6);
定义一个新的字符串str2，其内容被初始化成字符串str1的第0个字符开始的连续6个字符。第二个参数是从第一个参数的第几个字符开始截取，第三个参数是连续截取几个字符。
上述代码中，以下代码：
std::string str3 = str1.substr(6, 6);
是在字符串str1中截取第6个字符开始的连续6个字符作为一个新的字符串，赋值给str3。第一个参数是从str1的第几个字符开始截取，第二个参数是连续截取几个字符。
20 访问字符串中的单个字符
20.1 问题
访问字符串中的单个字符是像字符数组那样使用下标访问字符串中的某个元素。
20.2 步骤
实现此案例需要按照如下步骤进行。
步骤一：访问字符串中的单个字符
代码如下所示：
#include <iostream>
int main(int argc, const char* argv[]) {
    std::string str1 = "Hello World!";
    std::cout << str1[2] << std::endl;
    std::cout << str1[20] << std::endl;
    std::cout << str1.at(6) << std::endl;
    std::cout << str1.at(20) << std::endl;
    return 0;
}
上述代码中，以下代码：
std::cout << str1[2] << std::endl;
是像访问字符数组那样，将字符串中的第2个字符提取出来显示。值得注意的是如果下标越界，如下代码所示：
std::cout << str1[20] << std::endl;
不会报告错误。
上述代码中，以下代码：
std::cout << str1.at(6) << std::endl;
是使用成员函数来获得字符串中的第6个字符并显示。值得注意的是如果参数越界，如下代码所示：
std::cout << str1.at(20) << std::endl;
函数将抛出异常。
21 字符串的查找与替换
21.1 问题
字符串的查找是指查看在字符串中是否有另一个指定的子串。字符串的替换是指将字符串中指定部分替换成指定的内容。
21.2 步骤
实现此案例需要按照如下步骤进行。
步骤一：字符串的查找
代码如下所示：
#include <iostream>
int main(int argc, const char* argv[]) {
    std::string str1 = "Hello World!";
    std::cout << str1.find("o") << std::endl;
    std::cout << str1.find("o", 5) << std::endl;
    std::cout << str1.rfind("o") << std::endl;
    std::cout << str1.rfind("o", 5) << std::endl;
    return 0;
}
上述代码中，以下代码：
std::cout << str1.find("o") << std::endl;
在字符串str1中查看是否有o，如果有则返回字符o在字符串str1中的位置，否则返回npos，即-1。
上述代码中，以下代码：
std::cout << str1.find("o", 5) << std::endl;
在字符串str1中的第5个位置开始向后查看是否有o，如果有则返回字符o在字符串str1中的位置。
上述代码中，以下代码：
std::cout << str1.rfind("o") << std::endl;
在字符串str1中从后向前查看是否有o，如果有则返回字符o在字符串str1中的位置。
上述代码中，以下代码：
std::cout << str1.rfind("o", 5) << std::endl;
在字符串str1中的第5个位置开始向前查看是否有o，如果有则返回字符o在字符串str1中的位置。
步骤二：字符串的替换
代码如下所示：
#include <iostream>
int main(int argc, const char* argv[]) {
    std::string str1 = "Hello World!";
    std::cout << str1.find("o") << std::endl;
    std::cout << str1.find("o", 5) << std::endl;
    std::cout << str1.rfind("o") << std::endl;
    std::cout << str1.rfind("o", 5) << std::endl;
    std::string str2 = "Tarena";
    str1.replace(6, 5, str2);
    std::cout << str1 << std::endl;
    return 0;
}
上述代码中，以下代码：
str1.replace(6, 5, str2);
是将字符串str1中第6个字符开始的连续5个字符替换成字符串str2的内容。

22 字符串的比较与排序
22.1 问题
字符串的比较是指将两个字符串的对应字符进行比较，如果相同则对比下一对对应字符，知道不同或两个字符串同时结束。
字符串排序是指将字符串数组按指定顺序进行排序。
22.2 步骤
实现此案例需要按照如下步骤进行。
步骤一：字符串的比较
代码如下所示：
#include <iostream>
int main(int argc, const char* argv[]) {
    std::string str1 = "Hello World!";
    std::string str2 = "Hello World!";
    std::cout << str1.compare(str2) << std::endl;
    return 0;
}
上述代码中，以下代码：
std::cout << str1.compare(str2) << std::endl;
是将字符串str1中的第一个字符与字符串str2中的第一个字符进行比较，如果相同，则对比各自的第二个字符，直到两个字符串结束，如果一直相同，则返回0；如果有不同的，则str1中的字符的ASCII码大于str2中的ASCII码，则返回整数；否则返回负数。
步骤二：字符串的排序
代码如下所示：
#include <iostream>
int strCmp(const void* a, const void* b) {
    return (*(std::string const*)a).compare(*(std::string const*)b);
}
int main(int argc, const char* argv[]) {
    std::string str1 = "Hello World!";
    std::string str2 = "Hello World!";
    std::cout << str1.compare(str2) << std::endl;
    std::string str3[] = {"chongqing", "tianjin", "beijing", _    "shanghai"};
    size_t size = sizeof(str3[0]);
    size_t nmemb = sizeof(str3) / size;
    qsort(str3, nmemb, size, strCmp);
    for (int i = 0; i < nmemb; i++)
        std::cout << str3[i] << std::endl;
    return 0;
}
上述代码中，以下代码：
size_t size = sizeof (str3[0]);
是求字符数组str3的第一个元素所占的字节数。该值是作为qsort函数的参数使用。
上述代码中，以下代码：
size_t nmemb = sizeof (str3) / size;
是求字符数组的元素个数。该值也是作为qsort函数的参数使用。
上述代码中，以下代码：
qsort (str3, nmemb, size, strCmp);
是调用库函数qsort对数组str3进行排序。该函数的第一个参数是要排序的数组名，第二个参数是要排序的数组的元素个数，第三个参数是要排序的数组的每个元素所占的字节数，第四个参数是排序条件，它是一个函数的函数名。该函数如下所示：
int strCmp(const void* a, const void* b) {
    return (*(std::string const*)a).compare(*(std::string const*)b);
}
23 字符串的插入与删除
23.1 问题
字符串的插入是指在字符串中指定的位置插入指定的字符串。字符串删除是指在字符串中指定的位置删除指定长度个字符。
23.2 步骤
实现此案例需要按照如下步骤进行。
步骤一：字符串的插入
代码如下所示：
#include <iostream>
int main(int argc, const char* argv[]) {
    std::string str1 = "Hed!";
    std::string str2 = "llo Worl";
    std::cout << str1.insert(2, str2) << std::endl;
    return 0;
}
上述代码中，以下代码：
std::cout << str1.insert(2, str2) << std::endl;
是在字符串str1的第2个位置插入字符串str2的所有内容。
步骤二：字符串的删除
代码如下所示：
#include <iostream>
int main(int argc, const char* argv[]) {
    std::string str1 = "Hed!";
    std::string str2 = "llo Worl";
    std::cout << str1.insert(2, str2) << std::endl;
    std::cout << str1.erase(2, 8) << std::endl;
    return 0;
}
上述代码中，以下代码：
std::cout << str1.erase(2, 8) << std::endl;
是从字符串str1的第2个字符开始，连续删除8个字符。
24 字符串的交换与复制
24.1 问题
字符串的交换是指将两个字符串的内容互相交换。字符串复制是指生成一个新的字符串其内容为原有字符串的内容。
24.2 步骤
实现此案例需要按照如下步骤进行。
步骤一：字符串的交换
代码如下所示：
#include <iostream>
int main(int argc, const char* argv[]) {
    std::string str1 = "Hello ";
    std::string str2 = "World!";
    swap(str1, str2);
    std::cout << str1 << std::endl;
    std::cout << str2 << std::endl;
    return 0;
}
上述代码中，以下代码：
swap(str1, str2);
是将字符串str1的内容与字符串str2的内容进行交换。
步骤二：字符串的复制
代码如下所示：
#include <iostream>
int main(int argc, const char* argv[]) {
    std::string str1 = "Hello ";
    std::string str2 = "World!";
    swap(str1, str2);
    std::cout << str1 << std::endl;
    std::cout << str2 << std::endl;
    std::string str3 = "Hello World!";
    std::string str4;
    str4.assign(str3);
    std::cout << str4 << std::endl;
    std::string str5;
    str5.assign(str3, 2, 8);
    std::cout << str5 << std::endl;
    return 0;
}
上述代码中，以下代码：
str4.assign(str3);
是将字符串str3中的所有字符复制到字符串str4中。
上述代码中，以下代码：
str5.assign(str3, 2, 8);
是将字符串str3中的第2个字符开始连续8个字符复制到字符串str5中。
25 布尔类型
25.1 问题
布尔类型是表示布尔量的数据类型，其值只有真（true）和假（false）两个值，布尔类型的数据占1个字节的存储空间。
25.2 步骤
实现此案例需要按照如下步骤进行。
步骤一：布尔类型
代码如下所示：
#include <iostream>
int main(int argc, const char* argv[]) {
    bool b;
    b = true;
    b = false;
    std::cout << std::boolalpha << b << std::endl;
    std::cout << sizeof(bool) << std::endl;
    b = 5;
    b = 5.5;
    b = 'a';
    std::cout << std::boolalpha << b << std::endl;
    return 0;
}
上述代码中，以下代码：
bool b;
b = true;
b = false;
定义了布尔类型变量b，并将其赋值为true和false。
上述代码中，以下代码：
std::cout << sizeof(bool) << std::endl;
从运行结果可以看出，布尔类型占1个字节的存储空间。
上述代码中，以下代码：
b = 5;
b = 5.5;
b = 'a';
表示任何基本数据类型的数据均可直接复制给布尔变量b。
CSD STDCPP01 DAY02

1 重载关系
1.1 问题
同一作用域内，一组具有相同函数名，不同参数列表的函数，构成重载关系，这组名称相同的函数成为重载函数。重载函数通常完成的功能相近，这样做的好处是减少了函数名的数量，提供了程序的可读性。
1.2 步骤
实现此案例需要按照如下步骤进行。
步骤一：重载关系
代码如下：
#include <iostream>
void print(void) {
    std::cout << "call print function" << std::endl;
}
void print(int n) {
    std::cout << "n = " << n << std::endl;
}
void print(double d) {
    std::cout << "d = " << d << std::endl;
}
void print(int* p) {
    std::cout << "*p = " << *p << std::endl;
}
int main(int argc, const char* argv[]) {
    print();
    print(10);
    print(10.32);
    int n = 100;
    print(&n);
    return 0;
}
上述代码中，以下代码：
void print(void) {
    std::cout << "call print function" << std::endl;
}
void print(int n) {
    std::cout << "n = " << n << std::endl;
}
void print(double d) {
    std::cout << "d = " << d << std::endl;
}
void print(int* p) {
    std::cout << "*p = " << *p << std::endl;
}
定义了一组函数名为print的函数，但这些函数的参数均不相同，这就使它们构成了重载关系，相互称为重载函数。虽然只有一个函数名，但却是四个不同的函数。
注意：参数相同仅返回值不同的两个函数不构成重载关系。
代码如下所示：
void print(void) {
    std::cout << "call print function" << std::endl;
}
int print(void) {
    std::cout << "call print function" << std::endl;
    return 1;
}
上述代码将报错，print函数重定义。
步骤二：同一作用域内的函数才构成重载关系
代码如下：
void foo(void) {
}
namespace ns1 {
    void foo(int a) {
    }
    namespace ns2 {
        void foo(int a, int b) {
        }
        void bar(void) {
            foo(10, 20);
        }
    }
    void hum(void) {
        foo(30);
    }
}
void fun(void) {
    foo();
}
上述代码中有三个同名的foo函数，它们的参数也不相同，但他们不构成重载关系，因为他们分属三个不同的名字空间，在不同的作用域中。

2 完全匹配最优
2.1 问题
重载解析是指调用函数时，根据实参与形参的类型匹配情况，选择一个确定的重载版本的过程。在重载解析时，如果实参的类型与形参的类型完全匹配，则直接确定重载哪个函数。
2.2 步骤
实现此案例需要按照如下步骤进行。
步骤一：完全匹配
代码如下：
#include <iostream>
void print(int n) {
    std::cout << "n = " << n << std::endl;
}
void print(double d) {
    std::cout << "d = " << d << std::endl;
}
void print(int n, double d) {
    std::cout << "n = " << n << std::endl
    << "d = " << d << std::endl;
}
int main(int argc, const char* argv[]) {
    print(10.32);
    return 0;
}
上述代码中，以下代码：
print(10.32);
在编译时需要更具实参的类型决定调用哪一个print函数。在匹配的过程中，首先检查形参的数量是否与实参的数量相同，淘汰不相同的；然后检查每个实参的类型与对应性惨的类型是否一致，淘汰不一致的。完全相同的成为完全匹配。
在本例中，由于实参是双精度浮点数10.32，所以完全匹配的重载函数是：
void print(double d) {
    std::cout << "d = " << d << std::endl;
}

3 常量转换优于升级转换
3.1 问题
在重载的过程中，如果在实参的个数与形参的个数形同的情况下，实参的数据类型与所有重载函数的形参的数据类型均不相同，则需要查看数据类型能否转换。在转换的过程中存在优先级的问题，常量转换优于升级转换。
3.2 步骤
实现此案例需要按照如下步骤进行。
步骤一：常量转换优于升级转换
代码如下所示：
#include <iostream>
void print(int* p, char c) {
    std::cout << "*p = " << *p << std::endl;
    std::cout << "c = " << c << std::endl;
}
void print(const int* p, int n) {
    std::cout << "*p = " << *p << std::endl;
    std::cout << "n = " << n << std::endl;
}
int main(int argc, const char* argv[]) {
    char c = 'a';
    int n = 10, *p = &n;
    print(p, c);
    return 0;
}
上述代码中，以下代码：
print(p, c);
调用print函数时需要在重载函数中进行匹配。由于print函数的两个实参与所有重载函数均不能完全匹配，所以需要进行转换。在转换的过程中，可以将int* p类型转换成const int*p类型，这被称为常量转换。也可以将char c转换成int n，这被称为升级转换。C++规定常量转换优先于升级转换。即调用的是以下函数：
void print(int* p, char c) {
    std::cout << "*p = " << *p << std::endl;
    std::cout << "c = " << c << std::endl;
}

4 升级转换优于标准转换
4.1 问题
在重载的过程中，如果在实参的个数与形参的个数形同的情况下，实参的数据类型与所有重载函数的形参的数据类型均不相同，则需要查看数据类型能否转换。在转换的过程中存在优先级的问题，升级转换优于标准转换。
4.2 步骤
实现此案例需要按照如下步骤进行。
步骤一：升级转换优于标准转换
代码如下所示：
#include <iostream>
void print(char c) {
    std::cout << "c = " << c << std::endl;
}
void print(int n) {
    std::cout << "n = " << n << std::endl;
}
int main(int argc, const char* argv[]) {
    short s = 257;
    print(s);
    return 0;
}
上述代码中，以下代码：
print(s);
调用print函数时需要在重载函数中进行匹配。由于print函数的实参与所有重载函数均不能完全匹配，所以需要进行转换。在转换的过程中，可以将short int类型转换成char类型，这被称为标准转换。也可以将short int转换成int，这被称为升级转换。C++规定升级转换优于标准转换。即调用的是以下函数：
void print(int n) {
    std::cout << "n = " << n << std::endl;
}

5 省略号匹配最差
5.1 问题
在重载的过程中，如果在实参的个数与形参的个数形同的情况下，实参的数据类型与所有重载函数的形参的数据类型均不相同，则需要查看数据类型能否转换。在转换的过程中存在优先级的问题，省略号匹配最差。
5.2 步骤
实现此案例需要按照如下步骤进行。
步骤一：省略号匹配最差
代码如下所示：
#include <iostream>
void print(int n, void* p) {
    std::cout << "n = " << n << std::endl;
}
void print(double d1, ...) {
    std::cout << "d1 = " << d1 << std::endl;
}
int main(int argc, const char* argv[]) {
    double d = 10.23;
    void* p = NULL;
    print(d, p);
    return 0;
}
上述代码中，以下代码：
print(d, p);
调用print函数时需要在重载函数中进行匹配。由于print函数的两个实参与所有重载函数均不能完全匹配，所以需要进行转换。在转换的过程中，可以将double类型转换成int类型，这被称为标准转换。也可以将void*作为省略号...表示的不定个数的参数之一，这被称为省略号匹配。C++规定省略号匹配的优先级最差。即调用的是以下函数：
void print(int n, void* p) {
    std::cout << "n = " << n << std::endl;
}

6 等差歧义
6.1 问题
在重载的过程中，如果在实参的个数与形参的个数形同的情况下，实参的数据类型与所有重载函数的形参的数据类型均不相同，则需要查看数据类型能否转换。在转换的过程中存在优先级的问题，等差歧义。
6.2 步骤
实现此案例需要按照如下步骤进行。
步骤一：等差歧义
代码如下所示：
#include <iostream>
void print(char c) {
    std::cout << "c = " << c << std::endl;
}
void print(int n) {
    std::cout << "n = " << n << std::endl;
}
int main(int argc, const char* argv[]) {
    double d = 10.23;
    print(d);
    return 0;
}
上述代码中，以下代码：
print(d);
调用print函数时需要在重载函数中进行匹配。由于print函数的实参与所有重载函数均不能完全匹配，所以需要进行转换。在转换的过程中，可以将double类型转换成int类型，这被称为标准转换。也可以将double类型转换成char类型，这也被称为标准转换。由于可以转换成两个重载函数，这被称为等差歧义，将出现编译错误。

7 根据函数指针的类型确定重载版本
7.1 问题
函数指针可以指向函数的入口地址。当函数被重载时，函数指针具体指向哪个重载函数，也会根据函数指针的类型进行匹配。
7.2 步骤
实现此案例需要按照如下步骤进行。
步骤一：函数指针重载
代码如下所示：
#include <iostream>
void print(char c) {
    std::cout << "c = " << c << std::endl;
}
void print(int n) {
    std::cout << "n = " << n << std::endl;
}
int main(int argc, const char* argv[]) {
    void (*pfn1)(char c) = print;
    void (*pfn2)(int n) = print;
    pfn1('a');
    pfn2(10);
    return 0;
}
上述代码中，以下代码：
void (*pfn1)(char c) = print;
由于函数指针pfn1指向的函数名print是重载函数的函数名，所以具体指向哪一个重载函数，需要根据函数指针的类型加以匹配。因为函数指针pfn1的类型为void（*）（char），其参数为char类型，所以匹配的函数是：
void print(char c) {
    std::cout << "c = " << c << std::endl;
}
上述代码中，以下代码：
void (*pfn2)(int n) = print;
因为函数指针pfn2的类型为void（*）（int），其参数为int类型，所以匹配的函数是：
void print(int n) {
    std::cout << "n = " << n << std::endl;
}

8 C形式的调用规格
8.1 问题
重载是通过C++换名实现的，换名机制限制了C和C++模块之间的交叉引用。为了能够让C++编译器按照C方式处理函数接口，可以使用extern关键字实现。
8.2 步骤
实现此案例需要按照如下步骤进行。
步骤一：C形式的调用规格
代码如下所示：
extern "C" {
    void printChar(char c) {
        std::cout << "c = " << c << std::endl;
    }
    void printInt(int n) {
        std::cout << "n = " << n << std::endl;
    }
}
int main(int argc, const char* argv[]) {
    printChar('a');
    printInt(10);
    return 0;
}
上述代码中，以下代码：
extern "C" {
    void printChar(char c) {
        std::cout << "c = " << c << std::endl;
    }
    void printInt(int n) {
        std::cout << "n = " << n << std::endl;
    }
}
表示要求C++编译器按照C方式处理函数接口，即不做换名。由于无法执行换名操作，当然也就无法重载，所以需要用不同的函数名区分相似功能函数。
换名操作实际上就是在编译时，将匹配好的重载函数重新命名的方法。实际上，在编译后重载函数的函数名还是不相同的。

9 函数的缺省参数
9.1 问题
函数的缺省参数是指在定义函数的时候，给函数形参一个缺省值，当调用该函数的时后，若未给出实参，则与该实参相对应的形参取缺省值。函数的缺省参数是在编译阶段解决的，因此只能用常量、常量表达式或者全局变量等非局部化数值作为缺省值。
9.2 步骤
实现此案例需要按照如下步骤进行。
步骤一：函数的缺省参数
代码如下所示：
#include <iostream>
void foo(int a, int b = 456) {
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
}
int main(int argc, const char* argv[]) {
    foo(100, 200);
    foo(300);
    return 0;
}
上述代码中，以下代码：
void foo(int a, int b = 456) {
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
}
定义了一个函数foo，该函数有两个形参，第二个形参的后面有一个数值456，它就是缺省参数。
注意：
缺省参数只能是常量、常量表达式或者全局变量，如下代码是错误的：
void foo(int a, int b = a);
带缺省参数的形参b被定义成局部变量形参a的值了。
上述代码中，以下代码：
foo(100, 200);
在调用函数foo时，对于带缺省参数的形参位置可以像以前一样定义实参，这样，缺省参数将变得无效，实参200被赋值给形参。
上述代码中，以下代码：
foo(300);
在调用函数foo时，对于带缺省参数的形参位置也可以不写任何实参值，这样，缺省参数将起作用，相当于把实参456被赋值给形参。

10 声明函数时指定缺省值且必须靠右
10.1 问题
C++语法规定，如果函数的某一个参数具有缺省值，那么该参数后面的所有参数必须都具有缺省值。即所有带缺省参数的形参，必须全部在不带缺省参数的形参的右边。
10.2 步骤
实现此案例需要按照如下步骤进行。
步骤一：右置缺省参数
代码如下所示：
#include <iostream>
void foo(int a, int b = 456) {
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
}
/*
 void foo(int b = 456, int a)
 {
 std::cout << "a = " << a << std::endl;
 std::cout << "b = " << b << std::endl;
 }
 */
int main(int argc, const char* argv[]) {
    foo(100, 200);
    foo(300);
    return 0;
}
上述代码中，以下代码：
/*
 void foo(int b = 456, int a) {
	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
 }
 */
是错误的，带有缺省参数的形参b在不带缺省参数的形参a的左边了。这是违反C++语法规定的。应该写成如下方式：
void foo(int a, int b = 456) {
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
}

11 缺省参数可能引发重载歧义
11.1 问题
在缺省参数和函数重载两个概念同时使用的过程中，有可能会引发歧义。主要是因为缺省参数易导致调用时的二义性造成的。
11.2 步骤
实现此案例需要按照如下步骤进行。
步骤一：缺省参数可能引发重载歧义
代码如下所示：
#include <iostream>
void foo(int a, int b = 456) {
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
}
void foo(int a) {
    std::cout << "a = " << a << std::endl;
}
int main(int argc, const char* argv[]) {
    foo(100, 200);
    foo(300);
    return 0;
}
上述代码中，以下代码：
foo(100, 200);
根据重载函数的定义，会匹配如下函数：
void foo(int a, int b = 456) {
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
}
上述代码中，以下代码：
foo(300);
则会发生语法错误，因为根据重载函数的定义，应该匹配如下函数：
void foo(int a) {
    std::cout << "a = " << a << std::endl;
}
但是，又可以根据缺省参数的概念，匹配如下函数：
void foo(int a, int b = 456) {
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
}
此时编译器无法确定它匹配哪一个函数，造成二义性错误。

12 隐式内联和显式内联
12.1 问题
内联是指用函数已被编译好的二进制代码，替换对该函数的调用指令的方法。内联通过牺牲代码空间的方法，避免了函数调用的开销，赢得了运行时间。
内联分为隐式内联和显式内联两种。
12.2 步骤
实现此案例需要按照如下步骤进行。
步骤一：隐式内联
代码如下所示：
#include <iostream>
struct User {
    char name[256];
    int age;
    void who(void) {
        std::cout << "我是" << name << "，今年" << age << "岁。" << std::endl;
    }
};
int main(int argc, const char* argv[]) {
    User user = {"张飞", 25};
    user.who();
    return 0;
}
上述代码中，以下代码：
void who(void) {
    std::cout << "我是" << name << "，今年" << age << "岁。" << std::endl;
}
函数who被声明和定义在结构体User中。此时，该函数被自动优化为内联函数，称为隐式内联。函数的函数体被编译后成的二进制码，直接替换了上述代码中的以下代码：
user.who();
当程序执行到该语句时，不会再发生函数调用。
步骤二：显式内联
代码如下所示：
#include <iostream>
struct User {
    char name[256];
    int age;
    void who(void) {
        std::cout << "我是" << name << "，今年" << age << "岁。" << std::endl;
    }
    void show(void);
};
inline void User::show() {
    std::cout << "我是" << name << "，今年" << age << "岁。" << std::endl;
}
inline void foo(User* p) {
    std::cout << "我是" << p->name << "，今年" << p->age << "岁。" << std::endl;
}
int main(int argc, const char* argv[]) {
    User user = {"张飞", 25};
    user.who();
    user.show();
    foo(&user);
    return 0;
}
上述代码中，以下代码：
struct User {
    char name[256];
    int age;
    void who(void) {
        std::cout << "我是" << name << "，今年" << age << "岁。" << std::endl;
    }
    void show(void);
};
仅在结构体User中声明了成员函数show，没有在结构体内定义函数，那么该函数将不会被自动优化为内联函数，如果想让它成为内联函数，必须显示手动添加inline关键字，代码如下所示：
inline void User::show() {
    std::cout << "我是" << name << "，今年" << age << "岁。" << std::endl;
}
上述代码中，以下代码：
inline void foo(User* p) {
    p->who();
}
也可以在非结构体成员函数前面加inline，使之成为内联函数。

13 new和delete
13.1 问题
new和delete是C++提供的两个运算符，分别用于动态内存的分配和释放。new相当于C语言中的malloc函数，delete相当于C语言中的free函数。
13.2 步骤
实现此案例需要按照如下步骤进行。
步骤一：动态内存分配
代码如下所示：
#include <iostream>
int main(int argc, const char* argv[]) {
    int* p = new int;
    *p = 10;
    std::cout << *p << std::endl;
    delete p;
    p = new int(100);
    std::cout << *p << std::endl;
    delete p;
    return 0;
}
上述代码中，以下代码：
int *p = new int;
为整型指针变量p分配4个字节的存储空间。
上述代码中，以下代码：
delete p;
将指针p所指向的存储空间释放掉。
上述代码中，以下代码：
p = new int(100);
为整型指针变量p分配4个字节的存储空间，同时将新分配的存储空间初始化为整数100。
步骤二：不能与C语言中的动态内存分配函数混用
代码如下所示：
#include <iostream>
int main(int argc, const char* argv[]) {
    int* p = new int;
    *p = 10;
    std::cout << *p << std::endl;
    delete p;
    p = new int(100);
    std::cout << *p << std::endl;
    delete p;
    p = new int;
    free(p);
    p = (int*)malloc(sizeof(int));
    delete p;
    return 0;
}
上述代码中，以下代码：
p = new int;
free(p);

p = (int*)malloc(sizeof(int));
delete p;
是不建议使用的方法，它会带来不可预知的问题。
步骤三：数组的分配与释放
代码如下所示：
#include <iostream>
int main(int argc, const char* argv[]) {
    int* p = new int;
    *p = 10;
    std::cout << *p << std::endl;
    delete p;
    p = new int(100);
    std::cout << *p << std::endl;
    delete p;
    p = new int;
    free(p);
    p = (int*)malloc(sizeof(int));
    delete p;
    p = new int [4] {10, 20, 30, 40};
    for (int i = 0; i < 4; i++)
        std::cout << p[i] << ' ';
    std::cout << std::endl;
    delete[] p;
    int (*row) [4] = new int [3][4];
    row[1][2] = 15;
    delete[] row;
    return 0;
}
上述代码中，以下代码：
p = new int [4] {10, 20, 30, 40};
为整型指针变量p分配4个整型变量所占的存储空间，即4*4 = 16个字节。这样相当于分配了一个整型数组。用new操作符动态分配数组时，会在数组首元素前面多分配4或8个字节，用以存放数组的长度。
上述代码中，以下代码：
delete[] p;
将分配的16个字节的存储空间释放。注意此时一定不要忘记中括号[]。
上述代码中，以下代码：
int (*row) [4] = new int [3][4];
可以分配多维数组，但需要注意的是，高维数组释放时，依然使用如下语句：
delete[] row;
步骤四：野指针和空指针
代码如下所示：
#include <iostream>
int main(int argc, const char* argv[]) {
    int* p = new int;
    *p = 10;
    std::cout << *p << std::endl;
    delete p;
    p = new int(100);
    std::cout << *p << std::endl;
    delete p;
    p = new int;
    free(p);
    p = (int*)malloc(sizeof(int));
    delete p;
    p = new int [4] {10, 20, 30, 40};
    for (int i = 0; i < 4; i++)
        std::cout << p[i] << ' ';
    std::cout << std::endl;
    delete[] p;
    int (*row) [4] = new int [3][4];
    row[1][2] = 15;
    delete[] row;
    int* p1 = new int;
    *p1 = 200;
    delete p1;
    delete p1;
    int* p2;
    delete p2;
    int* p3 = NULL;
    delete p3;
    return 0;
}
上述代码中，以下代码：
int *p1 = new int;
*p1 = 200;
delete p1;
delete p1;
的最后一行，重复释放p1。因为倒数第二行释放后，p1已经变成野指针，释放野指针会导致程序崩溃。
上述代码中，以下代码：
int *p2;
delete p2;
指针p2定义时没有初始化，p2也是野指针。
上述代码中，以下代码：
int *p3 = NULL;
delete p3;
不会崩溃，因为delete运算符对空指针不作任何操作。
步骤五：内存分配失败
代码如下所示：
#include <iostream>
int main(int argc, const char* argv[]) {
    int* p = new int;
    *p = 10;
    std::cout << *p << std::endl;
    delete p;
    p = new int(100);
    std::cout << *p << std::endl;
    delete p;
    p = new int;
    free(p);
    p = (int*)malloc(sizeof(int));
    delete p;
    p = new int [4] {10, 20, 30, 40};
    for (int i = 0; i < 4; i++)
        std::cout << p[i] << ' ';
    std::cout << std::endl;
    delete[] p;
    int (*row) [4] = new int [3][4];
    row[1][2] = 15;
    delete[] row;
    int* p1 = new int;
    *p1 = 200;
    delete p1;
    //delete p1;
    int* p2;
    //delete p2;
    int* p3 = NULL;
    delete p3;
    try {
        char* p = new char[0xFFFFFFFF];
        p[0] = 'a';
        delete p;
    } catch (std::bad_alloc& ex) {
        std::cerr << "内存分配失败！" << std::endl;
        exit(-1);
    }
    return 0;
}
上述代码中，以下代码：
try {
    char* p = new char[0xFFFFFFFF];
} catch (std::bad_alloc& ex) {
    std::cerr << "内存分配失败！" << std::endl;
    exit(-1);
}
当使用new分配内存失败时，将抛出异常。
步骤六：定位分配
代码如下所示：
#include <iostream>
int main(int argc, const char* argv[]) {
    int* p = new int;
    *p = 10;
    std::cout << *p << std::endl;
    delete p;
    p = new int(100);
    std::cout << *p << std::endl;
    delete p;
    p = new int;
    free(p);
    p = (int*)malloc(sizeof(int));
    delete p;
    p = new int [4] {10, 20, 30, 40};
    for (int i = 0; i < 4; i++)
        std::cout << p[i] << ' ';
    std::cout << std::endl;
    delete[] p;
    int (*row) [4] = new int [3][4];
    row[1][2] = 15;
    delete[] row;
    int* p1 = new int;
    *p1 = 200;
    delete p1;
    //delete p1;
    int* p2;
    //delete p2;
    int* p3 = NULL;
    delete p3;
    try {
        char* p = new char[0xFFFFFFFF];
        p[0] = 'a';
        delete p;
    } catch (std::bad_alloc& ex) {
        std::cerr << "内存分配失败！" << std::endl;
        exit(-1);
    }
    char* pool = new char[1024]; // 分配内存池
    int* pn = new(pool) int (123);
    char* ps = new(pool + 4) char[15];
    strcpy(ps, "Hello, World !");
    double* pd = new(pool + 19) double (3.14);
    std::cout << *pn << std::endl; // 123
    std::cout << ps << std::endl; // Hello, World !
    std::cout << *pd << std::endl; // 3.14
    delete[] pool; // 释放内存池
    return 0;
}
上述代码中，以下代码：
char* pool = new char[1024]; // 分配内存池
分配了一个由1024个元素的字符数组，作为内存池使用。
上述代码中，以下代码：
int* pn = new (pool) int (123);
在内存池中分配4个字节作为一个整型变量使用。
上述代码中，以下代码：
char* ps = new (pool + 4) char[15];
在内存池中分配15个字节作为一个字符型数组使用。值得注意的是pool + 4是从内存池的第5个字节开始分配，否则上面分配的整型变量将被覆盖。
上述代码中，以下代码：
delete[] pool; // 释放内存池
在内存池中分配的变量或数组无需释放，只要最后一次性释放整个内存池即可。

14 引用是另一个变量的别名
14.1 问题
引用是指为对象起了另外一个名字，即两个标识符对应着一块儿存储空间，通过任何一个标识符，都能访问所对应的存储空间。
14.2 步骤
实现此案例需要按照如下步骤进行。
步骤一：引用是另一个变量的别名
代码如下所示：
#include <iostream>
int main(int argc, const char* argv[]) {
    int a = 10;
    int& b = a;
    std::cout << "b = " << b << std::endl;
    int& c = b;
    std::cout << "c = " << c << std::endl;
    int& d;
    int const& e = 100;
    std::cout << "e = " << e << std::endl;
    int const& f = e + 200;
    std::cout << "f = " << f << std::endl;
    return 0;
}
上述代码中，以下代码：
int &b = a;
定义了一个引用b，引用b是整型变量a的别名，即此时访问变量a和访问引用b将起到同样的效果。
上述代码中，以下代码：
int &c = b;
可以为引用再定义引用，即引用c是引用b的别名，此时整型变量a就有两个别名，它们分别是b和c。访问变量a和访问引用b、访问引用c将起到同样的效果。
上述代码中，以下代码：
int &d;
是错误的，在定义一个引用的时候，必须对该引用进行初始化。因为引用是起别名，必须知道为谁起别名。
上述代码中，以下代码：
int const& e = 100;
可以为无名对象定义引用，值得注意的是，该引用必须是常引用。

15 引用必须与有效内存相关联
15.1 问题
引用是指为对象起了另外一个名字，该对象必须存在，即占有一块儿存储空间，通过引用能访问所对应的存储空间。
15.2 步骤
实现此案例需要按照如下步骤进行。
步骤一：引用必须与有效内存相关联
代码如下所示：
#include <iostream>
int main(int argc, const char* argv[]) {
    int& a = NULL;
    int& r = *new int (1);
    ++r;
    std::cout << r << std::endl; // 2
    delete &r;
    ++r; // 未定义
    return 0;
}
上述代码中，以下代码：
int& a = NULL;
是错误的，引用必须对应一块存储空间。
上述代码中，以下代码：
int& r = *new int (1);
为堆上的一块儿存储空间建立引用是允许的，这被称为“野引用”或“悬空引用”。
上述代码中，以下代码：
delete &r;
将引用所对应的堆上的存储空间释放。
上述代码中，以下代码：
++r; // 未定义
引用所对应的存储空间被释放后，该引用就不能再被使用。因为其所对应的存储空间已经不存在了。

16 引用不能更换目标
16.1 问题
引用只有在其定义及初始化语境中具有“名”语义，一旦完成了定义及初始化，引用就和普通变量名一样，被赋予了“实”语义，即代表它的目标，而不是别名本身。
16.2 步骤
实现此案例需要按照如下步骤进行。
步骤一：引用不能更换目标
代码如下所示：
#include <iostream>
int main(int argc, const char* argv[]) {
    int a = 10, b = 20;
    int& c = a;
    c = b;
    return 0;
}
上述代码中，以下代码：
c = b;
是将整型变量b的值赋值给引用c，即将整型变量a改成20。此句话不是将引用c由整型变量a的别名改成整型变量b的别名，引用一旦被定义后，就不能改成其他变量的别名了。

17 交换变量的值
17.1 问题
可以将函数的形参声明为引用形式，该形参在参数传递过程中由对应位置的实参初始化，并成为该实参的别名。通过引用型形参，可以在函数体内部修改调用者实参的值，成为除返回值和指针参数之外，第三种由函数内部向函数外部输出数据的途径。
17.2 步骤
实现此案例需要按照如下步骤进行。
步骤一：交换变量的值
代码如下所示：
#include <iostream>
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
int main(int argc, const char* argv[]) {
    int a = 10, b = 20;
    std::cout << "交换前 a = " << a << ",b = " << b << std::endl;
    swap(a, b);
    std::cout << "交换后 a = " << a << ",b = " << b << std::endl;
    return 0;
}
上述代码中，以下代码：
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
定义了一个函数swap，其作用是将形参a和形参b的值进行交换。因为形参a和b都被定义成了引用，所以两个形参分别是对应实参的别名，这样在函数中对形参的操作就转化成了对实参的操作，即将实参的值交换了过来。

18 常引用型参数可接收常量实参
18.1 问题
在C++中，一切常量均带有右值属性。用内容只读的右值对象初始化目标可写的左值引用，将被编译器以放松类型限定为由予以拒绝。常引用型的形参因其对目标的只读性约束，满足了编译器类型限定从紧不从松的原则，可以接收常量型的实参。
18.2 步骤
实现此案例需要按照如下步骤进行。
步骤一：常引用型参数可接收常量实参
代码如下所示：
#include <iostream>
int sum(int const& a, int const& b) {
    return a + b;
}
int main(int argc, const char* argv[]) {
    int c = sum(10, 20);
    std::cout << "c1 = " << c << std::endl;
    int a = 100, b = 200;
    c = sum(a, b);
    std::cout << "c2 = " << c << std::endl;
    return 0;
}
上述代码中，以下代码：
int sum(int const& a, int const& b) {
    return a + b;
}
定义了一个函数sum，该函数的作用是求和。函数有两个形参，是常引用类型，这就意味着在函数sum的函数体内，不能修改常引用a和b的值。
上述代码中，以下代码：
int c = sum(10, 20);
函数sum的实参可以是整型常量，因为形参定义成了常引用类型。
上述代码中，以下代码：
c = sum(a, b);
函数sum的实参也可以是整型变量，只不过在函数sum中实参变成了只读属性。因此，常引用又被称为万能引用。

19 常引用型参数的目标不可修改
19.1 问题
对于常引用类型的形参，即便所传递的实参不是常量，只要函数不需要也不应该对该实参做任何修改，那么接收该实参的形参同样可以被声明为常引用，这样一方面避免了对象复制的开销，同时一旦做出对实参的意外修改，将直接引发编译错误，将修改实参所带来的风险降到最低。
19.2 步骤
实现此案例需要按照如下步骤进行。
步骤一：常引用型参数的目标不可修改
代码如下所示：
#include <iostream>
int sum(int const& a, int const& b) {
    a = 100;
    b = a + 200;
    return a + b;
}
int main(int argc, const char* argv[]) {
    int c = sum(10, 20);
    std::cout << "c1 = " << c << std::endl;
    int a = 100, b = 200;
    c = sum(a, b);
    std::cout << "c2 = " << c << std::endl;
    return 0;
}
上述代码中，以下代码：
a = 100;
b = a + 200;
是错误的。因为常引用a和b此时被定义成了只读属性，即它们只能作为右值使用，不能作为左值来使用。

20 返回有效引用
20.1 问题
函数返回值通常都具有右值属性，在函数的调用者空间根据函数的返回类型创建一个匿名对象，负责接收该函数的返回值，该匿名对象一般是临时对象。如果函数返回的是一个引用，那么用于接收该返回值的就不再是一个临时对象，而是一个引用该函数所返回引用的目标对象的引用，甚至可以是左值引用。
20.2 步骤
实现此案例需要按照如下步骤进行。
步骤一：返回全局、静态、成员变量的引用
代码如下所示：
#include <iostream>
int g = 123;
struct Dummy {
    int m;
    int& foo(void) {
        return g;
    }
    int& bar(void) {
        static int s = 456;
        return s;
    }
    int& hum(void) {
        return m;
    }
};
int main(int argc, const char* argv[]) {
    Dummy dummy = {789};
    int& rg = dummy.foo();
    std::cout << "rg = " << rg << std::endl;
    int& rs = dummy.bar();
    std::cout << "rs = " << rs << std::endl;
    int& rm = dummy.hum();
    std::cout << "rm = " << rm << std::endl;
    return 0;
}
上述代码中，以下代码：
int& foo (void) { return g; }
定义了结构体Dummy的一个成员函数，该函数返回全局变量g的一个引用。
上述代码中，以下代码：
int& rg = dummy.foo ();
定义了一个引用rg，该引用通过返回引用的函数foo使其成为全局变量g的别名，所以，下述语句：
std::cout << "rg = " << rg << std::endl;
输出的是全局变量g的值。
上述代码中，以下代码：
int& bar(void) {
    static int s = 456;
    return s;
}
定义了结构体Dummy的一个成员函数，该函数返回静态局部整型变量s的一个引用。
上述代码中，以下代码：
int& rs = dummy.bar ();
定义了一个引用rs，该引用通过返回引用的函数bar使其成为静态局部整型变量s的别名，所以，下述语句：
std::cout << "rs = " << rs << std::endl;
输出的是静态局部整型变量s的值。
上述代码中，以下代码：
int& hum(void) {
    return m;
}
定义了结构体Dummy的一个成员函数，该函数返回结构体成员变量m的一个引用。
上述代码中，以下代码：
int& rm = dummy.hum ();
定义了一个引用rm，该引用通过返回引用的函数hum使其成为机构体成员变量m的别名，所以，下述语句：
std::cout << "rm = " << rm << std::endl;
输出的是结构体成员变量m的值。
步骤二：返回调用对象自身的引用
代码如下所示：
#include <iostream>
int g = 123;
struct Dummy {
    int m;
    int& foo(void) {
        return g;
    }
    int& bar(void) {
        static int s = 456;
        return s;
    }
    int& hum(void) {
        return m;
    }
    Dummy& up(void) {
        ++m;
        return *this;
    }
};
int main(int argc, const char* argv[]) {
    Dummy dummy = {789};
    int& rg = dummy.foo();
    std::cout << "rg = " << rg << std::endl;
    int& rs = dummy.bar();
    std::cout << "rs = " << rs << std::endl;
    int& rm = dummy.hum();
    std::cout << "rm = " << rm << std::endl;
    dummy.up().up().up();
    std::cout << "rm = " << rm << std::endl;
    return 0;
}
上述代码中，以下代码：
Dummy& up (void) { ++m; return *this; }
定义了结构体Dummy的一个成员函数，该函数返回结构体自身*this的一个引用。
上述代码中，以下代码：
dummy.up().up().up();
相当于写成如下方式：
(dummy.up()).up().up();
因为dummy.up()函数的返回值就是dummy自身，所以（dummy.up()）.up()在第一个up函数返回后等效于（dummy）.up()，依次类推。
步骤三：返回堆变量的引用
代码如下所示：
#include <iostream>
int g = 123;
struct Dummy {
    int m;
    int& foo(void) {
        return g;
    }
    int& bar(void) {
        static int s = 456;
        return s;
    }
    int& hum(void) {
        return m;
    }
    Dummy& up(void) {
        ++m;
        return *this;
    }
};
int& square(int x) {
    int* y = new int;
    *y = x * x;
    return *y;
}
int main(int argc, const char* argv[]) {
    Dummy dummy = {789};
    int& rg = dummy.foo();
    std::cout << "rg = " << rg << std::endl;
    int& rs = dummy.bar();
    std::cout << "rs = " << rs << std::endl;
    int& rm = dummy.hum();
    std::cout << "rm = " << rm << std::endl;
    dummy.up().up().up();
    std::cout << "rm = " << rm << std::endl;
    int& y = square(16);
    std::cout << y << std::endl; // 256
    delete &y;
    return 0;
}
上述代码中，以下代码：
int& square(int x) {
    int* y = new int;
    *y = x * x;
    return *y;
}
定义了一个返回堆上变量引用的函数，在该函数体中，在堆上申请了一块儿存储空间，并返回该存储空间的引用。
上述代码中，以下代码：
int& y = square(16);
定义了一个引用y，该引用是对上申请的一块儿空间的别名。引用y实质上是一种“野引用”或“悬空引用”。
步骤四：返回引用型参数本身
代码如下所示：
#include <iostream>
int g = 123;
struct Dummy {
    int m;
    int& foo(void) {
        return g;
    }
    int& bar(void) {
        static int s = 456;
        return s;
    }
    int& hum(void) {
        return m;
    }
    Dummy& up(void) {
        ++m;
        return *this;
    }
};
int& square(int x) {
    int* y = new int;
    *y = x * x;
    return *y;
}
int const& max(int const& a, int const& b) {
    return a > b ? a : b;
}
int main(int argc, const char* argv[]) {
    Dummy dummy = {789};
    int& rg = dummy.foo();
    std::cout << "rg = " << rg << std::endl;
    int& rs = dummy.bar();
    std::cout << "rs = " << rs << std::endl;
    int& rm = dummy.hum();
    std::cout << "rm = " << rm << std::endl;
    dummy.up().up().up();
    std::cout << "rm = " << rm << std::endl;
    int& y = square(16);
    std::cout << y << std::endl; // 256
    delete &y;
    int a = 123, b = 456;
    std::cout << &a << ' ' << &b << std::endl;
    int const& c = max(a, b);
    std::cout << &c << " : " << c << std::endl;
    return 0;
}
上述代码中，以下代码：
int const& max(int const& a, int const& b) {
    return a > b ? a : b;
}
定义了一个返回常引用的函数，该函数有两个常引用形参，返回的是大的那个常引用形参。
上述代码中，以下代码：
int const& c = max (a, b);
定义了一个常引用c，它将是整型变量a或b的别名，至于最终是哪一个变量的别名，取决于哪个整型变量的值大。在本例中，由于a被初始化成了123，b被初始化成了456，b大于a，所以常引用c就是变量b的别名。
步骤五：不能返回局部变量的引用
代码如下所示：
#include <iostream>
int g = 123;
struct Dummy {
    int m;
    int& foo(void) {
        return g;
    }
    int& bar(void) {
        static int s = 456;
        return s;
    }
    int& hum(void) {
        return m;
    }
    Dummy& up(void) {
        ++m;
        return *this;
    }
};
int& square(int x) {
    int* y = new int;
    *y = x * x;
    return *y;
}
int const& max(int const& a, int const& b) {
    return a > b ? a : b;
}
int& foo(void) {
    int n = 123;
    return n;
}
int main(int argc, const char* argv[]) {
    Dummy dummy = {789};
    int& rg = dummy.foo();
    std::cout << "rg = " << rg << std::endl;
    int& rs = dummy.bar();
    std::cout << "rs = " << rs << std::endl;
    int& rm = dummy.hum();
    std::cout << "rm = " << rm << std::endl;
    dummy.up().up().up();
    std::cout << "rm = " << rm << std::endl;
    int& y = square(16);
    std::cout << y << std::endl; // 256
    delete &y;
    int a = 123, b = 456;
    std::cout << &a << ' ' << &b << std::endl;
    int const& c = max(a, b);
    std::cout << &c << " : " << c << std::endl;
    int& z = foo();
    std::cout << "z = " << z << std::endl;
    return 0;
}
上述代码中，以下代码：
int& foo(void) {
    int n = 123;
    return n;
}
是错误的。因为函数foo返回了局部变量n的引用。由于当函数foo运行结束时，变量n所占的存储空间已经被释放，所以返回的引用就没有一块儿合法的存储空间相对应了，这样必然带来不测的后果。所以下面的代码中：
int &z = foo();
引用z所对应的存储空间是一块儿已经被释放的存储空间，这样使用z将是危险的。

21 将泛型指针转换为具体指针
21.1 问题
static_cast<目标类型> (源类型对象)
编译器对源类型和目标类型做相容性检查，检查不通过报错。
21.2 步骤
实现此案例需要按照如下步骤进行。
步骤一：将泛型指针转换为具体指针
代码如下所示：
#include <iostream>
int main(int argc, const char* argv[]) {
    short x = 10;
    void* v = &x;
    short* p = static_cast<short*>(v);
    std::cout << "x = " << *p << std::endl;
    short x1 = 10, *v1 = &x1;
    //int* p1 = static_cast<int*>(v1); //错误
    //std::cout << "x1 = " << *p1 << std::endl;
    short x2 = 10, y2 = 20;
    void* v2 = &y2;
    int* p2 = static_cast<int*>(v2);
    *p2 = 0;
    std::cout << &x2 << "," << &y2 << std::endl;
    std::cout << "x2 = " << x2 << std::endl;
    return 0;
}
上述代码中，以下代码：
short* p = static_cast<short*>(v);
源类型(void*)和目标类型(short*)只要在一个方向上可以做隐式类型转换，如，void* v = &x;，那么在两个方向上就都可以做静态类型转换。
上述代码中，以下代码：
int* p1 = static_cast<int*> (v1); //错误
源类型(short*)和目标类型(int*)若在两个方向上都不能做隐式类型转换，如，int* p1 = v1;，那么在两个方向上也都不能做静态类型转换。
上述代码中，以下代码：
short x2 = 10, y2 = 20;
void* v2 = &y2;
int* p2 = static_cast<int*> (v2);
虽然void* v2可以静态类型转换成整型指针p2，但由于v2原来是指向short类型变量的指针，这样静态类型转换语法上没有问题，但会造成运行上的逻辑错误，如以下语句：
*p2 = 0;
由于*p2相当于一个整型变量，所以将*p2清零会使得4个字节变成零。我们通过观察短整型变量x2和y2的地址，如以下语句：
std::cout << &x2 << "," << &y2 << std::endl;
可以发现短整型变量y2所占的2个字节后面紧接着就是x2所占的2个字节，这样从y2的第一个字节开始清零，连续4个字节，x2也被清零了。可以通过如下语句验证：
std::cout << "x2 = " << x2 << std::endl;

22 通过去常修改只读变量的值
22.1 问题
const_cast<目标类型> (源类型对象)
编译器检查源类型和目标类型是否同为指针或引用，且其目标类型之间除常属性以外必须完全相同，否则直接报错。
22.2 步骤
实现此案例需要按照如下步骤进行。
步骤一：通过去常修改只读变量的值
代码如下所示：
#include <iostream>
int main(int argc, const char* argv[]) {
    int x = 100;
    int const* cp = &x;
    *cp = 200; // ERROR
    int* p = const_cast<int*>(cp);
    *p = 200;
    std::cout << "x = " << x << std::endl;
    std::cout << "*p = " << *p << std::endl;
    int x1 = 100;
    int const& cr = x1;
    cr = 200; // ERROR
    int& r = const_cast<int&>(cr);
    r = 200;
    std::cout << "x1 = " << x1 << std::endl;
    std::cout << "r = " << r << std::endl;
    return 0;
}
上述代码中，以下代码：
*cp = 200; // ERROR
错误是因为不能通过指针cp修改指针cp所指向的存储单元。
上述代码中，以下代码：
int* p = const_cast<int*> (cp);
因为源类型(int const*)和目标类型(int*)同为指针，并且除常属性以外必须完全相同，所以可以进行去常类型转换，只是指针p没有了常属性。
上述代码中，以下代码：
cr = 200; // ERROR
错误是因为cr为常引用，即不能做左值使用。
上述代码中，以下代码：
int& r = const_cast<int&> (cr);
因为源类型（int const&）和目标类型（int&）同为引用，并且除常属性以外必须完全相同，所以可以进行去常类型转换，只是引用r没有了常属性。

23 从低地址到高地址打印多字节变量
23.1 问题
reinterpret_cast<目标类型> (源类型对象)
编译器检查源类型和目标类型是否同为指针或引用，或者一个是指针一个是整型，否则直接报错。
23.2 步骤
实现此案例需要按照如下步骤进行。
步骤一：从低地址到高地址打印多字节变量
代码如下所示：
#include <iostream>
int main(int argc, const char* argv[]) {
    int n = 0x12345678;
    char* p;
    p = reinterpret_cast<char*>(&n);
    for (int i = 0; i < 4; i++, p++)
        std::cout << std::hex << (int)*p << " " << std::endl;
    std::cout << std::endl;
    return 0;
}
上述代码中，以下代码：
p = reinterpret_cast<char*>(&n);
源类型(int*)和目标类型(char*)同为指针，即可进行重解释类型转换。
上述代码中，以下代码：
for (int i = 0; i < 4; i++, p++)
std::cout << std::hex << (int)* p << " " << std::endl;
因为n为整型变量，整型变量在进行内存操作时一次要处理4个字节。而指针p为字符型指针，则字符变量*p在进行内存操作时一次只处理1个字节，所以要循环4次才能将整型变量n的值全部输出。
对于整型变量n中的值0x12345678在内存中的存放方法是从低地址到高地址存放的，即第一个字节存0x78，第二个字节存0x56，第三个字节存0x34，第四个字节存0x12。指针p指向变量n的第一个字节，这样就可以从低地址到高地址打印整型变量n内的多字节内容了。

CSD STDCPP01 DAY03

1 定义用户类并实例化为对象
1.1 问题
定义一个用户类User，该类包含两个私有的数据成员，它们是姓名name和年龄age;包含六个公有的成员函数，它们是带参构造函数User，设置姓名函数setName，获取姓名函数getName，设置年龄函数setAge，获取年龄函数getAge，自我介绍函数who。
1.2 步骤
实现此案例需要按照如下步骤进行。
步骤一：定义用户类
代码如下：
#include <iostream>
class User {
private:
    std::string m_name;
    int m_age;
public:
    User(std::string const& name, int age) {
        m_name = name;
        m_age = age;
    }
    void setName(std::string const& name) {
        m_name = name;
    }
    std::string getName() {
        return m_name;
    }
    void setAge(const int& age) {
        m_age = age;
    }
    int getAge() {
        return m_age;
    }
    void who(void);
};
void User::who(void) {
    std::cout << "我是" << m_name << "，今年" << m_age << "岁。" << std::endl;
}
上述代码中，以下代码：
class User
定义了一个类，其中class为关键字，表示开始定义一个类；User为标识符，表示类名。
上述代码中，以下代码：
private:
std::string m_name;
int m_age;
定义了两个私有的数据成员，姓名m_name和年龄m_age。
上述代码中，以下代码：
public:
User(std::string const& name, int age) {
    m_name = name;
    m_age = age;
}
void setName(std::string const& name) {
    m_name = name;
}
std::string getName() {
    return m_name;
}
void setAge(const int& age) {
    m_age = age;
}
int getAge() {
    return m_age;
}
void who(void);
定义了五个成员函数，它们是带参构造函数User，设置姓名函数setName，获取姓名函数getName，设置年龄函数setAge，获取年龄函数getAge。
声明了一个成员函数，是自我介绍函数who。该函数的定义在类外实现，如以下代码所示：
void User::who(void) {
    std::cout << "我是" << m_name << "，今年" << m_age << "岁。" << std::endl;
}
在类外定义函数时，注意使用类名加作用域限定符(User::)说明该函数属于哪一个类。
步骤二：将用户类实例化为对象
代码如下所示：
#include <iostream>
class User {
private:
    std::string m_name;
    int m_age;
public:
    User(std::string const& name, int age) {
        m_name = name;
        m_age = age;
    }
    void setName(std::string const& name) {
        m_name = name;
    }
    std::string getName() {
        return m_name;
    }
    void setAge(const int& age) {
        m_age = age;
    }
    int getAge() {
        return m_age;
    }
    void who(void);
};
void User::who(void) {
    std::cout << "我是" << m_name << "，今年" << m_age << "岁。" << std::endl;
}
int main(int argc, const char* argv[]) {
    User user("张飞", 25);
    user.who();
    user.setName("关羽");
    user.setAge(28);
    user.who();
    return 0;
}
上述代码中，以下代码：
User user("张飞", 25);
定义了一个用户类User的对象user。类是用户自定义的一种数据类型，所以可以直接用类名来定义对象。对象名user后面的括号中的内容为类User的构造函数的实参，当为对象user分配完存储空间后将自动调用类的构造函数。
上述代码中，以下代码：
user.who();
user.setName("关羽");
user.setAge(28);
user.who();
是调用类的成员函数。

2 将用户类的声明、实现和使用分别放在三个不同文件里
2.1 问题
类的声明部分声明了类的成员变量，给出构造函数和成员函数的原型，体现操作接口。类的实现部分给出类的构造函数和成员函数的定义，表达了业务逻辑。类的声明和实现一起，构成了类的完整定义。将类分成声明与实现两部分，是因为类的使用者并不关心亦无需了解类的实现细节，甚至不必或不能看到实现文件，只要包含声明文件即可使用类。
2.2 步骤
实现此案例需要按照如下步骤进行。
步骤一：用户类的声明
在User.h文件中声明用户类User，代码如下：
#ifndef __Day03__User__
#define __Day03__User__
#include <iostream>
class User {
private:
    std::string m_name;
    int m_age;
public:
    User(std::string const& name, int age);
    void setName(std::string const& name);
    std::string getName();
    void setAge(const int& age);
    int getAge();
    void who(void);
};
#endif /* defined(__Day03__User__) */
上述代码中，以下代码：
#ifndef __Day03__User__
#define __Day03__User__
......
#endif /* defined(__Day03__User__) */
为条件编译语句，其作用是防止该头文件被重复包含。
步骤二：用户类的实现
在User.cpp文件中声明用户类User，代码如下：
#include "User.h"
User::User(std::string const& name, int age) {
    m_name = name;
    m_age = age;
}
void User::setName(std::string const& name) {
    m_name = name;
}
std::string User::getName() {
    return m_name;
}
void User::setAge(const int& age) {
    m_age = age;
}
int User::getAge() {
    return m_age;
}
void User::who(void) {
    std::cout << "我是" << m_name << "，今年" << m_age << "岁。" << std::endl;
}
步骤三：用户类的使用
在main.cpp文件中使用用户类User，代码如下：
#include "User.h"
int main(int argc, const char* argv[]) {
    User user("张飞", 25);
    user.who();
    user.setName("关羽");
    user.setAge(28);
    user.who();
    return 0;
}

3 类的构造函数可以重载
3.1 问题
因为构造函数带有参数，按照函数重载的概念，只要构造函数的参数类型不同或参数的个数不同，构造函数就可以重载。
3.2 步骤
实现此案例需要按照如下步骤进行。
步骤一：构造函数可以重载
代码如下：
#include <iostream>
class User {
private:
    std::string m_name;
    int m_age;
public:
    User() {
        m_name = "";
        m_age = 0;
    }
    User(std::string const& name, int age) {
        m_name = name;
        m_age = age;
    }
    void setName(std::string const& name) {
        m_name = name;
    }
    std::string getName() {
        return m_name;
    }
    void setAge(const int& age) {
        m_age = age;
    }
    int getAge() {
        return m_age;
    }
    void who(void) {
        std::cout << "我是" << m_name << "，今年" << m_age << "岁。" << std::endl;
    }
};
int main(int argc, const char* argv[]) {
    User user;
    user.setName("关羽");
    user.setAge(28);
    user.who();
    User user1("张飞", 25);
    user1.who();
    return 0;
}
上述代码中，以下代码：
User() {
    m_name = "";
    m_age = 0;
}
User(std::string const& name, int age) {
    m_name = name;
    m_age = age;
}
构造函数通过参数表的差别化形成重载，第一个构造函数为无参构造函数，第二个构造函数带有两个形参。
上述代码中，以下代码：
User user;
定义了一个类User的对象user，由于在定义时没有构造函数参数，所以调用的是无参构造函数。
上述代码中，以下代码：
User user1("张飞", 25);
定义了一个类User的对象user1，由于在定义时有参数，所以调用的是带参构造函数。

4 带缺省参数的构造函数
4.1 问题
因为构造函数带有参数，按照缺省参数的概念，构造函数就可以带有缺省参数。使用缺省参数可以减少构造函数重载版本的数量，但是使用缺省参数时应注意避免与重载冲突。
4.2 步骤
实现此案例需要按照如下步骤进行。
步骤一：带缺省参数的构造函数
代码如下：
#include <iostream>
class User {
private:
    std::string m_name;
    int m_age;
public:
    User(std::string const& name = "", int age = 0) {
        m_name = name;
        m_age = age;
    }
    void setName(std::string const& name) {
        m_name = name;
    }
    std::string getName() {
        return m_name;
    }
    void setAge(const int& age) {
        m_age = age;
    }
    int getAge() {
        return m_age;
    }
    void who(void) {
        std::cout << "我是" << m_name << "，今年" << m_age << "岁。" << std::endl;
    }
};
int main(int argc, const char* argv[]) {
    User user;
    user.setName("关羽");
    user.setAge(28);
    user.who();
    User user1("张飞", 25);
    user1.who();
    return 0;
}
上述代码中，以下代码：
User(std::string const& name = "", int age = 0) {
    m_name = name;
    m_age = age;
}
定义了一个带有缺省参数的构造函数。值得注意的是，如果定义的此构造函数，就不要再重载无参构造函数了，如下代码所示：
User() {
    m_name = "";
    m_age = 0;
}
因为无参构造函数与此构造函数冲突。

5 缺省的构造函数
5.1 问题
缺省构造函数亦称无参构造函数，但其未必真的没有任何参数，为一个有参构造函数的每个参数都提供一个缺省值，同样可以达到无参构造函数的效果。
5.2 步骤
实现此案例需要按照如下步骤进行。
步骤一：缺省构造函数
代码如下：
#include <iostream>
class User {
private:
    std::string m_name;
    int m_age;
public:
    User() {
        m_name = "";
        m_age = 0;
    }
    void setName(std::string const& name) {
        m_name = name;
    }
    std::string getName() {
        return m_name;
    }
    void setAge(const int& age) {
        m_age = age;
    }
    int getAge() {
        return m_age;
    }
    void who(void) {
        std::cout << "我是" << m_name << "，今年" << m_age << "岁。" << std::endl;
    }
};
int main(int argc, const char* argv[]) {
    User user;
    user.setName("关羽");
    user.setAge(28);
    user.who();
    return 0;
}
上述代码中，以下代码：
User() {
    m_name = "";
    m_age = 0;
}
定义了一个缺省构造函数，该构造函数没有参数。值得注意的是，带参构造函数的每个参数如果都有缺省值，如下代码所示：
User(std::string const& name = "", int age = 0) {
    m_name = name;
    m_age = age;
}
也可以称为缺省构造函数，因为当没有实参时，缺省值可以代替实参。

6 编译器提供的缺省构造函数
6.1 问题
如果一个类没有定义任何构造函数，那么编译器会为其提供一个缺省构造函数，该构造函数对基本类型的成员变量，不做初始化；对类类型的成员变量和基类子对象，调用相应类型的缺省构造函数初始化。编译器提供的构造函数不会出现在源文件中，而是直接生成完成特定功能的机器(汇编)指令。
6.2 步骤
实现此案例需要按照如下步骤进行。
步骤一：编译器提供的缺省构造函数
代码如下：
#include <iostream>
class User {
private:
    std::string m_name;
    int m_age;
public:
    void setName(std::string const& name) {
        m_name = name;
    }
    std::string getName() {
        return m_name;
    }
    void setAge(const int& age) {
        m_age = age;
    }
    int getAge() {
        return m_age;
    }
    void who(void) {
        std::cout << "我是" << m_name << "，今年" << m_age << "岁。" << std::endl;
    }
};
int main(int argc, const char* argv[]) {
    User user;
    user.setName("关羽");
    user.setAge(28);
    user.who();
    return 0;
}
上述代码中，没有提供构造函数，而以下语句：
User user;
在为对象user分配完存储空间之后，仍然会调用类User的构造函数，这个被调用的构造函数是编译器为无构造函数的类User自动添加的，其形式如下所示：
User::User() {
}

7 编译器不提供缺省构造函数
7.1 问题
对于已经定义至少一个构造函数的类，无论其构造函数是否带有参数，编译器都不会再为其提供缺省构造函数。这种情况下，若该类需要支持以缺省方式构造对象，则必须自己定义缺省构造函数，否则将导致编译错误。
7.2 步骤
实现此案例需要按照如下步骤进行。
步骤一：编译器不提供缺省构造函数
代码如下：
#include <iostream>
class User {
private:
    std::string m_name;
    int m_age;
public:
    User(std::string const& name, int age) {
        m_name = name;
        m_age = age;
    }
    void setName(std::string const& name) {
        m_name = name;
    }
    std::string getName() {
        return m_name;
    }
    void setAge(const int& age) {
        m_age = age;
    }
    int getAge() {
        return m_age;
    }
    void who(void) {
        std::cout << "我是" << m_name << "，今年" << m_age << "岁。" << std::endl;
    }
};
int main(int argc, const char* argv[]) {
    User user("张飞", 25);
    user.who();
    User user1;
    user1.setName("关羽");
    user1.setAge(28);
    user1.who();
    return 0;
}
上述代码中，由于提供了带参构造函数，编译器就不会再为类User添加缺省构造函数了。这样，上述代码中，以下代码：
User user1;
就会出现编译错误，为防止此类错误，应添加以下缺省构造函数代码：
User() {
    m_name = "";
    m_age = 0;
}

8 数组元素类的缺省构造函数
8.1 问题
在使用数组或容器的时候，经常不对元素进行初始化。由于数组本质上就是多个对象的集合，每个对象在分配完存储空间后都将调用对应类的构造函数。所以，类中应有缺省构造函数。
8.2 步骤
实现此案例需要按照如下步骤进行。
步骤一：数组元素类的缺省构造函数
代码如下：
#include <iostream>
class User {
private:
    std::string m_name;
    int m_age;
public:
    User() {
        m_name = "";
        m_age = 0;
    }
    void who(void) {
        std::cout << "我是" << m_name << "，今年" << m_age << "岁。" << std::endl;
    }
};
int main(int argc, const char* argv[]) {
    User user[5];
    for (int i = 0; i < 5; i++)
        user[i].who();
    return 0;
}
上述代码中，以下代码：
User user[5];
定义了一个类User的对象数组user，该数组有5个数组元素。每个数组元素在分配完存储空间之后，将调用类User的缺省构造函数。

9 子对象类的缺省构造函数
9.1 问题
当一个类中含有另一个类的对象作为数据成员时，有时必须为一个类提供缺省构造函数。因为当给类的对象分配存储空间时，类中的对象数据成员分配完存储空间之后马上会调用对应类的缺省构造函数。
9.2 步骤
实现此案例需要按照如下步骤进行。
步骤一：数组元素类的缺省构造函数
代码如下：
#include <iostream>
class Date {
private:
    int m_year;
    int m_mon;
    int m_day;
public:
    Date(void) {
        m_year = 1970;
        m_mon = 1;
        m_day = 1;
    }
    void show(void) {
        std::cout << m_year << "年" << m_mon << "月" << m_day << "日" << std::endl;
    }
};
class User {
private:
    std::string m_name;
    int m_age;
    Date m_birthday;
public:
    User() {
        m_name = "张三";
        m_age = 20;
    }
    void who(void) {
        std::cout << "我是" << m_name << "，今年" << m_age << "岁。" << std::endl;
        std::cout << "出生日期：";
        m_birthday.show();
        std::cout << std::endl;
    }
};
int main(int argc, const char* argv[]) {
    User user;
    user.who();
    return 0;
}
上述代码中，以下代码：
Date m_birthday;
在类User中含有另一个类Date的对象作为数据成员。在如下语句中：
User user;
定义了类User的对象user。当程序运行到此语句时，会为对象user分配存储空间，首先为m_name分配存储空间，然后为m_age分配存储空间，当为m_birthday分配完存储空间之后，由于m_birthday是对象，所以分配完存储空间后会马上调用类Date的缺省构造函数。正是由于这个原因，当一个类中含有另一个类的对象作为数据成员时，有时必须为一个类提供缺省构造函数。

10 父对象类的缺省构造函数
10.1 问题
如果出于某种原因，对象的对象数据成员确实不宜缺省构造，那么也可以为对象提供自定义的缺省构造函数，在其中显式地以非缺省方式调用对象数据成员的构造函数。
10.2 步骤
实现此案例需要按照如下步骤进行。
步骤一：父对象类的缺省构造函数
代码如下：
#include <iostream>
class Date {
private:
    int m_year;
    int m_mon;
    int m_day;
public:
    Date(int year, int mon, int day) {
        m_year = year;
        m_mon = mon;
        m_day = day;
    }
    void show(void) {
        std::cout << m_year << "年" << m_mon << "月" << m_day << "日" << std::endl;
    }
};
class User {
private:
    std::string m_name;
    int m_age;
    Date m_birthday;
public:
    User(): m_birthday(1970, 1, 1) {
        m_name = "张三";
        m_age = 20;
    }
    void who(void) {
        std::cout << "我是" << m_name << "，今年" << m_age << "岁。" << std::endl;
        std::cout << "出生日期：";
        m_birthday.show();
        std::cout << std::endl;
    }
};
int main(int argc, const char* argv[]) {
    User user;
    user.who();
    return 0;
}
上述代码中，假设类Date出于某种原因，确实不宜缺省构造，必须是带参构造，代码如下所示：
Date(int year, int mon, int day) {
    m_year = year;
    m_mon = mon;
    m_day = day;
}
那么，在类User中又含有类Date的对象的数据成员，代码如下所示：
Date m_birthday;
这样，当给m_birthday分配完存储空间之后，应该马上调用类Date的构造函数，但因为类Date已经有自定义的带参构造函数，所以编译器就不会自动添加缺省构造函数了，但调用带参构造函数必须给出实参，因此必须显式地以非缺省方式调用带参构造函数，代码如下所示：
User(): m_birthday(1970, 1, 1) {
    m_name = "张三";
    m_age = 20;
}

11 支持自定义类型转换的构造函数
11.1 问题
所谓类型转换，其本质都是在创建新对象，该对象的类型由目标类型决定，内容则源自被转换对象，而被转换对象的类型和内容在转换前后不会发生任何变化。
在C++中， 单参构造函数除了是个构造器，还是个默认且隐含的类型转换操作符。
11.2 步骤
实现此案例需要按照如下步骤进行。
步骤一：支持自定义类型转换的构造函数
代码如下：
#include <iostream>
class User {
private:
    std::string m_name;
    int m_age;
public:
    User(std::string const& name, int age) {
        m_name = name;
        m_age = age;
    }
    User(const char* str) {
        m_name = str;
    }
    void who(void) {
        std::cout << "我是" << m_name << "，今年" << m_age << "岁。" << std::endl;
    }
};
int main(int argc, const char* argv[]) {
    User user("张三");
    user.who();
    User user1 = "王五";
    user1.who();
    return 0;
}
上述代码中，以下代码：
User(const char* str) {
    m_name = str;
}
是一个单参构造函数，当以下语句：
User user("张三");
被执行时，这个单参构造函数会被调用，即作为一个构造器来使用。但单参构造函数除了可以作为构造器使用外，还是个默认且隐含的类型转换操作符，如下代码所示：
User user1 = "王五";
这个单参构造函数会将右值const char*类型的"王五"默认地转换成一个User类型的临时对象，再将该临时对象赋值给user1。

12 拷贝构造函数
12.1 问题
拷贝构造函数，是一种特殊的构造函数，用于从一个已定义的对象构造其同类型的副本对象，即对象克隆。
12.2 步骤
实现此案例需要按照如下步骤进行。
步骤一：拷贝构造函数
代码如下：
#include <iostream>
class User {
private:
    std::string m_name;
    int m_age;
public:
    User(std::string const& name, int age) {
        m_name = name;
        m_age = age;
    }
    User(User const& user) {
        m_name = user.m_name;
        m_age = user.m_age;
    }
    void who(void) {
        std::cout << "我是" << m_name << "，今年" << m_age << "岁。" << std::endl;
    }
};
int main(int argc, const char* argv[]) {
    User user("张三", 25);
    user.who();
    User user1 = user;
    user1.who();
    return 0;
}
上述代码中，以下代码：
User(User const& user) {
    m_name = user.m_name;
    m_age = user.m_age;
}
为拷贝构造函数，其唯一的形参必须是引用，但并不限制为const，一般普遍的会加上const限制。当执行以下与赋值有关的语句时：
User user1 = user;
拷贝构造函数会被调用。

13 编译器提供的缺省拷贝构造函数
13.1 问题
如果一个类没有定义拷贝构造函数，那么编译器会为其提供一个缺省拷贝构造函数。在缺省拷贝构造函数中，对基本类型的成员变量，按字节复制；对类类型的成员变量和基类子对象，调用相应类型的拷贝构造函数。
13.2 步骤
实现此案例需要按照如下步骤进行。
步骤一：编译器提供的缺省拷贝构造函数
代码如下：
#include <iostream>
class User {
private:
    std::string m_name;
    int m_age;
public:
    User(std::string const& name, int age) {
        m_name = name;
        m_age = age;
    }
    void who(void) {
        std::cout << "我是" << m_name << "，今年" << m_age << "岁。" << std::endl;
    }
};
int main(int argc, const char* argv[]) {
    User user("张三", 25);
    user.who();
    User user1 = user;
    user1.who();
    return 0;
}
上述代码中没有定义拷贝构造函数，那么编译器会为类User提供一个缺省拷贝构造函数，所以如下语句：
User user1 = user;
仍然能够完成制作副本的工作。只不过完成的过程是这样的：
std::string m_name;
int m_age;
对于类User的两个数据成员，m_name会调用类std：：string的拷贝构造函数，而m_age会按字节拷贝的方式复制。

14 用自定义拷贝构造函数取代缺省拷贝构造函数
14.1 问题
如果自己定义了拷贝构造函数，那么编译器将不再提供缺省拷贝构造函数。这种情况下，所有与对象复制有关的操作，都必须在自定义拷贝构造函数中通过编写代码完成。
14.2 步骤
实现此案例需要按照如下步骤进行。
步骤一：用自定义拷贝构造函数取代缺省拷贝构造函数
代码如下：
#include <iostream>
class User {
private:
    std::string m_name;
    int m_age;
public:
    User(std::string const& name, int age) {
        m_name = name;
        m_age = age;
    }
    User(User const& user) {
        m_name = user.m_name;
        m_age = user.m_age;
    }
    void who(void) {
        std::cout << "我是" << m_name << "，今年" << m_age << "岁。" << std::endl;
    }
};
int main(int argc, const char* argv[]) {
    User user("张三", 25);
    user.who();
    User user1 = user;
    user1.who();
    return 0;
}
上述代码中，以下代码：
User(User const& user) {
    m_name = user.m_name;
    m_age = user.m_age;
}
为自定义拷贝构造函数，此时编译器将不再提供缺省拷贝构造函数。这样如何复制一个当前类的对象就完全取决于自定义拷贝构造函数的函数体如何编写。

15 缺省拷贝构造函数的缺陷
15.1 问题
多数情况下，编译器提供的缺省拷贝构造函数已足够适用，这时无需自己定义拷贝构造函数。特殊情况下，编译器提供的缺省拷贝构造函数可能无法满足要求，这时就必须通过自定义拷贝构造函数，实现特殊的对象复制语义，以弥补缺省拷贝构造函数的缺陷。
15.2 步骤
实现此案例需要按照如下步骤进行。
步骤一：缺省拷贝构造函数的缺陷
代码如下：
#include <iostream>
#include <string>
class User {
private:
    char* m_name;
    int m_age;
public:
    User(char const* name, int age) {
        m_name = new char[strlen(name) + 1];
        strcpy(m_name, name);
        m_age = age;
    }
    void who(void) {
        std::cout << "我是" << m_name << "，今年" << m_age << "岁。" << std::endl;
    }
};
int main(int argc, const char* argv[]) {
    User user("张三", 25);
    user.who();
    User user1 = user;
    user1.who();
    return 0;
}
上述代码中，以下代码：
private:
char* m_name;
int m_age;
表示类User中定义了两个数据成员，一个是字符指针m_name，另一个是整型变量m_age，它们属于基本类型的成员变量。因此，缺省拷贝构造函数在实现类User的对象复制时，对上述两个数据成员均采用字节复制的方法。如下代码所示：
User user1 = user;
复制的结果是user1.m_name指向了user.m_name指向的空间，是user.m_name指针的浅拷贝。如果user对象先释放了，则user1.m_name将变成野指针。这显然不是我们希望的结果，为了避免这种情况的发生，就必须自定义拷贝构造函数，代码如下：
User(User const& user) {
    m_name = new char[strlen(user.m_name) + 1];
    strcpy(m_name, user.m_name);
    m_age = user.m_age;
}
为user1.m_name再在堆上分配一块儿存储空间，实现真正意义上的深拷贝。这样即使user对象先释放了，user1.m_name指向的空间仍然存在。

16 拷贝构造与编译优化
16.1 问题
拷贝构造过程通常被使用在以下三种情况：用已定义的对象作为同类型对象的构造实参；一个对象作为函数参数，以值传递的方式传入函数体；从函数中返回对象。
拷贝构造过程风险高而效率低，设计时应尽可能避免。编译器会通过必要的优化策略，减少拷贝构造的机会。
16.2 步骤
实现此案例需要按照如下步骤进行。
步骤一：拷贝构造与编译优化
代码如下：
#include <iostream>
class User {
private:
    std::string m_name;
    int m_age;
public:
    User(std::string const& name, int age) {
        m_name = name;
        m_age = age;
    }
    User(User const& user) {
        m_name = user.m_name;
        m_age = user.m_age;
    }
    void who(void) {
        std::cout << "我是" << m_name << "，今年" << m_age << "岁。" << std::endl;
    }
};
void print(User user) {
    user.who();
}
User create() {
    User obj("张三", 25);
    return obj;
}
int main(int argc, const char* argv[]) {
    User user = create();
    print(user);
    User user1 = user;
    print(user);
    return 0;
}
上述代码中，以下代码：
void print(User user) {
    user.who();
}
类User的对象user作为形参值传递给函数print。当调用该函数时：
print(user);
相当于将实参赋值给形参。形参需要分配一块儿与实参相同大小的存储空间，然后通过拷贝构造函数再将实参的数据拷贝到形参当中去，这一过程效率极低。一般应使用引用方法代替。
上述代码中，以下代码：
User create() {
    User obj("张三", 25);
    return obj;
}
函数create返回一个类User的对象。效率也是极低的，原因同上，应当避免。

17 带初始化表的构造函数
17.1 问题
通过在类的构造函数中使用初始化表，指明该类的成员变量如何被初始化。
17.2 步骤
实现此案例需要按照如下步骤进行。
步骤一：带初始化表的构造函数
代码如下：
#include <iostream>
class User {
private:
    std::string m_name;
    int m_age;
public:
    User(std::string const& name, int age): m_name(name), m_age(age) {
    }
    void who(void) {
        std::cout << "我是" << m_name << "，今年" << m_age << "岁。" << std::endl;
    }
};
int main(int argc, const char* argv[]) {
    User user("张三", 20);
    user.who();
    return 0;
}
上述代码中，以下代码：
User(std::string const& name, int age): m_name(name), m_age(age) {
}
定义了一个带初始化表的构造函数，冒号：后面的内容被称为初始化列表，当初始化列表中含有多个数据成员时，用逗号，分开。使用初始化列表的构造函数显式的初始化类的成员。如，当数据成员m_name分配完存储空间之后，会马上到初始化列表中寻找m_name（name），如果存在则调用对应的构造函数，否则调用类std::string的缺省构造函数。如果将自定义构造函数写成如下所示：
User(std::string const& name, int age) {
    m_name = name;
    m_age = age;
}
则数据成员m_name分配完存储空间之后，因为初始化列表为空，所以直接调用类std::string的缺省构造函数。当所有数据成员均构造完成之后，在对m_name进行赋值操作。显然在初始化列表中，直接调用对应的构造函数效率更高。
对于基本数据类型的数据成员，上述两种方法没有区别，但习惯上还是使用初始化列表的方法。

18 数组和结构型成员的初始化
18.1 问题
数组和结构体型的成员变量在类构造函数的初始化表中需要用花括号“{}”初始化。
18.2 步骤
实现此案例需要按照如下步骤进行。
步骤一：数组和结构型成员的初始化
代码如下：
#include <iostream>
struct Curriculum {
    std::string subject;
    int period;
};
class Teacher {
private:
    std::string m_students[3];
    Curriculum m_curriculum;
public:
    Teacher(std::string const& s1, std::string const& s2, std::string const& s3,
            std::string const& subject, const int& period) : m_students {s1, s2, s3},
    m_curriculum {subject, period} {
    }
    void show(void) {
        std::cout << "学科：" << m_curriculum.subject << ",周期：" <<
        m_curriculum.period << "天" << std::endl;
        std::cout << "学生姓名：";
        for (int i = 0; i < 3; i++)
            std::cout << m_students[i] << " ";
        std::cout << std::endl;
    }
};
int main(int argc, const char* argv[]) {
    Teacher t("张三", "李四", "王五", "标准C++", 9);
    t.show();
    return 0;
}
上述代码中，以下代码：
private:
std::string m_students[3];
Curriculum m_curriculum;
定义了类Teacher的两个数据成员，一个是std::string类型的数组m_students，另一个是Curriculum类型的结构体变量m_curriculum。因为m_students数组因为有三个元素，所以在初始化列表中需要将三个元素用大括号括起来，如下代码所示：
Teacher(std::string const& s1, std::string const& s2, std::string const& s3,
        std::string const& subject, const int& period) : m_students {s1, s2, s3},
m_curriculum {subject, period} {
}
又因为结构体变量m_curriculum有两个成员，所以在初始化列表中也需要用大括号将两个成员的初始化值括起来。

19 类类型成员的初始化
19.1 问题
类的类类型成员变量和基类子对象，要么在初始化表中显式初始化，要么通过相应类型的缺省构造函数初始化。
19.2 步骤
实现此案例需要按照如下步骤进行。
步骤一：类类型成员的初始化
代码如下：
#include <iostream>
class Date {
private:
    int m_year;
    int m_mon;
    int m_day;
public:
    Date(const int& year, const int& mon, const int& day) {
        m_year = year;
        m_mon = mon;
        m_day = day;
    }
    void show(void) {
        std::cout << m_year << "年" << m_mon << "月" << m_day << "日" << std::endl;
    }
};
class User {
private:
    std::string m_name;
    int m_age;
    Date m_birthday;
public:
    User(std::string const& name, const int& age, const int& year, const int& mon,
         const int& day): m_name(name), m_age(age), m_birthday(year, mon, day) {
    }
    void who(void) {
        std::cout << "我是" << m_name << "，今年" << m_age << "岁。" << std::endl;
        std::cout << "出生日期：";
        m_birthday.show();
        std::cout << std::endl;
    }
};
int main(int argc, const char* argv[]) {
    User user("张三", 20, 1970, 1, 1);
    user.who();
    return 0;
}
上述代码中，以下代码：
Date m_birthday;
在类User中有一个类Data的对象作为类User类型成员变量，该成员变量需要在类User构造函数的初始化表中显式初始化，代码如下所示：
User(std::string const& name, const int& age, const int& year, const int& mon,
     const int& day): m_name(name), m_age(age), m_birthday(year, mon, day) {
}
其中，m_birthday(year, mon, day)为像是初始化的内容。

20 常量和引用型成员的初始化
20.1 问题
当一个类中有常量型和引用型成员变量时，必须在初始化表中显式初始化，不能在构造函数体中赋初值。
20.2 步骤
实现此案例需要按照如下步骤进行。
步骤一：常量和引用型成员的初始化
代码如下：
#include <iostream>
class Circle {
private:
    double const m_pi; // 常量型成员变量
    double& m_r; // 引用型成员变量
public:
    Circle(double pi, double& r) : m_pi(pi), m_r(r) {
    }
    double perimeter(void) {
        return 2 * m_pi * m_r;
    }
    double area(void) {
        return m_pi * m_r * m_r;
    }
};
int main(int argc, const char* argv[]) {
    double r = 10.0;
    Circle cir(3.14, r);
    std::cout << "周长：" << cir.perimeter() << std::endl;
    std::cout << "面积：" << cir.area() << std::endl;
    return 0;
}
上述代码中，以下代码：
private:
double const m_pi; // 常量型成员变量
double& m_r; // 引用型成员变量
在类Circle中定义了两个私有的成员变量，一个是常量型成员变量m_pi，另一个是引用型成员变量m_r。我们知道，常量和引用在定义时必须初始化，那么类中的常量和引用数据成员由于是在定义对象时分配存储空间，所以它们的初始化工作也被放到构造函数中完成，只不过要求必须在初始化列表中初始化，代码如下所示：
Circle(double pi, double& r) : m_pi(pi), m_r(r) {
}
其中，m_pi (pi)是对常量型成员变量的初始化，m_r (r)是对引用性成员变量的初始化。

21 初始化顺序
21.1 问题
类的成员变量按其在类中的声明顺序依次被初始化，而与其在初始化表中的排列顺序无关。
21.2 步骤
实现此案例需要按照如下步骤进行。
步骤一：初始化顺序
代码如下：
#include <iostream>
class Message {
private:
    size_t m_len;
    std::string m_str;
public:
    Message(std::string const& str) : m_str(str), m_len(m_str.length()) {
    }
    void show(void) {
        std::cout << m_str << std::endl;
    }
    size_t size(void) {
        return m_len;
    }
};
int main(int argc, const char* argv[]) {
    Message m("Hello World!");
    m.show();
    return 0;
}
上述代码中，以下代码：
private:
size_t m_len;
std::string m_str;
public:
Message(std::string const& str) : m_str(str), m_len(m_str.length()) {
}
在类Message中定义了两个成员变量m_len和m_str，并在构造函数的初始化列表中对它们进行初始化。那么两个成员变量先初始化哪一个，是按其在类中的声明顺序依次被初始化，声明顺序是指以下代码：
private:
size_t m_len;
std::string m_str;
还有一个顺序是其在初始化表中的排列顺序，是指以下代码：
Message(std::string const& str) : m_str(str), m_len(m_str.length()) {
}
该顺序与变量的初始化顺序无关。其原因是，当定义一个类的对象时，会首先给该对象的所有数据成员分配存储空间，这些数据成员在分配空间时是按照声明的顺序来逐个分配的，每分配一个数据成员就会马上对其进行初始化。

22 隐藏的this指针参数
22.1 问题
相同类型的不同对象各自拥有独立的存储空间，但它们在代码区中彼此共享同一份成员函数代码。这样就带来一个问题，就是函数代码如何区分所访问的成员变量隶属于哪个对象？因此，编译器为类的每个成员函数添加一个隐藏的指针型参数this，指向调用该成员函数的对象，这就是this指针。
22.2 步骤
实现此案例需要按照如下步骤进行。
步骤一：隐藏的this指针参数
代码如下：
#include <iostream>
class User {
private:
    std::string m_name;
    int m_age;
public:
    User(std::string const& name, int age) {
        m_name = name;
        m_age = age;
    }
    void print(void) {
        std::cout << "我是" << m_name << "，今年" << m_age << "岁。" << std::endl;
    }
};
int main(int argc, const char* argv[]) {
    User user("张飞", 25);
    user.print();
    return 0;
}
上述代码中，以下代码：
void print(void) {
    std::cout << "我是" << m_name << "，今年" << m_age << "岁。" << std::endl;
}
是类User的一个成员函数，该函数没有形参。编译时，编译器会为该函数添加一个形参，如下代码所示：
void _ZN4User5printEv(User* this) {
    std::cout << "我是" << this->m_name << "，今年" << this->m_age << "岁。" <<
    std::endl;
}
该形参就是一个本类的指针this。在该函数的调用处：
user.print();
编译器会相应的添加一个实参，该实参就是调用函数的对象的地址&user。
类的构造和析构函数中同样有this指针，指向这个正在被构造或析构的对象。

23 通过this指针区分成员
23.1 问题
多数情况下，程序并不需要显式地使用this指针，编译器通过名字解析，可以判断出所访问的标识符是否属于该类的成员，是则为其加上“this->”。
为了提高代码的可读性，常将类的构造函数的参数，与被该参数初始化的成员取成相同的名称，在构造函数内部，除了使用初始化表外，还可以通过this指针，将同名的成员与非成员区分开来。
23.2 步骤
实现此案例需要按照如下步骤进行。
步骤一：通过this指针区分成员
代码如下：
#include <iostream>
class User {
private:
    std::string name;
    int age;
public:
    User(std::string const& name, int age) {
        this->name = name;
        this->age = age;
    }
    void print(void) {
        std::cout << "我是" << name << "，今年" << age << "岁。" << std::endl;
    }
};
int main(int argc, const char* argv[]) {
    User user("张飞", 25);
    user.print();
    return 0;
}
上述代码中，以下代码：
private:
std::string name;
int age;
public:
User(std::string const& name, int age) {
    this->name = name;
    this->age = age;
}
在类User中定义了两个数据成员name和age，并在构造函数中对其进行初始化。为了提高代码的可读性，构造函数的参数名也起成name和age，但这样，属于局部变量的形参将隐藏类的成员变量，使之不起作用。此时如果在构造函数体内对类的成员变量进行操作的话，就可以使用this指针对形参和成员变量进行区分。

24 返回调用对象
24.1 问题
在类的成员函数中，通过this指针向该成员函数的调用者可以返回调用对象的自拷贝或自引用。
24.2 步骤
实现此案例需要按照如下步骤进行。
步骤一：返回调用对象
代码如下：
#include <iostream>
class Integer {
private:
    int m_value;
public:
    Integer(const int& integer): m_value(integer) {
    }
    Integer add(Integer const& that) {
        m_value += that.m_value;
        return *this; // 返回自拷贝
    }
    Integer& inc(void) {
        ++m_value;
        return *this; // 返回自引用
    }
    void show(void) {
        std::cout << m_value << std::endl;
    }
};
int main(int argc, const char* argv[]) {
    Integer inte1(10);
    Integer inte2(20);
    Integer inte3(30);
    inte1 = inte1.add(inte2).add(inte3);
    inte1.show();
    inte1.inc().inc();
    inte1.show();
    return 0;
}
上述代码中，以下代码：
Integer add(Integer const& that) {
    m_value += that.m_value;
    return *this; // 返回自拷贝
}
在类Integer中定义了一个成员函数add，该函数返回一个类Integer的对象，由于this指针指向的是调用该函数的对象，那么*this就是调用该函数的对象本身。这样的返回值可以起到如下代码的作用：
inte1 = inte1.add(inte2).add(inte3);
因为inte1.add(inte2)函数调用的返回值是类Integer的对象，既然是对象，就可以调用其成员函数，所以可以连续调用。
上述代码中，以下代码：
Integer& inc(void) {
    ++m_value;
    return *this; // 返回自引用
}
在类Integer中定义了一个成员函数inc，该函数返回一个类Integer的引用，而*this就是调用该函数的对象，所以返回的就是调用成员函数的对象的引用。这样的返回值同样可以起到如下代码的作用：
inte1.inc().inc();
注意：
上边两个方法是有区别的，inte1.add(inte2)的返回值是一个临时对象，而inte1.inc()的返回值是对象inte1本身。

25 教师和学生
25.1 问题
this指针可以作为函数的实际参数，从一个对象传递给另一个对象，这样能够实现对象间的交互。
25.2 步骤
实现此案例需要按照如下步骤进行。
步骤一：教师
头文件代码如下：
#ifndef __Day03__Teacher__
#define __Day03__Teacher__
#include <iostream>
#include "Student.h"
class Teacher {
public:
    void educate(Student* student);
    void reply(char const* answer);
};
#endif /* defined(__Day03__Teacher__) */
上述代码中，以下代码：
void educate (Student* student);
成员函数educate带有一个形参，该形参是类Student的指针。
实现文件代码如下：
#include "Teacher.h"
void Teacher::educate(Student* student) {
    student->ask("什么是this指针？", this);
}
void Teacher::reply(char const* answer) {
    std::cout << "老师答：" << answer << std::endl;
}
上述代码中，以下代码：
void Teacher::educate(Student* student) {
    student->ask("什么是this指针？", this);
}
在函数educate中调用类Student的成员函数ask，函数ask的第二个实参即为this，此时传入函数ask的是调用函数educate的对象的地址，这样就使得类Teacher和类Student可以互动。
步骤二：学生
头文件代码如下：
#ifndef __Day03__Student__
#define __Day03__Student__
#include <iostream>
class Teacher;
class Student {
public:
    void ask(char const* question, Teacher* teacher);
};
#endif /* defined(__Day03__Student__) */
上述代码中，以下代码：
void ask(char const* question, Teacher* teacher);
成员函数ask带有两个形参，第二个形参是类Teacher的指针。
实现文件代码如下：
#include "Student.h"
#include "Teacher.h"
void Student::ask(char const* question, Teacher* teacher) {
    std::cout << "学生问：" << question << std::endl;
    teacher->reply("this指针就是指向调用对象的指针");
}
上述代码中，函数ask中调用类Teacher的成员函数reply。函数ask的第二个形参得到的是类Teacher的this指针，此时传入函数ask的是调用类Teacher的成员函数educate的对象的地址，这样就使得类Teacher和类Student又一次的互动。
26 常函数和mutable关键字
26.1 问题
在类成员函数的形参表之后，函数体之前加上const关键字，该成员函数的this指针即具有常属性，这样的成员函数被称为常函数。在常函数内部，因为this指针被声明为常量指针，所以无法修改成员变量的值，除非该成员变量被mutable关键字修饰。
26.2 步骤
实现此案例需要按照如下步骤进行。
步骤一：常函数和mutable关键字
头文件代码如下：
#include <iostream>
class User {
private:
    std::string m_name;
    int m_age;
    mutable unsigned int m_times;
public:
    User(std::string const& name, int age) {
        m_name = name;
        m_age = age;
    }
    void print(void) const {
        m_times++;
        std::cout << "我是" << m_name << "，今年" << m_age << "岁。（第" << m_times <<
        "次打印）" << std::endl;
    }
};
int main(int argc, const char* argv[]) {
    User user("张飞", 25);
    user.print();
    user.print();
    return 0;
}
上述代码中，以下代码：
void print(void) const {
    m_times++;
    std::cout << "我是" << m_name << "，今年" << m_age << "岁。（第" << m_times <<
    "次打印）" << std::endl;
}
是类User的一个成员函数，值得注意的是在函数头的最后有一个const，当一个成员函数有此const时，此函数被称为常函数。在常函数内部，因为this指针被声明为常量指针，所以无法修改成员变量的值，除非该成员变量被mutable关键字修饰。如果在print函数中添加以下语句：
m_name = "";
m_age  = 0;
是非法的，因为this->m_name和this->m_age是只读型变量。但函数中以下语句：
m_times++;
是合法的，因为成员变量m_times在声明的时候添加了mutable关键字，如下语句：
private:
std::string m_name;
int m_age;
mutable unsigned int m_times;
mutable关键字会在常函数中此成员变量m_times被使用的语句中添加隐式转换，将this指针临时转换成普通指针。

27 通过常/非常对象调用常/非常函数
27.1 问题
常对象是指被const关键字修饰的对象、对象指针或对象引用，非常对象就是没有被const关键字修饰的。通过常对象调用成员函数，传递给该成员函数this指针参数的实参是一个常量指针。
27.2 步骤
实现此案例需要按照如下步骤进行。
步骤一：通过常/非常对象调用常/非常函数
头文件代码如下：
#include <iostream>
class User {
private:
    std::string m_name;
    int m_age;
    mutable unsigned int m_times;
public:
    User(std::string const& name, int age) {
        m_name = name;
        m_age = age;
    }
    void modify(std::string const& name, int age) {
        m_name = name;
        m_age = age;
    }
    void print(void) const {
        m_times++;
        std::cout << "我是" << m_name << "，今年" << m_age << "岁。（第" << m_times <<
        "次打印）" << std::endl;
    }
};
int main(int argc, const char* argv[]) {
    const User user("张飞", 25);
    //user.modify("关羽", 28);
    user.print();
    user.print();
    User user1("张飞", 25);
    user1.modify("关羽", 28);
    user1.print();
    return 0;
}
上述代码中，以下代码：
const User user("张飞", 25);
定义了一个常对象。常对象无法调用非常函数，如以下语句所示：
//user.modify("关羽", 28);
因为成员函数modify，在以下语句：
void modify(std::string const& name, int age) {
    m_name = name;
    m_age = age;
}
没有说明成一个常函数。
常对象只能调用常函数，如以下语句所示：
user.print();
注意：
如果在成员变量声明时，添加了mutable关键字，如以下语句所示：
private:
std::string m_name;
int m_age;
mutable unsigned int m_times;
成员变量m_times添加了mutable关键字，则该变量在常函数中仍可改变。如以下语句所示：
user.print();
user.print();
上述代码中，以下代码：
User user1("张飞", 25);
user1.modify("关羽", 28);
user1.print();
定义了一个非常对象user1，它既可以调用非常函数modify，也可以调用常函数print。

28 常函数与非常函数的重载匹配
28.1 问题
原型相同的成员函数，常函数版本和非常函数版本能够构成重载函数。常对象只能选择常函数版本；非常对象优先选择非常函数版本，如果没有非常函数版本，也能选择常函数版本。
28.2 步骤
实现此案例需要按照如下步骤进行。
步骤一：常函数与非常函数的重载匹配
头文件代码如下：
#include <iostream>
class Array {
private:
    int* m_array;
    size_t m_size;
public:
    Array(const int& size) {
        m_size = size;
        m_array = new int[m_size];
    }
    size_t size(void) const {
        return m_size;
    }
    const int& at(size_t index) const {
        return m_array[index];
    }
    int& at(size_t index) {
        return m_array[index];
    }
};
void init(Array& array, int elm) {
    for (size_t i = 0; i < array.size(); ++i)
        array.at(i) = elm;
}
void print(Array const& array) {
    for (size_t i = 0; i < array.size(); ++i)
        std::cout << array.at(i) << " ";
    std::cout << std::endl;
}
int main(int argc, const char* argv[]) {
    Array array(10);
    init(array, 5);
    print(array);
    return 0;
}
上述代码中，以下代码：
const int& at(size_t index) const {
    return m_array[index];
}
int& at(size_t index) {
    return m_array[index];
}
函数at为重载函数。虽然函数at的参数完全相同，但第一个函数是常函数，第二个函数为非常函数。常函数与非常函数可以构成重载。
上述代码中，以下代码：
void print(Array const& array) {
    for (size_t i = 0; i < array.size(); ++i)
        std::cout << array.at(i) << " ";
    std::cout << std::endl;
}
由于对象array是常对象，由于常对象只能调用类中的常函数，所以下述代码中：
std::cout << array.at (i) << " ";
函数at只能调用常版本的函数at。
上述代码中，以下代码：
void init(Array& array, int elm) {
    for (size_t i = 0; i < array.size(); ++i)
        array.at(i) = elm;
}
由于对象array是非常对象，由于非常对象既能调用类中的非常函数，又能调用类中的非常函数，但优先调用非常版本，所以下述代码中：
array.at (i) = elm;
函数at会优先调用非常版本的函数at。
注意：非常版本at的返回值是引用，即array.at (i)是m_array[index]的别名，所以等效于m_array[index] = elm。

CSD STDCPP01 DAY04
1 析构函数的基本用法
1.1 问题
析构函数是特殊的成员函数。它的函数名就是在类名前面加“~”，没有返回类型，没有参数，也不能重载。析构函数在销毁对象时自动被调用，析构函数在对象的整个生命周期内，最多被调用一次。
1.2 步骤
实现此案例需要按照如下步骤进行。
步骤一：析构函数的基本用法
代码如下：
#include <iostream>
class Array {
private:
    int* m_array;
public:
    Array(size_t size) : m_array(new int[size]) {
    }
    ~Array(void) {
        delete[] m_array;
    }
};
int main(int argc, const char* argv[]) {
    Array array(10);
    return 0;
}
上述代码中，以下代码：
~Array(void) {
    delete[] m_array;
}
定义了一个析构函数，其函数名与构造函数一样，为了与构造函数相区分前面加了一个~号。析构函数是没有返回值，没有参数的函数，因为没有参数，所以析构函数不能被重载。
析构函数同构造函数一样，是自动被调用的，构造函数是在对象的存储空间分配完毕时被调用的，而析构函数则是在对象的存储空间被销毁前调用的。
析构函数可以被用来销毁释放在对象的构造过程或生命周期内所获得的资源。如本例中，在构造函数中new的数组m_array，在析构函数中将其释放。

2 析构函数负责总善后
2.1 问题
析构函数的功能不仅限于释放资源，它可以执行任何作为类的设计者希望在最后一次使用对象之后执行的动作。
2.2 步骤
实现此案例需要按照如下步骤进行。
步骤一：析构函数负责总善后
代码如下：
#include <iostream>
class Child;
class Parent {
private:
    int m_count;
public:
    Parent() {
        m_count = 0;
    }
    void reg(Child* child) {
        m_count++;
    }
    void unreg(Child* child) {
        m_count--;
    }
};
class Child {
private:
    Parent* m_parent;
public:
    Child(Parent* parent) : m_parent(parent) {
        m_parent->reg(this);
    }
    ~Child(void) {
        m_parent->unreg(this);
    }
};
int main(int argc, const char* argv[]) {
    Parent parent;
    Child child(&parent);
    return 0;
}
上述代码中，以下代码：
Child(Parent* parent) : m_parent(parent) {
    m_parent->reg(this);
}
定义了类Child的构造函数，在该函数中当生成一个类Child的对象时，需要在类Parent中进行注册。
上述代码中，以下代码：
~Child(void) {
    m_parent->unreg(this);
}
定义了类Child的析构函数，因为当类Child的对象在生成时需要在类Parent中注册，所以当类Child的对象销毁前，需要在类Parent中反注册。

3 缺省析构函数不释放动态分配的资源
3.1 问题
通常情况下，如果对象在其生命周期的最终时刻，并不持有任何动态分配的资源，也没有任何善后工作可做，那么完全可以不为其定义析构函数。
如果一个类没有定义析构函数，那么编译器会为其提供一个缺省析构函数，该函数对基本类型的成员变量，什么也不做，对类类型的成员变量和基类子对象，调用相应类型的析构函数。
3.2 步骤
实现此案例需要按照如下步骤进行。
步骤一：缺省析构函数不释放动态分配的资源
设置循环，将待排序数组中的数组元素两两进行比较，如果有不符合要求的顺序的，进行交换。
代码如下所示：
#include <iostream>
class Array {
private:
    int* m_array;
public:
    Array(size_t size) : m_array(new int[size]) {
    }
};
int main(int argc, const char* argv[]) {
    Array array(10);
    return 0;
}
上述代码中，类Array没有定义析构函数，那么，编译器会为该类自动添加一个缺省析构函数，代码如下所示：
~Array(void) {
}
该缺省析构函数的函数体内没有任何代码，所以如果在对象的构造过程或生命周期内获得过任何资源，都必须手动添加析构函数，不能使用缺省析构函数，否则就会造成内存泄露。

4 缺省拷贝构造函数仅支持浅拷贝
4.1 问题
缺省方式的拷贝构造和拷贝赋值，对包括指针在内的基本类型成员变量按字节复制，导致浅拷贝问题。
4.2 步骤
实现此案例需要按照如下步骤进行。
步骤一：缺省拷贝构造函数仅支持浅拷贝
代码如下所示：
#include <iostream>
#include <string>
class User {
private:
    char* m_name;
    int m_age;
public:
    User(char const* name, int age) {
        m_name = new char[strlen(name) + 1];
        strcpy(m_name, name);
        m_age = age;
    }
    void who(void) {
        std::cout << "我是" << m_name << "，今年" << m_age << "岁。" << std::endl;
    }
};
int main(int argc, const char* argv[]) {
    User user("张三", 25);
    user.who();
    User user1 = user;
    user1.who();
    return 0;
}
上述代码中，以下代码：
private:
char* m_name;
int m_age;
表示类User中定义了两个数据成员，一个是字符指针m_name，另一个是整型变量m_age，它们属于基本类型的成员变量。因此，缺省拷贝构造函数在实现类User的对象复制时，对上述两个数据成员均采用字节复制的方法。如下代码所示：
User user1 = user;
复制的结果是user1.m_name指向了user.m_name指向的空间，是user.m_name指针的浅拷贝。如果user对象先释放了，则user1.m_name将变成野指针。

5 自定义拷贝构造函数支持深拷贝
5.1 问题
为了获得完整意义上的对象副本，必须自己定义拷贝构造和拷贝赋值，针对指针型成员变量做深拷贝。
5.2 步骤
实现此案例需要按照如下步骤进行。
步骤一：自定义拷贝构造函数支持深拷贝
首先，定义一个变量，用于存放最小元素在数组中的下标。
然后，设置循环，遍历数组找出最小元素。
代码如下所示：
#include <iostream>
#include <string>
class User {
private:
    char* m_name;
    int m_age;
public:
    User(char const* name, int age) {
        m_name = new char[strlen(name) + 1];
        strcpy(m_name, name);
        m_age = age;
    }
    User(User const& user) {
        m_name = new char[strlen(user.m_name) + 1];
        strcpy(m_name, user.m_name);
        m_age = user.m_age;
    }
    void who(void) {
        std::cout << "我是" << m_name << "，今年" << m_age << "岁。" << std::endl;
    }
};
int main(int argc, const char* argv[]) {
    User user("张三", 25);
    user.who();
    User user1 = user;
    user1.who();
    return 0;
}
缺省拷贝构造函数在实现类User的对象复制时，对类的两个基本数据类型的数据成员均采用字节复制的方法。如下代码所示：
User user1 = user;
复制的结果是user1.m_name指向了user.m_name指向的空间，是user.m_name指针的浅拷贝。如果user对象先释放了，则user1.m_name将变成野指针。这显然不是我们希望的结果，为了避免这种情况的发生，就必须自定义拷贝构造函数，代码如下：
User(User const& user) {
    m_name = new char[strlen(user.m_name) + 1];
    strcpy(m_name, user.m_name);
    m_age = user.m_age;
}
为user1.m_name再在堆上分配一块儿存储空间，实现真正意义上的深拷贝。这样即使user对象先释放了，user1.m_name指向的空间仍然存在。

6 支持深拷贝的拷贝赋值运算符函数
6.1 问题
C++中预定义的赋值运算符的操作对象只能是基本数据类型。但实际上，对于许多用户自定义类型（例如类），也需要赋值运算操作。这时就必须在C++中重新定义赋值运算符，赋予赋值运算符新的功能，使它能够用于用户自定义类型执行用户自定义的操作。
6.2 步骤
实现此案例需要按照如下步骤进行。
步骤一：支持深拷贝的拷贝赋值运算符函数
代码如下：
#include <iostream>
#include <string>
class User {
private:
    char* m_name;
    int m_age;
public:
    User(char const* name, int age) {
        m_name = new char[strlen(name) + 1];
        strcpy(m_name, name);
        m_age = age;
    }
    User(User const& user) {
        m_name = new char[strlen(user.m_name) + 1];
        strcpy(m_name, user.m_name);
        m_age = user.m_age;
    }
    User& operator = (User const& user) {
        if (&user != this) {
            char* psz = new char[strlen(user.m_name) + 1];
            delete[] m_name;
            m_name = strcpy(psz, user.m_name);
        }
        return *this;
    }
    void who(void) {
        std::cout << "我是" << m_name << "，今年" << m_age << "岁。" << std::endl;
    }
};
int main(int argc, const char* argv[]) {
    User user("张三", 25);
    user.who();
    User user1("李四", 25);
    user1 = user;
    user1.who();
    return 0;
}
上述代码中，以下代码：
User& operator = (User const& user) {
    if (&user != this) {
        char* psz = new char[strlen(user.m_name) + 1];
        delete[] m_name;
        m_name = strcpy(psz, user.m_name);
    }
    return *this;
}
定义了一个赋值运算符的重载函数。因为，赋值运算符在C++中只能是操作基本数据类型，对于类User的对象，赋值运算符对以下语句：
user1 = user;
只是简单地让user1.m_name指向了user.m_name指向的空间，这样带来的隐患与浅拷贝相同，如果user对象先释放了，则user1.m_name将变成野指针。为了避免这一现象的发生需要重载赋值运算符，赋予赋值运算符深拷贝的功能。在这一过程中，以下语句：
if (&user != this)
的作用是，如果执行了自身赋值，那么就什么都不做，直接返回。
以下语句：
char* psz = new char[strlen(user.m_name) + 1];
delete[] m_name;
m_name = strcpy(psz, user.m_name);
先分配新资源再释放旧资源是有意义的，即使目标对象的新资源分配失败，其原有的内容也不至于遭到破坏
最后应该说明的是，这个赋值运算符函数的返回值是User&，目的是满足赋值表达式的语义，即当有以下语句时：
user = user1 = user2;
user1 = user2的返回值仍是一个类User的对象，即user1，这样可以继续赋值给user。

7 支持结息调息功能的银行账户类
7.1 问题
静态成员变量不包含在对象实例中，具有进程级的生命周期。静态成员函数没有this指针，也没有常属性。但是静态成员受类作用域和访问控制限定符的约束。静态成员变量的声明在类中；而定义和初始化，只能在类的外部而不能在构造函数中进行。静态成员变量为该类的所有对象实例所共享。类的静态成员变量通常用于表示需要在该类的多个实例化对象间共享的属性，如银行账户的利率。
静态成员函数只能访问静态成员变量或调用静态成员函数。非静态成员函数既可以访问静态成员变量或调用静态成员函数，也可以访问非静态成员变量或调用非静态成员函数。类的静态成员函数一方面可以独立于对象充当静态成员变量的访问接口，另一方面它也可以在不破坏封装性的前提下，让一个类有能力管理自己的对象。
访问静态成员，既可以通过类也可以通过对象。
7.2 步骤
实现此案例需要按照如下步骤进行。
步骤一：支持结息调息功能的银行账户类
代码如下：
#include <iostream>
class Account {
private:
    std::string m_name;
    long m_number;
    double m_principal;
    static double s_interest;
public:
    Account(std::string const& name, const long& number,
            const double& principal) : m_name(name), m_number(number),
    m_principal(principal) {
    }
    static void setInterest(const double& interest) {
        s_interest = interest;
    }
    static double getInterestRate() {
        return s_interest;
    }
    double getInterest() {
        return m_principal * s_interest;
    }
};
double Account::s_interest = 0.001;
int main(int argc, const char* argv[]) {
    std::cout << "当前利率是：" << Account::getInterestRate() << std::endl;
    Account zhangsan("张三", 1234567890123, 1000);
    std::cout << "存款利息是：" << zhangsan.getInterest() << std::endl;
    //利率调整
    Account::setInterest(0.002);
    std::cout << "利率调整后的存款利息是：" << zhangsan.getInterest() << std::endl;
    return 0;
}
上述代码中，以下代码：
static double s_interest;
在类Account中声明了一个私有的静态成员变量s_interest。
上述代码中，以下代码：
double Account::s_interest = 0.001;
在类Account的外部定义并初始化了静态成员变量s_interest。
上述代码中，以下代码：
static void setInterest(const double& interest) {
    s_interest = interest;
}
static double getInterestRate() {
    return s_interest;
}
在类Account中定义了两个静态成员函数，第一个函数用于调息，第二个函数用于获取当前利率值。
上述代码中，以下代码：
double getInterest() {
    return m_principal * s_interest;
}
在类Account中定义了一个普通成员函数，用于结息。
上述代码中，以下代码：
std::cout << "当前利率是：" << Account::getInterestRate() << std::endl;
显示了当前利率值是多少，值得注意的是，获取当前利率值是用Account::getInterestRate()方法获得的，这是允许的。C++规定，访问静态成员，既可以通过类也可以通过对象。

8 饿汉式的单例模式
8.1 问题
单例模式使用私有构造函数的方法禁止在类外部创建实例，而类自己使用静态成员变量的方法来维护其唯一实例，并提供访问该实例的方法。
饿汉式单例模式的优点是加载进程时静态创建单例对象，线程安全；缺点是无论使用与否，总要创建一个实例。
8.2 步骤
实现此案例需要按照如下步骤进行。
步骤一：饿汉式的单例模式
代码如下：
#include <iostream>
class Singleton {
private:
    Singleton(void) {
    }
    Singleton(Singleton const& that) {
    }
    static Singleton s_instance;
public:
    static Singleton& getInstance(void) {
        return s_instance;
    }
};
Singleton Singleton::s_instance;
int main(int argc, const char* argv[]) {
    Singleton& a = Singleton::getInstance();
    std::cout << std::hex << &a << std::endl;
    Singleton& b = Singleton::getInstance();
    std::cout << std::hex << &b << std::endl;
    return 0;
}
上述代码中，以下代码：
private:
Singleton(void) {
}
Singleton(Singleton const& that) {
}
通过将类Singleton的构造函数和拷贝构造函数定义成私有的，来禁止在类外创建该类的对象。
上述代码中，以下代码：
static Singleton s_instance;
将单例类的唯一对象实例，实现为其静态成员变量。虽然静态成员变量s_instance需要在类的外部实例化，但它毕竟是Singleton类的成员(尽管是静态成员)，依然属于类的内部元素，可以调用该类的私有构造函数。
上述代码中，以下代码：
static Singleton& getInstance(void) {
    return s_instance;
}
通过成员函数getInstance来获得类Singleton的唯一对象实例。

9 懒汉式的单例模式
9.1 问题
单例模式使用私有构造函数的方法禁止在类外部创建实例，而类自己使用静态成员变量的方法来维护其唯一实例，并提供访问该实例的方法。
饿汉式单例模式的优点是用则创建，不用不创建，什么时候用什么时候创建；缺点是首次访问时动态创建单例对象，在多线程应用中，存在线程不安全的问题。
9.2 步骤
实现此案例需要按照如下步骤进行。
步骤一：懒汉式的单例模式
代码如下：
#include <iostream>
class Singleton {
private:
    Singleton(void) {
    }
    Singleton(Singleton const& that) {
    }
    static Singleton* s_instance;
public:
    static Singleton& getInstance(void) {
        if (! s_instance)
            s_instance = new Singleton;
        return *s_instance;
    }
};
Singleton* Singleton::s_instance = NULL;
int main(int argc, const char* argv[]) {
    Singleton& a = Singleton::getInstance();
    std::cout << std::hex << &a << std::endl;
    Singleton& b = Singleton::getInstance();
    std::cout << std::hex << &b << std::endl;
    return 0;
}
上述代码中，以下代码：
private:
Singleton(void) {
}
Singleton(Singleton const& that) {
}
通过将类Singleton的构造函数和拷贝构造函数定义成私有的，来禁止在类外创建该类的对象。
上述代码中，以下代码：
static Singleton* s_instance;
声明了类Singleton的静态指针，该指针在类外定义时，被初始化为空，如以下代码所示：
Singleton* Singleton::s_instance = NULL;
上述代码中，以下代码：
static Singleton& getInstance(void) {
    if (! s_instance)
        s_instance = new Singleton;
    return *s_instance;
}
通过成员函数getInstance来获得类Singleton的唯一对象实例。与饿汉式的区别是在函数getInstance第一次被调用时，才创建唯一对象实例，而不是在创建程序一开始就创建唯一对象实例。

10 考虑线程安全的单例模式
10.1 问题
饿汉式单例模式在多线程应用中，由于是多线程并发执行，有可能创建出多个对象实例，存在线程不安全的问题。借助互斥锁能够防止单例对象在不同线程中被重复创建。
10.2 步骤
实现此案例需要按照如下步骤进行。
步骤一：考虑线程安全的单例模式
代码如下：
#include <iostream>
class Singleton {
private:
    Singleton(void) {
    }
    Singleton(Singleton const& that) {
    }
    static Singleton* s_instance;
    static pthread_mutex_t s_mutex;
public:
    static Singleton& getInstance(void) {
        if (! s_instance) {
            pthread_mutex_lock(&s_mutex);
            if (! s_instance)
                s_instance = new Singleton;
            pthread_mutex_unlock(&s_mutex);
        }
        return *s_instance;
    }
};
Singleton* Singleton::s_instance = NULL;
pthread_mutex_t Singleton::s_mutex = PTHREAD_MUTEX_INITIALIZER;
_
int main(int argc, const char* argv[]) {
    Singleton& a = Singleton::getInstance();
    std::cout << std::hex << &a << std::endl;
    Singleton& b = Singleton::getInstance();
    std::cout << std::hex << &b << std::endl;
    return 0;
}
上述代码中，以下代码：
static Singleton& getInstance(void) {
    if (! s_instance) {
        pthread_mutex_lock(&s_mutex);
        if (! s_instance)
            s_instance = new Singleton;
        pthread_mutex_unlock(&s_mutex);
    }
    return *s_instance;
}
在获得类Singleton的唯一对象实例的成员函数getInstance中，通过加互斥锁的方法来保证多线程安全。如下代码：
pthread_mutex_lock (&s_mutex);
首先设置互斥变量s_mutex，此时如果有其它线程已经设置了该变量，则当前线程就等待，直到其他线程释放互斥变量，此线程才重新开始执行。
以下代码：
pthread_mutex_unlock (&s_mutex);
是释放互斥变量s_mutex。

11 通过成员指针访问对象
11.1 问题
成员变量指针的本质，就是特定成员变量在类对象实例中的相对地址。成员变量指针解引用，就是根据类对象实例的起始地址，结合成员变量指针中的相对地址，计算出具体成员变量的绝对地址，并访问之。类的静态成员变量不是对象的一部分，不需要根据相对地址计算绝对地址，也不需要通过对象或其指针解引用。
成员函数并不存储在对象中，不存在根据相对地址计算绝对地址的问题，但是需要通过对象或对象指针对成员函数指针解引用，其目的只有一个，即提供this指针。类的静态成员函数没有this指针，无需调用对象。
静态成员与对象无关，因此静态成员指针与普通指针并没有任何本质性区别。
11.2 步骤
实现此案例需要按照如下步骤进行。
步骤一：通过成员变量指针访问成员变量
代码如下：
#include <iostream>
class Student {
public:
    std::string m_name;
    std::string m_sex;
    int m_age;
    int m_no;
};
int main(int argc, const char* argv[]) {
    int Student::*p_age = &Student::m_age;
    Student student;
    student.*p_age = 10;
    std::cout << student.m_age << std::endl;
    return 0;
}
上述代码中，以下代码：
int Student::*p_age = &Student::m_age;
定义了一个成员变量指针p_age，指向类Student的变量成员m_age.
上述代码中，以下代码：
Student student;
student.*p_age = 10;
定义了一个类Student的对象student，然后通过成员变量指针p_age，将对象student中的变量成员m_age赋值为10，这被称为解引用。其实，成员变量指针p_age指向的是变量成员m_age在对象student中的相对地址。“.*”是一个独立的运算符，成员指针解引用运算符。
步骤二：通过成员函数指针访问成员函数
代码如下：
#include <iostream>
class Student {
public:
    std::string m_name;
    std::string m_sex;
    int m_age;
    int m_no;
    void who(void) const {
        std::cout <<  "我是" << m_name << "，性别" << m_sex << "，今年" << m_age <<
        "岁，学号" << m_no << std::endl;
    }
};
int main(int argc, const char* argv[]) {
    int Student::*p_age = &Student::m_age;
    Student student;
    student.*p_age = 10;
    std::cout << student.m_age << std::endl;
    student.m_name = "张三";
    student.m_no = 12;
    student.m_sex = "男";
    void (Student::*p_who)(void) const = &Student::who;
    (student.*p_who)();
    return 0;
}
上述代码中，以下代码：
void (Student::*p_who) (void) const = &Student::who;
定义了一个成员函数指针p_who，指向类Student的函数成员who。
上述代码中，以下代码：
(student.*p_who)();
通过成员函数指针p_who，调用类Student的成员函数who，这被称为解引用。添加student的目的只有一个，即提供this指针。
步骤三：通过静态成员指针访问静态成员
代码如下：
#include <iostream>
class Student {
public:
    std::string m_name;
    std::string m_sex;
    int m_age;
    int m_no;
    static int s_count;
    void who(void) const {
        std::cout <<  "我是" << m_name << "，性别" << m_sex << "，今年" << m_age <<
        "岁，学号" << m_no << std::endl;
    }
    static void inc(void) {
        s_count++;
    }
};
int Student::s_count = 0;
int main(int argc, const char* argv[]) {
    int Student::*p_age = &Student::m_age;
    Student student;
    student.*p_age = 10;
    std::cout << "age = " << student.m_age << std::endl;
    student.m_name = "张三";
    student.m_no = 12;
    student.m_sex = "男";
    void (Student::*p_who)(void) const = &Student::who;
    (student.*p_who)();
    int* p_count = &Student::s_count;
    *p_count = 10;
    std::cout << "count = " << Student::s_count << std::endl;
    void (*p_inc)(void) = Student::inc;
    (*p_inc)();
    std::cout << "count = " << Student::s_count << std::endl;
    return 0;
}
上述代码中，以下代码：
int* p_count = &Student::s_count;
*p_count = 10;
定义了一个静态成员指针变量p_count，指向类Student的静态变量成员s_count。静态成员指针与普通指针并没有任何本质性区别，只是成员指针受访问控制属性约束。
上述代码中，以下代码：
void (*p_inc)(void) = Student::inc;
定义了一个静态成员函数指针p_inc，指向类Student的函数成员inc。
上述代码中，以下代码：
(*p_inc)();
通过静态成员函数指针p_inc，调用类Student的成员函数inc。类的静态成员函数没有this指针，无需调用对象。

CSD STDCPP01 DAY05
1 支持+/-操作符的复数类
1.1 问题
定义一个复数类，类中包括两个私有的成员变量，m_r代表实部，m_i代表虚部，并重载+/-运算符，以实现复数的加法与减法运算，及显示运算结果。
1.2 步骤
实现此案例需要按照如下步骤进行。
步骤一：支持+/-操作符的复数类
代码如下：
#include <iostream>
class Complex {
private:
    double m_r;//实部
    double m_i;//虚部
public:
    Complex(double r = 0, double i = 0) : m_r(r), m_i(i) {
    }
    Complex const operator+ (Complex const& rhs) const {
        return Complex(m_r + rhs.m_r, m_i + rhs.m_i);
    }
    void show(void) const {
        std::cout << m_r << "+" << m_i << "i" << std::endl;
    }
    friend Complex const operator- (Complex const&, Complex const&);
};
Complex const operator- (Complex const& lhs, Complex const& rhs) {
    return Complex(lhs.m_r - rhs.m_r, lhs.m_i - rhs.m_i);
}
int main(int argc, const char* argv[]) {
    Complex c1(3, 5);
    Complex c2(4, 1);
    Complex c3;
    c3 = c1 + c2;
    c3.show();
    c3 = c1 - c2;
    c3.show();
    return 0;
}
上述代码中，以下代码：
Complex const operator+ (Complex const& rhs) const {
    return Complex(m_r + rhs.m_r, m_i + rhs.m_i);
}
定义了复数类Complex的+运算符的重载函数。常函数以支持右值型左操作数，常参数以支持右值型右操作数，常返回值以支持右值型表达式的值。
上述代码中，以下代码：
Complex const operator- (Complex const& lhs, Complex const& rhs) {
    return Complex(lhs.m_r - rhs.m_r, lhs.m_i - rhs.m_i);
}
定义了复数类Complex的-运算符的全局函数。常第一参数以支持右值型左操作数，常第二参数以支持右值型右操作数，常返回值以支持右值型表达式的值。
上述代码中，以下代码：
friend Complex const operator- (Complex const&, Complex const&);
为了在一个全局操作符函数中直接访问其操作数类型的私有及保护成员，同时又不破坏其操作数类型的封装性，可以将该操作符函数声明为其操作数类型的友元。

2 支持+=/-=操作符的复数类
2.1 问题
定义一个复数类，类中包括两个私有的成员变量，m_r代表实部，m_i代表虚部，并重载+=/-=运算符，以实现复数的复合赋值运算，及显示运算结果。
2.2 步骤
实现此案例需要按照如下步骤进行。
步骤一：支持+=/-=操作符的复数类
代码如下：
#include <iostream>
class Complex {
private:
    double m_r;//实部
    double m_i;//虚部
public:
    Complex(double r = 0, double i = 0) : m_r(r), m_i(i) {
    }
    Complex& operator+= (Complex const& rhs) {
        m_r += rhs.m_r;
        m_i += rhs.m_i;
        return *this;
    }
    void show(void) const {
        std::cout << m_r << "+" << m_i << "i" << std::endl;
    }
    friend Complex& operator-= (Complex&, Complex const&);
};
Complex& operator-= (Complex& lhs, Complex const& rhs) {
    lhs.m_r -= rhs.m_r;
    lhs.m_i -= rhs.m_i;
    return lhs;
}
int main(int argc, const char* argv[]) {
    Complex c1(3, 5);
    Complex c2(4, 1);
    c1 += c2;
    c1.show();
    c1 -= c2;
    c1.show();
    return 0;
}
上述代码中，以下代码：
Complex& operator+= (Complex const& rhs) {
    m_r += rhs.m_r;
    m_i += rhs.m_i;
    return *this;
}
定义了复数类Complex的+=运算符的重载函数。非常函数以支持左值型左操作数，常参数以支持右值型右操作数，非常返回值以支持左值型表达式的值，返回自引用即左操作数本身。
上述代码中，以下代码：
Complex& operator-= (Complex& lhs, Complex const& rhs) {
    lhs.m_r -= rhs.m_r;
    lhs.m_i -= rhs.m_i;
    return lhs;
}
定义了复数类Complex的-=运算符的全局函数。非常第一参数以支持左值型左操作数，常第二参数以支持右值型右操作数，非常返回值以支持左值型表达式的值，返回引用型第一参数即左操作数本身。
上述代码中，以下代码：
friend Complex const operator- (Complex const&, Complex const&);
为了在一个全局操作符函数中直接访问其操作数类型的私有及保护成员，同时又不破坏其操作数类型的封装性，可以将该操作符函数声明为其操作数类型的友元。

3 支持-/~操作符的复数类
3.1 问题
定义一个复数类，类中包括两个私有的成员变量，m_r代表实部，m_i代表虚部，并重载-/~运算符，以实现复数的相反数和位反运算，及显示运算结果。
3.2 步骤
实现此案例需要按照如下步骤进行。
步骤一：支持-/~操作符的复数类
代码如下所示：
#include <iostream>
class Complex {
private:
    int m_r;//实部
    int m_i;//虚部
public:
    Complex(double r = 0, double i = 0) : m_r(r), m_i(i) {
    }
    Complex const operator- (void) const {
        return Complex(-m_r, -m_i);
    }
    void show(void) const {
        std::cout << m_r << "+" << m_i << "i" << std::endl;
    }
    friend Complex const operator~(Complex const&);
};
Complex const operator~(Complex const& lhs) {
    return Complex(~lhs.m_r, ~lhs.m_i);
}
int main(int argc, const char* argv[]) {
    Complex c1(3, 5);
    Complex c2;
    c2 = -c1;
    c2.show();
    c2 = ~c1;
    c2.show();
    return 0;
}
上述代码中，以下代码：
Complex const operator- (void) const {
    return Complex(-m_r, -m_i);
}
定义了复数类Complex的-运算符的重载函数。常函数以支持右值型操作数，常返回值以支持右值型表达式的值。
上述代码中，以下代码：
Complex const operator~(Complex const& lhs) {
    return Complex(~lhs.m_r, ~lhs.m_i);
}
定义了复数类Complex的~运算符的全局函数。
上述代码中，以下代码：
friend Complex const operator~ (Complex const&);
为了在一个全局操作符函数中直接访问其操作数类型的私有及保护成员，同时又不破坏其操作数类型的封装性，可以将该操作符函数声明为其操作数类型的友元。

4 支持前++/--操作符的复数类
4.1 问题
定义一个复数类，类中包括两个私有的成员变量，m_r代表实部，m_i代表虚部，并重载前++/--运算符，以实现复数的前置自增/前置自减运算，及显示运算结果。
4.2 步骤
实现此案例需要按照如下步骤进行。
步骤一：支持前++/--操作符的复数类
代码如下所示：
#include <iostream>
class Complex {
private:
    int m_r;//实部
    int m_i;//虚部
public:
    Complex(double r = 0, double i = 0) : m_r(r), m_i(i) {
    }
    Complex& operator++ (void) {
        ++m_r;
        ++m_i;
        return *this;
    }
    void show(void) const {
        std::cout << m_r << "+" << m_i << "i" << std::endl;
    }
    friend Complex& operator-- (Complex&);
};
Complex& operator-- (Complex& opd) {
    --opd.m_r;
    --opd.m_i;
    return opd;
}
int main(int argc, const char* argv[]) {
    Complex c1(3, 5);
    ++c1;
    c1.show();
    --c1;
    c1.show();
    return 0;
}
上述代码中，以下代码：
Complex& operator++ (void) {
    ++m_r;
    ++m_i;
    return *this;
}
定义了复数类Complex的前置++运算符的重载函数。非常参数以支持左值型操作数，非常返回值以支持左值型表达式的值，返回自引用即操作数本身。
上述代码中，以下代码：
Complex& operator-- (Complex& opd) {
    --opd.m_r;
    --opd.m_i;
    return opd;
}
定义了复数类Complex的前置--运算符的全局函数。非常函数以支持左值型操作数，非常返回值以支持左值型表达式的值，返回自引用即操作数本身。
上述代码中，以下代码：
friend Complex& operator-- (Complex&);
为了在一个全局操作符函数中直接访问其操作数类型的私有及保护成员，同时又不破坏其操作数类型的封装性，可以将该操作符函数声明为其操作数类型的友元。

5 支持后++/--操作符的复数类
5.1 问题
定义一个复数类，类中包括两个私有的成员变量，m_r代表实部，m_i代表虚部，并重载后++/--运算符，以实现复数的后置自增/后置自减运算，及显示运算结果。
5.2 步骤
实现此案例需要按照如下步骤进行。
步骤一：支持后++/--操作符的复数类
代码如下所示：
#include <iostream>
class Complex {
private:
    int m_r;//实部
    int m_i;//虚部
public:
    Complex(double r = 0, double i = 0) : m_r(r), m_i(i) {
    }
    Complex const operator++ (int) {
        Complex old = *this;
        ++m_r;
        ++m_i;
        return old;
    }
    void show(void) const {
        std::cout << m_r << "+" << m_i << "i" << std::endl;
    }
    friend Complex const operator-- (Complex&, int);
};
Complex const operator-- (Complex& opd, int) {
    Complex old = opd;
    --opd.m_r;
    --opd.m_i;
    return old;
}
int main(int argc, const char* argv[]) {
    Complex c1(3, 5);
    Complex c2;
    c2 = c1++;
    c1.show();
    c2.show();
    c2 = c1--;
    c1.show();
    c2.show();
    return 0;
}
上述代码中，以下代码：
Complex const operator++ (int) {
    Complex old = *this;
    ++m_r;
    ++m_i;
    return old;
}
定义了复数类Complex的后置++运算符的重载函数。非常函数以支持左值型操作数，常返回值以支持右值型表达式的值，整型哑元参数以区别于前置自增。由于是后置自增运算，所以操作数应该先参与其他运算符的运算，然后再自增，这样就必须返回自增前的对象，即old，使自增前的对象与其它运算符运算。对于后置自增表达式，编译器在调用操作符函数时会多传一个整型参数，通过重载解析匹配到后缀操作符函数。
上述代码中，以下代码：
Complex const operator-- (Complex& opd, int) {
    Complex old = opd;
    --opd.m_r;
    --opd.m_i;
    return old;
}
定义了复数类Complex的后置--运算符的全局函数。非常参数以支持左值型操作数，常返回值以支持右值型表达式的值，整型哑元参数以区别于前置自减。
上述代码中，以下代码：
friend Complex const operator-- (Complex&, int);
为了在一个全局操作符函数中直接访问其操作数类型的私有及保护成员，同时又不破坏其操作数类型的封装性，可以将该操作符函数声明为其操作数类型的友元。

6 支持<<操作符的复数类
6.1 问题
定义一个复数类，类中包括两个私有的成员变量，m_r代表实部，m_i代表虚部，并重载<<输出流运算符，以实现复数的输出操作。
6.2 步骤
实现此案例需要按照如下步骤进行。
步骤一：支持<<操作符的复数类
代码如下：
#include <iostream>
class Complex {
private:
    int m_r;//实部
    int m_i;//虚部
public:
    Complex(double r = 0, double i = 0) : m_r(r), m_i(i) {
    }
    void show(void) const {
        std::cout << m_r << "+" << m_i << "i" << std::endl;
    }
    friend std::ostream& operator<< (std::ostream&, Complex const&);
};
std::ostream& operator<< (std::ostream& lhs, Complex const& rhs) {
    return lhs << rhs.m_r << '+' << rhs.m_i << 'i';
}
int main(int argc, const char* argv[]) {
    Complex c1(3, 5);
    std::cout << c1 << std::endl;
    return 0;
}
上述代码中，以下代码：
std::ostream& operator<< (std::ostream& lhs, Complex const& rhs) {
    return lhs << rhs.m_r << '+' << rhs.m_i << 'i';
}
定义了复数类Complex的<<输出流运算符的全局函数。因为左操作数的类型为ostream，若以成员函数形式重载该操作符，就应将其定义为ostream类的成员，该类为标准库提供，无法添加新的成员，因此只能以全局函数形式重载该操作符。非常第一参数以支持左值型左操作数，常第二参数以支持右值型右操作数，非常返回值以支持左值型表达式的值，返回引用型第一参数即左操作数本身。
上述代码中，以下代码：
friend std::ostream& operator<< (std::ostream&, Complex const&);
为了在一个全局操作符函数中直接访问其操作数类型的私有及保护成员，同时又不破坏其操作数类型的封装性，可以将该操作符函数声明为其操作数类型的友元。

7 支持>>操作符的复数类
7.1 问题
定义一个复数类，类中包括两个私有的成员变量，m_r代表实部，m_i代表虚部，并重载>>输入流运算符，以实现复数的输入操作。
7.2 步骤
实现此案例需要按照如下步骤进行。
步骤一：支持>>操作符的复数类
使用递归方法，将数组先分成前后两部分，然后再将前一部分分解，最后将后一部分分解。
代码如下：
#include <iostream>
class Complex {
private:
    int m_r;//实部
    int m_i;//虚部
public:
    Complex(double r = 0, double i = 0) : m_r(r), m_i(i) {
    }
    void show(void) const {
        std::cout << m_r << "+" << m_i << "i" << std::endl;
    }
    friend std::istream& operator>> (std::istream&, Complex&);
    friend std::ostream& operator<< (std::ostream&, Complex const&);
};
std::istream& operator>> (std::istream& lhs, Complex& rhs) {
    return lhs >> rhs.m_r >> rhs.m_i;
}
std::ostream& operator<< (std::ostream& lhs, Complex const& rhs) {
    return lhs << rhs.m_r << '+' << rhs.m_i << 'i';
}
int main(int argc, const char* argv[]) {
    Complex c1;
    std::cin >> c1;
    std::cout << c1 << std::endl;
    return 0;
}
上述代码中，以下代码：
std::istream& operator>> (std::istream& lhs, Complex& rhs) {
    return lhs >> rhs.m_r >> rhs.m_i;
}
定义了复数类Complex的>>输入流运算符的全局函数。因为左操作数的类型为istream，若以成员函数形式重载该操作符，就应将其定义为istream类的成员，该类为标准库提供，无法添加新的成员，因此只能以全局函数形式重载该操作符。非常第一参数以支持左值型左操作数，非常第二参数以支持左值型右操作数，非常返回值以支持左值型表达式的值，返回引用型第一参数即左操作数本身。
上述代码中，以下代码：
friend std::istream& operator>> (std::istream&, Complex&);
为了在一个全局操作符函数中直接访问其操作数类型的私有及保护成员，同时又不破坏其操作数类型的封装性，可以将该操作符函数声明为其操作数类型的友元。

CSD STDCPP02 DAY01

1 支持[]操作符的数组类
1.1 问题
下标[]操作符重载常用于在容器类型中以下标方式获取数据元素，对于非常容器的元素为左值，对于常容器的元素为右值。
1.2 步骤
实现此案例需要按照如下步骤进行。
步骤一：支持[]操作符的数组类
代码如下：
#include <iostream>
class Array {
private:
    int m_array[256];
public:
    Array(void) {
        memset(m_array, 0, sizeof(m_array));
    }
    int& operator[](size_t i) {
        return m_array[i];
    }
    const int& operator[](size_t i) const {
        return const_cast<Array&>(*this)[i];
    }
};
int main(int argc, const char* argv[]) {
    Array array;
    array[100] = 1000;
    std::cout << array.operator[](100) << std::endl;
    const Array& carray = array;
    std::cout << carray[100] << std::endl;
    return 0;
}
上述代码中，以下代码：
int& operator[](size_t i) {
    return m_array[i];
}
定义了容器类Array的下标[]操作符重载。由于非常容器的元素可能为左值，如在主程序中的以下代码：
array[100] = 1000;
所以，下标[]操作符的重载函数的返回值必须是引用类型。
上述代码中，以下代码：
const int& operator[](size_t i) const {
    return const_cast<Array&>(*this)[i];
}
是由于常容器的元素只能作为右值，如在主程序中的以下代码：
const Array& carray = array;
std::cout << carray[100] << std::endl;
carray即为常容器对象，常容器的元素carray[100]因为是常量，所以只能做右值使用。

2 支持()操作符的平方类
2.1 问题
如果一个类重载了函数操作符()，那么该类的对象就可以被当做函数来调用，其参数和返回值就是函数操作符函数的参数和返回值，参数的个数、类型以及返回值的类型，没有限制，函数操作符()是唯一可以带有缺省参数的操作符重载函数。
2.2 步骤
实现此案例需要按照如下步骤进行。
步骤一：支持()操作符的平方类
代码如下：
#include <iostream>
class Square {
public:
    int operator()(int x) {
        return x * x;
    }
};
int main(int argc, const char* argv[]) {
    Square square;
    std::cout << square(5) << std::endl;
    return 0;
}
上述代码中，以下代码：
int operator()(int x) {
    return x * x;
}
定义了类Square的函数操作符()重载。当一个类重载了函数操作符()后，该类的对象就可以被当做函数来调用，如在主程序中的以下语句：
std::cout << square(5) << std::endl;
其中square是一个对象，不是函数名，但square(5)的使用方法与调用一个函数没有区别，就是因为重载了函数操作符的缘故。

3 简化版的智能指针类
3.1 问题
如果一个类重载了解引用*操作符和间接成员访问->操作符，那么该类的对象就可以被当做指针来使用。智能指针是一个封装了常规指针的类类型对象，当它离开作用域时，其析构函数负责释放该常规指针所指向的动态内存。任何时候，针对同一个对象，只允许有一个智能指针持有其地址，否则该对象将在多个智能指针中被析构多次，因此智能指针的拷贝构造和拷贝赋值需要做特殊处理，对其所持有的对象地址，以指针间的转移代替复制。
3.2 步骤
实现此案例需要按照如下步骤进行。
步骤一：简化版的智能指针类
代码如下：
#include <iostream>
class Integer {
private:
    int m_val;
public:
    Integer(const int& val) : m_val(val) {
    }
    int& value(void) {
        return m_val;
    }
    const int& value(void) const {
        return m_val;
    }
};
class IntegerPointer {
private:
    Integer* m_p;
public:
    IntegerPointer(Integer* p = NULL) : m_p(p) {
    }
    IntegerPointer(IntegerPointer& p) {
        m_p = p.m_p;
        p.m_p = NULL;
    }
    ~IntegerPointer() {
        delete m_p;
    }
    IntegerPointer& operator= (IntegerPointer& p) {
        if (&p != this) {
            delete m_p;
            m_p = p.m_p;
            p.m_p = NULL;
        }
        return *this;
    }
    Integer& operator* (void) const {
        return *m_p;
    }
    Integer* operator-> (void) const {
        return m_p;
    }
};
int main(int argc, const char* argv[]) {
    IntegerPointer ip(new Integer(100));
    std::cout << (*ip).value() << std::endl;
    ip->value()++;
    std::cout << ip->value() << std::endl;
    IntegerPointer ip1 = ip;
    //std::cout << ip->value() << std::endl;
    std::cout << ip1->value() << std::endl;
    IntegerPointer ip2(new Integer(200));
    ip2 = ip1;
    //std::cout << ip1->value() << std::endl;
    std::cout << ip2->value() << std::endl;
    return 0;
}
上述代码中，以下代码：
class IntegerPointer
定义了一个简化版的智能指针类IntegerPointer。
上述代码中，以下代码：
Integer& operator* (void) const {
    return *m_p;
}
在类IntegerPoiner中重载了解引用*操作符，由于解引用*操作符可以将指针指向的内存单元的内容取出来，所以该函数返回一个当前指针m_p指向的对象。如在主程序中的以下语句：
std::cout << (*ip).value() << std::endl;
等效于如下语句：
std::cout << (ip.operator*()).value() << std::endl;
其中(*ip)，即(ip.operator*())，得到的是智能指针ip指向的对象。
上述代码中，以下代码：
Integer* operator-> (void) const {
    return m_p;
}
在类IntegerPoiner中重载了间接成员访问->操作符，使得主程序中的如下语句：
std::cout << ip->value() << std::endl;
使得智能指针ip可以访问其指向的对象的成员。
上述代码中，以下代码：
IntegerPointer(IntegerPointer& p) {
    m_p = p.m_p;
    p.m_p = NULL;
}
重新定义了拷贝构造函数，这是因为在任何时候，针对同一个对象，只允许有一个智能指针持有其地址，否则该对象将在多个智能指针中被析构多次。如在主程序中的以下语句：
IntegerPointer ip1 = ip;
如果不按上述方法重新定义拷贝构造函数，则智能指针ip和ip1指向同一对象，当两个对象的作用域结束时，都要调用如下析构函数：
~IntegerPointer() {
    delete m_p;
}
释放其指向的存储空间，当ip和ip1指向的是同一个对象，释放两次，第二次必然会导致程序崩溃。
上述代码中，以下代码：
IntegerPointer& operator= (IntegerPointer& p) {
    if (&p != this) {
        delete m_p;
        m_p = p.m_p;
        p.m_p = NULL;
    }
    return *this;
}
重载了赋值=操作符，也是为了防止多个智能指针指向同一个对象导致的被析构多次。如在主程序中的以下语句：
IntegerPointer ip2(new Integer(200));
ip2 = ip1;
当一个智能指针ip1赋值给另一个智能指针ip2时，ip1将变成空指针，以防止多个智能指针指向同一个对象。

4 auto_ptr的基本用法和局限
4.1 问题
auto_ptr模板定义了类似指针的对象，可以将new直接或间接获得的地址赋值给这种对象。当auto_ptr对象生命周期结束时，其析构函数会将auto_ptr对象拥有的动态内存自动释放。即使发生异常，通过异常的栈展开过程也能将动态内存释放。
4.2 步骤
实现此案例需要按照如下步骤进行。
步骤一：auto_ptr的基本用法和局限
代码如下：
#include <iostream>
#include <memory>
class Integer {
private:
    int m_val;
public:
    Integer(const int& val) : m_val(val) {
    }
    int& value(void) {
        return m_val;
    }
    const int& value(void) const {
        return m_val;
    }
};
int main(int argc, const char* argv[]) {
    std::auto_ptr<Integer> ip(new Integer(100));
    std::cout << (*ip).value() << std::endl;
    ip->value()++;
    std::cout << ip->value() << std::endl;
    std::auto_ptr<Integer> ip1 = ip;
    //std::cout << ip->value() << std::endl;
    std::cout << ip1->value() << std::endl;
    std::auto_ptr<Integer> ip2(new Integer(200));
    ip2 = ip1;
    //std::cout << ip1->value() << std::endl;
    std::cout << ip2->value() << std::endl;
    //std::auto_ptr<Integer> ip3(new Integer[10]);
    return 0;
}
上述代码中，以下代码：
std::auto_ptr<Integer> ip (new Integer(100));
定义了一个auto_ptr智能指针模板类的对象ip，指向一个由new生成的类Integer的对象，其中<Integer>表示智能指针的数据类型。
上述代码中，以下代码：
std::cout << (*ip).value() << std::endl;
由于在模板类auto_ptr中重载了解引用*操作符，所以(*ip)即是上面用new生成的类Integer的对象。
上述代码中，以下代码：
std::cout << ip->value() << std::endl;
由于在模板类auto_ptr中重载了间接成员访问->操作符，所以模板类auto_ptr的对象ip可以访问到上面用new生成的类Integer的对象的成员函数。
上述代码中，以下代码：
std::auto_ptr<Integer> ip1 = ip;
//std::cout << ip->value() << std::endl;
std::cout << ip1->value() << std::endl;
由于在模板类auto_ptr中重新定义了拷贝构造函数，所以当将ip初始化给ip1时，ip将自动变成空指针，这是因为在任何时候，针对同一个对象，只允许有一个模板类auto_ptr指针持有其地址，否则该对象将在多个模板类auto_ptr指针中被析构多次，造成程序崩溃。
上述代码中，以下代码：
std::auto_ptr<Integer> ip2(new Integer(200));
ip2 = ip1;
//std::cout << ip1->value() << std::endl;
std::cout << ip2->value() << std::endl;
由于重载了模板类auto_ptr中赋值=操作符，所以当将ip1赋值给ip2时，ip1将自动变成空指针，这也是为了防止同一个对象在多个模板类auto_ptr指针中被析构多次。
上述代码中，以下代码：
//std::auto_ptr<Integer> ip3(new Integer[10]);
不允许让模板类auto_ptr指针指向对象数组。这是因为在模板类auto_ptr中的析构函数是使用delete释放存储空间的，而不是使用delete[]释放。

5 在基本类型和类类型之间做类型转换
5.1 问题
由基本数据类型向类数据类型转换，只能通过类类型的构造函数实现。由类数据类型向基本数据类型转换，只能通过类类型的类型转换操作符函数实现。
5.2 步骤
实现此案例需要按照如下步骤进行。
步骤一：在基本类型和类类型之间做类型转换
代码如下：
#include <iostream>
class Integer {
private:
    int m_val;
public:
    Integer(const int& val) : m_val(val) {
    }
    int& value(void) {
        return m_val;
    }
    const int& value(void) const {
        return m_val;
    }
    operator int (void) const {
        return m_val;
    }
};
int main(int argc, const char* argv[]) {
    Integer i = 10;
    std::cout << i.value() << std::endl;
    i = 20;
    std::cout << i.value() << std::endl;
    int a = i;
    std::cout << a << std::endl;
    return 0;
}
上述代码中，以下代码：
Integer(const int& val) : m_val(val) {
}
是类Integer的构造函数，当此构造函数如上只有一个形参时，它还有一个功能就是由基本数据类型int向类数据类型Integer进行转换。如在主程序中，以下语句：
Integer i = 10;
和以下语句：
i = 20;
都是将int型数据赋值给类Integer类型的对象，我们知道，当赋值号两边的数据类型不一致时，会按照左值的类型进行转换。左值的类型为类Integer，所以转换方法就是类Integer的构造函数。
上述代码中，以下代码：
operator int (void) const {
    return m_val;
}
是类Integer的类型转换操作符函数，该函数可以将类数据类型Integer的数据向基本数据类型int进行转换。如在主程序中，以下语句：
int a = i;
是将类Integer类型的对象赋值给int型变量，此时需要将类Integer类型转换成int类型，这个转换方法由类Integer的operator int (void) const函数完成。
注意：以上类型之间的转换都是隐式转换，可以使用关键字explicit加以禁止。
如将代码写成：
explicit Integer(const int& val) : m_val(val) {
}
则主程序中的如下语句：
Integer i = 10;
和以下语句：
i = 20;
将变成非法。

6 重载new和delete操作符
6.1 问题
由于new和delete都是运算符，所以可以重载new和delete。这样做的好处是，有时希望使用某种特殊的动态内存分配方法。例如，可能有些分配子程序，他们的堆已耗尽，自动开始把一个磁盘文件当虚存储使用，或者用户希望控制某一片存储空间的分配等。
6.2 步骤
实现此案例需要按照如下步骤进行。
步骤一：重载new和delete操作符
代码如下：
#include <iostream>
class Integer {
private:
    int m_val;
public:
    Integer(const int& val = 0) : m_val(val) {
    }
    ~Integer() {
        std::cout << "Integer destructor" << std::endl;
    }
    int& value(void) {
        return m_val;
    }
    const int& value(void) const {
        return m_val;
    }
    static void* operator new(size_t size) {
        return malloc(size);
    }
    static void* operator new[](size_t size) {
        return malloc(size);
    }
    static void operator delete(void* p) {
        free(p);
    }
    static void operator delete[](void* p) {
        free(p);
    }
};
int main(int argc, const char* argv[]) {
    Integer* pi = new Integer(10);
    std::cout << pi->value() << std::endl;
    delete pi;
    Integer* pi1 = new Integer[10] {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    for (int i = 0; i < 10; i++)
        std::cout << pi1[i].value() << " ";
    std::cout << std::endl;
    delete[] pi1;
    return 0;
}
上述代码中，以下代码：
static void* operator new(size_t size) {
    return malloc(size);
}
类Integer重载了new操作符。那么当在主程序中，通过如下代码：
Integer *pi = new Integer(10);
使用new创建该类的对象，此时将首先调用该操作符函数分配内存，然后再调用该类的构造函数。
上述代码中，以下代码：
static void operator delete(void* p) {
    free(p);
}
类Integer重载了delete操作符。那么当在主程序中，通过如下代码：
delete pi;
使用delete销毁该类的对象，此时将首先调用该类的析构函数，然后再调用该操作符函数释放内存。
上述代码中，以下代码：
static void* operator new[](size_t size) {
    return malloc(size);
}
类Integer重载了new[]操作符。那么当在主程序中，通过如下代码：
Integer* pi1 = new Integer[10] {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
使用new[]创建该类的对象数组，此时将首先调用该操作符函数为数组的每个元素分配内存，然后再为数组的每个元素调用该类的构造函数。
上述代码中，以下代码：
static void operator delete[](void* p) {
    free(p);
}
类Integer重载了delete[]操作符。那么当在主程序中，通过如下代码：
delete[] pi1;
使用delete[]销毁该类的对象数组，此时将首先为数组的每个元素调用该类的析构函数，然后再为数组的每个元素调用该操作符函数释放内存

7 人、学生和教师
7.1 问题
定义三个类，它们是类Human，类Student和类Teacher，其中，类Human是类Student和类Teacher的基类。在类Human中，包含两个数据成员，一个是类string的对象m_name用于存储姓名，另一个是整型变量m_age，用于存储年龄。在类Human中，还包含六个函数成员，它们是m_name的设置、获取函数，m_age的设置、获取函数，eat函数和sleep函数。类Student继承自类Human，自己又新增了一个成员变量m_no，用于存储学号，新增了三个函数成员，它们是m_no的设置、获取函数和learn函数。类Teacher也继承自类Human，自己又新增了一个成员变量m_course，用于存储其所教授的课程，新增了三个函数成员，它们是m_course的设置、获取函数和teach函数。
7.2 步骤
实现此案例需要按照如下步骤进行。
步骤一：人、学生和教师
代码如下：
#include <iostream>
class Human {
private:
    std::string m_name;
    int m_age;
public:
    void setName(std::string const& name) {
        m_name = name;
    }
    void setAge(const int& age) {
        m_age = age;
    }
    std::string const& name(void) const {
        return m_name;
    }
    const int& age(void) const {
        return m_age;
    }
    void eat(std::string const& food) const {
        std::cout << m_name << "正在吃" << food << std::endl;
    }
    void sleep(int hours) {
        std::cout << m_name << "睡了" << hours << "小时" << std::endl;
    }
};
class Student : public Human {
private:
    int eat;
    int m_no;
public:
    void setNo(const int& no) {
        m_no = no;
    }
    const int& no(void) const {
        return m_no;
    }
    void learn(std::string const& course) const {
        //std::cout << m_name << "学" << course << std::endl; // 错误
        std::cout << name() << "学" << course << std::endl;
    }
};
class Teacher : public Human {
private:
    std::string m_course;
public:
    void setCourse(std::string const& course) {
        m_course = course;
    }
    std::string const& course(void) const {
        return m_course;
    }
    void teach() const {
        std::cout << name() << "教《" << m_course << "》课程" << std::endl;
    }
};
int main(int argc, const char* argv[]) {
    Student student;
    Human* phuman = &student;
    //Student* pstudent = phuman; // 错误
    Student* pstudent = static_cast<Student*>(phuman);
    _
    Human& rhuman = student;
    //Student& rstudent = rhuman; // 错误
    Student& rstudent = static_cast<Student&>(rhuman);
    //student.eat("饺子");
    student.Human::eat("饺子");
    student.sleep(6);
    return 0;
}
上述代码中，以下代码：
Student student;
Human* phuman = &student;
和以下代码：
Human& rhuman = student;
是合法的，子类类型Student的指针或引用总可以被隐式地转换为其基类类型Human的指针或引用，这种操作性缩小的类型转换，在编译器看来是安全的。
上述代码中，以下代码：
//Student* pstudent = phuman; // 错误
和以下代码：
//Student& rstudent = rhuman; // 错误
是非法的。基类类型Human的指针或引用不可以被隐式地转换为其子类类型Student的指针或引用，这种操作性扩大的类型转换，在编译器看来是危险的。如果一定要转换，可以使用静态类型转换。如以下代码：
Student* pstudent = static_cast<Student*> (phuman);_
或
Student& rstudent = static_cast<Student&> (rhuman);
上述代码中，以下代码：
student.sleep(6);
在子类中或通过子类，可以直接访问基类的所有公有和保护成员，就如同它们是在子类中声明的一样。
上述代码中，以下代码：
void learn(std::string const& course) const {
    //std::cout << m_name << "学" << course << std::endl; // 错误
    std::cout << name() << "学" << course << std::endl;
}
基类的私有成员m_name在子类Student中虽然存在却是不能直接使用的，故无法直接访问。
上述代码中，以下代码：
class Student : public Human {
private:
   	int eat;
    int m_no;
    尽管基类Human的公有和保护成员在子类Student中直接可见，但仍然可以在子类中重新定义这些名字，如eat，在基类Human中是成员函数名，在子类Student中可以重新定义成成员变量名，需要注意的是子类中的名字会隐藏所有基类中的同名定义。如下代码所示：
    //student.eat("饺子");
    在子类Student中，eat被定义成私有的成员变量，这样eat会隐藏从基类继承过来的成员函数eat，如此调用是非法的。应改成：
    student.Human::eat("饺子");
    如果需要在子类Student中或通过子类访问一个在基类Human中定义却为子类所隐藏的名字eat，可以借助作用域限定操作符“::”实现。
    
    8 公有成员、保护成员和私有成员
    8.1 问题
    访问控制限定符规定了一个类的特定成员，是否具有被从类的内部、类的子类，以及类的外部进行访问的能力。说明见图-1。
    图-1
    8.2 步骤
    实现此案例需要按照如下步骤进行。
    步骤一：公有成员、保护成员和私有成员
    代码如下：
#include <iostream>
    class Base {
    private:
        int m_private;
    protected:
        int m_protected;
    public:
        int m_public;
        void show(void) const {
            std::cout << m_private << std::endl;
            std::cout << m_protected << std::endl;
            std::cout << m_public << std::endl;
        }
        friend void print(Base const& base);
    };
    class Derive : public Base {
    public:
        void show(void) const {
            //std::cout << m_private << std::endl;
            std::cout << m_protected << std::endl;
            std::cout << m_public << std::endl;
        }
    };
    void print(Base const& base) {
        std::cout << base.m_private << std::endl;
        std::cout << base.m_protected << std::endl;
        std::cout << base.m_public << std::endl;
    }
    int main(int argc, const char* argv[]) {
        Base base;
        //    base.m_private = 10;
        //    base.m_protected = 20;
        base.m_public = 30;
        print(base);
        return 0;
    }
    上述代码中，以下代码：
    class Base {
    private:
        int m_private;
    protected:
        int m_protected;
    public:
        int m_public;
        在类Base中定义了一个私有的成员变量m_private，一个保护的成员变量m_protected和一个公有的成员变量m_public。
        上述代码中，以下代码：
        class Base {
        private:
            int m_private;
        protected:
            int m_protected;
        public:
            int m_public;
            void show(void) const {
                std::cout << m_private << std::endl;
                std::cout << m_protected << std::endl;
                std::cout << m_public << std::endl;
            }
            在类Base内，成员函数show可以访问类Base的私有的、保护的和公有的成员变量。
            上述代码中，以下代码：
            class Derive : public Base {
            public:
                void show(void) const {
                    //std::cout << m_private << std::endl;
                    std::cout << m_protected << std::endl;
                    std::cout << m_public << std::endl;
                }
            };
            在类Base的子类Derive中的成员函数show只可以访问类Base的保护的和公有的成员变量，不能访问私有的成员变量。
            上述代码中，以下代码：
            void print(Base const& base) {
                std::cout << base.m_private << std::endl;
                std::cout << base.m_protected << std::endl;
                std::cout << base.m_public << std::endl;
            }
            是一个全局函数，但该函数在类Base中被声明为友元，如下语句所示：
            friend void print (Base const& base);
            所以，全局函数print可以访问类Base的私有的、保护的和公有的成员变量。
            上述代码中，以下代码：
            int main(int argc, const char* argv[]) {
                Base base;
                //    base.m_private = 10;
                //    base.m_protected = 20;
                base.m_public = 30;
                print(base);
                return 0;
            }
            在类外定义了类Base的对象base，该对象只能访问类Base的共有的成员，不能访问私有的和保护的成员。
            
            9 公有继承、保护继承和私有继承
            9.1 问题
            基类中的公有、保护和私有成员，在其公有、保护和私有子类中的访问控制属性，会因继承方式而异。说明见图-2。
            图-2
            9.2 步骤
            实现此案例需要按照如下步骤进行。
            步骤一：公有继承、保护继承和私有继承
            代码如下：
#include <iostream>
            class Base {
            private:
                int m_private;
            protected:
                int m_protected;
            public:
                int m_public;
            };
            class Public : public Base {
            public:
                void show(void) const {
                    //std::cout << m_private << std::endl;
                    std::cout << m_protected << std::endl;
                    std::cout << m_public << std::endl;
                }
            };
            class Protected : protected Base {
            public:
                void show(void) const {
                    //std::cout << m_private << std::endl;
                    std::cout << m_protected << std::endl;
                    std::cout << m_public << std::endl;
                }
            };
            class Private : private Base {
            public:
                void show(void) const {
                    //std::cout << m_private << std::endl;
                    std::cout << m_protected << std::endl;
                    std::cout << m_public << std::endl;
                }
            };
            int main(int argc, const char* argv[]) {
                Base base;
                //    base.m_private = 10;
                //    base.m_protected = 20;
                base.m_public = 30;
                return 0;
            }
            上述代码中，以下代码：
            class Base {
            private:
                int m_private;
            protected:
                int m_protected;
            public:
                int m_public;
            };
            定义了一个类Base，在该类中定义了一个私有的成员变量m_private，一个保护的成员变量m_protected和一个公有的成员变量m_public。
            上述代码中，以下代码：
            class Public : public Base {
            public:
                void show(void) const {
                    //std::cout << m_private << std::endl;
                    std::cout << m_protected << std::endl;
                    std::cout << m_public << std::endl;
                }
            };
            定义了类Base的公有继承子类Public，在该类中，基类Base的私有成员m_private在类Public中变成了不可访问的成员，保护的成员变量m_protected仍然是保护的，公有的成员变量m_public仍然是公有的。
            上述代码中，以下代码：
            class Protected : protected Base {
            public:
                void show(void) const {
                    //std::cout << m_private << std::endl;
                    std::cout << m_protected << std::endl;
                    std::cout << m_public << std::endl;
                }
            };
            定义了类Base的保护继承子类Protected，在该类中，基类Base的私有成员m_private在类Protected中变成了不可访问的成员，保护的成员变量m_protected和公有的成员变量m_public都变成了保护的。
            上述代码中，以下代码：
            class Private : private Base {
            public:
                void show(void) const {
                    //std::cout << m_private << std::endl;
                    std::cout << m_protected << std::endl;
                    std::cout << m_public << std::endl;
                }
            };
            定义了类Base的私有继承子类Private，在该类中，基类Base的私有成员m_private在类Private中变成了不可访问的成员，保护的成员变量m_protected和公有的成员变量m_public都变成了私有的。
            
            CSD STDCPP02 DAY02
            
            1 基类子对象的隐式构造
            1.1 问题
            如果子类的构造函数没有显式指明其基类部分的构造方式，那么编译器会选择其基类的缺省构造函数，构造该子类对象中的基类子对象，但是请注意，只有在为基类显式提供一个无参构造函数，或者不提供任何构造函数(系统会提供一个缺省的无参构造函数)的情况下，基类才拥有无参构造函数。
            1.2 步骤
            实现此案例需要按照如下步骤进行。
            步骤一：基类子对象的隐式构造
            代码如下：
#include <iostream>
            class Human {
            private:
                std::string m_name;
                int m_age;
            public:
                Human(std::string const& name = "", const int& age = 0) : m_name(name),
                m_age(age) {
                }
                void setName(std::string const& name) {
                    m_name = name;
                }
                void setAge(const int& age) {
                    m_age = age;
                }
                std::string const& name(void) const {
                    return m_name;
                }
                const int& age(void) const {
                    return m_age;
                }
                void eat(std::string const& food) const {
                    std::cout << m_name << "正在吃" << food << std::endl;
                }
                void sleep(int hours) {
                    std::cout << m_name << "睡了" << hours << "小时" << std::endl;
                }
            };
            class Student : public Human {
            private:
                int m_no;
            public:
                Student(const int& no) : m_no(no) {
                }
                void setNo(const int& no) {
                    m_no = no;
                }
                const int& no(void) const {
                    return m_no;
                }
                void learn(std::string const& course) const {
                    std::cout << name() << "学" << course << std::endl;
                }
            };
            int main(int argc, const char* argv[]) {
                Student student(123456);
                return 0;
            }
            上述代码中，以下代码：
            Human(std::string const& name = "", const int& age = 0) : m_name(name),
            m_age(age) {
            }
            为基类Human显式提供一个带参构造函数，但由于该构造函数的两个形参均带有缺省参数，所以也可以将其当做无参构造函数来使用。
            上述代码中，以下代码：
            Student(const int& no) : m_no(no) {
            }
            为子类Student显示的提供了一个带参构造函数，但由于子类Student的构造函数没有显式指明其基类Human部分的构造方式，那么编译器会选择其基类的缺省构造函数，构造该子类对象中的基类子对象。如以下主程序中的代码：
            Student student(123456);
            定义了一个子类Student的对象student，首先为student中继承的基类部分成员分配空间，分配完成后，就会调用基类的构造函数进行初始化，然后再分配子类中新添加的成员变量的存储空间，分配完成后，才会调用子类的构造函数进行初始化。
            
            2 基类子对象的显式构造
            2.1 问题
            子类的构造函数可以在初始化表中显式指明其基类部分的构造方式，即通过其基类的特定构造函数，构造该子类对象中的基类子对象。
            2.2 步骤
            实现此案例需要按照如下步骤进行。
            步骤一：基类子对象的显式构造
            代码如下：
#include <iostream>
            class Human {
            private:
                std::string m_name;
                int m_age;
            public:
                Human(std::string const& name = "", const int& age = 0) : m_name(name),
                m_age(age) {
                }
                void setName(std::string const& name) {
                    m_name = name;
                }
                void setAge(const int& age) {
                    m_age = age;
                }
                std::string const& name(void) const {
                    return m_name;
                }
                const int& age(void) const {
                    return m_age;
                }
                void eat(std::string const& food) const {
                    std::cout << m_name << "正在吃" << food << std::endl;
                }
                void sleep(int hours) {
                    std::cout << m_name << "睡了" << hours << "小时" << std::endl;
                }
            };
            class Student : public Human {
            private:
                int m_no;
            public:
                Student(std::string const& name, const int& age, const int& no) : Human(name,
                                                                                        age), m_no(no) {
                }
                void setNo(const int& no) {
                    m_no = no;
                }
                const int& no(void) const {
                    return m_no;
                }
                void learn(std::string const& course) const {
                    std::cout << name() << "学" << course << std::endl;
                }
            };
            int main(int argc, const char* argv[]) {
                Student student("张三", 20, 123456);
                return 0;
            }
            上述代码中，以下代码：
            Human(std::string const& name = "", const int& age = 0) : m_name(name),
            m_age(age) {
            }
            为基类Human显式提供一个带参构造函数，但由于该构造函数的两个形参均带有缺省参数，所以也可以将其当做无参构造函数来使用。
            上述代码中，以下代码：
            Student(std::string const& name, const int& age, const int& no) : Human(name,
                                                                                    age), m_no(no) {
            }
            为子类Student显示的提供了一个带参构造函数，子类Student的构造函数可以在初始化表中显式指明其基类Human部分的构造方式，即通过其基类Human的特定构造函数，构造该子类对象中的基类子对象。如以下主程序中的代码：
            Student student("张三", 20, 123456);
            定义了一个子类Student的对象student，首先为student中继承的基类部分成员分配空间，分配完成后，就会从初始化表中找到并调用基类Human的构造函数进行初始化，然后再分配子类中新添加的成员变量的存储空间，分配完成后，才会调用子类Student的构造函数进行初始化。
            
            3 子类对象的构造过程
            3.1 问题
            子类的构造函数执行过程是这样的，首先，按照继承表中的顺序，依次调用各个基类的构造函数，构造子类对象中的基类子对象，然后，按照声明的顺序，依次调用各个类类型成员变量相应类型的构造函数，构造子类对象中的成员子对象，最后，执行子类构造函数体中的代码，完成整个构造过程。无论如何，子类的构造函数都一定会(显式或隐式地)调用其基类和类类型成员变量类型的构造函数。
            3.2 步骤
            实现此案例需要按照如下步骤进行。
            步骤一：子类对象的构造过程
            代码如下所示：
#include <iostream>
            class Human {
            private:
                std::string m_name;
                int m_age;
            public:
                Human(std::string const& name = "", const int& age = 0) : m_name(name),
                m_age(age) {
                }
                void setName(std::string const& name) {
                    m_name = name;
                }
                void setAge(const int& age) {
                    m_age = age;
                }
                std::string const& name(void) const {
                    return m_name;
                }
                const int& age(void) const {
                    return m_age;
                }
                void eat(std::string const& food) const {
                    std::cout << m_name << "正在吃" << food << std::endl;
                }
                void sleep(int hours) {
                    std::cout << m_name << "睡了" << hours << "小时" << std::endl;
                }
            };
            class Student : public Human {
            private:
                int m_no;
                std::string m_address;
            public:
                Student(std::string const& name, const int& age, const int& no,
                        std::string const& address) : Human(name, age), m_address(address), m_no(no) {
                }
                void setNo(const int& no) {
                    m_no = no;
                }
                const int& no(void) const {
                    return m_no;
                }
                void learn(std::string const& course) const {
                    std::cout << name() << "学" << course << std::endl;
                }
            };
            int main(int argc, const char* argv[]) {
                Student student("张三", 20, 123456, "江苏南京市");
                return 0;
            }
            上述代码中，以下代码：
            Human(std::string const& name = "", const int& age = 0) : m_name(name),
            m_age(age) {
            }
            为基类Human显式提供一个带参构造函数，但由于该构造函数的两个形参均带有缺省参数，所以也可以将其当做无参构造函数来使用。
            上述代码中，以下代码：
            Student(std::string const& name, const int& age, const int& no,
                    std::string const& address) : Human(name, age), m_address(address), m_no(no) {
            }
            为子类Student显示的提供了一个带参构造函数，子类Student的构造函数可以在初始化表中显式指明其基类Human部分的构造方式，即通过其基类Human的特定构造函数，构造该子类对象中的基类子对象。同时子类Student的构造函数在初始化表中，显式指明类类型string成员变量m_address相应类型的构造函数，构造子类对象中的成员子对象m_address。如以下主程序中的代码：
            Student student("张三", 20, 123456, "江苏南京市");
            定义了一个子类Student的对象student，首先，按照继承表中的顺序，如下代码：
            class Student : public Human
            冒号后面的部分即为继承表的内容，当多重继承时，继承表中可以有多个基类，此时依次调用各个基类的构造函数，构造子类对象中的基类子对象。然后，按照声明的顺序，如下代码：
        private:
            int m_no;
            std::string m_address;
            声明的顺序就是定义数据成员的顺序，一个类中可能会有多个类类型的成员，此时依次调用各个类类型成员变量相应类型的构造函数，构造子类对象中的成员子对象。最后，执行子类构造函数体中的代码，完成整个构造过程。
            
            4 断子绝孙的类
            4.1 问题
            与其它一些面向对象语言(比如Java)不同，C++语言并没有提供专门的方法来阻止一个类被继承。但如果把一个类的全部构造函数声明为私有，那么一旦从该类派生了子类，该子类将由于无法调用基类的构造函数而导致编译错误，因为基类的私有部分的内容在子类中是不可访问的。为了获得被阻断继承的基类本身的对象，可能需要为其提供专门用于创建对象的静态接口。
            4.2 步骤
            实现此案例需要按照如下步骤进行。
            步骤一：断子绝孙的类
            代码如下所示：
#include <iostream>
            class User {
            private:
                std::string m_name;
                User(void) {
                }
                User(std::string const& name) : m_name(name) {
                }
                User(User const& user) {
                }
            public:
                static User* createInstance(std::string const& name) {
                    return new User(name);
                }
                void show(void) const {
                    std::cout << m_name << std::endl;
                }
            };
            class UserVIP : public User {
            };
            int main(int argc, const char* argv[]) {
                //UserVIP vip;
                User* user = User::createInstance("张三");
                user->show();
                return 0;
            }
            上述代码中，以下代码：
            class User {
            private:
                std::string m_name;
                User(void) {
                }
                User(std::string const& name) : m_name(name) {
                }
                User(User const& user) {
                }
                把类User的构造函数声明为私有的，则这些构造函数将不能在类外被使用。
                上述代码中，以下代码：
                class UserVIP : public User {
                };
                定义了基类User的子类UserVIP，这是错误的。因为基类User中构造函数是私有成员，则被继承到子类UserVIP中这些构造函数将是不可访问的，那么子类的构造函数必须显示的或隐式的调用基类的构造函数，由于构造函数的不可访问性，造成不能访问。如下主程序中的语句：
                //UserVIP vip;
                就会出现语法错误。
                上述代码中，以下代码：
                static User* createInstance(std::string const& name) {
                    return new User(name);
                }
                为了获得基类User本身的对象，则需要为其提供专门用于创建对象的静态接口。如下主程序中的语句：
                User *user = User::createInstance("张三");
                user->show();
                创建类User的对象。
                
                5 delete指向子类对象的基类指针
                5.1 问题
                对一个指向子类对象的基类指针使用delete运算符，实际被调用的将是基类的析构函数，该函数不会调用子类的析构函数，其所析构的仅仅是子类对象中的基类子对象，而子类的扩展部分极有可能因此而形成内存泄漏。
                5.2 步骤
                实现此案例需要按照如下步骤进行。
                步骤一：delete指向子类对象的基类指针
                代码如下所示：
#include <iostream>
                class Human {
                private:
                    std::string m_name;
                    int m_age;
                public:
                    Human(std::string const& name = "", const int& age = 0) : m_name(name),
                    m_age(age) {
                    }
                    ~Human(void) {
                        std::cout << "Human destructor" << std::endl;
                    }
                    void setName(std::string const& name) {
                        m_name = name;
                    }
                    void setAge(const int& age) {
                        m_age = age;
                    }
                    std::string const& name(void) const {
                        return m_name;
                    }
                    const int& age(void) const {
                        return m_age;
                    }
                    void eat(std::string const& food) const {
                        std::cout << m_name << "正在吃" << food << std::endl;
                    }
                    void sleep(int hours) {
                        std::cout << m_name << "睡了" << hours << "小时" << std::endl;
                    }
                };
                class Student : public Human {
                private:
                    int m_no;
                    char* m_address;
                public:
                    Student(const int& no, const char* address) : m_no(no) {
                        m_address = new char[strlen(address) + 1];
                        strcpy(m_address, address);
                    }
                    ~Student(void) {
                        delete [] m_address;
                        std::cout << "Student destructor" << std::endl;
                    }
                    void setNo(const int& no) {
                        m_no = no;
                    }
                    const int& no(void) const {
                        return m_no;
                    }
                    void learn(std::string const& course) const {
                        std::cout << name() << "学" << course << std::endl;
                    }
                };
                int main(int argc, const char* argv[]) {
                    Human* pHuman = new Student(123456, "江苏南京市");
                    delete pHuman;
                    return 0;
                }
                上述代码中，以下代码：
                ~Human(void) {
                    std::cout << "Human destructor" << std::endl;
                }
                定义了类Human的析构函数，在该函数中，只是输出一句话，提示该函数被调用了。
                上述代码中，以下代码：
                class Student : public Human {
                private:
                    int m_no;
                    char* m_address;
                public:
                    Student(const int& no, const char* address) : m_no(no) {
                        m_address = new char[strlen(address) + 1];
                        strcpy(m_address, address);
                    }
                    在子类Student中定义了一个字符指针m_address，并在构造函数中，为其分配存储空间。
                    上述代码中，以下代码：
                    ~Student(void) {
                        delete [] m_address;
                        std::cout << "Student destructor" << std::endl;
                    }
                    由于在子类Student的构造函数中给m_address分配了存储空间，所以在析构函数中需要将其释放。
                    上述代码中，以下代码：
                    Human *pHuman = new Student(123456, "江苏南京市");
                    定义了一个基类的指针pHuman，让它指向一个子类Student在堆上的对象。这是没有问题的。因为基类的指针可以指向子类的对象。但此时该指针只能访问子类中继承过来的基类的子对象，子类中自己扩展的内容该指针无法访问。这就造成了一个问题，如下主程序中的语句：
                    delete pHuman;
                    当用delete释放pHuman指向的对象时，只会调用子类中继承过来的基类部分的析构函数，释放子类中继承过来的基类部分，而不会调用子类的析构函数。如上所述，子类的析构函数要释放m_address指向的空间，不调用子类的析构函数，就意味着内存泄露。
                    
                    6 子类对象的析构过程
                    6.1 问题
                    子类的析构函数的执行过程是这样的。首先，执行子类析构函数体中的代码，析构子类的扩展部分，然后，按照声明的逆序，依次调用各个类类型成员变量相应类型的析构函数，析构子类对象中的成员子对象，最后，按照继承表的逆序，依次调用各个基类的析构函数，析构子类对象中的基类子对象，完成整个析构过程。无论如何，子类的析构函数都一定会隐式地调用其类类型成员变量类型和基类的析构函数。
                    6.2 步骤
                    实现此案例需要按照如下步骤进行。
                    步骤一：子类对象的析构过程
                    代码如下所示：
#include <iostream>
                    class Human {
                    private:
                        std::string m_name;
                        int m_age;
                    public:
                        Human(std::string const& name = "", const int& age = 0) : m_name(name),
                        m_age(age) {
                        }
                        ~Human(void) {
                            std::cout << "Human destructor" << std::endl;
                        }
                        void setName(std::string const& name) {
                            m_name = name;
                        }
                        void setAge(const int& age) {
                            m_age = age;
                        }
                        std::string const& name(void) const {
                            return m_name;
                        }
                        const int& age(void) const {
                            return m_age;
                        }
                        void eat(std::string const& food) const {
                            std::cout << m_name << "正在吃" << food << std::endl;
                        }
                        void sleep(int hours) {
                            std::cout << m_name << "睡了" << hours << "小时" << std::endl;
                        }
                    };
                    class Student : public Human {
                    private:
                        int m_no;
                        std::string m_address;
                    public:
                        Student(std::string const& name, const int& age, const int& no,
                                std::string const& address) : Human(name, age), m_address(address), m_no(no) {
                        }
                        ~Student(void) {
                            std::cout << "Student destructor" << std::endl;
                        }
                        void setNo(const int& no) {
                            m_no = no;
                        }
                        const int& no(void) const {
                            return m_no;
                        }
                        void learn(std::string const& course) const {
                            std::cout << name() << "学" << course << std::endl;
                        }
                    };
                    int main(int argc, const char* argv[]) {
                        Student* pStudent = new Student("张三", 20, 123456, "江苏南京市");
                        delete pStudent;
                        return 0;
                    }
                    上述代码中，以下代码：
                    ~Human(void) {
                        std::cout << "Human destructor" << std::endl;
                    }
                    定义了类Human的析构函数，在该函数中，只是输出一句话，提示该函数被调用了。
                    上述代码中，以下代码：
                    ~Student(void) {
                        std::cout << "Student destructor" << std::endl;
                    }
                    定义了子类Student的析构函数，在该函数中，也只是输出一句话，提示该函数被调用了。
                    上述代码中，以下代码：
                    Student* pStudent = new Student("张三", 20, 123456, "江苏南京市");
                    定义了子类Student的指针pStudent，让它指向堆上的子类Student的对象。
                    上述代码中，以下代码：
                    delete pStudent;
                    释放子类Student的对象pStudent。此时由于堆上的子类Student的对象生命周期结束，会首先执行子类Student析构函数体中的代码，析构子类的扩展部分，然后，按照声明的逆序，如下代码：
                private:
                    int m_no;
                    std::string m_address;
                    声明的顺序就是定义数据成员的顺序，一个类中可能会有多个类类型的成员，此时依逆序调用各个类类型成员变量相应类型的析构函数，析构子类对象中的成员子对象，最后，按照继承表的逆序，如下代码：
                    class Student : public Human
                    冒号后面的部分即为继承表的内容，当多重继承时，继承表中可以有多个基类，此时依逆序调用各个基类的析构函数，析构子类对象中的基类子对象，完成整个析构过程。
                    
                    7 缺省全拷贝
                    7.1 问题
                    如果子类没有定义拷贝构造函数，那么编译器为子类提供的缺省拷贝构造函数，会自动调用其基类的(自定义或缺省)拷贝构造函数，拷贝构造子类对象中的基类子对象。
                    7.2 步骤
                    实现此案例需要按照如下步骤进行。
                    步骤一：缺省全拷贝
                    代码如下所示：
#include <iostream>
                    class Human {
                    private:
                        char* m_name;
                        int m_age;
                    public:
                        Human(const char* name = "", const int& age = 0) : m_age(age) {
                            m_name = new char[strlen(name) + 1];
                            strcpy(m_name, name);
                        }
                        void setName(const char* name) {
                            delete [] m_name;
                            m_name = new char[strlen(name) + 1];
                            strcpy(m_name, name);
                        }
                        void setAge(const int& age) {
                            m_age = age;
                        }
                        std::string const name(void) const {
                            return m_name;
                        }
                        const int& age(void) const {
                            return m_age;
                        }
                        void eat(std::string const& food) const {
                            std::cout << m_name << "正在吃" << food << std::endl;
                        }
                        void sleep(int hours) {
                            std::cout << m_name << "睡了" << hours << "小时" << std::endl;
                        }
                    };
                    class Student : public Human {
                    private:
                        int m_no;
                        char* m_address;
                    public:
                        Student(const char* name, const int& age, const int& no,
                                const char* address) : Human(name, age), m_no(no) {
                            m_address = new char[strlen(address) + 1];
                            strcpy(m_address, address);
                        }
                        void setNo(const int& no) {
                            m_no = no;
                        }
                        const int& no(void) const {
                            return m_no;
                        }
                        void learn(std::string const& course) const {
                            std::cout << name() << "学" << course << std::endl;
                        }
                    };
                    int main(int argc, const char* argv[]) {
                        Student student("张三", 20, 123456, "江苏南京市");
                        Student student1 = student;
                        return 0;
                    }
                    上述代码中，没有定义基类Human和子类Student的拷贝构造函数，此时编译器会为它们各自添加一个缺省拷贝构造函数。值得注意的是，缺省拷贝构造函数在实现子类Student的对象复制时，如下代码所示：
                    Student student1 = student;
                    采用字节复制的方法。复制的结果是继承过来的基类子对象中的指针student1.m_name指向了指针student.m_name指向的空间，是student.m_name指针的浅拷贝，同样子类扩展的指针student1.m_address指向了student.m_address指向的空间，是student.m_address指针的浅拷贝。如果student对象先释放了，则student1.m_name与student1.m_address都将变成野指针。
                    
                    8 自定义局部拷贝
                    8.1 问题
                    如果子类定义了拷贝构造函数，但没有显式指明以拷贝方式构造其基类部分，那么编译器会选择其基类的缺省构造函数，构造子类对象中的基类子对象
                    8.2 步骤
                    实现此案例需要按照如下步骤进行。
                    步骤一：自定义局部拷贝
                    代码如下所示：
#include <iostream>
                    class Human {
                    private:
                        char* m_name;
                        int m_age;
                    public:
                        Human(const char* name = "", const int& age = 0) : m_age(age) {
                            m_name = new char[strlen(name) + 1];
                            strcpy(m_name, name);
                        }
                        void setName(const char* name) {
                            delete [] m_name;
                            m_name = new char[strlen(name) + 1];
                            strcpy(m_name, name);
                        }
                        void setAge(const int& age) {
                            m_age = age;
                        }
                        std::string const name(void) const {
                            return m_name;
                        }
                        const int& age(void) const {
                            return m_age;
                        }
                        void eat(std::string const& food) const {
                            std::cout << m_name << "正在吃" << food << std::endl;
                        }
                        void sleep(int hours) {
                            std::cout << m_name << "睡了" << hours << "小时" << std::endl;
                        }
                    };
                    class Student : public Human {
                    private:
                        int m_no;
                        char* m_address;
                    public:
                        Student(const char* name, const int& age, const int& no,
                                const char* address) : Human(name, age), m_no(no) {
                            m_address = new char[strlen(address) + 1];
                            strcpy(m_address, address);
                        }
                        Student(Student const& student) : m_no(student.m_no) {
                            m_address = new char[strlen(student.m_address) + 1];
                            strcpy(m_address, student.m_address);
                        }
                        void setNo(const int& no) {
                            m_no = no;
                        }
                        const int& no(void) const {
                            return m_no;
                        }
                        void learn(std::string const& course) const {
                            std::cout << name() << "学" << course << std::endl;
                        }
                    };
                    int main(int argc, const char* argv[]) {
                        Student student("张三", 20, 123456, "江苏南京市");
                        Student student1 = student;
                        return 0;
                    }
                    上述代码中，以下代码：
                    Student(Student const& student) : m_no(student.m_no) {
                        m_address = new char[strlen(student.m_address) + 1];
                        strcpy(m_address, student.m_address);
                    }
                    子类Student定义了拷贝构造函数，但没有显式指明以拷贝方式构造其基类部分，即在冒号后面的初始化列表中没有调用基类的拷贝构造函数，那么编译器会选择其基类的缺省构造函数，构造子类对象中的基类子对象。这样就造成主程序中的如下代码：
                    Student student1 = student;
                    在复制对象student时，对象student1中的继承过来的基类子对象调用缺省构造函数，这样，student1.m_name将为空，student1.m_age将是0，而子类扩展的指针student1.m_address由于自定义了拷贝构造函数，指向了自己的空间，没有指向student.m_address指向的空间，是student.m_address指针的深拷贝。即是student1没有把student的全部内容拷贝过来。
                    
                    9 自定义全拷贝
                    9.1 问题
                    如果子类定义了拷贝构造函数，同时显式指明了其基类部分以拷贝方式构造，那么子类对象中的基类部分和扩展部分将一起被复制。
                    9.2 步骤
                    实现此案例需要按照如下步骤进行。
                    步骤一：自定义全拷贝
                    代码如下所示：
#include <iostream>
                    class Human {
                    private:
                        char* m_name;
                        int m_age;
                    public:
                        Human(const char* name = "", const int& age = 0) : m_age(age) {
                            m_name = new char[strlen(name) + 1];
                            strcpy(m_name, name);
                        }
                        Human(Human const& human) : m_age(human.m_age) {
                            m_name = new char[strlen(human.m_name) + 1];
                            strcpy(m_name, human.m_name);
                        }
                        void setName(const char* name) {
                            delete [] m_name;
                            m_name = new char[strlen(name) + 1];
                            strcpy(m_name, name);
                        }
                        void setAge(const int& age) {
                            m_age = age;
                        }
                        std::string const name(void) const {
                            return m_name;
                        }
                        const int& age(void) const {
                            return m_age;
                        }
                        void eat(std::string const& food) const {
                            std::cout << m_name << "正在吃" << food << std::endl;
                        }
                        void sleep(int hours) {
                            std::cout << m_name << "睡了" << hours << "小时" << std::endl;
                        }
                    };
                    class Student : public Human {
                    private:
                        int m_no;
                        char* m_address;
                    public:
                        Student(const char* name, const int& age, const int& no,
                                const char* address) : Human(name, age), m_no(no) {
                            m_address = new char[strlen(address) + 1];
                            strcpy(m_address, address);
                        }
                        Student(Student const& student) : Human(student), m_no(student.m_no) {
                            m_address = new char[strlen(student.m_address) + 1];
                            strcpy(m_address, student.m_address);
                        }
                        void setNo(const int& no) {
                            m_no = no;
                        }
                        const int& no(void) const {
                            return m_no;
                        }
                        void learn(std::string const& course) const {
                            std::cout << name() << "学" << course << std::endl;
                        }
                    };
                    int main(int argc, const char* argv[]) {
                        Student student("张三", 20, 123456, "江苏南京市");
                        Student student1 = student;
                        return 0;
                    }
                    上述代码中，以下代码：
                    Human(Human const& human) : m_age(human.m_age) {
                        m_name = new char[strlen(human.m_name) + 1];
                        strcpy(m_name, human.m_name);
                    }
                    定义了基类Human的拷贝构造函数。
                    上述代码中，以下代码：
                    Student(Student const& student) : Human(student), m_no(student.m_no) {
                        m_address = new char[strlen(student.m_address) + 1];
                        strcpy(m_address, student.m_address);
                    }
                    定义了子类Student的拷贝构造函数，同时在冒号后面的初始化列表中显式指明了其基类部分以拷贝方式构造，这样子类对象中的基类部分和扩展部分将一起被深拷贝。
                    
                    10 缺省全赋值
                    10.1 问题
                    如果子类没有定义拷贝赋值运算符函数，那么编译器为子类提供的缺省拷贝赋值运算符函数，会自动调用其基类的(自定义或缺省)拷贝赋值运算符函数，复制子类对象中的基类子对象。
                    10.2 步骤
                    实现此案例需要按照如下步骤进行。
                    步骤一：缺省全赋值
                    代码如下所示：
#include <iostream>
                    class Human {
                    private:
                        char* m_name;
                        int m_age;
                    public:
                        Human(const char* name = "", const int& age = 0) : m_age(age) {
                            m_name = new char[strlen(name) + 1];
                            strcpy(m_name, name);
                        }
                        void setName(const char* name) {
                            delete [] m_name;
                            m_name = new char[strlen(name) + 1];
                            strcpy(m_name, name);
                        }
                        void setAge(const int& age) {
                            m_age = age;
                        }
                        std::string const name(void) const {
                            return m_name;
                        }
                        const int& age(void) const {
                            return m_age;
                        }
                        void eat(std::string const& food) const {
                            std::cout << m_name << "正在吃" << food << std::endl;
                        }
                        void sleep(int hours) {
                            std::cout << m_name << "睡了" << hours << "小时" << std::endl;
                        }
                    };
                    class Student : public Human {
                    private:
                        int m_no;
                        char* m_address;
                    public:
                        Student(const char* name, const int& age, const int& no,
                                const char* address) : Human(name, age), m_no(no) {
                            m_address = new char[strlen(address) + 1];
                            strcpy(m_address, address);
                        }
                        void setNo(const int& no) {
                            m_no = no;
                        }
                        const int& no(void) const {
                            return m_no;
                        }
                        void learn(std::string const& course) const {
                            std::cout << name() << "学" << course << std::endl;
                        }
                    };
                    int main(int argc, const char* argv[]) {
                        Student student("张三", 20, 123456, "江苏南京市");
                        Student student1("李四", 25, 654321, "广东广州市");
                        student1 = student;
                        return 0;
                    }
                    上述代码中，没有定义基类Human和子类Student的拷贝赋值运算符函数，此时编译器会为它们各自添加一个缺省拷贝赋值运算符函数。值得注意的是，缺省拷贝赋值运算符函数在实现子类Student的对象复制时，如下代码所示：
                    student1 = student;
                    采用字节复制的方法。复制的结果是继承过来的基类子对象中的指针student1.m_name指向了指针student.m_name指向的空间，是student.m_name指针的浅拷贝，同样子类扩展的指针student1.m_address指向了student.m_address指向的空间，是student.m_address指针的浅拷贝。如果student对象先释放了，则student1.m_name与student1.m_address都将变成野指针。
                    
                    11 自定义局部赋值
                    11.1 问题
                    如果子类定义了拷贝赋值运算符函数，但没有显式调用其基类的拷贝赋值运算符函数，那么子类对象中的基类子对象将因得不到复制而保持原状。
                    11.2 步骤
                    实现此案例需要按照如下步骤进行。
                    步骤一：自定义局部赋值
                    代码如下所示：
#include <iostream>
                    class Human {
                    private:
                        char* m_name;
                        int m_age;
                    public:
                        Human(const char* name = "", const int& age = 0) : m_age(age) {
                            m_name = new char[strlen(name) + 1];
                            strcpy(m_name, name);
                        }
                        void setName(const char* name) {
                            delete [] m_name;
                            m_name = new char[strlen(name) + 1];
                            strcpy(m_name, name);
                        }
                        void setAge(const int& age) {
                            m_age = age;
                        }
                        std::string const name(void) const {
                            return m_name;
                        }
                        const int& age(void) const {
                            return m_age;
                        }
                        void eat(std::string const& food) const {
                            std::cout << m_name << "正在吃" << food << std::endl;
                        }
                        void sleep(int hours) {
                            std::cout << m_name << "睡了" << hours << "小时" << std::endl;
                        }
                        void show(void) const {
                            std::cout << "" << m_name << ",年龄：" << m_age << std::endl;
                        }
                    };
                    class Student : public Human {
                    private:
                        int m_no;
                        char* m_address;
                    public:
                        Student(const char* name, const int& age, const int& no,
                                const char* address) : Human(name, age), m_no(no) {
                            m_address = new char[strlen(address) + 1];
                            strcpy(m_address, address);
                        }
                        Student(Student const& student) : m_no(student.m_no) {
                            m_address = new char[strlen(student.m_address) + 1];
                            strcpy(m_address, student.m_address);
                        }
                        Student& operator= (Student const& student) {
                            if (&student != this) {
                                delete [] m_address;
                                m_address = new char[strlen(student.m_address) + 1];
                                strcpy(m_address, student.m_address);
                                m_no = student.m_no;
                            }
                            return *this;
                        }
                        void setNo(const int& no) {
                            m_no = no;
                        }
                        const int& no(void) const {
                            return m_no;
                        }
                        void learn(std::string const& course) const {
                            std::cout << name() << "学" << course << std::endl;
                        }
                        void show(void) const {
                            Human::show();
                            std::cout << "学号：" << m_no << ",住址：" << m_address << std::endl;
                        }
                    };
                    int main(int argc, const char* argv[]) {
                        Student student("张三", 20, 123456, "江苏南京市");
                        Student student1("李四", 25, 654321, "广东广州市");
                        student1 = student;
                        student.show();
                        student1.show();
                        return 0;
                    }
                    上述代码中，以下代码：
                    Student& operator= (Student const& student) {
                        if (&student != this) {
                            delete [] m_address;
                            m_address = new char[strlen(student.m_address) + 1];
                            strcpy(m_address, student.m_address);
                            m_no = student.m_no;
                        }
                        return *this;
                    }
                    定义了子类Student的拷贝赋值运算符函数，但在函数体中没有显式调用其基类的拷贝赋值运算符函数，那么子类对象中的基类子对象将因得不到复制而保持原状。如执行主程序中的如下语句：
                    Student student("张三", 20, 123456, "江苏南京市");
                    Student student1("李四", 25, 654321, "广东广州市");
                    student1 = student;
                    student.show();
                    student1.show();
                    则可以看到类Student的对象student1中的基类子对象内容没变，姓名仍然是“李四”，年龄仍然是25，但对象student1中的扩展部分变成了对象student中的扩展部分，学号变成了123456，家庭住址变成了“江苏南京市”。
                    
                    12 自定义全赋值
                    12.1 问题
                    如果子类定义了拷贝赋值运算符函数，同时显式调用了其基类的拷贝赋值运算符函数，那么子类对象中的基类部分和扩展部分将一起被复制。
                    12.2 步骤
                    实现此案例需要按照如下步骤进行。
                    步骤一：自定义全赋值
                    代码如下所示：
#include <iostream>
                    class Human {
                    private:
                        char* m_name;
                        int m_age;
                    public:
                        Human(const char* name = "", const int& age = 0) : m_age(age) {
                            m_name = new char[strlen(name) + 1];
                            strcpy(m_name, name);
                        }
                        Human(Human const& human) : m_age(human.m_age) {
                            m_name = new char[strlen(human.m_name) + 1];
                            strcpy(m_name, human.m_name);
                        }
                        Human& operator= (Human const& human) {
                            if (&human != this) {
                                delete [] m_name;
                                m_name = new char[strlen(human.m_name) + 1];
                                strcpy(m_name, human.m_name);
                                m_age = human.m_age;
                            }
                            return *this;
                        }
                        void setName(const char* name) {
                            delete [] m_name;
                            m_name = new char[strlen(name) + 1];
                            strcpy(m_name, name);
                        }
                        void setAge(const int& age) {
                            m_age = age;
                        }
                        std::string const name(void) const {
                            return m_name;
                        }
                        const int& age(void) const {
                            return m_age;
                        }
                        void eat(std::string const& food) const {
                            std::cout << m_name << "正在吃" << food << std::endl;
                        }
                        void sleep(int hours) {
                            std::cout << m_name << "睡了" << hours << "小时" << std::endl;
                        }
                        void show(void) const {
                            std::cout << "" << m_name << ",年龄：" << m_age << std::endl;
                        }
                    };
                    class Student : public Human {
                    private:
                        int m_no;
                        char* m_address;
                    public:
                        Student(const char* name, const int& age, const int& no,
                                const char* address) : Human(name, age), m_no(no) {
                            m_address = new char[strlen(address) + 1];
                            strcpy(m_address, address);
                        }
                        Student(Student const& student) : Human(student), m_no(student.m_no) {
                            m_address = new char[strlen(student.m_address) + 1];
                            strcpy(m_address, student.m_address);
                        }
                        Student& operator= (Student const& student) {
                            if (&student != this) {
                                Human::operator=(student);
                                delete [] m_address;
                                m_address = new char[strlen(student.m_address) + 1];
                                strcpy(m_address, student.m_address);
                                m_no = student.m_no;
                            }
                            return *this;
                        }
                        void setNo(const int& no) {
                            m_no = no;
                        }
                        const int& no(void) const {
                            return m_no;
                        }
                        void learn(std::string const& course) const {
                            std::cout << name() << "学" << course << std::endl;
                        }
                        void show(void) const {
                            Human::show();
                            std::cout << "学号：" << m_no << ",住址：" << m_address << std::endl;
                        }
                    };
                    int main(int argc, const char* argv[]) {
                        Student student("张三", 20, 123456, "江苏南京市");
                        Student student1("李四", 25, 654321, "广东广州市");
                        student1 = student;
                        student.show();
                        student1.show();
                        return 0;
                    }
                    上述代码中，以下代码：
                    Human& operator= (Human const& human) {
                        if (&human != this) {
                            delete [] m_name;
                            m_name = new char[strlen(human.m_name) + 1];
                            strcpy(m_name, human.m_name);
                            m_age = human.m_age;
                        }
                        return *this;
                    }
                    定义了基类Human的拷贝赋值运算符函数。
                    上述代码中，以下代码：
                    Student& operator= (Student const& student) {
                        if (&student != this) {
                            Human::operator=(student);
                            delete [] m_address;
                            m_address = new char[strlen(student.m_address) + 1];
                            strcpy(m_address, student.m_address);
                            m_no = student.m_no;
                        }
                        return *this;
                    }
                    定义了子类Student的拷贝赋值运算符函数，由于在函数体中，使用如下语句：
                    Human::operator=(student);
                    显式调用其基类的拷贝赋值运算符函数，那么子类对象中的基类子对象将能够得到复制。如执行主程序中的如下语句：
                    Student student("张三", 20, 123456, "江苏南京市");
                    Student student1("李四", 25, 654321, "广东广州市");
                    student1 = student;
                    student.show();
                    student1.show();
                    则可以看到类Student的对象student1中的基类子对象内容变成了对象student中的基类子对象内容，姓名变成了“张三”，年龄变成了20，而对象student1中的扩展部分变成了对象student中的扩展部分，学号变成了123456，家庭住址变成了“江苏南京市”。
                    
                    13 各司其职的基类和子类
                    13.1 问题
                    在为子类提供操作符重载定义时，往往需要调用其基类针对该操作符所做的重载定义，完成部分工作。通过将子类对象的指针或引用向上造型为其基类类型的指针或引用，可以迫使针对基类的操作符重载函数在针对子类的操作符重载函数中被调用。
                    13.2 步骤
                    实现此案例需要按照如下步骤进行。
                    步骤一：各司其职的基类和子类
                    代码如下所示：
#include <iostream>
                    class Human {
                    private:
                        char* m_name;
                        int m_age;
                    public:
                        Human(const char* name = "", const int& age = 0) : m_age(age) {
                            m_name = new char[strlen(name) + 1];
                            strcpy(m_name, name);
                        }
                        Human(Human const& human) : m_age(human.m_age) {
                            m_name = new char[strlen(human.m_name) + 1];
                            strcpy(m_name, human.m_name);
                        }
                        Human& operator= (Human const& human) {
                            if (&human != this) {
                                delete [] m_name;
                                m_name = new char[strlen(human.m_name) + 1];
                                strcpy(m_name, human.m_name);
                                m_age = human.m_age;
                            }
                            return *this;
                        }
                        void setName(const char* name) {
                            delete [] m_name;
                            m_name = new char[strlen(name) + 1];
                            strcpy(m_name, name);
                        }
                        void setAge(const int& age) {
                            m_age = age;
                        }
                        std::string const name(void) const {
                            return m_name;
                        }
                        const int& age(void) const {
                            return m_age;
                        }
                        void eat(std::string const& food) const {
                            std::cout << m_name << "正在吃" << food << std::endl;
                        }
                        void sleep(int hours) {
                            std::cout << m_name << "睡了" << hours << "小时" << std::endl;
                        }
                        void show(void) const {
                            std::cout << "" << m_name << ",年龄：" << m_age << std::endl;
                        }
                        friend std::ostream& operator<< (std::ostream& lhs, Human const& rhs);
                    };
                    class Student : public Human {
                    private:
                        int m_no;
                        char* m_address;
                    public:
                        Student(const char* name, const int& age, const int& no,
                                const char* address) : Human(name, age), m_no(no) {
                            m_address = new char[strlen(address) + 1];
                            strcpy(m_address, address);
                        }
                        Student(Student const& student) : Human(student), m_no(student.m_no) {
                            m_address = new char[strlen(student.m_address) + 1];
                            strcpy(m_address, student.m_address);
                        }
                        Student& operator= (Student const& student) {
                            if (&student != this) {
                                Human::operator=(student);
                                delete [] m_address;
                                m_address = new char[strlen(student.m_address) + 1];
                                strcpy(m_address, student.m_address);
                                m_no = student.m_no;
                            }
                            return *this;
                        }
                        void setNo(const int& no) {
                            m_no = no;
                        }
                        const int& no(void) const {
                            return m_no;
                        }
                        void learn(std::string const& course) const {
                            std::cout << name() << "学" << course << std::endl;
                        }
                        void show(void) const {
                            std::cout << "学号：" << m_no << ",住址：" << m_address << std::endl;
                        }
                        friend std::ostream& operator<< (std::ostream& lhs, Student const& rhs);
                    };
                    std::ostream& operator<< (std::ostream& lhs, Human const& rhs) {
                        rhs.show();
                        return lhs;
                    }
                    std::ostream& operator<< (std::ostream& lhs, Student const& rhs) {
                        lhs << static_cast<Human const&>(rhs);
                        rhs.show();
                        return lhs;
                    }
                    int main(int argc, const char* argv[]) {
                        Student student("张三", 20, 123456, "江苏南京市");
                        Student student1("李四", 25, 654321, "广东广州市");
                        std::cout << student << std::endl;
                        std::cout << student1 << std::endl;
                        return 0;
                    }
                    上述代码中，以下代码：
                    Human& operator= (Human const& human) {
                        if (&human != this) {
                            delete [] m_name;
                            m_name = new char[strlen(human.m_name) + 1];
                            strcpy(m_name, human.m_name);
                            m_age = human.m_age;
                        }
                        return *this;
                    }
                    定义了基类Human的拷贝赋值运算符函数。
                    上述代码中，以下代码：
                    Student& operator= (Student const& student) {
                        if (&student != this) {
                            Human::operator=(student);
                            delete [] m_address;
                            m_address = new char[strlen(student.m_address) + 1];
                            strcpy(m_address, student.m_address);
                            m_no = student.m_no;
                        }
                        return *this;
                    }
                    定义了子类Student的拷贝赋值运算符函数，在为子类提供操作符重载定义时，往往需要调用其基类针对该操作符所做的重载定义，完成部分工作，如在函数体中，使用以下语句：
                    Human::operator=(student);
                    显式调用其基类的拷贝赋值运算符函数，完成子类对象中的基类子对象的复制工作。
                    上述代码中，以下代码：
                    std::ostream& operator<< (std::ostream& lhs, Human const& rhs) {
                        rhs.show();
                        return lhs;
                    }
                    定义了基类Human的输出流运算符函数。
                    上述代码中，以下代码：
                    std::ostream& operator<< (std::ostream& lhs, Student const& rhs) {
                        lhs << static_cast<Human const&>(rhs);
                        rhs.show();
                        return lhs;
                    }
                    定义了子类Student的输出流运算符函数，通过将子类对象rhs的引用向上造型为其基类类型的引用，如在函数体中，使用以下语句：
                    lhs << static_cast<Human const&>(rhs);
                    可以迫使针对基类的操作符重载函数在针对子类的操作符重载函数中被调用。
                    
                    14 隐藏与重载
                    14.1 问题
                    继承不会改变类成员的作用域，基类的成员永远都是基类的成员，并不会因为继承而变成子类的成员。因为作用域的不同，分别在子类和基类中定义的同名成员函数(包括静态成员函数)，并不构成重载关系，相反是一种隐藏关系。任何时候，无论在子类的内部还是外部，总可以通过作用域限定操作符“::”，显式地调用那些在基类中定义却为子类所隐藏的成员函数。
                    通过using声明可将在基类中声明的标识符引入子类的作用域，就如同在子类中声明的一样，如果所引入的标识符是基类的成员函数，并且满足函数重载的条件，那么子类对基类的隐藏关系可以变为重载关系。
                    14.2 步骤
                    实现此案例需要按照如下步骤进行。
                    步骤一：隐藏与重载
                    代码如下所示：
#include <iostream>
                    class Real {
                    private:
                        int m_r;
                    public:
                        Real(const int& r = 0) : m_r(r) {
                        }
                        void add(Real const& that) {
                            m_r += that.m_r;
                        }
                        void show(void) const {
                            std::cout << m_r;
                        }
                    };
                    class Complex : public Real {
                    private:
                        int m_i;
                    public:
                        Complex(const int& r = 0, const int& i = 0) : Real(r), m_i(i) {
                        }
                        void add(Complex const& that) {
                            Real::add(that);
                            m_i += that.m_i;
                        }
                        void show(void) const {
                            Real::show();
                            std::cout << "+" << m_i << "i" << std::endl;
                        }
                    };
                    int main(int argc, const char* argv[]) {
                        Complex c(5, 3);
                        Complex c1(2, 2);
                        c.add(c1);
                        c.show();
                        return 0;
                    }
                    上述代码中，以下代码：
                    void add(Real const& that) {
                        m_r += that.m_r;
                    }
                    是基类Real中的一个成员函数。
                    上述代码中，以下代码：
                    void add(Complex const& that) {
                        Real::add(that);
                        m_i += that.m_i;
                    }
                    是子类Complex中的一个成员函数。继承不会改变类成员的作用域，基类Real的成员add永远都是基类的成员，并不会因为继承而变成子类Complex的成员。因为作用域的不同，分别在子类Complex和基类Real中定义的同名成员函数add，并不构成重载关系，相反是一种隐藏关系，子类Complex中的成员函数add将隐藏基类Real中的成员函数add，如在主程序中的以下语句：
                    c.add(c1);
                    子类Complex的对象c调用成员函数add时，调用的是子类Complex中扩展的成员函数add，而不是从基类中继承的成员函数add。任何时候，无论在子类的内部还是外部，总可以通过作用域限定操作符“::”，显式地调用那些在基类中定义却为子类所隐藏的成员函数。如可以用以下语句调用子类Complex的对象c中从基类中继承的成员函数add：
                    c.Real::add(c1);
                    通过using声明可将在基类中声明的标识符引入子类的作用域，就如同在子类中声明的一样，如将子类Complex修改如下：
                    class Complex : public Real {
                        using Real::add;
                    private:
                        int m_i;
                    public:
                        Complex(const int& r = 0, const int& i = 0) : Real(r), m_i(i) {
                        }
                        void add(Complex const& that) {
                            add((Real const&)that);
                            m_i += that.m_i;
                        }
                        void show(void) const {
                            Real::show();
                            std::cout << "+" << m_i << "i" << std::endl;
                        }
                    };
                    则所引入的标识符add是基类的成员函数add，由于与子类扩展的成员函数add满足重载的条件，所以子类Complex扩展的成员函数add对基类Real的成员函数add的隐藏关系就变为重载关系。
                    
                    15 智能手机
                    15.1 问题
                    一个类可以同时从多个基类继承实现代码。如果在子类的多个基类中，存在同名的标识符，而且子类又没有隐藏该名字，那么任何试图在子类中，或通过子类对象访问该名字的操作，都将引发歧义，除非通过作用域限定操作符“::”显式指明所属基类。如果无法避免基类中的名字冲突，最简单的方法是在子类中隐藏这些标识符，或借助using声明令其在子类中重载。
                    15.2 步骤
                    实现此案例需要按照如下步骤进行。
                    步骤一：智能手机
                    代码如下所示：
#include <iostream>
                    class Computer {
                    public:
                        void show(Computer* c = NULL) const {
                            std::cout << "Computer" << std::endl;
                        }
                    };
                    class Telephone {
                    public:
                        void show(Telephone* t = NULL) const {
                            std::cout << "Telephone" << std::endl;
                        }
                    };
                    class MobilePhone : public Computer, public Telephone {
                    };
                    int main(int argc, const char* argv[]) {
                        MobilePhone mp;
                        mp.show();
                        return 0;
                    }
                    上述代码中，以下代码：
                    class Computer {
                    public:
                        void show(Computer* c = NULL) const {
                            std::cout << "Computer" << std::endl;
                        }
                    };
                    class Telephone {
                    public:
                        void show(Telephone* t = NULL) const {
                            std::cout << "Telephone" << std::endl;
                        }
                    };
                    定义了两个类，类Computer和类Telephone，其中各自定义了一个成员函数show。这是正确的。因为类的封装性，两个函数show分别在两个不同的作用域中。
                    上述代码中，以下代码：
                    class MobilePhone : public Computer, public Telephone {
                    };
                    定义了一个子类Mobilephone，多重继承了类Computer和类Telephone。这样就带来了一个问题，就是子类Mobilephone中有两个成员函数show，一个继承自类Computer，另一个继承自类Telephone。当在主程序中，出现如下语句时：
                    MobilePhone mp;
                    mp.show();
                    就会出现编译错误，因为编译器不知道mp.show()调用哪一个show。只能通过作用域限定操作符“::”显式指明所属基类，如以下语句所示：
                    MobilePhone mp;
                    mp.Computer::show();
                    或者借助using声明令其在子类中重载。如将子类Mobilephone定义成如下形式：
                    class MobilePhone : public Computer, public Telephone {
                        using Computer::show;
                        using Telephone::show;
                    };
                    此时，两个成员函数将变成重载的关系。
                    
                    16 钻石继承
                    16.1 问题
                    一个子类继承自多个基类，而这些基类又源自共同的祖先(公共基类)，这样的继承结构称为钻石继承。派生多个中间子类的公共基类子对象，在继承自多个中间子类的汇聚子类对象中，存在多个实例，在汇聚子类中，或通过汇聚子类对象，访问公共基类的成员，会因继承路径的不同而导致不一致。
                    16.2 步骤
                    实现此案例需要按照如下步骤进行。
                    步骤一：钻石继承
                    代码如下所示：
#include <iostream>
                    class Base {
                    public:
                        void show(void) const {
                            std::cout << "Base" << std::endl;
                        }
                    };
                    class MidDerive1 : public Base {
                    };
                    class MidDerive2 : public Base {
                    };
                    class Derive : public MidDerive1, public MidDerive2 {
                    };
                    int main(int argc, const char* argv[]) {
                        Derive d;
                        //d.show();
                        return 0;
                    }
                    上述代码中，以下代码：
                    class Base {
                    public:
                        void show(void) const {
                            std::cout << "Base" << std::endl;
                        }
                    };
                    class MidDerive1 : public Base {
                    };
                    class MidDerive2 : public Base {
                    };
                    定义了一个类Base，由它派生出两个子类，类MidDerive1和类MidDerive2，其中各自继承了基类Base中的成员函数show。这是正确的。因为类的封装性，三个函数show分别在三个不同的类作用域中。
                    上述代码中，以下代码：
                    class Derive : public MidDerive1, public MidDerive2 {
                    };
                    定义了一个子类Derive，多重继承了类MidDerive1和类MidDerive2。这样就带来了一个问题，就是子类Derive中有两个成员函数show，一个继承自类MidDerive1，另一个继承自类MidDerive2。当在主程序中，出现如下语句时：
                    Derive d;
                    //d.show();
                    就会出现编译错误，因为编译器不知道d.show()调用哪一个show。只能通过作用域限定操作符“::”显式指明所属基类，如以下语句所示：
                    MobilePhone mp;
                    d.MidDerive1::show();
                    
                    17 虚继承对钻石继承的改善
                    17.1 问题
                    通过虚继承，可以保证公共基类子对象在汇聚子类对象中，仅存一份实例，且为多个中间子类子对象所共享。为了表示虚继承，需要在继承表中使用virtual关键字。
                    一般而言，子类的构造函数不能调用其间接基类的构造函数。但是，一旦这个间接基类被声明为虚基类，它的所有子类(无论直接的还是间接的)都必须显式地调用该间接基类的构造函数。否则，系统将试图为它的每个子类对象调用该间接基类的无参构造函数。
                    17.2 步骤
                    实现此案例需要按照如下步骤进行。
                    步骤一：虚继承对钻石继承的改善
                    代码如下所示：
#include <iostream>
                    class Base {
                    private:
                        int m_a;
                    public:
                        Base(const int& a) : m_a(a) {
                        }
                        void show(void) const {
                            std::cout << "Base" << std::endl;
                        }
                    };
                    class MidDerive1 : virtual public Base {
                    public:
                        MidDerive1(const int& a) : Base(a) {
                        }
                    };
                    class MidDerive2 : virtual public Base {
                    public:
                        MidDerive2(const int& a) : Base(a) {
                        }
                    };
                    class Derive : public MidDerive1, public MidDerive2 {
                    public:
                        Derive(const int& a = 0) : MidDerive1(a), MidDerive2(a), Base(a) {
                        }
                    };
                    int main(int argc, const char* argv[]) {
                        Derive d;
                        d.show();
                        return 0;
                    }
                    上述代码中，以下代码：
                    class Base {
                    private:
                        int m_a;
                    public:
                        Base(const int& a) : m_a(a) {
                        }
                        void show(void) const {
                            std::cout << "Base" << std::endl;
                        }
                    };
                    class MidDerive1 : virtual public Base {
                    public:
                        MidDerive1(const int& a) : Base(a) {
                        }
                    };
                    class MidDerive2 : virtual public Base {
                    public:
                        MidDerive2(const int& a) : Base(a) {
                        }
                    };
                    定义了一个类Base，由它派生出两个子类，类MidDerive1和类MidDerive2，其中各自继承了基类Base中的成员函数show。这是正确的。因为类的封装性，三个函数show分别在三个不同的类作用域中。值得注意的是，类MidDerive1和类MidDerive2继承基类Base，在继承表中多了一个关键字virtual，这样就构成了虚继承的概念。
                    上述代码中，以下代码：
                    class Derive : public MidDerive1, public MidDerive2 {
                    public:
                        Derive(const int& a = 0) : MidDerive1(a), MidDerive2(a), Base(a) {
                        }
                    };
                    定义了一个子类Derive，多重继承了类MidDerive1和类MidDerive2。由于通过虚继承，可以保证公共基类Base在汇聚子类Derive中，仅存一份成员函数show，且为多个中间子类MidDerive1和MidDerive2所共享。所以，在如下主函数程序中：
                    Derive d;
                    d.show();
                    不会出现编译错误。
                    一般而言，子类Derive的构造函数不能调用其间接基类Base的构造函数。但是，一旦这个间接基类被声明为虚基类，它的所有子类(无论直接的还是间接的)都必须显式地调用该间接基类的构造函数。否则，系统将试图为它的每个子类对象调用该间接基类的无参构造函数。如以下代码所示：
                    Derive(const int& a = 0) : MidDerive1(a), MidDerive2(a), Base(a) {
                    }
                    
                    18 阻断继承类的静态实例化
                    18.1 问题
                    通过将类的构造函数私有化，可以禁止该类被继承，因为子类必须能够调用基类的构造函数。但该类本身也因此无法被静态实例化，只能通过静态接口动态地创建，而这样极可能因为忘记delete而导致内存泄漏。
                    为了解决这个矛盾，可从该类公有派生一个友元子类，子类是基类的友元，可访问其私有部分，且可被静态实例化。但该友元子类亦可被继承，虽然禁止用户定义阻断继承类的直接子类，但仍无法禁止用户定义其间接子类。为此，可将友元子类从阻断继承类的继承改为虚继承，即令阻断继承类成为其友元子类的虚基类。
                    18.2 步骤
                    实现此案例需要按照如下步骤进行。
                    步骤一：阻断继承类的静态实例化
                    代码如下所示：
#include <iostream>
                    class User {
                    private:
                        std::string m_name;
                        User(std::string const& name) : m_name(name) {
                        }
                    public:
                        static User* createInstance(std::string const& name) {
                            return new User(name);
                        }
                        friend class UserWrapper;
                    };
                    class UserWrapper : public User {
                    public:
                        UserWrapper(std::string const& name) : User(name) {
                        }
                    };
                    int main(int argc, const char* argv[]) {
                        //User user("张飞");
                        User* pUser = User::createInstance("张飞");
                        delete pUser;
                        UserWrapper user("张飞");
                        return 0;
                    }
                    上述代码中，以下代码：
                    class User {
                    private:
                        std::string m_name;
                        User(std::string const& name) : m_name(name) {
                        }
                        通过将类User的构造函数私有化，可以禁止该类被继承，因为子类必须能够调用基类的构造函数。但类User本身也因此无法被静态实例化，如以下主程序中的语句：
                        //User user("张飞");
                        编译错误。为了使用该类的对象，只能通过如下语句：
                        static User* createInstance(std::string const& name) {
                            return new User(name);
                        }
                        定义类User的静态接口动态地创建，如以下主程序中的语句：
                        User *pUser = User::createInstance("张飞");
                        但这样做极可能因为忘记通过delete释放pUser指向的空间而导致内存泄漏。为了解决这个问题，可从类User公有派生一个子类，如下代码所示：
                        class UserWrapper : public User {
                        public:
                            UserWrapper(std::string const& name) : User(name) {
                            }
                        };
                        但因为类User的构造函数是私有的，所以类User被禁止继承，但可以将该子类UserWrapper声明为子类是基类User的友元，如以下在类User中的代码：
                        friend class UserWrapper;
                        这样，子类UserWrapper就可访问类User的私有部分，且可被静态实例化了，如以下主程序中的语句：
                        UserWrapper user("张飞");
                        是正确的。但该友元子类UserWrapper却可以被继承，这样虽然禁止用户定义阻断继承类User的派生子类，但仍无法禁止用户定义其间接子类，即友元子类UserWrapper派生子类。为此，可将友元子类UserWrapper从阻断继承类User的继承改为虚继承，即令阻断继承类成为其友元子类的虚基类，如以下友元子类UserWrapper的定义：
                        class UserWrapper : virtual public User {
                        public:
                            UserWrapper(std::string const& name) : User(name) {
                            }
                        };
                        这样友元子类UserWrapper的任何派生类中的构造函数中都必须 (显式或隐式)调用类User的构造函数，致使编译器报错，而阻断了友元子类UserWrapper派生子类。
                        
                        CSD STDCPP02 DAY03
                        
                        1 电子文档阅读器
                        1.1 问题
                        虚函数是指在类的成员函数声明之前添加了关键字virtual的成员函数。
                        如果子类提供了对基类虚函数的有效覆盖，那么通过一个指向子类对象的基类指针，或者引用子类对象的基类引用，调用该虚函数，实际被调用的将是子类中的覆盖版本，而非基类中的原始版本，这种语法现象称为多态。
                        多态的重要意义在于，一般情况下，调用哪个类的成员函数是由调用者指针或引用本身的类型决定的，而当多态发生时，调用哪个类的成员函数则完全由调用者指针或引用的实际目标对象的类型决定。
                        1.2 步骤
                        实现此案例需要按照如下步骤进行。
                        步骤一：电子文档阅读器
                        代码如下：
#include <iostream>
                        class Reader {
                        public:
                            virtual void display(void) const {
                                std::cout << "请选择一本书" << std::endl;
                            }
                        };
                        class HongLouMeng : public Reader {
                        public:
                            void display(void) const {
                                std::cout << "世事洞明皆学问，人情练达即文章。" << std::endl;
                                std::cout << "假作真时真亦假，无为有处有还无。" << std::endl;
                                std::cout << "春恨秋悲皆自惹，花容月貌为谁妍。" << std::endl;
                            }
                        };
                        class SanGuoYanYi : public Reader {
                        public:
                            void display(void) const {
                                std::cout << "滚滚长江东逝水，浪花淘尽英雄。" << std::endl;
                                std::cout << "是非成败转头空。" << std::endl;
                                std::cout << "青山依旧在，几度夕阳红。" << std::endl;
                                std::cout << "白发渔樵江渚上，惯看秋月春风。" << std::endl;
                                std::cout << "一壶浊酒喜相逢。" << std::endl;
                                std::cout << "古今多少事，都付笑谈中。" << std::endl;
                            }
                        };
                        void read(Reader const* reader) {
                            reader->display();
                        }
                        int main(int argc, const char* argv[]) {
                            HongLouMeng hlm;
                            SanGuoYanYi sgyy;
                            read(&hlm);
                            read(&sgyy);
                            return 0;
                        }
                        上述代码中，以下代码：
                        class Reader {
                        public:
                            virtual void display(void) const {
                                std::cout << "请选择一本书" << std::endl;
                            }
                        };
                        定义了电子文档阅读器类Reader，在该类中定义了一个成员函数display，在该函数定义的前面添加了关键字virtual，说明该函数是一个虚函数。
                        上述代码中，以下代码：
                        class HongLouMeng : public Reader {
                        public:
                            void display(void) const {
                                std::cout << "世事洞明皆学问，人情练达即文章。" << std::endl;
                                std::cout << "假作真时真亦假，无为有处有还无。" << std::endl;
                                std::cout << "春恨秋悲皆自惹，花容月貌为谁妍。" << std::endl;
                            }
                        };
                        定义了电子文档阅读器类Reader的子类HonglouMeng。由于子类HonglouMeng的成员函数display和基类Reader的虚函数display具有相同的函数原型，所以子类HonglouMeng的成员函数display也是虚函数，无论其是否带有virtual关键字，且对基类的虚函数构成覆盖。
                        上述代码中，以下代码：
                        class SanGuoYanYi : public Reader {
                        public:
                            void display(void) const {
                                std::cout << "滚滚长江东逝水，浪花淘尽英雄。" << std::endl;
                                std::cout << "是非成败转头空。" << std::endl;
                                std::cout << "青山依旧在，几度夕阳红。" << std::endl;
                                std::cout << "白发渔樵江渚上，惯看秋月春风。" << std::endl;
                                std::cout << "一壶浊酒喜相逢。" << std::endl;
                                std::cout << "古今多少事，都付笑谈中。" << std::endl;
                            }
                        };
                        定义了电子文档阅读器类Reader的子类SanGuoYanYi。由于子类SanGuoYanYi的成员函数display和基类Reader的虚函数display具有相同的函数原型，所以子类SanGuoYanYi的成员函数display也是虚函数，也对基类的虚函数构成覆盖。
                        上述代码中，以下代码：
                        read(&hlm);
                        是调用read函数，该函数的定义如下：
                        void read(Reader const* reader) {
                            reader->display();
                        }
                        这样就将使得函数read的形参（基类Reader的指针reader）指向了实参（子类HonglouMeng的对象hlm）的地址。那么通过一个指向子类对象hlm的基类指针read，调用虚函数display，实际被调用的将是子类HonglouMeng中的覆盖版本，而非基类Reader中的原始版本。以下代码同理：
                        read(&sgyy);
                        从而实现了多态。
                        
                        2 覆盖的条件
                        2.1 问题
                        只有类的成员函数才能被声明为虚函数，全局函数和类的静态成员函数都不能被声明为虚函数。只有基类中被virtual关键字声明为虚函数的成员函数才能被子类覆盖。虚函数在子类中的覆盖版必须和该函数的基类版本拥有完全相同的签名，即函数名、形参表和常属性严格一致。如果基类中的虚函数返回基本类型的数据或类类型的对象，那么该函数在子类中的覆盖版本必须返回相同类型的数据或对象，否则将引发编译错误。如果基类中的虚函数返回类类型的指针或引用，那么该函数在子类中的覆盖版本可以返回其基类版本返回类型的公有子类的指针或引用。如果基类中的虚函数带有异常说明，那么该函数在子类中的覆盖版本不能说明比其基类版本抛出更多的异常。无论基类中的虚函数位于该类的公有、私有还是保护部分，该函数在子类中的覆盖版本都可以出现在该类包括公有、私有和保护在内的任何部分。
                        2.2 步骤
                        实现此案例需要按照如下步骤进行。
                        步骤一：必须是成员函数
                        代码如下：
#include <iostream>
                        class A {
                        public:
                            virtual void foo(void) {
                            }
                            //    static virtual void staticNumb (void)
                            //    {
                            //
                            //    }
                        };
                        //virtual void global (void)
                        //{
                        //
                        //}
                        上述代码中，以下代码：
                        virtual void foo(void) {
                        }
                        只有类的成员函数才能被声明为虚函数。
                        上述代码中，以下代码：
                        //    static virtual void staticNumb (void)
                        //    {
                        //
                        //    }
                        类的静态成员函数不能被声明为虚函数。
                        上述代码中，以下代码：
                        //virtual void global (void)
                        //{
                        //
                        //}
                        全局函数也不能被声明为虚函数。
                        步骤二：函数签名必须相同
                        代码如下：
#include <iostream>
                        class A {
                        public:
                            virtual void foo(void) {
                            }
                            //    static virtual void staticNumb (void)
                            //    {
                            //
                            //    }
                        };
                        class B : public A {
                            virtual void bar(void) {
                            }
                            virtual void foo(float) {
                            }
                            virtual void foo(void) const {
                            }
                            void foo(void) {
                            }
                        };
                        //virtual void global (void)
                        //{
                        //
                        //}
                        上述代码中，以下代码：
                        virtual void bar (void)
                        由于虚函数在子类中的覆盖版必须和该函数的基类版本拥有完全相同函数名，所以类B的成员函数bar不是类A中的虚函数foo的覆盖版。
                        上述代码中，以下代码：
                        virtual void foo (float)
                        由于虚函数在子类中的覆盖版必须和该函数的基类版本拥有完全相同形参表，所以类B的成员函数void foo(int)不是类A中的虚函数void foo(void)的覆盖版。
                        上述代码中，以下代码：
                        virtual void foo (void) const
                        由于虚函数在子类中的覆盖版必须和该函数的基类版本拥有完全相同常属性，所以类B的成员函数void foo(void)const不是类A中的虚函数void foo(void)的覆盖版。
                        上述代码中，以下代码：
                        void foo (void)
                        由于虚函数在子类中的覆盖版必须和该函数的基类版本拥有完全相同函数名、形参表和常属性，所以类B的成员函数void foo(void)是类A中的虚函数void foo(void)的覆盖版。
                        步骤三：返回同类型的基本类型或对象
                        代码如下：
#include <iostream>
                        class X {
                        public:
                            int m_x;
                        };
                        class A {
                        public:
                            virtual void foo(void) {
                            }
                            virtual int bar(void) {
                                return 0;
                            }
                            virtual X hum(void) {
                                return *new X;
                            }
                            //    static virtual void staticNumb (void)
                            //    {
                            //
                            //    }
                        };
                        class B : public A {
                            int bar(void) {
                                return 0;
                            }
                            virtual void foo(float) {
                            }
                            virtual void foo(void) const {
                            }
                            void foo(void) {
                            }
                            X hum(void) {
                                return *new X;
                            }
                        };
                        //virtual void global (void)
                        //{
                        //
                        //}
                        上述代码中，以下代码：
                        virtual int bar(void) {
                            return 0;
                        }
                        如果基类A中的虚函数bar返回基本类型int的数据，那么该函数在子类B中的覆盖版，如下语句所示：
                        int bar(void) {
                            return 0;
                        }
                        也必须返回相同类型的数据，即int型的数据。
                        上述代码中，以下代码：
                        virtual X hum(void) {
                            return *new X;
                        }
                        如果基类A中的虚函数hum返回类类型X的对象，那么该函数在子类B中的覆盖版本，如下语句所示：
                        X hum(void) {
                            return *new X;
                        }
                        必须返回相同类型的数据，即类X的对象。
                        步骤四：返回类的指针或引用允许协变
                        代码如下：
#include <iostream>
                        class X {
                        public:
                            int m_x;
                            X(const int& x = 0) : m_x(x) {
                            }
                        };
                        class Y : public X {
                        public:
                            Y(const int& y = 0) : X(y) {
                            }
                        };
                        class A {
                        public:
                            virtual void foo(void) {
                            }
                            virtual int bar(void) {
                                return 0;
                            }
                            virtual X hum(void) {
                                return *new X;
                            }
                            virtual X* foo(int i) {
                                return new X(i);
                            }
                            virtual X& bar(int i) {
                                return *new X(i);
                            }
                            //    static virtual void staticNumb (void)
                            //    {
                            //
                            //    }
                        };
                        class B : public A {
                            int bar(void) {
                                return 0;
                            }
                            virtual void foo(float) {
                            }
                            virtual void foo(void) const {
                            }
                            void foo(void) {
                            }
                            X hum(void) {
                                return *new X;
                            }
                            virtual Y* foo(int i) {
                                return new Y(i);
                            }
                            virtual Y& bar(int i) {
                                return *new Y(i);
                            }
                        };
                        //virtual void global (void)
                        //{
                        //
                        //}
                        上述代码中，以下代码：
                        virtual X* foo(int i) {
                            return new X(i);
                        }
                        如果基类A中的虚函数foo返回类类型X的指针，那么该函数在子类中的覆盖版本，如下语句所示：
                        virtual Y* foo(int i) {
                            return new Y(i);
                        }
                        可以返回在基类A中的虚函数foo返回类类型X的公有子类Y的指针
                        上述代码中，以下代码：
                        virtual X& bar(int i) {
                            return *new X(i);
                        }
                        如果基类A中的虚函数foo返回类类型X的引用，那么该函数在子类中的覆盖版本，如下语句所示：
                        virtual Y& bar(int i) {
                            return *new Y(i);
                        }
                        可以返回在基类A中的虚函数foo返回类类型X的公有子类Y的引用。
                        步骤五：不能扩大异常说明
                        代码如下：
#include <iostream>
                        class X {
                        public:
                            int m_x;
                            X(const int& x = 0) : m_x(x) {
                            }
                        };
                        class Y : public X {
                        public:
                            Y(const int& y = 0) : X(y) {
                            }
                        };
                        class A {
                        public:
                            virtual void foo(void) {
                            }
                            virtual int bar(void) {
                                return 0;
                            }
                            virtual X hum(void) {
                                return *new X;
                            }
                            virtual X* foo(int i) {
                                return new X(i);
                            }
                            virtual X& bar(int i) {
                                return *new X(i);
                            }
                            virtual void func(void) throw (int, std::string) {
                            }
                            //    static virtual void staticNumb (void)
                            //    {
                            //
                            //    }
                        };
                        class B : public A {
                            int bar(void) {
                                return 0;
                            }
                            virtual void foo(float) {
                            }
                            virtual void foo(void) const {
                            }
                            void foo(void) {
                            }
                            X hum(void) {
                                return *new X;
                            }
                            virtual Y* foo(int i) {
                                return new Y(i);
                            }
                            virtual Y& bar(int i) {
                                return *new Y(i);
                            }
                            virtual void func(void) throw (int) {
                            }
                        };
                        //virtual void global (void)
                        //{
                        //
                        //}
                        上述代码中，以下代码：
                        virtual void func(void) throw (int, std::string) {
                        }
                        如果基类A中的虚函数func带有异常说明，那么该函数在子类B中的覆盖版本，如下语句所示：
                        virtual void func(void) throw (int) {
                        }
                        不能说明比其基类版本抛出更多的异常。
                        步骤六：访控属性可以不同
                        代码如下：
#include <iostream>
                        class X {
                        public:
                            int m_x;
                            X(const int& x = 0) : m_x(x) {
                            }
                        };
                        class Y : public X {
                        public:
                            Y(const int& y = 0) : X(y) {
                            }
                        };
                        class A {
                        public:
                            virtual void foo(void) {
                            }
                            virtual int bar(void) {
                                return 0;
                            }
                            virtual X hum(void) {
                                return *new X;
                            }
                            virtual X* foo(int i) {
                                return new X(i);
                            }
                            virtual X& bar(int i) {
                                return *new X(i);
                            }
                            virtual void func(void) throw (int, std::string) {
                            }
                            virtual void access(void) {
                            }
                            //    static virtual void staticNumb (void)
                            //    {
                            //
                            //    }
                        };
                        class B : public A {
                        private:
                            void access(void) {
                            }
                        public:
                            int bar(void) {
                                return 0;
                            }
                            virtual void foo(float) {
                            }
                            virtual void foo(void) const {
                            }
                            void foo(void) {
                            }
                            X hum(void) {
                                return *new X;
                            }
                            virtual Y* foo(int i) {
                                return new Y(i);
                            }
                            virtual Y& bar(int i) {
                                return *new Y(i);
                            }
                            virtual void func(void) throw (int) {
                            }
                        };
                        //virtual void global (void)
                        //{
                        //
                        //}
                        int main(int argc, const char* argv[]) {
                            A* p = new B;
                            p->access();
                            return 0;
                        }
                        上述代码中，以下代码：
                        virtual void access(void) {
                        }
                        无论基类A中的虚函数access位于该类的公有、私有还是保护部分，该函数在子类B中的覆盖版本，如下语句所示：
                    private:
                        void access(void) {
                        }
                        都可以出现在子类B包括公有、私有和保护在内的任何部分。只要在基类A中位于公有部分，即是在子类B中定义到了私有部分，仍然能实现多态，如以下主程序中语句：
                        A* p = new B;
                        p->access();
                        不会报编译错误。
                        
                        3 严格区分重载、覆盖和隐藏
                        3.1 问题
                        重载的函数必须在同一个作用域中，包括通过using声明引入到同一作用域的函数。覆盖的函数必须是虚函数，并且要满足上面讲的虚函数的一系列特殊条件。子类与基类的同名成员函数，不满足重载和覆盖的条件，且能正常通过编译，则必然构成隐藏。
                        3.2 步骤
                        实现此案例需要按照如下步骤进行。
                        步骤一：严格区分重载、覆盖和隐藏
                        代码如下：
#include <iostream>
                        class Base {
                        public:
                            virtual void foo(void) {
                                std::cout << "Base foo" << std::endl;
                            }
                            virtual void foo(void) const {
                                std::cout << "Base foo const" << std::endl;
                            }
                        };
                        class Derived : public Base {
                        public:
                            void foo(void) {
                                std::cout << "Derived foo" << std::endl;
                            }
                            void foo(void) const {
                                std::cout << "Derived foo const" << std::endl;
                            }
                        };
                        int main(int argc, const char* argv[]) {
                            Base* b = new Derived;
                            b->foo();
                            delete b;
                            Base const* b1 = new Derived;
                            b1->foo();
                            delete b1;
                            Derived d;
                            d.Base::foo();
                            d.foo();
                            Derived const d1 = d;
                            d1.Base::foo();
                            d1.foo();
                            return 0;
                        }
                        上述代码中，以下代码：
                        class Base {
                        public:
                            virtual void foo(void) {
                                std::cout << "Base foo" << std::endl;
                            }
                            virtual void foo(void) const {
                                std::cout << "Base foo const" << std::endl;
                            }
                        };
                        定义了一个类Base，在该类的作用域中，重载了两个成员函数foo。
                        上述代码中，以下代码：
                        class Derived : public Base {
                        public:
                            void foo(void) {
                                std::cout << "Derived foo" << std::endl;
                            }
                            void foo(void) const {
                                std::cout << "Derived foo const" << std::endl;
                            }
                        };
                        定义了一个子类Derived，继承自类Base，在子类Derived的作用域中，同样重载了两个成员函数foo。
                        对于子类Derived的成员函数foo，如下所示：
                        void foo(void) {
                            std::cout << "Derived foo" << std::endl;
                        }
                        由于与基类Base的同名成员函数foo，如下所示：
                        virtual void foo(void) {
                            std::cout << "Base foo" << std::endl;
                        }
                        不在一个作用域内，所以不满足重载条件，不是重载关系。又因为它们两个都是虚函数并且满足覆盖的条件，所以子类Derived中的foo覆盖基类Base中的foo。
                        又由于与基类Base的同名常函数foo，如下所示：
                        virtual void foo(void) const {
                            std::cout << "Base foo const" << std::endl;
                        }
                        不在一个作用域内，所以不满足重载条件，不是重载关系。虽然它们两个都是虚函数但是不满足覆盖的条件，不是覆盖关系。由于它们能正常通过编译，所以是隐藏关系。
                        
                        4 在构造和析构函数中调用虚函数
                        4.1 问题
                        在基类的构造和析构函数中调用虚函数，绝不可能表现出多态性。实际被调用的一定是基类的原始版本，而非子类的覆盖版本。因为基类的构造函数被子类的构造函数调用时，子类对象尚未构造完成。这时调用虚函数，它只能被绑定到基类版本。同样基类的析构函数被子类的析构函数调用时，子类对象已被释放。这时调用虚函数，它也只能被绑定到基类版本。
                        4.2 步骤
                        实现此案例需要按照如下步骤进行。
                        步骤一：在构造和析构函数中调用虚函数
                        代码如下：
#include <iostream>
                        class Base {
                        public:
                            Base(void) {
                                foo();
                            }
                            ~Base(void) {
                                foo();
                            }
                            virtual void foo(void) {
                                std::cout << "Base foo" << std::endl;
                            }
                        };
                        class Derived : public Base {
                        public:
                            void foo(void) {
                                std::cout << "Derived foo" << std::endl;
                            }
                        };
                        int main(int argc, const char* argv[]) {
                            Base* b = new Derived;
                            delete b;
                            return 0;
                        }
                        上述代码中，以下代码：
                        Base(void) {
                            foo();
                        }
                        ~Base(void) {
                            foo();
                        }
                        在基类Base中定义了它的构造函数与析构函数，在这两个函数中，分别调用了虚函数foo。虚函数foo在基类Base中的定义如下：
                        virtual void foo(void) {
                            std::cout << "Base foo" << std::endl;
                        }
                        虚函数foo在子类Derived中的定义如下：
                        void foo(void) {
                            std::cout << "Derived foo" << std::endl;
                        }
                        上述代码中，以下代码：
                        Base* b = new Derived;
                        在主程序中，定义了基类Base的指针b，让它指向堆上的子类Derived的对象。此时，new操作符为堆上的子类Derived的对象分配空间，首先分配子类Derived的对象的基类部分，基类部分分配完成后，即调用基类Base的构造函数，在基类的构造函数体中，如下代码所示：
                        Base(void) {
                            foo();
                        }
                        调用了虚函数foo，此时由于堆上的子类Derived的对象只分配了基类部分，子类
                        Derived的扩展部分还没有被分配，所以此时虚函数foo只能被绑定到基类版本。
                        上述代码中，以下代码：
                        delete b;
                        在主程序中，释放了基类Base的指针b指向的堆上的子类Derived对象。此时，delete操作符首先调用子类Derived的析构函数，并释放子类Derived的对象的扩展部分，然后调用基类Base的析构函数，在基类的析构函数体中，如下代码所示：
                        ~Base(void) {
                            foo();
                        }
                        调用了虚函数foo，此时由于堆上的子类Derived的对象已经释放了它的扩展部分，所以此时虚函数foo只能被绑定到基类版本。
                        
                        5 抽象基类
                        5.1 问题
                        纯虚函数是如下定义的虚函数
                        class 类名 {
                            virtual 返回类型 函数名(形参表) = 0;
                        };
                        纯虚函数因其所代表的抽象行为而无需或无法实现，包含此种函数的类亦因其所具有的一般性而表现出抽象的特征。至少包含一个纯虚函数的类称为抽象类，抽象类往往用来表示在对问题进行分析、设计的过程中所得出的抽象概念，是对一系列看上去不同，但本质上相同的具体概念的抽象。抽象类不能实例化为对象。抽象类的子类如果不对基类中的全部纯虚函数提供有效的覆盖，那么该子类就也是抽象类。
                        5.2 步骤
                        实现此案例需要按照如下步骤进行。
                        步骤一：纯虚函数与抽象类
                        代码如下：
#include <iostream>
                        class Abstract {
                        public:
                            virtual void show(void) = 0;
                        };
                        定义了一个类Abstract的纯虚函数show。因为类Abstract中包含了一个纯虚函数，所以类Abstract被称为抽象类。
                        步骤二：抽象类不能实例化为对象
                        代码如下：
#include <iostream>
                        class Abstract {
                        public:
                            virtual void show(void) = 0;
                        };
                        int main(int argc, const char* argv[]) {
                            Abstract a;
                            return 0;
                        }
                        上述代码中，以下代码：
                        Abstract a;
                        会报编译错误。因为无论是直接定义，还是通过new运算符，抽象类永远不能实例化为对象。
                        步骤三：抽象类的子类
                        代码如下：
#include <iostream>
                        class Abstract {
                        public:
                            virtual void show(void) = 0;
                        };
                        class MidDerived : public Abstract {
                        };
                        class Derived : public Abstract {
                        public:
                            void show(void) {
                                std::cout << "Derived show" << std::endl;
                            }
                        };
                        int main(int argc, const char* argv[]) {
                            Abstract a;
                            MidDerived m;
                            Derived d;
                            return 0;
                        }
                        上述代码中，以下代码：
                        class MidDerived : public Abstract {
                        };
                        抽象类Abstract的子类MidDerived，如果不对基类Abstract中的全部纯虚函数提供有效的覆盖，那么该子类MidDerived就也是抽象类。在主程序中，如下代码：
                        MidDerived m;
                        同样会报编译错误。
                        上述代码中，以下代码：
                        class Derived : public Abstract {
                        public:
                            void show(void) {
                                std::cout << "Derived show" << std::endl;
                            }
                        };
                        抽象类Abstract的子类Derived，如果对基类Abstract中的全部纯虚函数提供有效的覆盖，那么该子类Derived就不再是抽象类。在主程序中，如下代码：
                        Derived d;
                        是正确的。
                        
                        6 简单工厂模式
                        6.1 问题
                        全部由纯虚函数构成的抽象类称为纯抽象类或接口。面向抽象编程，使得所有基于接口编写的代码，在子类被更替后，无需做任何修改或只需做很少的修改，就能在新子类上正确运行。
                        6.2 步骤
                        实现此案例需要按照如下步骤进行。
                        步骤一：简单工厂模式
                        代码如下：
#include <iostream>
                        typedef enum ProductTypeTag {
                            TypeA,
                            TypeB,
                            TypeC
                        } PRODUCTTYPE;
                        // Here is the product class
                        class Product {
                        public:
                            virtual void show() = 0;
                        };
                        class ProductA : public Product {
                        public:
                            void show(void) {
                                std::cout << "I'm ProductA" << std::endl;
                            }
                        };
                        class ProductB : public Product {
                        public:
                            void show(void) {
                                std::cout << "I'm ProductB" << std::endl;
                            }
                        };
                        class ProductC : public Product {
                        public:
                            void show(void) {
                                std::cout << "I'm ProductC" << std::endl;
                            }
                        };
                        // Here is the Factory class
                        class Factory {
                        public:
                            Product* CreateProduct(PRODUCTTYPE type) {
                                switch (type) {
                                    case TypeA:
                                        return new ProductA;
                                    case TypeB:
                                        return new ProductB;
                                    case TypeC:
                                        return new ProductC;
                                    default:
                                        return NULL;
                                }
                            }
                        };
                        int main(int argc, char* argv[]) {
                            // First, create a factory object
                            Factory* ProductFactory = new Factory();
                            Product* productObjA = ProductFactory->CreateProduct(TypeA);
                            if (productObjA != NULL)
                                productObjA->show();
                            Product* productObjB = ProductFactory->CreateProduct(TypeB);
                            if (productObjB != NULL)
                                productObjB->show();
                            Product* productObjC = ProductFactory->CreateProduct(TypeC);
                            if (productObjC != NULL)
                                productObjC->show();
                            delete ProductFactory;
                            delete productObjA;
                            delete productObjB;
                            delete productObjC;
                            return 0;
                        }
                        上述代码中，以下代码：
                        class Product {
                        public:
                            virtual void show() = 0;
                        };
                        定义了一个抽象产品类Product。
                        上述代码中，以下代码：
                        class ProductA : public Product {
                        public:
                            void show(void) {
                                std::cout << "I'm ProductA" << std::endl;
                            }
                        };
                        class ProductB : public Product {
                        public:
                            void show(void) {
                                std::cout << "I'm ProductB" << std::endl;
                            }
                        };
                        class ProductC : public Product {
                        public:
                            void show(void) {
                                std::cout << "I'm ProductC" << std::endl;
                            }
                        };
                        定义了3个具体产品类。在这3个类中，分别对纯虚函数show进行了实现。还可能有更多的具体产品类。这样就造成创建对象时，对象多而杂。
                        上述代码中，以下代码：
                        class Factory {
                        public:
                            Product* CreateProduct(PRODUCTTYPE type) {
                                switch (type) {
                                    case TypeA:
                                        return new ProductA;
                                    case TypeB:
                                        return new ProductB;
                                    case TypeC:
                                        return new ProductC;
                                    default:
                                        return NULL;
                                }
                            }
                        };
                        定义了一个简单工厂类Factory，其中含有一个成员函数CreateProduct用于生成具体产品对象，以简化创建对象时，对象多而杂的现象。这样就能把对象的创建和操作两部分分离开，方便后期的程序扩展和维护。
                        上述代码中，以下代码：
                        Factory* ProductFactory = new Factory();
                        Product* productObjA = ProductFactory->CreateProduct(TypeA);
                        if (productObjA != NULL)
                            productObjA->show();
                        在主程序中，使用简单工厂类Factory的CreateProduct函数生成具体产品对象，用抽象基类Product的指针实现多态。
                        
                        7 模板方法模式
                        7.1 问题
                        全部由纯虚函数构成的抽象类称为纯抽象类或接口。面向抽象编程，使得所有基于接口编写的代码，在子类被更替后，无需做任何修改或只需做很少的修改，就能在新子类上正确运行。
                        7.2 步骤
                        实现此案例需要按照如下步骤进行。
                        步骤一：模板方法模式
                        代码如下：
#include <iostream>
                        class Abstract {
                        protected:
                            virtual void PrimitiveOperation1() = 0;
                            virtual void PrimitiveOperation2() = 0;
                        public:
                            void TemplateMethod() {
                                std::cout << "TemplateMethod" << std::endl;
                                PrimitiveOperation1();
                                PrimitiveOperation2();
                            }
                        };
                        class ConcreteA : public Abstract {
                        protected:
                            virtual void PrimitiveOperation1() {
                                std::cout << "ConcreteA Operation1" << std::endl;
                            }
                            virtual void PrimitiveOperation2() {
                                std::cout << "ConcreteA Operation2" << std::endl;
                            }
                        };
                        class ConcreteB : public Abstract {
                        protected:
                            virtual void PrimitiveOperation1() {
                                std::cout << "ConcreteB Operation1" << std::endl;
                            }
                            virtual void PrimitiveOperation2() {
                                std::cout << "ConcreteB Operation2" << std::endl;
                            }
                        };
                        int main() {
                            Abstract* pAbstractA = new ConcreteA;
                            pAbstractA->TemplateMethod();
                            Abstract* pAbstractB = new ConcreteB;
                            pAbstractB->TemplateMethod();
                            delete pAbstractA;
                            delete pAbstractB;
                        }
                        上述代码中，以下代码：
                        class Abstract {
                        protected:
                            virtual void PrimitiveOperation1() = 0;
                            virtual void PrimitiveOperation2() = 0;
                        public:
                            void TemplateMethod() {
                                std::cout << "TemplateMethod" << std::endl;
                                PrimitiveOperation1();
                                PrimitiveOperation2();
                            }
                        };
                        定义了抽象模板类Abstract。在该类中，定义两个抽象的原语操作纯虚函数PrimitiveOperation1和纯虚函数PrimitiveOperation2，用这两个原语操作定义一个抽象算法的两个步骤。在该类中还定义了一个模板成员函数TemplateMethod负责整合两个原语操作及其它一些操作，形成一个不变的算法流程。
                        上述代码中，以下代码：
                        class ConcreteA : public Abstract {
                        protected:
                            virtual void PrimitiveOperation1() {
                                std::cout << "ConcreteA Operation1" << std::endl;
                            }
                            virtual void PrimitiveOperation2() {
                                std::cout << "ConcreteA Operation2" << std::endl;
                            }
                        };
                        class ConcreteB : public Abstract {
                        protected:
                            virtual void PrimitiveOperation1() {
                                std::cout << "ConcreteB Operation1" << std::endl;
                            }
                            virtual void PrimitiveOperation2() {
                                std::cout << "ConcreteB Operation2" << std::endl;
                            }
                        };
                        定义了两个实体类，在这两个实体类中，各自实现两个具体的原语操作，完成各自实体中的具体算法的各步骤的具体操作。这样如果再有其它的具体算法，只需要再定义一个实体类，实现具体的原语操作即可。
                        上述代码中，以下代码：
                        Abstract* pAbstractA = new ConcreteA;
                        pAbstractA->TemplateMethod();
                        在主程序中，用抽象模板类Abstract的指针指向实体类ConcreteA，完成一个具体的算法。
                        
                        8 单继承虚表模型
                        8.1 问题
                        编译器会为每个包含虚函数的类生成一张虚函数表，即存放每个虚函数地址的函数指针数组，简称虚表(vtbl)。
                        8.2 步骤
                        实现此案例需要按照如下步骤进行。
                        步骤一：单继承虚表模型
                        代码如下：
#include <iostream>
                        class Base {
                        public:
                            virtual int f1(void) {
                                std::cout << "Base f1" << std::endl;
                                return 0;
                            }
                            virtual void f2(int i) {
                                std::cout << "Base f2" << std::endl;
                            }
                            virtual int f3(int i) {
                                std::cout << "Base f3" << std::endl;
                                return 0;
                            }
                        };
                        class Derived : public Base {
                        public:
                            int f1(void) {
                                std::cout << "Derived f1" << std::endl;
                                return 0;
                            }
                            int f3(int i) {
                                std::cout << "Derived f3" << std::endl;
                                return 0;
                            }
                            virtual void f4(void) {
                                std::cout << "Derived f4" << std::endl;
                            }
                        };
                        int main() {
                            Base* b = new Base;
                            b->f3(10);
                            delete b;
                            b = new Derived;
                            b->f3(20);
                            delete b;
                        }
                        上述代码中，以下代码：
                        class Base {
                        public:
                            virtual int f1(void) {
                                std::cout << "Base f1" << std::endl;
                                return 0;
                            }
                            virtual void f2(int i) {
                                std::cout << "Base f2" << std::endl;
                            }
                            virtual int f3(int i) {
                                std::cout << "Base f3" << std::endl;
                                return 0;
                            }
                        };
                        定义了一个类Base，该类中含有三个虚函数。编译器会为类Base生成一张虚函数表，该表是用于存放每个虚函数地址的函数指针数组，简称虚表(vtbl)，每个虚函数对应一个虚函数表中的数组元素。即vtbl[0]->f1，vtbl[1]->f2，vtbl[2]->f3。
                        除了为类Base生成虚函数表以外，编译器还会为类Base增加一个隐式的成员变量，通常在该类实例化对象的起始位置，用于存放虚函数表的首地址，该变量被称为虚函数表指针，简称虚指针(vptr)。即vptr = &vtbl[0]。
                        这样，主程序中以下语句：
                        Base* b = new Base;
                        b->f3(10);
                        相当于：
                        Base* b = new Base;
                        b->vptr[2](10);
                        虚表是一个类一张，而不是一个对象一张，同一个类的多个对象，通过各自的虚指针，共享同一张虚表。
                        上述代码中，以下代码：
                        class Derived : public Base {
                        public:
                            int f1(void) {
                                std::cout << "Derived f1" << std::endl;
                                return 0;
                            }
                            int f3(int i) {
                                std::cout << "Derived f3" << std::endl;
                                return 0;
                            }
                            virtual void f4(void) {
                                std::cout << "Derived f4" << std::endl;
                            }
                        };
                        定义了子类Derived，并且在子类Derived中覆盖了基类Base的f1和f3，继承了基类Base的f2，增加了自己的f4，编译器同样会为子类生成一张专属于它的虚表。指向子类Derived虚表的虚指针就存放在子类对象的基类子对象中，通常还是在起始位置。
                        这样，主程序中以下语句：
                        b = new Derived;
                        b->f3(20);
                        相当于：
                        b = new Derived;
                        b->vptr[2](20);
                        此时vptr[2]中存放的是子类Derived中覆盖基类Base的f3，而这就是所谓的多态。
                        
                        9 动态类型转换
                        9.1 问题
                        动态类型转换(dynamic_cast)用于将基类类型的指针或引用转换为其子类类型的指针或引用，前提是子类必须从基类多态继承，即基类包含至少一个虚函数
                        9.2 步骤
                        实现此案例需要按照如下步骤进行。
                        步骤一：动态类型转换
                        代码如下：
#include <iostream>
                        class Base {
                        public:
                            virtual int f1(void) {
                                std::cout << "Base f1" << std::endl;
                                return 0;
                            }
                        };
                        class Derived : public Base {
                        public:
                            int f1(void) {
                                std::cout << "Derived f1" << std::endl;
                                return 0;
                            }
                        };
                        int main() {
                            Derived d;
                            Base* pa = &d;
                            Derived* pb = dynamic_cast<Derived*>(pa);
                            if (pb == NULL)
                                std::cout << "转换失败！" << std::endl;
                            Base& ra = d;
                            try {
                                Derived& rb = dynamic_cast<Derived&>(ra);
                            } catch (std::bad_cast& ex) {
                                std::cout << "转换失败！" << std::endl;
                            }
                            Derived b = dynamic_cast<Derived>(*pa);
                            return 0;
                        }
                        上述代码中，以下代码：
                        Derived d;
                        Base* pa = &d;
                        Derived* pb = dynamic_cast<Derived*>(pa);
                        应用动态类型转换，将基类Base类型的指针转换为其子类Derived类型的指针。
                        上述代码中，以下代码：
                        if (pb == NULL)
                            std::cout << "转换失败！" << std::endl;
                        针对指针的动态类型转换，以返回空指针(NULL)表示失败。
                        上述代码中，以下代码：
                        Base& ra = d;
                        try {
                            Derived& rb = dynamic_cast<Derived&>(ra);
                        }
                        应用动态类型转换，将基类Base类型的引用转换为其子类Derived类型的引用。
                        上述代码中，以下代码：
                        Base& ra = d;
                        try {
                            Derived& rb = dynamic_cast<Derived&>(ra);
                        } catch (std::bad_cast& ex) {
                            std::cout << "转换失败！" << std::endl;
                        }
                        针对引用的动态类型转换，以抛出bad_cast异常表示失败。
                        上述代码中，以下代码：
                        Derived b = dynamic_cast<Derived>(*pa);
                        不是针对指针或引用做的动态类型转换，编译错误。另外，要注意，转换目标类型和源类型之间不具有多态继承性也会发生编译错误。转换源类型的目标对象非目标类型会发生运行错误。
                        
                        10 类型信息
                        10.1 问题
                        typeid操作符既可用于类型也可用于对象，用于返回类型信息，即类typeinfo对象的常引用。类typeinfo中含所有一个成员函数name，通过它可以得到类型名。
                        10.2 步骤
                        实现此案例需要按照如下步骤进行。
                        步骤一：类型信息
                        代码如下：
#include <iostream>
                        class A {
                        };
                        class B : public A {
                        public:
                            virtual void foo(void) {
                            }
                        };
                        class C : public B {
                        };
                        int main() {
                            int x;
                            int* px;
                            std::cout << "int is: " << typeid(int).name() << std::endl;
                            std::cout << "  x is: " << typeid(x).name() << std::endl;
                            std::cout << " px is: " << typeid(px).name() << std::endl;
                            std::cout << "*px is: " << typeid(*px).name() << std::endl;
                            C c;
                            A& a = c;
                            std::cout << typeid(a).name() << std::endl;
                            B& b = c;
                            std::cout << typeid(b).name() << std::endl;
                            return 0;
                        }
                        上述代码中，以下代码：
                        int x;
                        int* px;
                        std::cout << "int is: " << typeid(int).name() << std::endl;
                        std::cout << "  x is: " << typeid(x).name() << std::endl;
                        std::cout << " px is: " << typeid(px).name() << std::endl;
                        std::cout << "*px is: " << typeid(*px).name() << std::endl;
                        使用typeid获取指定目标的类型信息。如：
                        std::cout << "int is: " << typeid(int).name() << std::endl;
                        的输出结果为：int is: i。
                        上述代码中，以下代码：
                        C c;
                        A& a = c;
                        std::cout << typeid(a).name() << std::endl;
                        当typeid作用于基类A类型的引用的目标c时，若基类A中不包含任何虚函数，则该操作符所返回的类型信息由引用A本身的类型决定，即返回的是类A的类名A。
                        上述代码中，以下代码：
                        B& b = c;
                        std::cout << typeid (b).name () << std::endl;
                        当typeid作用于基类B类型的引用的目标c时，若基类包含至少一个虚函数，即存在多态继承，该操作符所返回的类型信息由该引用的实际目标对象的类型决定，即返回的是类C的类名C。
                        
                        CSD STDCPP02 DAY04
                        
                        1 子类对象的内存泄漏
                        1.1 问题
                        当使用delete运算符释放一个指向子类对象的基类指针时，因为基类指针只能访问子类对象中的基类子对象，所以实际被调用的仅仅是基类的析构函数，而基类的析构函数只负责析构子类对象中的基类子对象，不会调用子类的析构函数，这样就造成在子类中分配的资源将形成内存泄漏。
                        1.2 步骤
                        实现此案例需要按照如下步骤进行。
                        步骤一：子类对象的内存泄漏
                        代码如下所示：
#include <iostream>
                        class Human {
                        private:
                            std::string m_name;
                            int m_age;
                        public:
                            Human(std::string const& name = "", const int& age = 0) : m_name(name),
                            m_age(age) {
                            }
                            ~Human(void) {
                                std::cout << "Human destructor" << std::endl;
                            }
                        };
                        class Student : public Human {
                        private:
                            int m_no;
                            char* m_address;
                        public:
                            Student(const int& no, const char* address) : m_no(no) {
                                m_address = new char[strlen(address) + 1];
                                strcpy(m_address, address);
                            }
                            ~Student(void) {
                                delete [] m_address;
                                std::cout << "Student destructor" << std::endl;
                            }
                        };
                        int main(int argc, const char* argv[]) {
                            Human* pHuman = new Student(123456, "江苏南京市");
                            delete pHuman;
                            return 0;
                        }
                        上述代码中，以下代码：
                        ~Human(void) {
                            std::cout << "Human destructor" << std::endl;
                        }
                        定义了类Human的析构函数，在该函数中，只是输出一句话，提示该函数被调用了。
                        上述代码中，以下代码：
                        class Student : public Human {
                        private:
                            int m_no;
                            char* m_address;
                        public:
                            Student(const int& no, const char* address) : m_no(no) {
                                m_address = new char[strlen(address) + 1];
                                strcpy(m_address, address);
                            }
                            在子类Student中定义了一个字符指针m_address，并在构造函数中，为其分配存储空间。
                            上述代码中，以下代码：
                            ~Student(void) {
                                delete [] m_address;
                                std::cout << "Student destructor" << std::endl;
                            }
                            由于在子类Student的构造函数中给m_address分配了存储空间，所以在析构函数中需要将其释放。
                            上述代码中，以下代码：
                            Human *pHuman = new Student(123456, "江苏南京市");
                            定义了一个基类的指针pHuman，让它指向一个子类Student在堆上的对象。这是没有问题的。因为基类的指针可以指向子类的对象。但此时该指针只能访问子类中继承过来的基类的子对象，子类中自己扩展的内容该指针无法访问。这就造成了一个问题，如下主程序中的语句：
                            delete pHuman;
                            当用delete释放pHuman指向的对象时，只会调用子类中继承过来的基类部分的析构函数，释放子类中继承过来的基类部分，而不会调用子类的析构函数。如上所述，子类的析构函数要释放m_address指向的空间，不调用子类的析构函数，就意味着内存泄露。
                            
                            2 虚析构函数
                            2.1 问题
                            如果将基类的析构函数声明为虚函数，那么当使用delete运算符释放一个指向子类对象的基类指针时，实际被调用的将是子类的析构函数。而子类的析构函数将首先析构子类对象的扩展部分，然后再通过基类的析构函数析构该对象的基类部分，最终实现完美的资源释放。
                            2.2 步骤
                            实现此案例需要按照如下步骤进行。
                            步骤一：虚析构函数
                            代码如下：
#include <iostream>
                            class Human {
                            private:
                                std::string m_name;
                                int m_age;
                            public:
                                Human(std::string const& name = "", const int& age = 0) : m_name(name),
                                m_age(age) {
                                }
                                virtual ~Human(void) {
                                    std::cout << "Human destructor" << std::endl;
                                }
                            };
                            class Student : public Human {
                            private:
                                int m_no;
                                char* m_address;
                            public:
                                Student(const int& no, const char* address) : m_no(no) {
                                    m_address = new char[strlen(address) + 1];
                                    strcpy(m_address, address);
                                }
                                ~Student(void) {
                                    delete [] m_address;
                                    std::cout << "Student destructor" << std::endl;
                                }
                            };
                            int main(int argc, const char* argv[]) {
                                Human* pHuman = new Student(123456, "江苏南京市");
                                delete pHuman;
                                return 0;
                            }
                            上述代码中，以下代码：
                            virtual ~Human(void) {
                                std::cout << "Human destructor" << std::endl;
                            }
                            定义了类Human的析构函数，并将该析构函数说明成了虚析构函数。当一个类的析构函数被说名称虚函数后，其向下任何一代派生类中的析构函数都将是虚函数，无论是否添加virtual关键字。
                            上述代码中，以下代码：
                            ~Student(void) {
                                delete [] m_address;
                                std::cout << "Student destructor" << std::endl;
                            }
                            由于在子类Student的构造函数中给m_address分配了存储空间，所以在析构函数中需要将其释放。又因为基类Human中的析构函数是虚函数，所以子类Student的析构函数也是虚函数。
                            上述代码中，以下代码：
                            Human *pHuman = new Student(123456, "江苏南京市");
                            定义了一个基类的指针pHuman，让它指向一个子类Student在堆上的对象。此时该指针由于析构函数是虚函数，就能访问子类中析构函数，如下主程序中的语句：
                            delete pHuman;
                            当用delete释放pHuman指向的对象时，实际被调用的将是子类Student的析构函数。而子类的析构函数将首先析构子类对象的扩展部分，然后再通过基类Human的析构函数析构该对象的基类部分。这样就不会造成子类Student的扩展部分申请的内存空间m_address被泄露了。
                            
                            3 空虚析构函数
                            3.1 问题
                            对于一个没有分配任何资源的类，无需定义析构函数。但这样的类，编译器会为其提供一个缺省析构函数，而缺省析构函数并不是虚函数。为了保证当delete指向子类对象的基类指针时，能够正确调用子类的析构函数，就必须把基类的析构函数定义为虚函数，即使它是一个空函数。任何时候，为基类定义一个虚析构函数总是无害的。
                            3.2 步骤
                            实现此案例需要按照如下步骤进行。
                            步骤一：空虚析构函数
                            代码如下所示：
#include <iostream>
                            class Human {
                            private:
                                std::string m_name;
                                int m_age;
                            public:
                                Human(std::string const& name = "", const int& age = 0) : m_name(name),
                                m_age(age) {
                                }
                                virtual ~Human(void) {
                                    std::cout << "Human destructor" << std::endl;
                                }
                            };
                            class Student : public Human {
                            private:
                                int m_no;
                                char* m_address;
                            public:
                                Student(const int& no, const char* address) : m_no(no) {
                                    m_address = new char[strlen(address) + 1];
                                    strcpy(m_address, address);
                                }
                                ~Student(void) {
                                    delete [] m_address;
                                    std::cout << "Student destructor" << std::endl;
                                }
                            };
                            int main(int argc, const char* argv[]) {
                                Human* pHuman = new Student(123456, "江苏南京市");
                                delete pHuman;
                                return 0;
                            }
                            上述代码中，以下代码：
                            virtual ~Human(void) {
                                std::cout << "Human destructor" << std::endl;
                            }
                            定义了类Human的析构函数，并将该析构函数说明成了虚析构函数。当一个类的析构函数被说名称虚函数后，其向下任何一代派生类中的析构函数都将是虚函数，无论是否添加virtual关键字。我们可以注意到，再该析构函数当中的语句，是可有可无的，只是一个调试用的提示语句。如果将该语句删除掉，则析构函数就是空析构函数。
                            上述代码中，以下代码：
                            ~Student(void) {
                                delete [] m_address;
                                std::cout << "Student destructor" << std::endl;
                            }
                            由于在子类Student的构造函数中给m_address分配了存储空间，所以在析构函数中需要将其释放。又因为基类Human中的析构函数是虚函数，所以子类Student的析构函数也是虚函数。
                            上述代码中，以下代码：
                            Human* pHuman = new Student(123456, "江苏南京市");
                            定义了一个基类的指针pHuman，让它指向一个子类Student在堆上的对象。此时该指针由于析构函数是虚函数，就能访问子类中析构函数，如下主程序中的语句：
                            delete pHuman;
                            当用delete释放pHuman指向的对象时，实际被调用的将是子类Student的析构函数。而子类的析构函数将首先析构子类对象的扩展部分，然后再通过基类Human的析构函数析构该对象的基类部分。这样就不会造成子类Student的扩展部分申请的内存空间m_address被泄露了。
                            
                            4 纯虚析构函数
                            4.1 问题
                            如果在一个需要体现出抽象性的类中，实在找不到更适合被定义为纯虚函数的成员函数，那么不妨把它的析构函数定义为纯虚函数。与普通纯虚函数不同的是，纯虚析构函数必须有定义，因为子类的析构函数总要调用基类的析构函数。
                            4.2 步骤
                            实现此案例需要按照如下步骤进行。
                            步骤一：纯虚析构函数
                            代码如下所示：
#include <iostream>
                            class Human {
                            private:
                                std::string m_name;
                                int m_age;
                            public:
                                Human(std::string const& name = "", const int& age = 0) : m_name(name),
                                m_age(age) {
                                }
                                virtual ~Human(void) = 0;
                            };
                            Human::~Human(void) {
                                std::cout << "Human destructor" << std::endl;
                            }
                            class Student : public Human {
                            private:
                                int m_no;
                                char* m_address;
                            public:
                                Student(const int& no, const char* address) : m_no(no) {
                                    m_address = new char[strlen(address) + 1];
                                    strcpy(m_address, address);
                                }
                                ~Student(void) {
                                    delete [] m_address;
                                    std::cout << "Student destructor" << std::endl;
                                }
                            };
                            int main(int argc, const char* argv[]) {
                                Human* pHuman = new Student(123456, "江苏南京市");
                                delete pHuman;
                                return 0;
                            }
                            上述代码中，以下代码：
                            virtual ~Human(void) = 0;
                            定义了类Human的纯虚析构函数。当一个类的析构函数被说名称纯虚函数后，其向下任何一代派生类中的析构函数都将是虚函数，无论是否添加virtual关键字。但是与普通纯虚函数不同的是，纯虚析构函数必须有定义，如下代码所示：
                            Human::~Human(void) {
                                std::cout << "Human destructor" << std::endl;
                            }
                            因为子类的析构函数总要调用基类的析构函数。
                            上述代码中，以下代码：
                            ~Student(void) {
                                delete [] m_address;
                                std::cout << "Student destructor" << std::endl;
                            }
                            由于在子类Student的构造函数中给m_address分配了存储空间，所以在析构函数中需要将其释放。又因为基类Human中的析构函数是虚函数，所以子类Student的析构函数也是虚函数。
                            上述代码中，以下代码：
                            Human* pHuman = new Student(123456, "江苏南京市");
                            定义了一个基类的指针pHuman，让它指向一个子类Student在堆上的对象。此时该指针由于析构函数是虚函数，就能访问子类中析构函数，如下主程序中的语句：
                            delete pHuman;
                            当用delete释放pHuman指向的对象时，实际被调用的将是子类Student的析构函数。而子类的析构函数将首先析构子类对象的扩展部分，然后再通过基类Human的析构函数析构该对象的基类部分。这样就不会造成子类Student的扩展部分申请的内存空间m_address被泄露了。
                            
                            5 返回错误
                            5.1 问题
                            在项目的整个生命周期内，错误随时随地都有可能发生，虽然那些错误都在实际运行过程中发生，在设计、编码和测试阶段无法规避但却是可以预见的，如通过返回值返回错误信息。
                            5.2 步骤
                            实现此案例需要按照如下步骤进行。
                            步骤一：返回错误
                            代码如下所示：
#include <iostream>
                            int connectServer(char const* config) {
                                FILE* fp = fopen(config, "r");
                                if (fp == NULL)
                                    return -1;
                                //其他操作
                                return 0;
                            }
                            int main(int argc, const char* argv[]) {
                                if (connectServer("/etc/server.cfg") == -1) {
                                    std::cerr << "打开文件失败！" << std::endl;
                                    exit(-1);
                                }
                                return 0;
                            }
                            上述代码中，以下代码：
                            FILE* fp = fopen(config, "r");
                            if (fp == NULL)
                                return -1;
                            是一种常见的可预见性错误，当打开一个文件时，如果打开失败，则后续的操作将无法执行，并会导致程序崩溃。此时可以通过返回错误码的形式通知主调函数发生了错误。如以下主程序中的代码：
                            if (connectServer("/etc/server.cfg") == -1) {
                                std::cerr << "打开文件失败！" << std::endl;
                                exit(-1);
                            }
                            通过判断返回值，就可以知道所需的操作是否正确完成。
                            
                            6 远程跳转
                            6.1 问题
                            在项目的整个生命周期内，错误随时随地都有可能发生，虽然那些错误都在实际运行过程中发生，在设计、编码和测试阶段无法规避但却是可以预见的，如通过远程跳转返回错误信息。
                            6.2 步骤
                            实现此案例需要按照如下步骤进行。
                            步骤一：远程跳转
                            代码如下：
#include <iostream>
#include <setjmp.h>
                            jmp_buf g_env;
                            int connectServer(char const* config) {
                                FILE* fp = fopen(config, "r");
                                if (fp == NULL)
                                    longjmp(g_env, -1);
                                //其他操作
                                return 0;
                            }
                            int main(int argc, const char* argv[]) {
                                if (setjmp(g_env) == -1) {
                                    std::cerr << "打开文件失败！" << std::endl;
                                    exit(-1);
                                }
                                connectServer("/etc/server.cfg");
                                return 0;
                            }
                            上述代码中，以下代码：
                            FILE* fp = fopen(config, "r");
                            if (fp == NULL)
                                longjmp(g_env, -1);
                            是一种常见的可预见性错误，当打开一个文件时，如果打开失败，则后续的操作将无法执行，并会导致程序崩溃。此时可以通过远程跳转的形式通知主调函数发生了错误。如以下主程序中的代码：
                            if (setjmp(g_env) == -1) {
                                std::cerr << "打开文件失败！" << std::endl;
                                exit(-1);
                            }
                            connectServer("/etc/server.cfg");
                            先调用setjmp，用变量g_env记录当前主函数被执行到的位置，然后在connectServer函数中如果调用了longjmp，程序的执行流程将返回到g_env所记录的位置，并使setjmp的返回值为设定的-1。通过判断返回值，就可以知道所需的操作是否正确完成。
                            
                            7 抛出异常
                            7.1 问题
                            在项目的整个生命周期内，错误随时随地都有可能发生，虽然那些错误都在实际运行过程中发生，在设计、编码和测试阶段无法规避但却是可以预见的，如通过使用C++语言所提供的异常机制返回错误信息。
                            7.2 步骤
                            实现此案例需要按照如下步骤进行。
                            步骤一：抛出异常
                            代码如下：
#include <iostream>
                            int connectServer(char const* config) {
                                FILE* fp = fopen(config, "r");
                                if (fp == NULL)
                                    throw - 1;
                                //其他操作
                                return 0;
                            }
                            int main(int argc, const char* argv[]) {
                                try {
                                    connectServer("/etc/server.cfg");
                                } catch (int ex) {
                                    std::cerr << "打开文件失败！" << std::endl;
                                    exit(-1);
                                }
                                return 0;
                            }
                            上述代码中，以下代码：
                            FILE* fp = fopen(config, "r");
                            if (fp == NULL)
                                throw - 1;
                            是一种常见的可预见性错误，当打开一个文件时，如果打开失败，则后续的操作将无法执行，并会导致程序崩溃。此时可以通过throw语句抛出异常的形式通知主调函数发生了错误。如以下主程序中的代码：
                            try {
                                connectServer("/etc/server.cfg");
                            } catch (int ex) {
                                std::cerr << "打开文件失败！" << std::endl;
                                exit(-1);
                            }
                            将函数调用connectServer放在try的作用域中，当函数connectServer在执行的过程中抛出了一个异常的时候，catch语句将进行捕捉。通过判断catch语句是否进行捕捉，就可以知道所需的操作是否正确完成。
                            
                            8 抛出基本类型异常
                            8.1 问题
                            抛出基本类型的异常时，可以分别抛出不同的异常对象的值，在捕捉异常后，根据异常对象的值分别处理不同的错误。
                            8.2 步骤
                            实现此案例需要按照如下步骤进行。
                            步骤一：抛出基本类型异常
                            代码如下：
#include <iostream>
                            int connectServer(char const* config) {
                                FILE* fp = fopen(config, "r");
                                if (fp == NULL)
                                    throw - 1;
                                char* pc = (char*)malloc(1024);
                                if (pc == NULL)
                                    throw - 2;
                                //其他操作
                                return 0;
                            }
                            int main(int argc, const char* argv[]) {
                                try {
                                    connectServer("/etc/server.cfg");
                                } catch (int ex) {
                                    if (ex == -1)
                                        std::cerr << "打开文件失败！" << std::endl;
                                    else if (ex == -2)
                                        std::cerr << "分配内存失败！" << std::endl;
                                    exit(-1);
                                }
                                return 0;
                            }
                            上述代码中，以下代码：
                            FILE* fp = fopen(config, "r");
                            if (fp == NULL)
                                throw - 1;
                            char* pc = (char*)malloc(1024);
                            if (pc == NULL)
                                throw - 2;
                            当文件打开失败后，抛出基本类型的异常对象的值为-1；申请内存失败后，抛出基本类型的异常对象的值为-2。
                            上述代码中，以下代码：
                            catch (int ex) {
                                if (ex == -1)
                                    std::cerr << "打开文件失败！" << std::endl;
                                else if (ex == -2)
                                    std::cerr << "分配内存失败！" << std::endl;
                                exit(-1);
                            }
                            根据异常对象的值分别处理不同的错误。
                            
                            9 抛出类类型异常
                            9.1 问题
                            抛出类类型的异常时，可以分别抛出类类型的异常，在捕捉异常时，根据异常对象的类型分别处理。
                            9.2 步骤
                            实现此案例需要按照如下步骤进行。
                            步骤一：抛出类类型异常
                            代码如下：
#include <iostream>
                            class FileException : public std::exception {
                            };
                            class MemoryException : public std::exception {
                            };
                            int connectServer(char const* config) {
                                FILE* fp = fopen(config, "r");
                                if (fp == NULL)
                                    throw FileException();
                                char* pc = (char*)malloc(1024);
                                if (pc == NULL)
                                    throw MemoryException();
                                //其他操作
                                return 0;
                            }
                            int main(int argc, const char* argv[]) {
                                try {
                                    connectServer("/etc/server.cfg");
                                } catch (FileException& ex) {
                                    std::cerr << "打开文件失败！" << std::endl;
                                    exit(-1);
                                } catch (MemoryException& ex) {
                                    std::cerr << "分配内存失败！" << std::endl;
                                    exit(-1);
                                }
                                return 0;
                            }
                            上述代码中，以下代码：
                            FILE* fp = fopen(config, "r");
                            if (fp == NULL)
                                throw FileException();
                            char* pc = (char*)malloc(1024);
                            if (pc == NULL)
                                throw MemoryException();
                            当文件打开失败后，抛出类类型FileException的异常；申请内存失败后，抛出类类型MemoryException的异常。
                            上述代码中，以下代码：
                            catch (FileException& ex) {
                                std::cerr << "打开文件失败！" << std::endl;
                                exit(-1);
                            } catch (MemoryException& ex) {
                                std::cerr << "分配内存失败！" << std::endl;
                                exit(-1);
                            }
                            在捕捉异常时，根据异常对象的类型分别处理。
                            
                            10 借助异常携带更多诊断信息
                            10.1 问题
                            由于类是由用户定义的数据类型，在定义类时，类中可以有任意用户想要的数据，所以利用类类型的异常，能够携带更多诊断信息，以便查错。
                            10.2 步骤
                            实现此案例需要按照如下步骤进行。
                            步骤一：借助异常携带更多诊断信息
                            代码如下：
#include <iostream>
                            class FileException : public std::exception {
                            public:
                                std::string m_file;
                                int m_line;
                                std::string m_func;
                                std::string m_error;
                                FileException(std::string const& file, const int& line, std::string const& func,
                                              std::string const& error) : m_file(file), m_line(line), m_func(func),
                                m_error(error) {
                                }
                            };
                            extern int errno;
                            int connectServer(char const* config) {
                                FILE* fp = fopen(config, "r");
                                if (fp == NULL)
                                    throw FileException(__FILE__, __LINE__, __FUNCTION__, std::strerror(errno));
                                //其他操作
                                return 0;
                            }
                            int main(int argc, const char* argv[]) {
                                try {
                                    connectServer("/etc/server.cfg");
                                } catch (FileException& ex) {
                                    std::cerr << "文件：" << ex.m_file << std::endl;
                                    std::cerr << "行号：" << ex.m_line << std::endl;
                                    std::cerr << "函数：" << ex.m_func << std::endl;
                                    std::cerr << "错误：" << ex.m_error << std::endl;
                                    exit(-1);
                                }
                                return 0;
                            }
                            上述代码中，以下代码：
                            class FileException : public std::exception {
                            public:
                                std::string m_file;
                                int m_line;
                                std::string m_func;
                                std::string m_error;
                                FileException(std::string const& file, const int& line, std::string const& func,
                                              std::string const& error) : m_file(file), m_line(line), m_func(func),
                                m_error(error) {
                                }
                            };
                            自定义文件异常类FileException，在类中添加与文件操作相关的数据，m_file文件名，m_line行号，m_func函数名，m_error错误名称。
                            上述代码中，以下代码：
                            FILE* fp = fopen(config, "r");
                            if (fp == NULL)
                                throw FileException(__FILE__, __LINE__, __FUNCTION__, std::strerror(errno));
                            在函数connectServer中打开文件，如果打开失败，抛出自定义文件异常类FileException的对象。__FILE__，__LINE__，__FUNCTION__是编译器定义的三个宏，分别为当前运行程序的文件名、行号和函数名，函数strerror根据错误号errno得到错误的名称。
                            上述代码中，以下代码：
                            catch (FileException& ex) {
                                std::cerr << "文件：" << ex.m_file << std::endl;
                                std::cerr << "行号：" << ex.m_line << std::endl;
                                std::cerr << "函数：" << ex.m_func << std::endl;
                                std::cerr << "错误：" << ex.m_error << std::endl;
                                exit(-1);
                            }
                            当异常发生时，能够得到更多的信息。
                            
                            11 忽略异常
                            11.1 问题
                            在函数中可以不捕捉异常，不做处理，这样异常会自动向函数的调用者继续抛出，如果直至主函数都不捕捉异常，会由std::unexpected()函数处理。
                            11.2 步骤
                            实现此案例需要按照如下步骤进行。
                            步骤一：忽略异常
                            代码如下：
#include <iostream>
                            int connectServer(char const* config) throw (int) {
                                FILE* fp = fopen(config, "r");
                                if (fp == NULL)
                                    throw - 1;
                                //其他操作
                                return 0;
                            }
                            void login(char const* username, char const* passwd) throw (int) {
                                connectServer("/etc/server.cfg");
                            }
                            int main(int argc, const char* argv[]) {
                                try {
                                    connectServer("/etc/server.cfg");
                                } catch (int ex) {
                                    std::cerr << "打开文件失败！" << std::endl;
                                    exit(-1);
                                }
                                return 0;
                            }
                            上述代码中，以下代码：
                            int connectServer(char const* config) throw (int) {
                                FILE* fp = fopen(config, "r");
                                if (fp == NULL)
                                    throw - 1;
                                //其他操作
                                return 0;
                            }
                            在函数connectServer中，当打开文件失败时，抛出异常。
                            上述代码中，以下代码：
                            void login(char const* username, char const* passwd) throw (int) {
                                connectServer("/etc/server.cfg");
                            }
                            在函数login中可以不捕捉异常，不做处理，这样异常会自动向函数login的调用者继续抛出。
                            
                            12 继续抛出异常
                            12.1 问题
                            在函数中捕捉到异常之后，可以从catch块中继续抛出所捕获的异常，或者抛出其它异常。
                            12.2 步骤
                            实现此案例需要按照如下步骤进行。
                            步骤一：继续抛出异常
                            代码如下：
#include <iostream>
                            int connectServer(char const* config) throw (int) {
                                FILE* fp = fopen(config, "r");
                                if (fp == NULL)
                                    throw - 1;
                                //其他操作
                                return 0;
                            }
                            void login(char const* username, char const* passwd) throw (int) {
                                try {
                                    connectServer("/etc/server.cfg");
                                } catch (int) {
                                    std::cerr << "登录失败！" << std::endl;
                                    throw;
                                }
                            }
                            int main(int argc, const char* argv[]) {
                                try {
                                    login("/etc/server.cfg", "123456");
                                } catch (int ex) {
                                    std::cerr << "打开文件失败！" << std::endl;
                                    exit(-1);
                                }
                                return 0;
                            }
                            上述代码中，以下代码：
                            int connectServer(char const* config) throw (int) {
                                FILE* fp = fopen(config, "r");
                                if (fp == NULL)
                                    throw - 1;
                                //其他操作
                                return 0;
                            }
                            在函数connectServer中，当打开文件失败时，抛出异常。
                            上述代码中，以下代码：
                            void login(char const* username, char const* passwd) throw (int) {
                                try {
                                    connectServer("/etc/server.cfg");
                                } catch (int) {
                                    std::cerr << "登录失败！" << std::endl;
                                    throw;
                                }
                            }
                            在函数login中捕捉到异常之后，可以从catch块中继续抛出所捕获的异常。
                            上述代码中，以下代码：
                            int main(int argc, const char* argv[]) {
                                try {
                                    login("/etc/server.cfg", "123456");
                                } catch (int ex) {
                                    std::cerr << "打开文件失败！" << std::endl;
                                    exit(-1);
                                }
                                return 0;
                            }
                            在主函数中就能够继续捕捉到函数login抛出的异常。
                            
                            13 异常终结者
                            13.1 问题
                            在函数中抛出异常之后，任何未被捕获的异常，都会由std::unexpected()函数处理，缺省的处理方式就是中止进程。
                            13.2 步骤
                            实现此案例需要按照如下步骤进行。
                            步骤一：异常终结者
                            代码如下：
#include <iostream>
                            int connectServer(char const* config) throw (int) {
                                FILE* fp = fopen(config, "r");
                                if (fp == NULL)
                                    throw - 1;
                                //其他操作
                                return 0;
                            }
                            void login(char const* username, char const* passwd) throw (int) {
                                connectServer("/etc/server.cfg");
                            }
                            int main(int argc, const char* argv[]) {
                                login("/etc/server.cfg", "123456");
                                return 0;
                            }
                            上述代码中，以下代码：
                            int connectServer(char const* config) throw (int) {
                                FILE* fp = fopen(config, "r");
                                if (fp == NULL)
                                    throw - 1;
                                //其他操作
                                return 0;
                            }
                            在函数connectServer中，当打开文件失败时，抛出异常。
                            上述代码中，以下代码：
                            void login(char const* username, char const* passwd) throw (int) {
                                connectServer("/etc/server.cfg");
                            }
                            int main(int argc, const char* argv[]) {
                                login("/etc/server.cfg", "123456");
                                return 0;
                            }
                            但是，在函数connectServer的调用函数login以及函数login的调用函数main中都没有使用catch捕捉函数connectServer抛出的异常。这样std::unexpected()函数将最终处理该异常，缺省的处理方式就是中止进程。
                            
                            14 异常说明
                            14.1 问题
                            异常说明是函数原型的一部分，旨在说明函数可能抛出的异常类型。异常说明是一种承诺，承诺函数不会抛出异常说明以外的异常类型，否则该异常将无法被捕获，并导致进程中止。隐式抛出异常的函数也可以列出它的异常说明。没有异常说明，表示可能抛出任何类型的异常。异常说明为空，表示不会抛出任何类型的异常。如果基类中的虚函数带有异常说明，那么该函数在子类中的覆盖版本不能说明比其基类版本抛出更多的异常。异常说明在函数的声明和定义中必须保持严格一致，否则将导致编译错误。
                            14.2 步骤
                            实现此案例需要按照如下步骤进行。
                            步骤一：异常说明是函数原型的一部分
                            代码如下：
#include <iostream>
                            int connectServer(char const* config) throw (int) {
                                FILE* fp = fopen(config, "r");
                                if (fp == NULL)
                                    throw - 1;
                                //其他操作
                                return 0;
                            }
                            上述代码中异常说明是函数原型的一部分，旨在说明函数可能抛出的异常类型。在本案例中，异常说明是throw (int)，可能抛出的异常类型是int。
                            异常说明是一种承诺，承诺函数不会抛出异常说明以外的异常类型，如果函数抛出了异常说明以外的异常类型，那么该异常将无法被捕获，并导致进程中止。在本案例中，如果抛出了除int外的其他类型，如float，函数connectServer将终止运行。
                            步骤二：说明隐式抛出的异常
                            代码如下：
#include <iostream>
                            int connectServer(char const* config) throw (int) {
                                FILE* fp = fopen(config, "r");
                                if (fp == NULL)
                                    throw - 1;
                                //其他操作
                                return 0;
                            }
                            void login(char const* username, char const* passwd) throw (int) {
                                connectServer("/etc/server.cfg");
                            }
                            上述代码中，以下代码：
                            void login(char const* username, char const* passwd) throw (int) {
                                connectServer("/etc/server.cfg");
                            }
                            的函数体内未直接抛出异常，但其调用的函数connectServer抛出了异常，此时函数login将隐式抛出的异常。
                            步骤三：异常说明可以没有也可以为空
                            代码如下：
#include <iostream>
                            int connectServer(char const* config) throw (int) {
                                FILE* fp = fopen(config, "r");
                                if (fp == NULL)
                                    throw - 1;
                                //其他操作
                                return 0;
                            }
                            void login(char const* username, char const* passwd) throw (int) {
                                connectServer("/etc/server.cfg");
                            }
                            void loginServer(char const* username, char const* passwd) {
                                connectServer("/etc/server.cfg");
                            }
                            void loginConnectServer(char const* username, char const* passwd) throw() {
                                connectServer("/etc/server.cfg");
                            }
                            上述代码中，以下代码：
                            void loginServer(char const* username, char const* passwd) {
                                connectServer("/etc/server.cfg");
                            }
                            函数loginServer没有异常说明，表示函数loginServer可以抛出任何类型的异常。
                            上述代码中，以下代码：
                            void loginConnectServer(char const* username, char const* passwd) throw() {
                                connectServer("/etc/server.cfg");
                            }
                            函数loginConnectServer异常说明为空，表示函数loginConnectServer不会抛出任何类型的异常。
                            步骤四：异常说明与虚函数覆盖
                            代码如下：
#include <iostream>
                            int connectServer(char const* config) throw (int) {
                                FILE* fp = fopen(config, "r");
                                if (fp == NULL)
                                    throw - 1;
                                //其他操作
                                return 0;
                            }
                            void login(char const* username, char const* passwd) throw (int) {
                                connectServer("/etc/server.cfg");
                            }
                            void loginServer(char const* username, char const* passwd) {
                                connectServer("/etc/server.cfg");
                            }
                            void loginConnectServer(char const* username, char const* passwd) throw() {
                                connectServer("/etc/server.cfg");
                            }
                            class A {
                            public:
                                virtual void foo(void) throw (int, std::string);
                            };
                            class B : public A {
                            public:
                                void foo(void) throw (int) {
                                    throw 1;
                                }
                            };
                            上述代码中，以下代码：
                            class A {
                            public:
                                virtual void foo(void) throw (int, std::string);
                            };
                            class B : public A {
                            public:
                                void foo(void) throw (int) {
                                    throw 1;
                                }
                            };
                            如果基类A中的虚函数foo带有异常说明throw(int, std::string)，那么该函数在子类B中的覆盖版本不能说明比其基类A版本抛出更多的异常。
                            步骤五：声明和定义的异常说明要一致
                            代码如下：
#include <iostream>
                            int connectServer(char const* config) throw (int) {
                                FILE* fp = fopen(config, "r");
                                if (fp == NULL)
                                    throw - 1;
                                //其他操作
                                return 0;
                            }
                            void login(char const* username, char const* passwd) throw (int) {
                                connectServer("/etc/server.cfg");
                            }
                            void loginServer(char const* username, char const* passwd) {
                                connectServer("/etc/server.cfg");
                            }
                            void loginConnectServer(char const* username, char const* passwd) throw() {
                                connectServer("/etc/server.cfg");
                            }
                            class A {
                            public:
                                virtual void foo(void) throw (int, std::string);
                            };
                            class B : public A {
                            public:
                                void foo(void) throw (int) {
                                    throw 1;
                                }
                            };
                            void A::foo(void) throw (int, std::string) {
                            }
                            上述代码中，以下代码：
                            virtual void foo(void) throw (int, std::string);
                            是类A的成员函数foo的说明。
                            上述代码中，以下代码：
                            void A::foo(void) throw (int, std::string) {
                            }
                            是类A的成员函数foo的定义。异常说明在函数foo的声明和定义中必须保持严格一致，否则将导致编译错误。
                            
                            15 构造过程中的异常
                            15.1 问题
                            构造函数可以抛出异常，某些时候还必须抛出异常。如因为构造函数没有返回值，所以无法通过返回值通知调用者，这样当构造过程中发生如内存分配失败等可能遇到各种错误时，就必须抛出异常。
                            15.2 步骤
                            实现此案例需要按照如下步骤进行。
                            步骤一：构造函数抛出异常
                            代码如下：
#include <iostream>
                            class MemoryException : public std::exception {
                            public:
                                MemoryException(std::string const& msg) : m_msg(msg) {
                                }
                                char const* what(void) const throw () {
                                    return m_msg.c_str();
                                }
                                std::string m_msg;
                            };
                            class String {
                            private:
                                char* m_str;
                            public:
                                String(char const* str) {
                                    if (!(m_str = (char*)malloc(strlen(str ? str : "") + 1)))
                                        throw MemoryException(strerror(errno));
                                }
                            };
                            int main(int argc, const char* argv[]) {
                                try {
                                    String str("This is a string.");
                                } catch (std::exception& ex) {
                                    std::cerr << ex.what() << std::endl;
                                    exit(-1);
                                }
                                return 0;
                            }
                            上述代码中，以下代码：
                            String(char const* str) {
                                if (!(m_str = (char*)malloc(strlen(str ? str : "") + 1)))
                                    throw MemoryException(strerror(errno));
                            }
                            是类string的构造函数。因为构造函数没有返回值，所以当在构造过程中发生内存分配失败错误时，就必须抛出异常。
                            
                            16 不完整对象的回滚
                            16.1 问题
                            构造函数抛出异常，对象将被不完整构造，而一个被不完整构造的对象，其析构函数永远不会被执行。构造函数的回滚机制，可以保证所有成员子对象和基类子对象，在抛出异常的过程中，都能得到正确地析构。所有动态分配的资源，必须在抛出异常之前，手动释放，否则将形成内存泄漏，除非使用了智能指针。
                            16.2 步骤
                            实现此案例需要按照如下步骤进行。
                            步骤一：不完整对象的回滚
                            代码如下：
#include <iostream>
                            class FileException : public std::exception {
                            public:
                                std::string m_file;
                                int m_line;
                                std::string m_func;
                                std::string m_error;
                                std::string m_msg;
                                FileException(std::string const& file, const int& line, std::string const& func,
                                              std::string const& error) : m_file(file), m_line(line), m_func(func),
                                m_error(error) {
                                    char strLine[10];
                                    sprintf(strLine, "%d", line);
                                    m_msg = "文件：" + file + "\n行号：" + strLine + "\n函数：" + func + "\n错误："
                                    + error + "\n";
                                }
                                char const* what(void) const throw () {
                                    return m_msg.c_str();
                                }
                            };
                            class MemoryException : public std::exception {
                            public:
                                MemoryException(std::string const& msg) : m_msg(msg) {
                                }
                                char const* what(void) const throw () {
                                    return m_msg.c_str();
                                }
                                std::string m_msg;
                            };
                            class Human {
                            private:
                                std::string m_address;
                                char* m_name;
                            public:
                                Human(std::string const& address, char const* name) {
                                    if (!(m_name = (char*)malloc(strlen(name ? name : "") + 1)))
                                        throw MemoryException(strerror(errno));
                                    FILE* fp = fopen("/etc/server.cfg", "r");
                                    if (fp == NULL) {
                                        delete [] m_name;
                                        throw FileException(__FILE__, __LINE__, __FUNCTION__, std::strerror(errno));
                                    }
                                }
                                ~Human(void) {
                                    free(m_name);
                                }
                            };
                            int main(int argc, const char* argv[]) {
                                try {
                                    Human human("江苏南京市", "ZhangSan");
                                } catch (std::exception& ex) {
                                    std::cerr << ex.what() << std::endl;
                                    exit(-1);
                                }
                                return 0;
                            }
                            上述代码中，以下代码：
                        private:
                            std::string m_address;
                            char* m_name;
                            定义了类Human的两个数据成员，一个是m_address，用于存放地址，另一个是m_name用于保存姓名。
                            上述代码中，以下代码：
                            Human(std::string const& address, char const* name) : m_address(address) {
                                if (!(m_name = (char*)malloc(strlen(name ? name : "") + 1)))
                                    throw MemoryException(strerror(errno));
                                FILE* fp = fopen("/etc/server.cfg", "r");
                                if (fp == NULL) {
                                    delete [] m_name;
                                    throw FileException(__FILE__, __LINE__, __FUNCTION__, std::strerror(errno));
                                }
                            }
                            定义了类Human的构造函数。构造函数的回滚机制，可以保证类Human成员子对象m_address，在如下代码：
                            if (!(m_name = (char*)malloc(strlen(name ? name : "") + 1)))
                                throw MemoryException(strerror(errno));
                            抛出异常的过程中，都能得到正确地析构。如果未抛出异常，当如下语句：
                            FILE* fp = fopen("/etc/server.cfg", "r");
                            if (fp == NULL) {
                                delete [] m_name;
                                throw FileException(__FILE__, __LINE__, __FUNCTION__, std::strerror(errno));
                            }
                            执行时打开文件失败，在抛出异常之前，必须释放为m_name分配的存储空间。
                            
                            17 析构过程中的异常
                            17.1 问题
                            不要从析构函数中主动抛出异常。在析构函数中，执行任何可能引发异常的操作，都尽量把异常在内部消化掉，防止其从析构函数中被继续抛出。
                            17.2 步骤
                            实现此案例需要按照如下步骤进行。
                            步骤一：析构过程中的异常
                            代码如下：
#include <iostream>
                            class FileException : public std::exception {
                            public:
                                std::string m_file;
                                int m_line;
                                std::string m_func;
                                std::string m_error;
                                std::string m_msg;
                                FileException(std::string const& file, const int& line, std::string const& func,
                                              std::string const& error) : m_file(file), m_line(line), m_func(func),
                                m_error(error) {
                                    char strLine[10];
                                    sprintf(strLine, "%d", line);
                                    m_msg = "文件：" + file + "\n行号：" + strLine + "\n函数：" + func + "\n错误："
                                    + error + "\n";
                                }
                                char const* what(void) const throw () {
                                    return m_msg.c_str();
                                }
                            };
                            class MemoryException : public std::exception {
                            public:
                                MemoryException(std::string const& msg) : m_msg(msg) {
                                }
                                char const* what(void) const throw () {
                                    return m_msg.c_str();
                                }
                                std::string m_msg;
                            };
                            class Human {
                            private:
                                std::string m_address;
                                char* m_name;
                            public:
                                Human(std::string const& address, char const* name) : m_address(address) {
                                    if (!(m_name = (char*)malloc(strlen(name ? name : "") + 1)))
                                        throw MemoryException(strerror(errno));
                                }
                                ~Human(void) {
                                    free(m_name);
                                    FILE* fp = fopen("/etc/server.cfg", "w");
                                    if (fp == NULL) {
                                        try {
                                            throw FileException(__FILE__, __LINE__, __FUNCTION__, std::strerror(errno));
                                        } catch (std::exception& ex) {
                                            std::cerr << ex.what() << std::endl;
                                        }
                                    } else {
                                        //保存数据
                                    }
                                }
                            };
                            int main(int argc, const char* argv[]) {
                                try {
                                    Human human("江苏南京市", "ZhangSan");
                                } catch (std::exception& ex) {
                                    std::cerr << ex.what() << std::endl;
                                }
                                return 0;
                            }
                            上述代码中，以下代码：
                            ~Human(void) {
                                free(m_name);
                                FILE* fp = fopen("/etc/server.cfg", "w");
                                if (fp == NULL) {
                                    try {
                                        throw FileException(__FILE__, __LINE__, __FUNCTION__, std::strerror(errno));
                                    } catch (std::exception& ex) {
                                        std::cerr << ex.what() << std::endl;
                                    }
                                } else {
                                    //保存数据
                                }
                            }
                            定义了类Human的析构函数。此时执行任何可能引发异常的操作，如下语句：
                            FILE* fp = fopen("/etc/server.cfg", "w");
                            if (fp == NULL) {
                                try {
                                    throw FileException(__FILE__, __LINE__, __FUNCTION__, std::strerror(errno));
                                } catch (std::exception& ex) {
                                    std::cerr << ex.what() << std::endl;
                                }
                            }
                            都尽量把异常在内部消化掉，防止其从析构函数中被继续抛出。
                            
                            18 继承标准异常
                            18.1 问题
                            抛出标准库异常，或标准库异常的子类异常，以允许用户以与标准库一致的方式捕获该异常。
                            18.2 步骤
                            实现此案例需要按照如下步骤进行。
                            步骤一：继承标准异常
                            代码如下：
#include <iostream>
                            class FileException : public std::exception {
                            public:
                                FileException(std::string const& msg) : m_msg(msg) {
                                }
                                char const* what(void) const throw () {
                                    return m_msg.c_str();
                                }
                                std::string m_msg;
                            };
                            int connectServer(const char* config) throw (FileException) {
                                FILE* fp = fopen(config, "r");
                                if (fp == NULL)
                                    throw FileException(config);
                                //其他操作
                                return 0;
                            }
                            int main(int argc, const char* argv[]) {
                                try {
                                    connectServer("/etc/server.cfg");
                                } catch (std::exception& ex) {
                                    std::cerr << ex.what() << std::endl;
                                    exit(-1);
                                }
                                return 0;
                            }
                            上述代码中，以下代码：
                            class FileException : public std::exception {
                            public:
                                FileException(std::string const& msg) : m_msg(msg) {
                                }
                                char const* what(void) const throw () {
                                    return m_msg.c_str();
                                }
                                std::string m_msg;
                            };
                            定义了标准库异常类exception的子类异常类FileException。
                            上述代码中，以下代码：
                            int connectServer(const char* config) throw (FileException) {
                                FILE* fp = fopen(config, "r");
                                if (fp == NULL)
                                    throw FileException(config);
                                //其他操作
                                return 0;
                            }
                            在函数connectServer中如果打开文件失败，则抛出异常类FileException的对象。
                            上述代码中，以下代码：
                            catch (std::exception& ex) {
                                std::cerr << ex.what() << std::endl;
                                exit(-1);
                            }
                            在主程序中，使用catch捕捉标准库异常类exception类型的异常。以允许用户以与标准库一致的方式捕获该异常。
                            
                            19 打开关闭I/O流
                            19.1 问题
                            流(Stream)是指字节序列形式的数据，有如流水一般，从一个对象流向另一个对象。流分为输入流(Input Stream)和输出流(Output Stream)，输入流是指数据字节从表示输入设备(如键盘、磁盘文件等)的对象流向内存对象，输出流是指数据字节从内存对象流向表示输出设备(如显示器、打印机、磁盘文件等)的对象。
                            19.2 步骤
                            实现此案例需要按照如下步骤进行。
                            步骤一：打开关闭I/O流
                            代码如下：
#include <iostream>
#include <fstream>
                            int main(int argc, const char* argv[]) {
                                std::ofstream file1;
                                file1.open("server.cfg", std::ios::out);
                                file1 << "Hello";
                                file1.close();
                                std::ifstream file2("server.cfg", std::ios::in);
                                char str[100];
                                file2 >> str;
                                std::cout << str << std::endl;
                                file2.close();
                                std::fstream file3;
                                file3.open("server1.cfg", std::ios::in | std::ios::out | std::ios::trunc);
                                file3 << "world";
                                file3.seekp(std::ios::beg);
                                file3 >> str;
                                std::cout << str << std::endl;
                                return 0;
                            }
                            上述代码中，以下代码：
                            std::ofstream file1;
                            定义了一个输出流对象。
                            上述代码中，以下代码：
                            file1.open("server.cfg", std::ios::out);
                            使用类std::ofstream的成员函数open打开一个文件。成员函数open的第一个参数是文件名，第二个参数是打开模式，打开模式有以下几种：
                            1)ios::in打开文件用于读取，不存在则失败，存在不清空。适用于ifstream(缺省)/fstream。
                            2)ios::out打开文件用于写入，不存在则创建，存在则清空。适用于ofstream(缺省)/fstream。
                            3)ios::app打开文件用于追加，不存在则创建，存在不清空。适用于ofstream/fstream。
                            4)ios::trunc打开时清空原内容，适用于ofstream/fstream。
                            5)ios::ate打开时定位文件尾，适用于ifstream/ofstream/fstream。
                            6)ios::binary以二进制模式读写，适用于ifstream/ofstream/fstream。
                            上述代码中，以下代码：
                            file1 << "Hello";
                            向文件中写入一个字符串。
                            上述代码中，以下代码：
                            file1.close();
                            使用类std::ofstream的成员函数close关闭对象file1中打开的文件。
                            上述代码中，以下代码：
                            std::ifstream file2("server.cfg", std::ios::in);
                            定义了一个输入流对象，使用类std::ifstream的构造函数打开一个文件。成员函数open的第一个参数是文件名，第二个参数是打开模式。
                            上述代码中，以下代码：
                            char str[100];
                            file2 >> str;
                            std::cout << str << std::endl;
                            从文件中读入字符串。
                            上述代码中，以下代码：
                            std::fstream file3;
                            定义了一个输入输出流对象。
                            上述代码中，以下代码：
                            file3.open("server1.cfg", std::ios::in | std::ios::out | std::ios::trunc);
                            file3 << "world";
                            file3.seekp(std::ios::beg);
                            file3 >> str;
                            std::cout << str << std::endl;
                            使用类std::fstream的成员函数open打开一个文件，打开模式可以组合使用。
                            上述代码中，以下代码：
                            file3 << "world";
                            向文件中写入一个字符串。
                            上述代码中，以下代码：
                            file3.seekp(std::ios::beg);
                            file3 >> str;
                            std::cout << str << std::endl;
                            使用类std::fstream的成员函数seekp，将文件指针指向文件的开始。上面写入字符串“world”后，文件指针指向字符d的后面，此句话将文件指针指向字符w。
                            上述代码中，以下代码：
                            file3 >> str;
                            std::cout << str << std::endl;
                            从文件中读入字符串。值得注意的是，此语句后没有使用类std::fstream的成员函数close关闭流对象file3。这是允许的，当file3的作用域结束时，类std::fstream的析构函数也会关闭流对象。
                            
                            20 判断I/O流的状态
                            20.1 问题
                            I/O流类内部维护当前状态，其值为以下常量的位或，ios::goodbit表示一切正常，ios::badbit表示发生致命错误，ios::eofbit表示遇到文件尾，ios::failbit表示实际读写字节数未达预期。I/O流类支持到bool类型的隐式转换，发生致命错误或遇到文件尾，返回false，否则返回true，将I/O流对象直接应用到布尔上下文中，即可实现转换。处于致命错误或文件尾状态的流，在复位前无法工作。
                            20.2 步骤
                            实现此案例需要按照如下步骤进行。
                            步骤一：判断I/O流的状态
                            代码如下：
#include <iostream>
#include <fstream>
                            int main(int argc, const char* argv[]) {
                                std::ifstream file("server.cfg", std::ios::in);
                                if (! file) {
                                    std::cout << std::boolalpha;
                                    std::cout << "ios::goodbit = " << file.good() << std::endl;
                                    std::cout << "ios::badbit = " << file.bad() << std::endl;
                                    std::cout << "ios::eofbit = " << file.eof() << std::endl;
                                    std::cout << "ios::failbit = " << file.fail() << std::endl;
                                    std::cout << "打开文件失败！" << std::endl;
                                    file.clear();
                                    file.open("client.cfg");
                                    if (! file) {
                                        std::cout << "打开文件失败！" << std::endl;
                                        exit(-1);
                                    }
                                }
                                char str[100];
                                file >> str;
                                std::cout << str << std::endl;
                                return 0;
                            }
                            上述代码中，以下代码：
                            std::ifstream file("server.cfg", std::ios::in);
                            if (! file) {
                                将I/O流对象file直接应用到布尔上下文if(！file)中，即可实现到bool类型的隐式转换, 发生致命错误或遇到文件尾，返回false，否则返回true。
                                    上述代码中，以下代码：
                                    std::cout << "ios::goodbit = " << file.good() << std::endl;
                                std::cout << "ios::badbit = " << file.bad() << std::endl;
                                std::cout << "ios::eofbit = " << file.eof() << std::endl;
                                std::cout << "ios::failbit = " << file.fail() << std::endl;
                                获取I/O流类内部维护当前状态，file.good()当流可用且状态位全零时返回true，file.bad()返回badbit位被设置否，badbit表示发生致命错误，file.eof()返回eofbit位被设置否，eofbit表示遇到文件尾，file.fail()返回badbit或failbit位被设置否，failbit表示实际读写字节数未达预期。
                                上述代码中，以下代码：
                                file.clear ();
                                处于致命错误或文件尾状态的流，在复位前无法工作。类std::ifstream的成员函数clear负责复位流状态。
                                
                                21 通过流函数格式化I/O流
                                21.1 问题
                                I/O流类(ios)定义了一组用于控制输入输出格式的公有成员函数，调用这些函数可以改变I/O流对象内部的格式状态，进而影响后续输入输出的格式化方式，一般而言，对I/O流格式的改变都是持久的，即只要不再设置新格式，当前格式将始终保持下去，但是显示域宽是个例外，通过ios::width(int)所设置的显示域宽，只影响紧随其后的第一次输出，再往后的输出又恢复到默认状态。
                                21.2 步骤
                                实现此案例需要按照如下步骤进行。
                                步骤一：通过流函数格式化I/O流
                                代码如下：
#include <iostream>
#include <cmath>
                                int main(int argc, const char* argv[]) {
                                    std::cout.precision(10);
                                    std::cout << sqrt(200) << std::endl;
                                    std::cout << std::cout.precision() << std::endl;
                                    std::cout.width(10);
                                    std::cout.fill('-');
                                    std::cout.setf(std::ios::internal, std::ios::adjustfield);
                                    std::cout.setf(std::ios::showpos);
                                    std::cout << 12345 << std::endl;
                                    return 0;
                                }
                                上述代码中，以下代码：
                                std::cout.precision (10);
                                设置浮点数的精度值，返回原精度。
                                上述代码中，以下代码：
                                std::cout << std::cout.precision () << std::endl;
                                获取当前浮点精度。
                                上述代码中，以下代码：
                                std::cout.width (10);
                                设置显示域宽，返回原域宽。当设置的域宽小于实际域宽时，按实际域宽显示，大于实际域宽时，默认用空格填补。也可以用下述函数指定填补字符：
                                std::cout.fill ('-');
                                上述代码中，以下代码：
                                std::cout.setf (std::ios::internal, std::ios::adjustfield);
                                第一个参数用于添加指定格式标志位std::ios::internal，该格式标志表示数值右对齐，符号左对齐，第二个参数将互斥域清零。函数返回原标志。
                                std::cout.setf (std::ios::showpos);
                                用于添加指定格式标志位std::ios::showpos，该格式标志表示正整数前面显示+号。
                                
                                22 通过流控制符格式化I/O流
                                22.1 问题
                                标准库提供了一组特殊的全局函数，它们有的带有参数(在iomanip头文件中声明)，有的不带参数(在iostream头文件中声明)，可被直接嵌入到输入输出表达式中，影响后续输入输出格式，称为流控制符。
                                22.2 步骤
                                实现此案例需要按照如下步骤进行。
                                步骤一：通过流控制符格式化I/O流
                                代码如下：
#include <iostream>
#include <iomanip>
#include <cmath>
                                int main(int argc, const char* argv[]) {
                                    std::cout << std::setprecision(10) << sqrt(200) << std::endl;
                                    std::cout << std::scientific << sqrt(200) << std::endl;
                                    std::cout << std::setw(10) << std::setfill('-') << std::internal << std::showpos
                                    << 12345 << std::endl;
                                    return 0;
                                }
                                上述代码中，以下代码：
                                std::cout << std::setprecision (10) << sqrt (200) << std::endl;
                                通过流控制符std::setprecision (10)设置200的平方根输出的浮点精度。
                                上述代码中，以下代码：
                                std::cout << std::scientific << sqrt (200) << std::endl;
                                通过流控制符std::scientific设置200的平方根输出用科学计数法表示。
                                上述代码中，以下代码：
                                std::cout << std::setw (10) << std::setfill ('-') << std::internal << std::showpos << 12345 << std::endl;
                                通过流控制符std::setw (10)设置域宽为10，通过流控制符std::setfill ('-')设置用字符-作为填充字符使用，通过流控制符std::internal设置数值右对齐但符号左对齐，通过流控制符std::showpos设置正整数前面显示+号，经过以上设置后，整型数12345输出结果为+----12345。
                                
                                23 设置字符颜色的流控制符
                                23.1 问题
                                C++允许程序员重载流控制符，以定义自己指定功能的流控制符。
                                23.2 步骤
                                实现此案例需要按照如下步骤进行。
                                步骤一：设置字符颜色的流控制符
                                代码如下：
#include <iostream>
#include <iomanip>
                                std::ostream& color(std::ostream& o) {
                                    const int foreColor = 37;
                                    const int backColor = 40;
                                    return o << "\x1b[" << foreColor << ";" << backColor << "m";
                                }
                                int main(int argc, const char* argv[]) {
                                    std::cout << color << "HelloWorld" << std::endl;
                                    return 0;
                                }
                                上述代码中，以下代码：
                                std::ostream& color(std::ostream& o) {
                                    const int foreColor = 37;
                                    const int backColor = 40;
                                    return o << "\x1b[" << foreColor << ";" << backColor << "m";
                                }
                                定义自己指定功能的流控制符color，用于改变Unix控制台字体颜色。其中前景色foreColor可选的范围为30: 黑，31: 红，32: 绿，33: 黄，34: 蓝，35: 紫，36: 深绿，37: 白色；背景色backColor可选的范围为：40: 黑，41: 红，42: 绿，43: 黄，44: 蓝，45: 紫，46: 深绿，47: 白色。
                                上述代码中，以下代码：
                                std::cout << color << "HelloWorld" << std::endl;
                                通过流控制符color设置后续现实的字符串颜色。
                                
                                24 非格式化I/O
                                24.1 问题
                                iostream类提供了许多库函数，用于处理非格式化I/O操作。
                                24.2 步骤
                                实现此案例需要按照如下步骤进行。
                                步骤一：非格式化I/O
                                代码如下：
#include <iostream>
                                int main(int argc, const char* argv[]) {
                                    char c;
                                    c = std::cin.get();
                                    std::cout << c << std::endl;
                                    if (std::cin.get(c))
                                        std::cout << c << std::endl;
                                    char str[10] = {};
                                    if (std::cin.get(str, 10, '#'))
                                        std::cout << str << std::endl;
                                    if (std::cin.getline(str, 10, '#'))
                                        std::cout << str << std::endl;
                                    std::cin.putback('c');
                                    c = std::cin.get();
                                    std::cout << c << std::endl;
                                    std::cin.putback('c');
                                    c = std::cin.peek();
                                    std::cout << c << std::endl;
                                    c = std::cin.get();
                                    std::cout << c << std::endl;
                                    std::cin.ignore(5, '#');
                                    if (std::cin.get(str, 10, '#'))
                                        std::cout << str << std::endl;
                                    if (std::cin.get(str, 10, '#'))
                                        std::cout << str << std::endl;
                                    std::cout << std::cin.gcount() << std::endl;
                                    std::cout.put('a');
                                    std::cout.flush();
                                    return 0;
                                }
                                上述代码中，以下代码：
                                char c;
                                c = std::cin.get();
                                std::cout << c << std::endl;
                                使用类iostream库函数int get(void)读取一个字符。
                                上述代码中，以下代码：
                                if (std::cin.get(c))
                                    std::cout << c << std::endl;
                                使用类iostream库函数iostream& get(char&c)读取一个字符，返回输入流本身，其在布尔上下文中的值，成功为true，失败或遇到文件尾为false。
                                上述代码中，以下代码：
                                char str[10] = {};
                                if (std::cin.get(str, 10, '#'))
                                    std::cout << str << std::endl;
                                使用类iostream库函数istream& istream::get (char* buffer, streamsize num, char delim = '\n')读取字符到buffer中，直到读满num-1个字符，或遇到文件尾，或遇到定界符delim(缺省为换行符)，追加结尾空字符，返回流本身。
                                上述代码中，以下代码：
                                if (std::cin.getline(str, 10, '#'))
                                    std::cout << str << std::endl;
                                使用类iostream库函数istream& istream::getline (char* buffer,streamsize num, char delim = '\n') 读取字符到buffer中，直到读满num-1个字符，或遇到文件尾，或遇到定界符delim(缺省为换行符)，追加结尾空字符，返回流本身。
                                上述代码中，以下代码：
                                std::cin.putback('c');
                                c = std::cin.get();
                                std::cout << c << std::endl;
                                使用类iostream库函数istream& istream::putback (char ch) 将字符ch放回输入流，返回流本身。
                                上述代码中，以下代码：
                                std::cin.putback('c');
                                c = std::cin.peek();
                                std::cout << c << std::endl;
                                c = std::cin.get();
                                std::cout << c << std::endl;
                                使用类iostream库函数int istream::peek (void)返回但不读取读指针当前位置处的字符，失败或遇到文件尾返回EOF。
                                上述代码中，以下代码：
                                std::cin.ignore(5, '#');
                                if (std::cin.get(str, 10, '#'))
                                    std::cout << str << std::endl;
                                使用类iostream库函数istream& istream::ignore (streamsize num = 1,int delim = EOF) 忽略输入流中的num(缺省1)个字符，或遇到定界符delim(缺省到文件尾)，返回流本身。
                                上述代码中，以下代码：
                                if (std::cin.get(str, 10, '#'))
                                    std::cout << str << std::endl;
                                std::cout << std::cin.gcount() << std::endl;
                                使用类iostream库函数streamsize istream::gcount (void) 返回最后一次从输入流中读取的字节数。
                                上述代码中，以下代码：
                                std::cout.put('a');
                                使用类iostream库函数ostream& ostream::put (char ch) 一次向输出流写入一个字符，返回流本身。
                                上述代码中，以下代码：
                                std::cout.flush();
                                使用类iostream库函数ostream& ostream::flush (void) 将输出流缓冲区中的数据刷到设备上，返回流本身。
                                
                                25 文件复制
                                25.1 问题
                                通过iostream类提供了二进制数据读写方法，先将一个文件读入内存，再将内存中的数据写回磁盘，实现文件复制。
                                25.2 步骤
                                实现此案例需要按照如下步骤进行。
                                步骤一：文件复制
                                代码如下：
#include <iostream>
#include <fstream>
                                int main(int argc, const char* argv[]) {
                                    std::ifstream file("server.cfg", std::ios::in | std::ios::binary);
                                    if (! file) {
                                        std::cout << "打开文件失败！" << std::endl;
                                        exit(-1);
                                    }
                                    std::ofstream fileCopy("server副本.cfg", std::ios::out | std::ios::binary);
                                    if (! fileCopy) {
                                        std::cout << "打开文件失败！" << std::endl;
                                        exit(-1);
                                    }
                                    char buffer[1025] = {};
                                    while (!file.eof()) {
                                        file.read(buffer, 1024);
                                        size_t size = file.gcount();
                                        fileCopy.write(buffer, size);
                                    }
                                    return 0;
                                }
                                上述代码中，以下代码：
                                std::ifstream file("server.cfg", std::ios::in | std::ios::binary);
                                if (! file) {
                                    std::cout << "打开文件失败！" << std::endl;
                                    exit(-1);
                                }
                                打开要被复制的源文件。
                                上述代码中，以下代码：
                                std::ofstream fileCopy("server副本.cfg", std::ios::out | std::ios::binary);
                                if (! fileCopy) {
                                    std::cout << "打开文件失败！" << std::endl;
                                    exit(-1);
                                }
                                打开要被复制的目标文件。
                                char buffer[1025] = {};
                                
                                while (!file.eof()) {
                                    file.read(buffer, 1024);
                                    size_t size = file.gcount();
                                    fileCopy.write(buffer, size);
                                }
                                设置循环，每次赋值1024个字节，直到源文件被复制完成。值得注意的是以下语句：
                                size_t size = file.gcount();
                                如果源文件本身就小于1024个字节，那么实际读取到buffer的字符就不是1024，所以需要通过该语句获取实际读入的字节数，以正确写入目标文件。这种情况还发生在源文件一般不会是1024个字节的整数倍，那么最后一次读取了多少个字节，也需要通过该语句获得。
                                
                                26 随机读写
                                26.1 问题
                                通过iostream类提供的文件指针获取设置函数，可以随机读写文件中的内容。
                                26.2 步骤
                                实现此案例需要按照如下步骤进行。
                                步骤一：随机读写
                                代码如下：
#include <iostream>
#include <fstream>
                                int main(int argc, const char* argv[]) {
                                    std::ofstream file("server.cfg", std::ios::out | std::ios::binary);
                                    if (! file) {
                                        std::cout << "打开文件失败！" << std::endl;
                                        exit(-1);
                                    }
                                    int buffer[10] = {100, 200, 300, 400, 500, 600, 700, 800, 900, 1000};
                                    file.write((char*)buffer, sizeof(buffer));
                                    file.close();
                                    std::ifstream file1("server.cfg", std::ios::in | std::ios::binary);
                                    if (! file) {
                                        std::cout << "打开文件失败！" << std::endl;
                                        exit(-1);
                                    }
                                    int number;
                                    file1.seekg(2 * sizeof(int));
                                    file1.read((char*)&number, sizeof(int));
                                    std::cout << number << std::endl;
                                    std::streamoff pos = file1.tellg();
                                    file1.seekg(pos + 3 * sizeof(int));
                                    file1.read((char*)&number, sizeof(int));
                                    std::cout << number << std::endl;
                                    return 0;
                                }
                                上述代码中，以下代码：
                                std::ofstream file("server.cfg", std::ios::out | std::ios::binary);
                                if (! file) {
                                    std::cout << "打开文件失败！" << std::endl;
                                    exit(-1);
                                }
                                int buffer[10] = {100, 200, 300, 400, 500, 600, 700, 800, 900, 1000};
                                file.write((char*)buffer, sizeof(buffer));
                                file.close();
                                用二进制方式在server.cfg中存储了10个整型数。
                                上述代码中，以下代码：
                                std::ifstream file1("server.cfg", std::ios::in | std::ios::binary);
                                if (! file) {
                                    std::cout << "打开文件失败！" << std::endl;
                                    exit(-1);
                                }
                                int number;
                                file1.seekg(2 * sizeof(int));
                                利用类ifstream中的成员函数seekg将文件指针直接定位到第三个整数，第一个整数的位置是文件开头，即0，第二个整数的位置是sizeof（int），即4，因为一个整数按二进制方式存储占4个字节，依次类推，第三个整数的位置就是2 * sizeof(int)，即8。
                                上述代码中，以下代码：
                                file1.read((char*)&number, sizeof(int));
                                std::cout << number << std::endl;
                                直接读取第三个整数。
                                上述代码中，以下代码：
                                std::streamoff pos = file1.tellg();
                                file1.seekg(pos + 3 * sizeof(int));
                                file1.read((char*)&number, sizeof(int));
                                利用类ifstream中的成员函数tellg获得文件指针的当前位置，因为上面直接读取了第三个整数，所以得到的当前位置是第四个整数的位置。
                                上述代码中，以下代码：
                                file1.seekg(pos + 3 * sizeof(int));
                                file1.read((char*)&number, sizeof(int));
                                再通过seekg函数将文件指针向后移动3个整数，读取的就是第七个整数。
                                
                                27 字符串流
                                27.1 问题
                                C++引入了ostringstream、istringstream、stringstream这三个类。istringstream类用于执行串流的输入操作，ostringstream类用于执行串流的输出操作，strstream类同时可以支持串流的输入输出操作。
                                27.2 步骤
                                实现此案例需要按照如下步骤进行。
                                步骤一：字符串流
                                代码如下：
#include <iostream>
#include <sstream>
                                int main(int argc, const char* argv[]) {
                                    std::string is("1234 56.78 ABCD");
                                    std::istringstream iss(is);
                                    int i;
                                    double d;
                                    std::string s;
                                    iss >> i >> d >> s;
                                    std::cout << i << "," << d << "," << s << std::endl;
                                    std::ostringstream oss;
                                    oss << 1234 << ' ' << 56.78 << ' ' << "ABCD";
                                    std::string os = oss.str();
                                    std::cout << os << std::endl;
                                    return 0;
                                }
                                上述代码中，以下代码：
                                std::string is ("1234 56.78 ABCD");
                                std::istringstream iss (is);
                                定义了一个输入字符串流类std::istringstream的对象iss，并初始化成字符串is。注意构造字符串流的时候，字符串is中空格会成为字符串参数的内部分界。
                                上述代码中，以下代码：
                                iss >> i >> d >> s;
                                是对int变量i、double变量d和string对象s的输入赋值操作，字符串is中空格分割出了三个变量值。
                                上述代码中，以下代码：
                                std::ostringstream oss;
                                oss << 1234 << ' ' << 56.78 << ' ' << "ABCD";
                                定义了一个输出字符串流类std::ostringstream的对象oss，然后将int常量1234、double常量56.78和字符串"ABCD"三个数据用空格分开，插入到对象oss中。
                                上述代码中，以下代码：
                                std::string os = oss.str ();
                                std::cout << os << std::endl;
                                可以通过输出字符串流类std::ostringstream的成员函数str，获取对象oss中保存的字符串流。
                                
                                
