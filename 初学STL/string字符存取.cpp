#include<iostream>
using namespace std;

//string 字符存取

void test01()
{
	string str = "Hello";
	cout << str << endl;
	//通过[]访问单个字符
	for (int i = 0; i < str.size(); i++)
	{
		cout << str[i] << endl;
	}
	//通过at方式访问单个字符
	for (int i = 0; i < str.size(); i++)
	{
		cout << str.at(i) << endl;//.at()是一个成员方法
	}
	//修改单个字符
	str[0] = 'X';
	cout <<"str = " << str << endl;

	str[1] = 'X';
	cout << "str = " << str << endl;

}

int main()
{
	test01();
	return 0;
}
