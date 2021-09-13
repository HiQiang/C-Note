#include <iostream>
using namespace std;
//引用：给数据取别名

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
