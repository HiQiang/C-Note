#include<iostream>
#include<string>
using namespace std;

//友元

class Building
{
	//全局函数goodGay(Building & building)作为Building类的友元，可以访问Building私有成员
	friend void goodGay(Building& building);
public:
	Building()
	{
		m_SittingRoom = "客厅";
		m_BedRoom = "卧室";
	}
	string m_SittingRoom;
private:
	string m_BedRoom;
};

//全局函数
void goodGay(Building & building)
{
	cout << building.m_SittingRoom << endl;
	cout << building.m_BedRoom << endl;
}

void test01()
{
	Building building;
	goodGay(building);
};

int main()
{
	test01();
	return 0;
}
