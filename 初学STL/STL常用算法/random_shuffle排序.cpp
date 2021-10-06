#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//random_shuffle
void myPrint(int val)
{
	cout << val<<" ";
}

void test01()
{
	srand((unsigned int)time(NULL));
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	random_shuffle(v.begin(), v.end());
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	//system("pause");
	for_each(v.begin(), v.end(), myPrint);
	cout << endl;
}


int main()
{
	test01();
	return 0;
}
