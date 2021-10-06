#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

//STL常用算法
//常用遍历算法 for_each

//普通函数
void print01(int val)
{
	cout << val << " ";
}

//仿函数
class Print02
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};

void test01()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	for_each(v.begin(), v.end(), print01);
	cout << "\n";
	for_each(v.begin(), v.end(), Print02());
	cout << endl;
}


int main()
{
	test01();
	return 0;
}
