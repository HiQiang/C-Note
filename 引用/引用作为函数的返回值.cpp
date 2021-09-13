#include <iostream>
using namespace std;
//1.不要返回局部变量的引用
/*
int& test01() {
    int a = 10;
    return a;
    }
*/



//2.函数的调用可以作为左值
int& test02()
{
   static int a = 10;//静态变量，存放在全局区，全局区上的数据在程序结束后由系统释放
   return a;
}


int main()
{
    //引用做函数的返回值
    int& ref2 = test02();
    cout << ref2 << endl;
    cout << ref2 << endl;
    cout << ref2 << endl;
    test02() = 20;
    cout << ref2 << endl;

    std::cout << "Hello World!\n";
}
