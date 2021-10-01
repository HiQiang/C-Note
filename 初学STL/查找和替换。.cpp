#include<iostream>
using namespace std;

//string 查找和替换

//查找
void test01()
{
	string str1 = "Abcdefg";
	int pos = str1.find("de");

	if (pos == -1)
	{
		cout << "未找到字符串" << endl;
	}
	else
	{
		cout << "pos = " << pos << endl;
	}

	//rfind
	pos = str1.rfind("de");

	//find和rfind的区别
	//rfind从右往左查 find从左往右找
	cout << "pos" << endl;

}
//替换
void test02()
{
	string str1 = "abcdefg";
	str1.replace(1,3,"11111");//从什么位置起 替换几个字符

	cout << str1 << endl;
}


int main()
{
	test02();
	return 0;
}
