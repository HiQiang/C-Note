#include<iostream>
#include<vector>
#include<algorithm>

//常用排序算法 merge

using namespace std;

void myPrint(int val)
{
	cout << val << " ";
}


void test01()
{
	vector<int> v1;//原容器需为有序序列，并且同为降序或升序
	vector<int> v2;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 1);
	}
	//目标容器
	vector<int>vTarget;
	vTarget.resize(v1.size() + v2.size());
	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
	for_each(vTarget.begin(), vTarget.end(), myPrint);
	cout << endl;
}


int main()
{
	test01();
	return 0;
}
