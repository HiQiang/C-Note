# 关于 指向指针的指针

```c++
int * a1 = new int;
*a1 = 1;
int * a2 = new int;
*a2 = 2;
//在堆区分配两个int变量类型的空间
//分别由指针a1 和 a2 指向，并将对应空间的值设置为1和2

int ** b = new int*[10];
//在堆区分配一个10维array的空间，其中每个元素都是 int * 类型
//即每个元素都是指向int的指针
//但是此时，并不知道该指针指向哪里
//b就是指向该10维指针数组的指针
//b的值是该指针数组的首地址

b[0] = a1;
//因为b指向数组，此处可以按照数组的索引进行赋值
//将该指针数组的第一个元素赋值为a1
//此处a1是一个int * 类型
//解决了该指针指向哪里的问题

b[1] = a2;
cout << *b[0]<<endl;
cout << *b[1]<<endl;

//与常规数组对比
int intArray[10];
intArray[0]=1;
intArray[1]=2;
cout<<intArray[0]<<endl;
cout<<intArray[1]<<endl;
cout<<intArray<<endl;

//本例子没有delete new分配的空间

//输出：
//1
//2
//1
//2
//0x712625ba57a0
```

###### 以下代码可以直接粘贴运行

```c++
// Example program
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int * a1 = new int;
    *a1 = 1;

    int * a2 = new int;
    *a2 = 2;

    int** b = new int*[10];
    b[0] = a1;
    b[1] = a2;
    cout << *b[0]<<endl;
    cout << *b[1]<<endl;
    
    int intArray[10];
    intArray[0]=1;
    cout<<intArray[0]<<endl;
    cout<<intArray<<endl;

    return 0;
}
```

