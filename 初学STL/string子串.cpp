#include<iostream>
using namespace std;

//string子串

void test01()
{
	string str = "abcdef";

	string subStr = str.substr(1, 3);//从什么位置起，截取多少个字符
	cout << subStr << endl;
}


//实用操作
void test02()
{
	string email = "hello@sina.com";

	//从邮件用户名中获取 用户名信息
	int pos = email.find('@');

	string usrName = email.substr(0, pos);
	cout << usrName << endl;

}

int main()
{
	test02();
	return 0;
}
