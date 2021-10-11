#include"student.h"

//Ĭ�Ϲ���
Student::Student() 
{

}

//�вι��� ������ѧ�š�����������
Student::Student(int id, string name, string pwd)
{
	//��ʼ������
	this->m_Id = id;
	this->m_Name = name;
	this->m_Pwd = pwd;

	//��ʼ��������Ϣ
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);

	ComputerRoom com;
	while (ifs >> com.m_Comid && ifs >> com.m_MaxNum)
	{
		vCom.push_back(com);//����ȡ������Ϣ����������
	}

	ifs.close();
		
}

//�˵�����
void Student::openMenu() 
{
	cout << "\t\t��ӭѧ������" << this->m_Name << " ��¼��" << endl;
	cout << endl;
	cout << "\t\t+-------------------------+\n";
	cout << "\t\t|                         |\n";
	cout << "\t\t|       1.����ԤԼ        |\n";
	cout << "\t\t|                         |\n";
	cout << "\t\t|       2.�鿴�ҵ�ԤԼ    |\n";
	cout << "\t\t|                         |\n";
	cout << "\t\t|       3.�鿴����ԤԼ    |\n";
	cout << "\t\t|                         |\n";
	cout << "\t\t|       4.ȡ��ԤԼ        |\n";
	cout << "\t\t|                         |\n";
	cout << "\t\t|       0.ע����¼        |\n";
	cout << "\t\t|                         |\n";
	cout << "\t\t+-------------------------+\n";
	cout << "����������ѡ��" << endl;
}

//����ԤԼ
void Student::applyOrder() 
{
	cout << "��������ʱ��Ϊ��һ�����壡" << endl;
	cout << "����������ԤԼ��ʱ�䣺" << endl;
	cout << "1.��һ" << endl;
	cout << "2.�ܶ�" << endl;
	cout << "3.����" << endl;
	cout << "4.����" << endl;
	cout << "5.����" << endl;

	int date = 0;//����
	int interval = 0;//ʱ���
	int room = 0;//�������

	while (true)
	{
		cin >> date;
		if (date >= 1 && date <= 5)
		{
			break;
		}
		cout << "�����������������룺" << endl;
	}

	cout << "����������ԤԼ��ʱ��Σ�" << endl;
	cout << "1.����" << endl;
	cout << "2.����" << endl;

	while (true)
	{
		cin >> interval;
		if (interval == 1 || interval == 2)
		{
			break;
		}
		cout << "�����������������룺" << endl;
	}
	cout << "��ѡ�������" << endl;
	cout << vCom[0].m_Comid << "�Ż���������Ϊ��" << vCom[0].m_MaxNum << endl;
	cout << vCom[1].m_Comid << "�Ż���������Ϊ��" << vCom[1].m_MaxNum << endl;
	cout << vCom[2].m_Comid << "�Ż���������Ϊ��" << vCom[2].m_MaxNum << endl;

	//for (int i = 0; i < vCom.size(); i++)
	//{
	//	cout << vCom[i].m_Comid << "�Ż���������Ϊ��" << vCom[i].m_MaxNum << endl;
	//}

	while (true)
	{
		cin >> room;
		if (room >= 1 && room <= 3)
		{
			break;
		}
		cout << "�����������������룺" << endl;
	}
	cout << "ԤԼ�ɹ��������" << endl;

	ofstream ofs;
	ofs.open(ORDER_FILE, ios::app);
	ofs << "date:" << date << " ";
	ofs << "interval:" << interval << " "; 
	ofs << "stuId:" << this->m_Id << " ";
	ofs << "stuName:" << this->m_Name << " ";
	ofs << "roomId:" << room << " ";
	ofs << "status:" << 1 << endl;
	ofs.close();
	system("pause");
	system("cls");
}

//�鿴����ԤԼ
void Student::showMyOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼��" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.m_Size; i++)
	{
		//string ת int
		//string ���� .c_str() ת const char *
		//���� atoi (const char *)ת��Ϊint
		if (this->m_Id == atoi(of.m_orderData[i]["stuId"].c_str()))//�ҵ�����ԤԼ
		{
			cout<<"ԤԼ���ڣ���"<<of.m_orderData[i]["date"];
			cout << "\tԤԼʱ��Σ�" << (of.m_orderData[i]["interval"] == "1" ? "����" : "����");
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
	}
	system("pause");
	system("cls");
}

//�鿴����ԤԼ
void Student::showAllOrder()
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
		cout << "\tԤԼʱ��Σ�" << (of.m_orderData[i]["interval"] == "1" ? "����" : "����");
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

//ȡ��ԤԼ
void Student::cancelOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "����л�ԤԼ�ɹ��ļ�¼��ȡ����������Ҫȡ���ļ�¼" << endl;
	vector<int>v;//�������������е��±���
	int index = 1;
	for (int i = 0; i < of.m_Size; i++)
	{
		//���ж�����ѧ��
		if (this->m_Id == atoi(of.m_orderData[i]["stuId"].c_str()))
		{
			//��ɸѡ״̬ ����л�ԤԼ�ɹ�
			if (of.m_orderData[i]["status"] == "1" || of.m_orderData[i]["status"] == "2")
			{
				v.push_back(i);
				cout << index++ << "��";
				cout << "ԤԼ���ڣ���" << of.m_orderData[i]["date"];
				cout << "\tԤԼʱ��Σ�" << (of.m_orderData[i]["interval"] == "1" ? "����" : "����");
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
				cout << status << endl;
			}
		}
	}
	cout << "��������ȡ���ļ�¼��0������" << endl;
	int select = 0;
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
				of.m_orderData[v[select - 1]]["status"] = "0";
				of.updateOrder();
				cout << "��ȡ��ԤԼ" << endl;
				break;
			}
		}
		cout << "�����������������룺" << endl;
	}
	system("pause");
	system("cls");
}

//ѧ��ѧ��
int m_Id;