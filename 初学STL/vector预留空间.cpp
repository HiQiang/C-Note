#include<iostream>
#include<vector>
using namespace std;

//vector预留空间

void test01()
{
	vector<int> v;
	//利用reserve预留空间
	v.reserve(100000);
	int num = 0;
	int num2 = 0;
	int numOfc = 0;
	int* p = NULL;

	for (int i = 0; i < 100000; i++)
	{
		v.push_back(i);

		if (p != &v[0])
		{
			p = &v[0];
			num++;
		}

		if (numOfc != v.capacity())
		{
			numOfc = v.capacity();
			cout << numOfc << endl;
			num2++;
		}
	}
	cout << num << " " << num2 << endl;

}


int main()
{
	test01();
	return 0;
}
