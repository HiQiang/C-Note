#include<iostream>
using namespace std;
//关于Qt的笔记
/*
myWidget::myWidget(QWidget *parent)
    : QWidget(parent)
{
}
*/
//继承时
//先调用父类构造函数
//再调用子类构造函数
//析构顺序相反

//继承时，若未指定父类构造函数
//则调用父类的无参构造函数（存在有参构造函数，因此不存在默认构造函数）
//继承时，若指定了父类构造函数（本例按照列表初始化方法调用父类构造函数）
//则调用该指定的父类构造函数

class Base {
public:
	int m_Num;
	Base() :m_Num(0)
	{
		cout << "Base 无参构造函数" << endl;
	}
	Base(int num) :m_Num(num)
	{
		cout << "Base 有参构造函数" << endl;
	}
	~Base()
	{
		cout << "Base 析构函数" << endl;
	}
};

class Son :public Base {
public:
	int m_SonNum;
	Son() :m_SonNum(0)
	{
		cout << "Son 无参构造函数" << endl;
	}
	Son(int num) :m_SonNum(num)
	{
		cout << "Son 有参构造函数" << endl;
	}
	~Son()
	{
		cout << "Son 析构函数" << endl;
	}
};

class Son2 :public Base {
public:
	int m_SonNum;
	Son2() :m_SonNum(0)
	{
		cout << "Son2 无参构造函数" << endl;
	}
	Son2(int num) :Base(num),m_SonNum(0)
	{
		cout << "Son2 调用父类有参构造函数,并且m_SonNum默认初始化为0" << endl;
	}
	Son2(int num, int s_num) :Base(num), m_SonNum(s_num)
	{
		cout << "Son2 调用父类有参构造函数,并同时初始化m_SonNum" << endl;
	}
	~Son2() {
		cout << "Son2 析构函数" << endl;
	}
};

void test01()
{
	Son s;
	cout << "s.m_Num = " << s.m_Num << endl;
	cout << "s.m_SonNum = " << s.m_SonNum << endl;

};

void test02()
{
	Son s(10);
	cout << "s.m_Num = " << s.m_Num << endl;
	cout << "s.m_SonNum = " << s.m_SonNum << endl;

};

void test03() {
	Son2 s(10);
	cout << "s.m_Num = " << s.m_Num << endl;
	cout << "s.m_SonNum = " << s.m_SonNum << endl;
}
void test04() {
	Son2 s(10, 100);
	cout << "s.m_Num = " << s.m_Num << endl;
	cout << "s.m_SonNum = " << s.m_SonNum << endl;
}

int main()
{
	test01();

	cout << "\n*********" << endl;
	test02();

	cout << "\n*********" << endl;
	test03();

	cout << "\n*********" << endl;
	test04();
	return 0;
}
