#include<iostream>
#include<algorithm>
#include<vector>
//#include<functional>
using namespace std;

void myPrint(int val)
{
	cout << val << " ";
}

void test01()
{
	vector<int> v;

	v.push_back(10);
	v.push_back(1);
	v.push_back(8);
	v.push_back(4);
	v.push_back(5);

	sort(v.begin(), v.end());
	for_each(v.begin(), v.end(), myPrint);
	cout << endl;

	//改变为 降序
	sort(v.begin(), v.end(),greater<int>());
	for_each(v.begin(), v.end(), myPrint);
	cout << endl;
}


int main()
{
	test01();
	return 0;
}
