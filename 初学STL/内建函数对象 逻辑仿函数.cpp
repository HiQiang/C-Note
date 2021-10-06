#include<iostream>
#include<vector>
#include<functional>
#include<algorithm>
using namespace std;

//内建函数对象 逻辑仿函数
//逻辑非 logical_not()

void test01()
{
	vector<bool> v;
	v.push_back(true);
	v.push_back(false);
	v.push_back(true);
	v.push_back(false);

	for (vector<bool>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	//利用逻辑非 将容器v 搬运到容器v2中，并执行取反操作
	vector<bool> v2;
	//v2 = v;
	v2.resize(v.size());
	transform(v.begin(), v.end(), v2.begin(),logical_not<bool>());//搬运，目标容器需要提前开辟空间
	for (vector<bool>::iterator it = v2.begin(); it != v2.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}


int main()
{
	test01();
	return 0;
}
