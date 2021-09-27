#include<iostream>
#include<string>
using namespace std;
//类模板基本语法
template<class NameType, class AgeType>

class Person
{
public:
	Person(NameType name,AgeType age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	NameType m_Name;
	AgeType m_Age;

	void shouPerson()
	{
		cout << this->m_Name<<" " << this->m_Age << endl;
	}
};

void test01()
{
	Person<string,int> p1("孙大圣",999);
	p1.shouPerson();
}


int main()
{
	test01();
	return 0;
}
