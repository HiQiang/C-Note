#include<iostream>
#include<string>
using namespace std;
class Building;

class GoodGay {
public:
	GoodGay();

	void visit();//让vist函数可以访问Building中私有成员
	
	Building* building;
};

class Building {
	friend void GoodGay::visit();
public:
	Building();
	string m_SittingRoom;
private:
	string m_BedRoom;
};
Building::Building() {
	m_SittingRoom = "客厅";
	m_BedRoom = "卧室";
}
GoodGay::GoodGay() {
pubilic:
	building = new Building;
}
void GoodGay::visit()
{
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
