#include<iostream>
using namespace std;

//string 的构造函数
//string 本质是一个类 是C++风格的字符串

void test01()
{
	string s1;//默认构造
	const char* str = "Hello World";

	string s2(str);//使用字符串s初始化
	cout << "s2 = "<< s2 << endl;

	string s3(s2);//拷贝构造
	cout << "s3 = " << s3 << endl;

	string s4(10, 'a');
	cout << "s4 = " << s4 << endl;
}


int main()
{
	test01();
	return 0;
}
