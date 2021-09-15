#include<iostream>
using namespace std;
//继承同名静态成员处理方式
class Base {
public:
	static int m_A;
	static void func() {
		cout << "Base func()" << endl;
	}
	
};
int Base::m_A = 100;

class Son : public Base {
public:
	static int m_A;
	static void func()
	{
		cout << "Son func()" << endl;
	}
};
int Son::m_A = 200;
//同名静态成员属性

void test01()
{
	//通过对象访问数据
	Son s;
	cout << s.m_A << endl;
	cout << s.Base::m_A << endl;
	//通过类名访问数据
	cout << Son::m_A << endl;
	//第一个::代表通过类名方式访问， 第二个::代表访问父类作用域下
	cout << Son::Base::m_A << endl;
	cout << Base::m_A << endl;
}
//同名静态成员函数
void test02()
{
	//通过对象访问
	Son s;
	s.func();
	s.Base::func();
	//通过类名访问
	Son::func();
	Son::Base::func();
}

int main()
{

	test01();
	test02();
	return 0;
}
