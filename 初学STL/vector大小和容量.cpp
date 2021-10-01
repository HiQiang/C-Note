#include<iostream>
using namespace std;
//vector容量和大小操作

#include<vector>
void printVector(vector<int>& v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << (*it) << " ";
	}
	cout << endl;
}


void test01()
{
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i + 1);
	}
	printVector(v1);
	if (v1.empty())//为真 代表容器为空
	{
		cout << "为空" << endl;
	}
	else
	{
		cout << "不为空" << endl;
		cout << "v1的容量为：" << v1.capacity() << endl;
		cout << "v1的大小为: " << v1.size() << endl;
	}

	//重新指定大小
	v1.resize(15, 200);
	printVector(v1);//如果重新指定的个数比原来的常，默认用0填充新的位置

	v1.resize(5);
	printVector(v1);//如果重新指定的比原来短了，超出的部分会被删除掉

}


int main()
{
	test01();
	return 0;
}
