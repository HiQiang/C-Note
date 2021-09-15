#include<iostream>
using namespace std;
//纯虚函数和抽象类
//只要有一个纯虚函数，这个类称为抽象类
//1.抽象类无法实例化对象
//2.抽象类的子类必须重写抽象类中的纯虚函数
//否则也属于抽象类，无法实例化对象

class Base {
public:
	virtual void func() = 0;
};

class Son :public Base
{
public:
	virtual void func() {
		cout << "func()函数调用" << endl;
	};
};
void test01()
{
	Base* b = new Son;
	b->func();
}
int main()
{
	test01();
	return 0;
}
