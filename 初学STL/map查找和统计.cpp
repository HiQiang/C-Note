#include<iostream>
#include<map>
using namespace std;

//map查找和统计

void test01()
{
	//查找
	map<int, int> m;
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(3, 30));
	
	map<int,int>::iterator pos = m.find(3);

	if (pos != m.end())
	{
		cout << "查到了元素 key = " << (*pos).first << ", value = " << pos->second << endl;
	}
	else
	{
		cout << "未找到元素" << endl;
		
	}
	//统计
	int num = m.count(3);//结果要么是0要么是1；
	//multimap中统计结果可以大于1
	cout << num << endl;


}


int main()
{
	test01();
	return 0;
}
