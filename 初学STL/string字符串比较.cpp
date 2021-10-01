#include<iostream>
using namespace std;

//string字符串比较

//str1 = str2 返回 0；
//str1 > str2 返回 1；
//str1 < str2 返回 -1；

 
void test01()
{
	string str1 = "Xello";
	string str2 = "Yello";
	if (str1.compare(str2) == 0)
	{
		cout << "str1 = str2" << endl;
	}
	else if (str1.compare(str2) > 0)
	{
		cout << "str1 > str2" << endl;
	}
	else
	{
		cout << "str1 < str2" << endl;
	}
}


int main()
{
	test01();
	return 0;
}
