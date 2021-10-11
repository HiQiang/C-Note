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

//����Ա�����
class Manager :public Identity
{
public:
	//Ĭ�Ϲ���
	Manager();

	//�вι���
	Manager(string name, string pwd);

	//�˵�����
	virtual void openMenu();

	//����˺�
	void addPerson();

	//�鿴�˺�
	void showPerson();

	//�鿴������Ϣ
	void showComputer();

	//���ԤԼ��¼
	void clearFile();

	//��ʼ������
	void initVector();

	//����ظ� ���� id �������� ����ֵ true false
	bool chechRepeat(int id, int type);


	//******************
	//ѧ������
	vector<Student> vStu;

	//��ʦ����
	vector<Teacher> vTea;

	//������Ϣ����
	vector<ComputerRoom> vCom;
};