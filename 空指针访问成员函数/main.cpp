#include<iostream>
using namespace std;
//空指针调用成员函数
class Person
{
public:
	int m_Age = 0;
	void showClassName()
	{
		cout << "this is Person class" << endl;
	}
	void showPersonAge()
	{
		cout << "age = " << this->m_Age << endl;
	}
};
void test01()
{
	Person* p = NULL;
	p->showClassName();

	//报错原因是因为传入的指针是为NULL
	//p->showPersonAge();
}
int main()
{
	test01();
	return 0;
}
