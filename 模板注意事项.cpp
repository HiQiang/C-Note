#include<iostream>
using namespace std;

//函数模板注意事项

template<class T> //typename 可以替换成class
void mySwap(T &a, T &b) {
	T temp = a;
	a = b;
	b = temp;
}

//1.自动类型推导，必须推导出一致的数据类型，才可以使用
void test01()
{
	int a = 1;
	int b = 2;
	mySwap(a, b);
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;

	char c = 'c';
	//mySwap(a, c);//推导不出一致的T类型，不可使用
}


//2.模板必须要确定出T的数据类型，才可以使用
template<class T>
void func() {
	cout << "func调用" << endl;
}
void test02()
{
	//func();//编译器无法推导T的数据类型
	func<int>();
}
int main()
{
	test01();
	test02();
	return 0;
}
