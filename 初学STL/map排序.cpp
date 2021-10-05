#include<iostream>
#include<map>
using namespace std;

//map排序

class MyCompare {
public:
	bool operator()(int v1, int v2)const
	{
		return v1 > v2;
	}
};

void test01()
{
	map<int, int,MyCompare> m;
	m.insert(pair<int, int>(1, 10));
	m.insert(make_pair(2, 20));
	m.insert(pair<int, int>(3, 30));
	m.insert(make_pair(4, 40));
	m.insert(pair<int, int>(5, 50));
	for (map<int, int,MyCompare>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key = " << it->first << ", value = " << it->second << endl;
	}
}


int main()
{
	test01();
	return 0;
}
