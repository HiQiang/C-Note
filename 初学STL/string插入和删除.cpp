#include<iostream>
using namespace std;

//string 插入和删除



void test01()
{
	string str = "Hello";

	//插入
	str.insert(1, "111");//从什么位置插入什么东西
	cout << str << endl;

	//删除
	str.erase(1, 3);//从什么位置起 ，删除几个字符
	cout << str << endl;
}


int main()
{
	test01();
	return 0;
}
