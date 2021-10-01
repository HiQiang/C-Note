#include<iostream>
#include<deque>

using namespace std;

//双端数组 像 一片连续的空间

//deque    构造函数

void printDeque(const deque<int>& d)
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
	{
		//*it = 100;//const 修饰符 容器中的数据不可修改
		cout << *it << " ";
	}
	cout << endl;
}

void test01()
{
	deque<int> d1;
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i + 1);
	}
	printDeque(d1);

	deque<int>d2(d1.begin(), d1.end());
	printDeque(d1);

	deque<int> d3(10, 100);
	printDeque(d3);

	deque<int>d4(d3);
	printDeque(d4);
}


int main()
{
	test01();
	return 0;
}
