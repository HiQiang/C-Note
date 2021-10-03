#include<iostream>
#include<map>
using namespace std;

//map 大小和交换

void printMap(map<int,int> & m)
{
	for (map<int,int>::iterator it =m.begin();it!=m.end();it++)
	{
		cout << "key = " << it->first << ", value = " << it->second << endl;
	}
}

//大小
void test01()
{
	map<int, int> m;
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(4, 40));
	m.insert(pair<int, int>(3, 30));


	if (m.empty())
	{
		cout << "m为空" << endl;
	}
	else
	{
		cout << "m不为空" << endl;
		cout << "m的大小为" << m.size() << endl;
	}
	map<int, int> m2;
	m2.insert(pair<int, int>(1, 100));
	m2.insert(pair<int, int>(2, 200));
	m2.insert(pair<int, int>(4, 400));

	cout << "交换前:" << endl;
	printMap(m);
	printMap(m2);

	m.swap(m2);
	cout << "交换后：" << endl;
	printMap(m);
	printMap(m2);



}

//交换

int main()
{
	test01();
	return 0;
}
