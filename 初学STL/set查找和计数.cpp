#include<iostream>
#include<set>
using namespace std;

//set查找和统计

void test01()
{
	set<int> s1;
	//插入
	s1.insert(10);
	s1.insert(30);
	s1.insert(20);
	s1.insert(40);

	set<int>::iterator pos = s1.find(30);
	if (pos != s1.end())
	{
		cout<<"找到"<<endl;
	}
	else 
	{
		cout << "未找到" << endl;
	}

	//查找
}

//统计
void test02()
{
	set<int> s1;
	//插入
	s1.insert(10);
	s1.insert(30);
	s1.insert(20);
	s1.insert(40);

	int num = s1.count(30);//统计30的个数
	//对于set而言 计数的结果要么是0要么是1
	cout << "num=" << num << endl;

}

int main()
{
	test02();
	return 0;
}
