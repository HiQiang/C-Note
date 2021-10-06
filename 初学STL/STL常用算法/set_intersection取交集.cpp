#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//常用集合算法
void myPrint(int val)
{
	cout<<val<<endl;
}

void test01()
{
	vector<int>v1;
	vector<int>v2;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 5);
	}
	vector<int> vTarget;
	//目标容器需要提前开辟空间
	//min(v1.size(),v2.size())
	vTarget.resize(v1.size() < v2.size()? v1.size():v2.size());

	//获取交集
	//原容器需要是有序序列
	vector<int>::iterator itEnd = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());//返回一个迭代器

	for_each(vTarget.begin(), itEnd, myPrint);
}


int main()
{
	test01();
	return 0;
}
