#include<iostream>
using namespace std;

//string赋值操作

void test01()
{
	string str1;
	str1 = "Hello World!";
	cout << "str1 = " << str1 << endl;

	string str2;
	str2 = str1;
	cout << "str2 = " << str2 << endl;

	string str3;
	str3 = 'a';

	string str4;
	str4.assign("Hello C++");//asign 是一个成员函数

	string str5;
	str5.assign("Hello C++", 5);//字符串前5个字符赋值给str5
	cout << "str5 = " << str5 << endl;

	string str6;
	str6.assign(str5);

	string str7;
	str7.assign(10, 'w');
	cout << "str7 = " << str7 << endl;
}


int main()
{
	test01();
	return 0;
}
