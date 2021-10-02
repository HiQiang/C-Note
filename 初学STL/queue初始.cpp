#include<iostream>
#include<queue>
using namespace std;

//queue 先进先出 队列
//只有队尾和队头可以被外界访问 不允许遍历
//入队 出队 队尾 对头

//先进先出

//push
//front
//back
//empty
//size
//...
class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	string m_Name;
	int m_Age;
};


void test01()
{
	Person p1("唐僧", 999);
	Person p2("孙悟空", 888);
	Person p3("猪八戒", 777);
	Person p4("沙师弟", 666);
	queue<Person>q;

	q.push(p1);
	q.push(p2);
	q.push(p3);
	q.push(p4);

	cout << q.size() << endl;

	//判断只要队列不为空，查看队头，查看队尾，出队
	while (!q.empty())
	{
		cout << q.front().m_Name << " " << q.front().m_Age << endl;
		cout << q.back().m_Name << " " << q.back().m_Age << endl;
		q.pop();
	}
	cout << q.size() << endl;
}


int main()
{
	test01();
	return 0;
}
