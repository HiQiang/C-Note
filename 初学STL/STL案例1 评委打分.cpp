#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>
using namespace std;

//STL案例1 评委打分

//选手类
class Person {
public:
	Person(string name, int score)
	{
		this->m_Name = name;
		this->m_Score = score;
	}
	string m_Name;//姓名
	int m_Score;  //平均分
};

void creatPerson(vector<Person>& v)
{
	for (int i = 0; i < 5; i++)
	{
		string nameSeed = "ABCDE";
		string name = "选手";
		name += nameSeed[i];
		int score = 0;
		Person p(name, score);
		//将创建的Person对象放入到容器中
		v.push_back(p);
	}
}

void setScore(vector<Person>& v)
{
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		//将评委的分数放入deque容器中
		deque<int> d;
		for (int i = 0; i < 10; i++)
		{
			int score = rand() % 41 + 60;
			d.push_back(score);
		}
		cout << it->m_Name << "得分" << endl;

		for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
		{
			cout << *dit << " ";
		}
		cout << endl;

		//排序
		sort(d.begin(), d.end());
		//去除最高分和最低分
		d.pop_back();
		d.pop_front();
		//取平均分
		int sum = 0;

		for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
		{
			sum += *dit;
		}
		(*it).m_Score = sum / 8;
	}
}

void test01()
{
	//随机数种子
	srand((unsigned int)time(NULL));
	//创建5名选手
	vector<Person> v;//存放选手的容器
	creatPerson(v);

	for (vector<Person>::const_iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "姓名：" << (*it).m_Name << " 分数：" << (*it).m_Score << endl;
	}

	//给5名选手打分
	setScore(v);
	//显示最后得分
	for (vector<Person>::const_iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "姓名：" << (*it).m_Name << " 分数：" << (*it).m_Score << endl;
	}
}


int main()
{
	test01();
	return 0;
}
