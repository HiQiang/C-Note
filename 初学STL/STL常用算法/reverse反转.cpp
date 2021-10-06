#include<iostream>
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
	v.push_back(10);
	v.push_back(20);
	v.push_back(12);
	v.push_back(18);

	cout << "反转前:" << endl;
	for_each(v.begin(), v.end(), myPrint);
	cout << endl;

	reverse(v.begin(), v.end());
	cout << "反转后:" << endl;
	for_each(v.begin(), v.end(), myPrint);
	cout << endl;
}


int main()
{
	test01();
	return 0;
}
