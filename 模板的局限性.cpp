#include<iostream>
using namespace std;

//模板的局限性
//模板不是万能的，有些特定的数据类型，需要用具体化方式做特殊实现

//对比两个数据是否相等的函数
class Person {
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	//姓名
	string m_Name;
	//年龄
	int m_Age;
};

template<class T>
bool myCompare(T& a, T& b)
{
	if (a == b)
	{
		return true;
	}
	else {
		return false;
	}
}

//利用具体化的Person的版本实现代码，具体化优先调用

template<> bool myCompare(Person & a, Person & b) 
{
	if (a.m_Name == b.m_Name && a.m_Age == b.m_Age)
	{
		return true;
	}
	else
	{
		return false;
	}
}


void test01()
{
	int a = 10;
	int b = 10;
	bool ret = myCompare(a, b);
	if (ret == true)
	{
		cout << "相等" << endl;
	}
	else {
		cout << "不相等" << endl;
	}
}

void test02()
{
	Person p1("Tom", 10);
	Person p2("Tom", 10);
	bool ret = myCompare(p1, p2);
	if (ret == true)
	{
		cout << "p1==p2" << endl;
	}
	else
	{
		cout << "p1!=p2" << endl;
	}
}


int main()
{
	test01();
	test02();
	return 0;
}
