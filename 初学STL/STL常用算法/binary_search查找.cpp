#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

//binary_search() 在无序序列中不可用 返回值不是迭代器 是bool类型



void test01()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	//v.push_back(2); //如果是无序序列，结果不准确
	//查找容器中是否有 9
	bool ret = binary_search(v.begin(), v.end(), 9);
	if (ret == true)
	{
		cout << "找到了元素" << endl;
	}
	else
	{
		cout << "未找到元素" << endl;
	}
}


int main()
{
	test01();
	return 0;
}
