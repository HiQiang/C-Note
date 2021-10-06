#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void myPrint(int val)
{
	cout << val << " ";
}
class Great30
{
public:
	bool operator()(int val)
	{
		if (val > 30)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

void test01()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);
	v.push_back(60);
	cout << "替换前：" << endl;
	for_each(v.begin(), v.end(), myPrint);

	replace_if(v.begin(), v.end(), Great30(), -1);
	cout << "替换后：" << endl;
	for_each(v.begin(), v.end(), myPrint);

}


int main()
{
	test01();
	return 0;
}
