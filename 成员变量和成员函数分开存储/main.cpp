#include<iostream>
using namespace std;

//成员变量和成员函数分开存储
//只有非静态成员变量才属于类的对象上
class Person
{
	int m_A;//非静态成员变量 属于类的对象上
	void func() {};//非静态成员函数 不属于类对象上
	static int m_B;//静态成员变量 不属于类对象上
	static void sFunc() {}; //静态成员变量 不属于类对象上
};
int Person::m_B = 10;

void test01()
{
	Person p;
	//空对象占用内存空间为：1
	//C++编译器会给每个空对象也分配一个字节空间，是为了区分空对象占内存的位置
	//每个空对象有一个独一无二的内存地址
	cout << "size of p = " << sizeof(p) << " Byte(s)" << endl;
}
void test02()
{
	Person p;
	cout << "size of p = " << sizeof(p) << " Byte(s)" << endl;
}
int main()
{
	test02();
	return 0;
}
