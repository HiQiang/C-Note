#include<iostream>
#include<fstream>
#include"manager.h"
#include"teacher.h"
#include"student.h"
#include"globalFile.h"
using namespace std;

//����ѧ���Ӳ˵�����
void studentMenu(Identity*& student)
{
	while (true)
	{
		//����ѧ�����Ӳ˵�
		student->openMenu();

		Student* stu = (Student*)student;

		int select = 0;//�����û���ѡ��
		cin >> select;
		if (select == 1)//����ԤԼ
		{
			stu->applyOrder();
		}
		else if (select == 2)//�鿴����ԤԼ
		{
			stu->showMyOrder();
		}
		else if (select == 3)//�鿴������ԤԼ
		{
			stu->showAllOrder();
		}
		else if (select == 4)//ȡ��ԤԼ
		{
			stu->cancelOrder();
		}
		else//ע����¼
		{
			delete student;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//�����ʦ�Ӳ˵�����
void teacherMenu(Identity*& teacher)
{
	while (true)
	{
		//�����Ӳ˵�����
		teacher->openMenu();
		Teacher* tea = (Teacher*)(teacher);

		int select = 0; //�����û�ѡ��

		cin >> select;
		if (select == 1)//�鿴����ԤԼ
		{
			tea->showAllOrder();
		}
		else if(select == 2)//���ԤԼ
		{
			tea->validOrder();
		}
		else
		{
			delete teacher;
			cout << " ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//�������Ա�˵�����
void nanagerMenu(Identity*& manager)
{
	do
	{
		//���ù���Ա���Ӳ˵�
		manager->openMenu();

		//�������ָ��תΪ�����ָ�룬�����������������нӿ�
		Manager* man = (Manager*)manager;
		int select = 0;
		//�����û���ѡ��
		cin >> select;
		if (select == 1)//����˺�
		{
			//cout << "����˺�" << endl;
			man->addPerson();
		}
		else if(select == 2) //�鿴�˺�
		{
			//cout << "�鿴�˺�" << endl;
			man->showPerson();
		}
		else if (select == 3) //�鿴����
		{
			//cout << "�鿴����" << endl;
			man->showComputer();
		}
		else if (select == 4) //���ԤԼ
		{
			//cout << "���ԤԼ" << endl;
			man->clearFile();
		}
		else
		{
			// ע��
			delete manager;//���ٵ������Ķ���
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	} while (true);
}

//��¼���� ���� �����ļ��� �����������
void LoginIn(string fileName, int type)
{
	//����ָ�룬����ָ���������
	Identity* person = NULL;

	//���ļ�
	ifstream ifs;
	ifs.open(fileName, ios::in);
	//�ж��ļ��Ƿ����
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		ifs.close();
		return;
	}

	//׼�������û���Ϣ
	int id = 0;
	string name;
	string pwd;

	//�ж����
	if (type == 1)//ѧ�����
	{
		cout << "����������ѧ�ţ�" << endl;
		cin >> id;
	}
	else if (type == 2)
	{
		cout << "����������ְ����" << endl;
		cin >> id;
	}
	cout << "�������û�����" << endl;
	cin >> name;
	cout << "���������룺" << endl;
	cin >> pwd;

	if (type == 1)
	{
		//ѧ�������֤
		int fId;//���ļ��ж�ȡ��id��
		string fName;//���ļ��л�ȡ������
		string fPwd;//���ļ��л�ȡ������
		while (ifs>>fId && ifs>>fName && ifs>>fPwd)
		{
			//cout << fId << endl;
			//cout << fName << endl;
			//cout << fPwd << endl;

			//���û��������Ϣ���Ա�
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "ѧ������֤��¼�ɹ���" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				//���뵽ѧ����ݵ��Ӳ˵�
				studentMenu(person);

				return;
			}
		}
	}
	else if(type == 2)
	{
		//��ʦ�����֤

		int fId;//���ļ��ж�ȡ��id��
		string fName;//���ļ��л�ȡ������
		string fPwd;//���ļ��л�ȡ������
		
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			//cout << fId << endl;
			//cout << fName << endl;
			//cout << fPwd << endl;

			//���û��������Ϣ���Ա�
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "��ʦ����֤��¼�ɹ���" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				//���뵽��ʦ��ݵ��Ӳ˵�
				teacherMenu(person);
				return;
			}
		}
	}
	else if(type == 3)
	{
		//����Ա�����֤
		//int fId;//���ļ��ж�ȡ��id��
		string fName;//���ļ��л�ȡ������
		string fPwd;//���ļ��л�ȡ������

		while (ifs >> fName && ifs >> fPwd)
		{
			//cout << fId << endl;
			//cout << fName << endl;
			//cout << fPwd << endl;

			//���û��������Ϣ���Ա�
			if (fName == name && fPwd == pwd)
			{
				cout << "����Ա����֤��¼�ɹ���" << endl;
				system("pause");
				system("cls");

				person = new Manager(name, pwd);
				//���뵽����Ա��ݵ��Ӳ˵�
				nanagerMenu(person);
				return;
			}
		}

	}

	cout << "��֤��¼ʧ�ܣ�" << endl;
	system("pause");
	system("cls");
	return;
}

int main()
{
	int select = 0;

	do
	{
		cout << "\t\t========����ԤԼϵͳ========" << endl;
		cout << endl;
		cout << "������������ݣ�" << endl;
		cout << "\t\t+-------------------------+\n";
		cout << "\t\t|                         |\n";
		cout << "\t\t|       1.ѧ������        |\n";
		cout << "\t\t|                         |\n";
		cout << "\t\t|       2.��    ʦ        |\n";
		cout << "\t\t|                         |\n";
		cout << "\t\t|       3.�� �� Ա        |\n";
		cout << "\t\t|                         |\n";
		cout << "\t\t|       0.��    ��        |\n";
		cout << "\t\t|                         |\n";
		cout << "\t\t+-------------------------+\n";
		cout << "����������ѡ��" << endl;

		cin >> select;//�����û�ѡ��

		switch (select)//�����û�ѡ�� ʵ�ֲ�ͬ�ӿ�
		{
		case 1://ѧ�����
			LoginIn(STUDENT_FILE, 1);
			break;

		case 2://��ʦ���
			LoginIn(TEACHER_FILE, 2);
			break;

		case 3://����Ա���
			LoginIn(ADMIN_FILE, 3);
			break;

		case 0://�˳�ϵͳ
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");

			return 0;
			
			break;

		default:
			cout << "��������������ѡ��" << endl;
			system("pause");
			system("cls");
			break;
		}
	} while (true);
	return 0;
}