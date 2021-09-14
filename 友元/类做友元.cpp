#include<iostream>
using namespace std;
//类做友元

class Building;

class Building
{
	friend class GoodGay;
public:
	string m_SittingRoom;
	Building();
private:
	string m_BedRoom;
};

Building::Building() {
	m_SittingRoom = "客厅";
	m_BedRoom = "卧室";
}

class GoodGay {
public:
	GoodGay();
	//visit()函数访问Building中的属性
	void visit();

	Building* building;
};
//类外写成员函数

GoodGay::GoodGay() {
	//创建一个Building对象
	building = new Building;
}

void GoodGay::visit() {
	cout << building->m_SittingRoom << endl;
	cout << building->m_BedRoom << endl;
}

void test01()
{
	GoodGay gg;
	gg.visit();
}

int main()
{
	test01();
	return 0;
}
