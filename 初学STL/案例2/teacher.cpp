#include "teacher.h"

//Ĭ�Ϲ���
Teacher::Teacher()
{

}

//�вι��� ������ְ����� ���� ����
Teacher::Teacher(int empid, string name, string pwd)
{
	this->m_EmpId = empid;
	this->m_Name = name;
	this->m_Pwd = pwd;
}

//�˵�����
void Teacher::openMenu()
{
	cout << "\t\t��ӭ��ʦ��" << this->m_Name << " ��¼��" << endl;
	cout << endl;
	cout << "\t\t+-------------------------+\n";
	cout << "\t\t|                         |\n";
	cout << "\t\t|       1.�鿴����ԤԼ    |\n";
	cout << "\t\t|                         |\n";
	cout << "\t\t|       2.���ԤԼ        |\n";
	cout << "\t\t|                         |\n";
	cout << "\t\t|       0.ע����¼        |\n";
	cout << "\t\t|                         |\n";
	cout << "\t\t+-------------------------+\n";
	cout << "����������ѡ��" << endl;
}
//�鿴����ԤԼ
void Teacher::showAllOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.m_Size; i++)
	{
		cout << i + 1 << "��";
		cout << "ԤԼ���ڣ���" << of.m_orderData[i]["date"];
		cout << "\tԤԼʱ��Σ�" << (of.m_orderData[i]["interval"] == "1" ? "����" : "����");//��Ŀ�����
		cout << "\tѧ�ţ�" << of.m_orderData[i]["stuId"];
		cout << "\t������" << of.m_orderData[i]["stuName"];
		cout << "\t�����ţ�" << of.m_orderData[i]["roomId"];

		string status = "\t״̬��";
		//1 ����� 2 ��ԤԼ -1 ԤԼʧ�� 0 ȡ��ԤԼ
		if (of.m_orderData[i]["status"] == "1")
		{
			status += "�����";
		}
		else if (of.m_orderData[i]["status"] == "2")
		{
			status += "ԤԼ�ɹ�";
		}
		else if (of.m_orderData[i]["status"] == "-1")
		{
			status += "ԤԼʧ�ܣ����δͨ��";
		}
		else
		{
			status += "ԤԼ��ȡ��";
		}
		cout << status << endl;
	}
	system("pause");
	system("cls");
}

//���ԤԼ
void Teacher::validOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "����˵�ԤԼ��¼���£�" << endl;
	vector<int>v;//�������������е��±���

	int index = 0;
	for (int i = 0; i < of.m_Size; i++)
	{
		if (of.m_orderData[i]["status"] == "1")
		{
			v.push_back(i);
			cout << ++index << "��";
			cout << "ԤԼ���ڣ���" << of.m_orderData[i]["date"];
			cout << "\tԤԼʱ��Σ�" << (of.m_orderData[i]["interval"] == "1" ? "����" : "����");
			cout << "\tѧ����ţ�" << of.m_orderData[i]["stuId"];
			cout << "\tѧ��������" << of.m_orderData[i]["stuName"];
			cout << "\t������ţ�" << of.m_orderData[i]["roomId"];
			cout << "״̬�������" << endl;
		}
	}
	cout << "����������˵�ԤԼ��¼��0������" << endl;
	int select = 0;//�����û�ѡ���ԤԼ��¼
	int ret = 0;//����ԤԼ�����¼
	while (true)
	{
		cin >> select;
		if (select >= 0 && select <= v.size())
		{
			if (select == 0)
			{
				break;
			}
			else
			{
				cout << "��������˽����" << endl;
				cout << "1.ͨ��" << endl;
				cout << "2.��ͨ��" << endl;
				cin >> ret;
				if (ret == 1)
				{
					//ͨ�����
					of.m_orderData[v[select - 1]]["status"] = "2";
				}
				else
				{
					of.m_orderData[v[select - 1]]["status"] = "-1";
				}
				of.updateOrder();//����ԤԼ��¼
				cout << "������" << endl;
				break;
			}
		}
		else 
		{
			cout << "�����������������룡" << endl;
		}
		
	}
	system("pause");
	system("cls");
}
