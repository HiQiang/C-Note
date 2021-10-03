#include<iostream>
#include<set>
using namespace std;

//set 大小和交换

void printSet(const set <int> s)
{
	for (set<int>::const_iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

//大小
void test01()
{
	set<int>s1;
	//插入数据
	s1.insert(10);
	s1.insert(30);
	s1.insert(20);
	s1.insert(40);
	printSet(s1);

	//判断是否为空
	if (s1.empty())
	{

	}
	else
	{
		cout << "s1不为空" << endl;
		cout << "s1的大小为" << s1.size() << endl;
	}

	set<int>s2;
	//插入数据
	s2.insert(100);
	s2.insert(300);
	s2.insert(200);
	s2.insert(400);

	cout << "交换前" << endl;
	printSet(s1);
	printSet(s2);

	s1.swap(s2);
	cout << "交换后" << endl;
	printSet(s1);
	printSet(s2);
}

void test02()
{

}

int main()
{
	test01();
	return 0;
}
