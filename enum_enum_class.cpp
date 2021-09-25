#include<iostream>
using namespace std;

void test01()
{
	enum ERR {
		num1 = 1,
		num2 = 2,
		num3 = 5
	};
	ERR err;//报warning
	err = num1;
	std::cout << err << std::endl;
}

void test02()
{
	typedef enum tagERR {
		num1 = 1,
		num2 = 2,
		num3 = 5
	} ERR;
	tagERR err;//报warning
	err = num1;
	std::cout << err << std::endl;
}

void test03()
{
	typedef enum tagERR {
		num1 = 1,
		num2 = 2,
		num3 = 5
	} ERR;
	ERR err = num1;//报warning
	err = num1;
	std::cout << err << std::endl;
}

void test04()
{
	enum class ERR {
		num1 = 1,
		num2 = 2,
		num3 = 5
	};
	ERR err;
	err = ERR::num1;//enum class 是具有作用域的
	std::cout << int(err) << std::endl;
	std::cout << int(ERR::num1) << std::endl;
}

int main()
{
	test01();
	test02();
	test03();
	test04();
	return 0;
}
