#include<iostream>
#include<deque>
using namespace std;

//deque数据获取操作

void test01()
{
	deque<int> d;
	d.push_back(10);
	d.push_back(20);
	d.push_back(30);
	d.push_front(100);
	d.push_front(200);
	d.push_front(300);

	//通过[]访问
	for (int i = 0; i < d.size(); i++)
	{
		cout << d[i] << " ";
	}
	cout << endl;

	//通过.at()访问
	for (int i = 0; i < d.size(); i++)
	{
		cout << d.at(i) << " ";
	}
	cout << endl;

	cout << d.front() << endl;
	cout << d.back() << endl;
}


int main()
{
	test01();
	return 0;
}
