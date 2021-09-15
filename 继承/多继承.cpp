#include<iostream>
using namespace std;
class Base1 {
public:
	int m_A;
	Base1() :m_A(100)
	{

	}
};
class Base2
{public:
	int m_B;
	Base2():m_B(200)
	{

	}

};

//子类 需要继承Base1和Base2
class Son : public Base1, public Base2
{
public:
	Son()
	{
		int m_C=100;
		int m_D=100;
	}
	int m_C = 0;
	int m_D = 0;
};
void test01()
{
	Son s;
	cout << "size of Son: " <<sizeof(Son)<< " Byte(s)" << endl;
	cout << "m_A = " << s.m_A << endl;
}

int main()
{
	test01();
	return 0;
}
