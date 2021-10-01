#include<iostream>
#include<vector>
using namespace std;

//vector 容器构造

void printVector(vector<int> &v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << (*it) << " ";
	}
	cout << endl;
}

void test01()
{
	vector<int> v1;//默认构造 无参构造
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i + 1);
	}
	printVector(v1);

	cout << *v1.begin() <<endl;

	//通过区间方式进行构造
	vector<int>v2(v1.begin(), v1.end());
	printVector(v2);

	//n个elem方式构造
	vector<int> v3(10, 100);//10个100；
	printVector(v3);

	//拷贝构造 //通常用到的方式
	vector<int> v4(v3);
	printVector(v4);

}

int main()
{
	test01();
	return 0;
}
