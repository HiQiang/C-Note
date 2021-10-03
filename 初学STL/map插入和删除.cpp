#include<iostream>
#include<map>
using namespace std;

//map对元素插入和删除
void printMap(map<int, int>& m)
{
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key = " << it->first << ", value = " << it->second << endl;;
	}

}

void test01()
{
	map<int, int>m;

	//插入
	m.insert(pair<int, int>(1, 10));

	m.insert(make_pair(2, 20));

	m.insert(map<int, int>::value_type(3, 30));

	m[4] = 40;
	//不建议用[]插入，可以用[]访问
	printMap(m);

	m.erase(3);//按照key删除
	printMap(m);

	
	//m.erase(m.begin(), m.end());
	m.clear();
}


int main()
{
	test01();
	return 0;
}
