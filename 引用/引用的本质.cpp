#include <iostream>
using namespace std;



int main()
{
    int a = 10;
    int& ref = a;//自动转换为int* const ref = &a;
                 //指针常量是指针指向不可改、也说明为什么y引用不可更改
    ref = 20;    //内部自动转换为 *ref = 20

    std::cout << "Hello World!\n";
}
