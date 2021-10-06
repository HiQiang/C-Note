#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//常用的查找算法
//find

//查找 内置数据类型

void test01()
{
	vector<int> v;
	for (int i = 0; i < 10;i++)
	{
		v.push_back(i);
	}

	//查找容器中是否有5
	vector<int>::iterator it = find(v.begin(), v.end(), 5);
	if (it == v.end())
	{
		cout << "没有找到" << endl;
	}
	else
	{
		cout << "找到 " << *it << endl;
	}
}

//查找 自定义数据类型
class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	//重载 == 让底层 find 知道如何对比 Person 数据类型
	bool operator==(const Person& p)
	{
		if (this->m_Name == p.m_Name && this->m_Age == p.m_Age)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
;

	string m_Name;
	int m_Age;
};

void test02()
{
	vector<Person> v;
	Person p1("AA", 10);
	Person p2("BB", 20);
	Person p3("CC", 30);
	Person p4("DD", 40);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);

	Person pp("BB", 20);

	vector<Person>::iterator it = find(v.begin(), v.end(), pp);
	if (it == v.end())
	{
		cout << "没有找到" << endl;
	}
	else
	{
		cout << "找到 姓名："<< it->m_Name<<" 年龄："<<it->m_Age << endl;
	}
}
int main()
{
	test01();
	test02();
	return 0;
}
