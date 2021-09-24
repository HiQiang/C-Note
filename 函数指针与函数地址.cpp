#include<iostream>
using namespace std;
int func() {
	cout << "func调用" << endl;
	return 0;
}
int func2(int a)
{
	return a;
}
int main() {
	//函数指针
	//返回值类型 (*funcPointer) (对应函数的参数列表)
	//函数名是函数地址，&函数名也是函数地址
	int(*fp)();//*fp不加括号会报错
	fp = func;
	(*fp)();//*fp不加括号会报错
	cout << fp << endl;
	fp = &func;
	cout << fp << endl;
	cout << func << endl;
	cout << &func << endl;
	int (*fp2)(int);
	fp2 = func2;
	cout << (*fp2)(2) << endl;
}


