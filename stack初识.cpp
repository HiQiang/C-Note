#include<iostream>
#include<stack>
using namespace std;

//stack常用接口

//栈容器 符合先进后出的数据结构

//栈不允许有遍历的行为
//栈可以判断容器是否为空
//栈可以返回元素个数

void test01()
{
	stack<int>s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);

	//只要栈不为空，我们就查看栈顶，并且执行出栈操作

	while (!s.empty())
	{
		//查看栈顶元素
		cout << "栈顶元素为：" << s.top() << endl;

		//出栈
		s.pop();
	}
	cout << "栈的大小：" << s.size() << endl;
}


int main()
{
	test01();
	return 0;
}
