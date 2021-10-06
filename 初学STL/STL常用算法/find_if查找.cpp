#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;

//find_if 按条件查找元素

class GreaterFive
{
public:
	bool operator()(int val)
	{
		return  val > 5;
	}
};

//查找内置数据类型
void test01()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	vector<int>:: iterator it = find_if(v.begin(), v.end(), GreaterFive());
	if (it == v.end())
	{
		cout << "未找到" << endl;
	}
	else
	{
		cout << "找到了：" << *it << endl;
	}
}

//查找自定义数据类型
class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	string m_Name;
	int m_Age;
};
class Greater20
{public:
	bool operator()(const Person &p1)
	{
		return p1.m_Age > 20;
	}
};


void test02()
{
	vector<Person> v;
	Person p1("AA", 20);
	Person p2("BB", 30);
	Person p3("CC", 30);
	Person p4("DD", 40);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	Person pp("BB", 20);

	//查找年龄大于20的人
	vector<Person>::iterator it = find_if(v.begin(), v.end(), Greater20());
	if (it == v.end())
	{
		cout << "未找到" << endl;
	}
	else
	{
		cout << "找到了 姓名:" << it->m_Name << " 年龄：" << it->m_Age << endl;
	}
}
int main()
{
	test01();
	test02();
	return 0;
}
