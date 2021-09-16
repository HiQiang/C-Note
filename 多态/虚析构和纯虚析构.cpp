#include<iostream>
#include<string>
using namespace std;
//虚析构和纯虚析构
class Animal {
public:
	Animal() {
		cout << "Animal的构造函数调用" << endl;
	}
	virtual void func() = 0;
	//利用虚析构可以解决 父类指针释放子对象时不干净的问题
	//virtual ~Animal() {
	//	cout << "Animal的析构函数调用" << endl;
	//}

	//纯虚析构
	//纯虚析构 需要声明也需要实现
	//有了纯虚析构之后，这个类也属于抽象类
	virtual ~Animal() = 0;
};
Animal:: ~Animal() {
	cout << "animal 纯虚析构函数" << endl;
}
class Cat : public Animal {
public:
	Cat(string name) {
		cout << "Cat的构造函数调用" << endl;
		m_Name = new string(name);
	}
	void func() {
		cout <<*this->m_Name <<"小猫在说话" << endl;
	}
	~Cat()
	{
		if (m_Name != NULL) {
			cout << "Cat的析构函数调用" << endl;
			delete m_Name;
			m_Name = NULL;
		}
	}
	string* m_Name;

};
void test01()
{
	Animal* animal = new Cat("Tom");
	animal->func();
	//父类指针在析构的时候 不会调用子类中析构函数，导致子类如果有堆区属性，出现内存泄露
	delete animal;
}
int main()
{
	test01();
	return 0;
}
