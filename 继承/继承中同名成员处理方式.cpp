#include<iostream>
using namespace std;
//继承中同名成员处理方式
//直接调用：调用的是子类的同名成员
//s.Base::func(),加上父类作用域后，调用父类成员
//若子类中出现和父类同名的成员函数，子类中的同名成员会隐藏掉父类中所有同名成员函数
//若想访问父类中同名的成员函数，需要加作用域
class Base 
{
public: 
	int m_A;
	Base()
	{
		m_A = 100;
	}
	void func()
	{
		cout << "Base func" << endl;
	}
};
class Son : public Base
{
public:
	Son()
	{
		m_A = 200;
	}
	void func()
	{
		cout << "Son func" << endl;
	}
	int m_A;
};
//同名成员属性
void test01()
{
	Son s;
	cout << "Son m_A: " << s.m_A << endl;
	cout << "s.Base::m_A: " << s.Base::m_A << endl;
}
//同名成员函数
void test02()
{
	Son s;
	s.func();
	s.Base::func();
}
int main()
{
	test01();
	test02();
	return 0;
}
