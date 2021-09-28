#include<iostream>
//#include"person.h"

//类模板分文件编写
//第一种解决方式，直接包含 源文件
//#include"person.cpp"
//第二种解决方式，将 .h和 .cpp中 的类容写到一起， 将后缀名改为 .hpp 文件
#include"person.hpp"
using namespace std;

void test01()
{
	Person<string, int> p1("jerry", 18);
	p1.showPerson();
}

int main()
{
	test01();
	return 0;
}
