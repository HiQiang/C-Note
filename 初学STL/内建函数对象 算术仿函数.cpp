#include<iostream>
#include<functional> //内建函数对象头文件
using namespace std;

//STL内建函数对象

//算数仿函数

//negate 一元仿函数 取反仿函数

//plus 二元仿函数 加法

void test01()
{
	negate<int> n;
	cout << n(50) << endl;

}

void test02()
{
	plus<int> p;
	cout << p(10, 10) << endl;
}

int main()
{
	test01();
	test02();
	return 0;
}
