#include<iostream>
#include<string>
using namespace std;
//类对象作为类成员
//先构造类成员再构造类自身
//先析构类自身再析构类成员
//析构顺序与构造顺序相反
class Phone
{
public:
	string m_PName;
	Phone(string pName)
	{
		m_PName = pName;
		cout << "Phone类构造函数" << endl;
	}
};

class Person {
public:
	//姓名
	string m_Name;
	//手机
	Phone m_Phone;
	Person(string name, string pName):m_Name(name),m_Phone(pName)
	{
		cout << "Person类构造函数" << endl;
	}
};

void test01()
{
	Person p1("张三", "诺基亚");
	cout << p1.m_Phone.m_PName << endl;
}

int main()
{
	test01();
	return 0;
}
