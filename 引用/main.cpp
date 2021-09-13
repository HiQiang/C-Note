#include <iostream>
using namespace std;
//引用：给变量取别名
//1.引用必须初始化
//2.引用初始化后不可以更改

int main()
{
    int a = 10;
    int& b = a;//
    cout << a << endl;
    cout << b << endl;
    b = 20;
    cout << a << endl;
    cout << b << endl;
    std::cout << "Hello World!\n";
}
