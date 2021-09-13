#include <iostream>
using namespace std;
//交换

//传引用
void swap01(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

//传指针
void swap02(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int a = 10;
    int b = 20;
    cout << a << endl;
    cout << b << endl;
    swap01(a, b);
    cout << a << endl;
    cout << b << endl;
    swap02(&a,&b);
    cout << a << endl;
    cout << b << endl;
    std::cout << "Hello World!\n";
}
