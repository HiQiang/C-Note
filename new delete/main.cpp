#include <iostream>
using namespace std;


//1.new的基本语法
int* func()
{
    //在堆区创建整形数据
    //new返回的是 该数据类型的指针
    int* p = new int(10);
    return p;
}

void test01()
{
    int* p = func();
    cout << *p << endl;
    //堆区的数据由程序员管理开辟和释放
    delete p;
    //再次访问非法
    //cout << *p << endl;
}

void test02() {
    //在堆区创建10个整型数据类型的数组
    int * pArr = new int[10];
    for (int i = 0; i < 10; i++) {
        pArr[i] = i + 1;
        cout << pArr[i] << endl;
    }
    for (int i = 0; i < 10; i++) {
        *(pArr + i) = 10 - i;
        cout << pArr[i] << endl;
    }
}


int main()
{
    test01();
    test02();
    std::cout << "Hello World!\n";
}
