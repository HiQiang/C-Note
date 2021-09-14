#include<iostream>
using namespace std;

//深拷贝与浅拷贝

class Person {
public:
	int m_Age;
	int* m_Height;
	Person():m_Age(0),m_Height(new int(0))
	{
		cout << "Person的默认构造函数调用" << endl;
	}
	Person(int age, int height) :m_Age(age),m_Height(new int(height))
	{
		cout << "Person的有参构造函数调用" << endl;
	}
	//自己实现拷贝构造函数解决浅拷贝带来的问题
	Person(const Person& p)
	{
		this->m_Age = p.m_Age;
		this->m_Height = new int(*p.m_Height);
	}
	~Person()
	{
		//浅拷贝带来的问题，堆区的内存被重复释放
		
		if (m_Height != NULL)
		{
			delete m_Height;
			m_Height = NULL;
		}
		
		cout << "Person的析构函数的调用" << endl;
	}
};
void test01()
{
	Person p1(18, 160);
	cout << "p1的年龄为：" << p1.m_Age << "身高为：" << *p1.m_Height << endl;
	Person p2(p1);
	cout << "p2的年龄为：" << p2.m_Age << "身高为：" << *p2.m_Height << endl;

	p1.m_Age = 28;
	*p1.m_Height = 260;
	
	cout << "p1的年龄为：" << p1.m_Age << "身高为：" << *p1.m_Height << endl;
	cout << "p2的年龄为：" << p2.m_Age << "身高为：" << *p2.m_Height << endl;

}
int main() 
{
	test01();
	return 0;
}
