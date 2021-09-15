#include<iostream>
#include<string>
using namespace std;
//普通写法
class Calculator {
public:
	int getResult(string oper)
	{
		if (oper == "+")
		{
			return m_Num1 + m_Num2;
		}
		else if (oper == "*")
		{
			return m_Num1 * m_Num2;
		}
		else if (oper == "-")
		{
			return m_Num1 - m_Num2;
		}
	}
	//若想扩展新的功能，需要修改源码
	//在真实开发中 提倡 开闭原则
	//开闭原则：对扩展进行开放，对修进行关闭
	int m_Num1;
	int m_Num2;
};
void test01()
{
	Calculator c;
	c.m_Num1 = 10;
	c.m_Num2 = 10;
	cout << c.m_Num1 << "+" << c.m_Num2 << "=" << c.getResult("+") << endl;
	cout << c.m_Num1 << "-" << c.m_Num2 << "=" << c.getResult("-") << endl;
	cout << c.m_Num1 << "*" << c.m_Num2 << "=" << c.getResult("*") << endl;
}
//利用多态实现计算器
// 多态好处：
// 1.组织结构清晰
// 2.可读性强
// 3.对于前期和后期扩展维护性高
//实现计算器抽象类
class AbstractCalculator {
public:
	int m_A;
	int m_B;
	virtual int getResult()
	{
		return 0;
	}
};
//加法计算器类
class AddCalculator :public AbstractCalculator {
public:
	int getResult()
	{
		return m_A + m_B;
	}

};
class SubCalculator :public AbstractCalculator {
public:
	int getResult()
	{
		return m_A - m_B;
	}

};
class MulCalculator :public AbstractCalculator {
public:
	int getResult()
	{
		return m_A * m_B;
	}

};
class DivCalculator{};
void test02()
{
	//多态使用条件
	//父类指针或者引用指向子类对象
	AbstractCalculator* abc = new AddCalculator;
	abc->m_A = 10;
	abc->m_B = 10;
	cout << abc->m_A<< "+" <<abc->m_B <<"=" << abc->getResult() << endl;
	delete abc;

	
	abc = new SubCalculator;
	abc->m_A = 10;
	abc->m_B = 10;
	cout << abc->m_A << "-" << abc->m_B << "=" << abc->getResult() << endl;
	delete abc;

	
	abc = new MulCalculator;
	abc->m_A = 10;
	abc->m_B = 10;
	cout << abc->m_A << "*" << abc->m_B << "=" << abc->getResult() << endl;
	delete abc;

	abc = NULL;
}
int main()
{
	test01();
	test02();
	return 0;
}
