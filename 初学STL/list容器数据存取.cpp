#include<iostream>
#include<list>
using namespace std;

//list容器中数据进行存取

void test01()
{
	list<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);

	//不可以用 [] 和 at 方式访问list中的元素

	//原因 list 本质是链表，不是用连续线性空间存储数据，迭代器不支持随机访问

	cout << L1.front() << endl;//第一个元素
	cout << L1.back() << endl; //最后一个元素

	//验证迭代器是不支持随机访问的
	list<int>::iterator it = L1.begin();
	it = it++;//支持双向
	it = it--;
	//it = it + 1;//不支持随机访问

}


int main()
{
	test01();
	return 0;
}
