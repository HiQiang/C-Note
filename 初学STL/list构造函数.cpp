#include<iostream>
#include<list>
using namespace std;

//list构造函数
//list 链表
//STL中list和vector是最常使用的容器，各有优缺点
// 
//结点

//链表的优点
//可以对任意位置快速插入或删除元素
//采用动态存储分配，不会造成内存浪费和溢出
//缺点
//list 对容器的遍历速度没有 数组 快
//list 占用的空间比数组大

//STL 中的链表是一个双向循环列表

//链表的存储方式不是连续的内存空间 list中的迭代器只支持前移和后移，属于双向迭代器

void printList(const list<int> & L)
{
	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}


void test01()
{
	//创建list容器
	list<int> L1;//默认构造

	//添加数据
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);

	printList(L1);

	//区间方式构造
	list<int>L2(L1.begin(), L1.end());
	printList(L2);

	list<int>L3(L2);
	printList(L3);

	list<int>L4(10, 1000);
	printList(L4);
}


int main()
{
	test01();
	return 0;
}
