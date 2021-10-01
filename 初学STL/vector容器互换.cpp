#include<iostream>
#include<vector>
using namespace std;


//vector容器互换

//基本使用

//实际用途


void printVector(vector<int> &v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << (*it) <<" ";
	}
	cout << endl;
}
void test01()
{
	vector<int> v1;

	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i + 1);
	}
	printVector(v1);

	vector<int> v2;
	for (int i = 10; i > 0; i--)
	{
		v2.push_back(i);
	}
	printVector(v2);


	v1.swap(v2);
	printVector(v1);
	printVector(v2);

}

//巧用swap可以收缩内存空间
void test02()
{
	vector<int>v;

	for (int i = 0; i < 100000; i++)
	{
		v.push_back(i);
	}
	cout << v.capacity() << endl;
	cout << v.size() << endl;

	v.resize(3);//重新指定大小
	cout << v.capacity() << endl;
	cout << v.size() << endl;

	//巧用swap
	vector<int>(v).swap(v);

	//匿名对象   vector<int>(v)
	//交换       .swap(v)
	//匿名对象   系统自动回收空间

	cout << v.capacity() << endl;
	cout << v.size() << endl;
}



int main()
{
	test02();
	return 0;
}
