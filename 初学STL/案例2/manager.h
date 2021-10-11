#pragma once
#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include"Identity.h"
#include "globalFile.h"
#include "student.h"
#include "teacher.h"
#include "computerRoom.h"
using namespace std;

//管理员类设计
class Manager :public Identity
{
public:
	//默认构造
	Manager();

	//有参构造
	Manager(string name, string pwd);

	//菜单界面
	virtual void openMenu();

	//添加账号
	void addPerson();

	//查看账号
	void showPerson();

	//查看机房信息
	void showComputer();

	//清空预约记录
	void clearFile();

	//初始化容器
	void initVector();

	//检测重复 参数 id 数据类型 返回值 true false
	bool chechRepeat(int id, int type);


	//******************
	//学生容器
	vector<Student> vStu;

	//教师容器
	vector<Teacher> vTea;

	//机房信息容器
	vector<ComputerRoom> vCom;
};