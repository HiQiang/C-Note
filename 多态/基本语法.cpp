#include<iostream>
using namespace std;

//动态多态的满足条件
//1.有继承关系
//2.子类重写父类的虚函数

//动态多态使用
//父类的指针或者引用 指向子类对象


class Animal {
public:
	virtual void speak()
	{
		cout << "动物在说话" << endl;
	}
};

class Cat :public Animal {
public:
	//重写 函数返回值类型 函数名 参数列表 完全相同
	void speak()//virtual 关键字可加可不加
	{
		cout << "小猫在说话" << endl;
	}
};

class Dog :public Animal {
public:
	void speak()
	{
		cout << "小狗在说话" << endl;
	}
};

//执行说话的函数
//地址早绑定 在编译阶段确定函数地址

//如果想执行让猫说话，这个函数的地址不能提前绑定。需要在运行阶段进行绑定，
//地址晚绑定
void doSpeak(Animal& animal)//Animal & animal = cat
{
	animal.speak();
}

void test01() {
	Cat cat;
	doSpeak(cat);
	Dog dog;
	doSpeak(dog);
}

int main()
{
	test01();
	return 0;
}
