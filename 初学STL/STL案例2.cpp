#include<iostream>
using namespace std;
#include<map>
#include<vector>
#define CEHUA 0
#define MEISHU 1
#define YANFA 2

class Worker
{
public:
	string m_Name;
	int m_Salary;
};

void createWorker(vector<Worker>& v)
{
	string nameSeed = "ABCDEFGHIJ";
	for (int i = 0; i < 10; i++)
	{
		Worker worker;
		worker.m_Name = "员工";
		worker.m_Name += nameSeed[i];
		worker.m_Salary = rand() % 10001 + 10000;
		v.push_back(worker);
	}
}

void setGroup(vector<Worker>& v, multimap<int, Worker>& m)
{
	for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++)
	{
		//产生随机的部门编号
		int deptId = rand() % 3;//0 1 2

		//将员工插入分组中
		//
		m.insert(make_pair(deptId, *it));
	}

}
void showWorkerByGroup(const multimap<int, Worker>& m)
{
	cout << "策划部门：" << endl;
	multimap<int, Worker>::const_iterator pos = m.find(CEHUA);
	int count = m.count(CEHUA);//
	int index = 0;
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "姓名：" << pos->second.m_Name << ", 工资：" << pos->second.m_Salary << endl;
	}

	cout << "美术部门：" << endl;
	pos = m.find(MEISHU);
	count = m.count(MEISHU);//
	index = 0;
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "姓名：" << pos->second.m_Name << ", 工资：" << pos->second.m_Salary << endl;
	}



	cout << "研发部门：" << endl;
	pos = m.find(YANFA);
	count = m.count(YANFA);//
	index = 0;
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "姓名：" << pos->second.m_Name << ", 工资：" << pos->second.m_Salary << endl;
	}

}

void test01()
{
	//创建员工
	vector<Worker> vWorker;
	createWorker(vWorker);
	for (vector<Worker>::iterator it = vWorker.begin(); it != vWorker.end(); it++)
	{
		cout <<"姓名：" << it->m_Name <<", 工资：" << it->m_Salary << endl;
	}
	//员工分组
	multimap<int, Worker>mWorker;
	setGroup(vWorker, mWorker);
	showWorkerByGroup(mWorker);

}


int main()
{
	test01();
	return 0;
}
