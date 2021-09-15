#include<iostream>
using namespace std;
//继承方式
//https://www.bilibili.com/video/BV1et411b73Z?p=128&spm_id_from=pageDriver
//公共继承
//保护继承
//私有继承

class Base1
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};

//公有继承
class Son1 :public Base1
{
	void func()
	{
		m_A = 10;//父类中的公共权限成员 到子类中依然是公共权限
		m_B = 10;//父类中的保护权限成员 到子类中依然是保护权限
		//m_C = 10;//父类中的私有权限成员 子类访问不到
	}
};
class Base2 
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};

//保护继承
class Son2 :protected Base2
{
public:
	void func()
	{
		m_A = 100;//父类中公有成员，到子类中变为保护权限
		m_B = 100;//父类中保护成员，到子类中也为保护权限
		//m_C = 100;//父类中私有权限成员，子类访问不到
	}
};
class Base3
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};
class Son3 :private Base3
{
public:
	void func()
	{
		m_A = 100;//父类种公共权限成员，到子类中变为私有成员
		m_B = 100;//父类种保护权限成员，到子类中变为私有成员
		//m_C = 100;//父类中私有权限成员，子类访问不到
	}
};
class GrandSon3 :public Son3
{
public:
	void func()
	{
		//m_A = 1000;
	}
};
void test01()
{
	Son1 s1;
	s1.m_A = 100;
	//s1.m_B = 100;//到son1中 m_B保护权限 类外访问不到
}

void test02()
{
	Son2 s1;
	//s1.m_A = 1000;//在Son2中 m_A 变为保护权限，因此类外访问不到
	//s1.m_B = 1000;//在Son2中 m_A 变为保护权限，因此类外访问不到
}

void test03()
{
	Son3 s1;
	//s1.m_A = 1000;//到Son3中，变为私有成员，类外访问不到
	//s1.m_B = 1000;//到Son3中，变为私有成员，类外访问不到
}


int main()
{
	return 0;
}
