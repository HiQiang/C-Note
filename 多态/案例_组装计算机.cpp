#include<iostream>
using namespace std;
//抽象不同零件类
class CPU {
public:
	//抽象的计算函数
	virtual void calculate() = 0;
};
class VideoCard {
public:
	//抽象的显示函数
	virtual void display() = 0;
};
class Memory {
public:
	//抽象的存储函数
	virtual void storage() = 0;
};
class Computer {
public:
	Computer(CPU* cpu, VideoCard* vc, Memory* mem)
	{
		m_cpu = cpu;
		m_vc = vc;
		m_mem = mem;
	}
	void work()
	{
		//让零件工作起来，调用接口
		m_cpu->calculate();
		m_vc->display();
		m_mem->storage();
	}
	//提供析构函数 释放3个电脑零件
	~Computer()
	{
		if (m_cpu != NULL)
		{
			delete m_cpu;
			m_cpu = NULL;
		}
		if (m_vc != NULL)
		{
			delete m_vc;
			m_vc = NULL;
		}
		if (m_mem != NULL)
		{
			delete m_mem;
			m_mem = NULL;
		}
	}
private:
	CPU* m_cpu;
	VideoCard* m_vc;
	Memory* m_mem;
};
//具体厂商
class IntelCPU :public CPU
{
public:
	virtual void calculate() {
		cout << "Intel的CPU开始计算" << endl;
	}
};
class IntelVideoCard :public VideoCard {
public:
	virtual void display()
	{
		cout << "Intel的显卡开始显示" << endl;
	}
};
class IntelMemory :public Memory {
public:
	virtual void storage()
	{
		cout << "Intel的内存条开始存储" << endl;
	}
};
class LenovoCPU :public CPU
{
public:
	virtual void calculate() {
		cout << "Lenovo的CPU开始计算" << endl;
	}
};
class LenovoVideoCard :public VideoCard {
public:
	virtual void display()
	{
		cout << "Lenovo的显卡开始显示" << endl;
	}
};
class LenovoMemory :public Memory {
public:
	virtual void storage()
	{
		cout << "Lenovo的内存条开始存储" << endl;
	}
};
void test01()
{
	CPU* intelCPU = new IntelCPU;
	VideoCard* intelVideoCard = new IntelVideoCard;
	Memory* intelMemory = new IntelMemory;
	Computer* computer1 = new Computer(intelCPU, intelVideoCard, intelMemory);
	computer1->work();
	delete computer1;//零件已在Computer析构函数中释放
	computer1 = NULL;

	Computer* computer2 = new Computer(new LenovoCPU, new LenovoVideoCard, new LenovoMemory);
	computer2->work();
	delete computer2;//零件已在Computer析构函数中释放
	computer2 = NULL;
}
int main()
{
	test01();
	return 0;
}
