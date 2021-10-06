#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//常用拷贝和替换算法 repalce
class MyPrint 
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};


void test01()
{
	vector<int> v1;
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);
	v1.push_back(30);
	for_each(v1.begin(), v1.end(), MyPrint());
	cout << endl;

	replace(v1.begin(), v1.end(), 30, 300);//替换所有满足条件的元素
	for_each(v1.begin(), v1.end(), MyPrint());
	cout << endl;
}


int main()
{
	test01();
	return 0;
}
