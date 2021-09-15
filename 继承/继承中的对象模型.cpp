#include<iostream>
using namespace std;
//继承中的对象模型
class Base
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};

class Son : public Base
{
public:
	int m_D;
};
//利用开发人员命令提示工具查看对象模型
//跳转盘符 F:
//跳转文件夹路径 cd 具体路径
//查看当前文件夹下文件 dir
//查看命令：
//  cl /d1 reportSingleClassLayout类名 main.cpp
void test01()
{
	//父类中所有非静态成员属性都会被子类继承下取
	//父类中私有成员属性 是被编译器隐藏了，因此访问不到，但是确实是被继承下去了
	cout << "size of Son: " << sizeof(Son)<<" Byte(s)" << endl;
}


int main()
{
	test01();
	
	return 0;
}
