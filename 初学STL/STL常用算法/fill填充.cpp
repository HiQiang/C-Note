#include<iostream>
#include<numeric>
#include<vector>
#include<algorithm>
using namespace std;

void myPrint(int val)
{
	cout << val << " ";
}

void test01()
{
	vector<int> v;
	v.push_back(1);
	v.resize(10, 0);
	//后期重新填充
	fill(v.begin(), v.end(), 100);
	for_each(v.begin(), v.end(), myPrint);
}


int main()
{
	test01();
	return 0;
}
