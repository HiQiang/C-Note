#include<iostream>
#include<vector>
#include<numeric>

using namespace std;

//常用算术生成算法

void test01()
{
	vector<int> v;
	for (int i = 0; i <= 100; i++)
	{
		v.push_back(i);
	}
	int total = accumulate(v.begin(),v.end(),0);//参数3 起始累加值
	cout << total << endl;
}


int main()
{
	test01();
	return 0;
}
