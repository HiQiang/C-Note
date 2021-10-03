#include<iostream>
#include<set>
using namespace std;

void printSet(const set<int> &s)
{
	for (set<int>::const_iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

//set插入和删除

void test01()
{
	set<int> s1;
	//插入
	
	s1.insert(30);
	s1.insert(20);
	s1.insert(40);
	s1.insert(10);

	//遍历
	printSet(s1);

	//删除
	s1.erase(s1.begin());
	printSet(s1);
	s1.erase(30);
	printSet(s1);
	s1.clear();//清空
}


int main()
{
	test01();
	return 0;
}
