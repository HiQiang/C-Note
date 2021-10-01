#include<iostream>
using namespace std;

//string 字符串拼接

void test01()
{
	string str1 = "我";
	str1 += "是你爸爸";
	cout << str1 << endl;
	str1 += 'A';
	cout << str1 << endl;
	string str2 = "DNF";
	str1 += str2;
	cout << str1 << endl;

	string str3 = "I";
	str3.append(" Love Game");//.append() 类成员函数
	cout << str3 << endl;
	str3.append("I Love Game", 6);
	cout << str3 << endl;

	str3.append(str2);
	cout << str3 << endl;

	str3.append(str2, 0, 1);//从什么位置起，截取多少个字符
	cout << str3 << endl;
}


int main()
{
	test01();
	return 0;
}
