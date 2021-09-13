#include"workerManager.h"


WorkerManager::WorkerManager()
{
	//1.�ļ�������
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		//��ʼ������
		//��ʼ����¼����
		this->m_EmpNum = 0;
		//��ʼ������ָ��
		this->m_EmpArray = NULL;
		//��ʼ���ļ��Ƿ�Ϊ��
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//2.�ļ����ڣ�����Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//�ļ�Ϊ��
		cout << "�ļ�Ϊ��" << endl;
		//��ʼ������
		//��ʼ����¼����
		this->m_EmpNum = 0;
		//��ʼ������ָ��
		this->m_EmpArray = NULL;
		//��ʼ���ļ��Ƿ�Ϊ��
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//3.�ļ����ڣ����Ҽ�¼����
	int num = this->get_EmpNum();
	cout << "ְ������Ϊ��" << num << "��" << endl;
	this->m_EmpNum = num;
	//���ٿռ�
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	//���ļ��е����ݴ浽������
	this->init_Emp();
	//���Դ���
	/*
	for (int i = 0; i < this->m_EmpNum; i++) {
		cout << "ְ����ţ�" << this->m_EmpArray[i]->m_Id<<"\t"
			<< "������" << this->m_EmpArray[i]->m_Name<<"\t"
			<< "���ű�ţ�" << this->m_EmpArray[i]->m_DeptId << endl;
	}
	*/
}

void WorkerManager::Show_Menu() {
	cout << "**********************************" << endl;
	cout << "******��ӭʹ��ְ������ϵͳ��******" << endl;
	cout << "**********0.�˳��������**********" << endl;
	cout << "**********1.����ְ����Ϣ**********" << endl;
	cout << "**********2.��ʾְ����Ϣ**********" << endl;
	cout << "**********3.ɾ����ְְ��**********" << endl;
	cout << "**********4.�޸�ְ����Ϣ**********" << endl;
	cout << "**********5.����ְ����Ϣ**********" << endl;
	cout << "**********6.���ձ������**********" << endl;
	cout << "**********7.��������ĵ�**********" << endl;
	cout << "**********************************" << endl;
}

void WorkerManager::ExitSystem() {
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}

//���ְ��
//m_EmpArray ����ŵ���ָ�룬ָ��worker���ָ�롣worker��������employee��mananger����boss�ࡣ

void WorkerManager::Add_Emp() {
	cout << "��������ӵ�ְ����������" << endl;
	int addNum = 0; //�����û�����������
	cin >> addNum;
	if (addNum > 0) {
		//���
		//������ӵ��µĿռ�Ĵ�С
		int newSize = this->m_EmpNum + addNum; //�¿ռ����� = ԭ����¼������ + ����������
		//�����¿ռ䣺���ٵ��¿ռ���ָ��Worker���ָ�����飬���ص���ָ��ָ���ָ�롣**
		Worker** newSpace = new Worker * [newSize];//ֱ�Ӽ�ס��new���ص���ָ�룬���ָ��int*��ָ�룺int ** .....
		//��ԭ���ռ��µ����ݿ������¿ռ���
		if (this->m_EmpArray != NULL) {
			for (int i = 0; i < this->m_EmpNum; i++) {
				newSpace[i] = this->m_EmpArray[i];
				//��Ϊ�����飬���Կ���������
			}
		}
		//�������������
		for (int i = 0; i < addNum; i++) {
			int id;//ְ�����
			string name;//ְ������
			int dSelect;//����ѡ��

			cout << "�������" << i + 1 << "����ְ���ı�ţ�" << endl;
			cin >> id;
			cout << "�������" << i + 1 << "����ְ����������" << endl;
			cin >> name;
			cout << "��ѡ���ְ���ĸ�λ��" << endl;
			cout << "1:��ְͨ��" << endl;
			cout << "2:����" << endl;
			cout << "3:�ϰ�" << endl;
			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(id, name, dSelect);
				break;
			case 2:
				worker = new Manager(id, name, dSelect);
				break;
			case 3:
				worker = new Boss(id, name, dSelect);
				break;
			default:
				break;
			}
			//������ְ�������浽������
			int index = m_EmpNum + i;
			if (index < newSize) {//����C6386�������������
				newSpace[index] = worker;
			}
		}
		//�ͷ�ԭ�пռ�
		delete[] this->m_EmpArray;
		//�����¿ռ�ָ��
		this->m_EmpArray = newSpace;
		//�������ݸ���
		this->m_EmpNum = newSize;
		//�������ݵ��ļ���
		this->save();
		//����ְ����Ϊ�ձ�־
		this->m_FileIsEmpty = false;
		//��ʾ��ӳɹ�
		cout << "��ӳɹ�" << addNum << "����ְ��" << endl;

	}
	else {
		cout << "������������" << endl;
	}
	//������������
	system("pause");
}

void WorkerManager::save() {
	ofstream ofs;
	ofs.open(FILENAME, ios::out);//�����ģʽ���ļ� -- д�ļ�
	//��ÿ��������д�뵽�ļ���
	for (int i = 0; i < this->m_EmpNum; i++) {
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptId << endl;
	}
	ofs.close();
}

int WorkerManager::get_EmpNum() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//���ļ� ���ļ�
	int id;
	string name;
	int dId;
	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> dId) {
		//ͳ����������
		num++;
	}
	return num;
}

void WorkerManager::init_Emp() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int dId;
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId) {
		Worker* worker = NULL;

		if (dId == 1)//��ְͨ��
		{
			worker = new Employee(id, name, dId);
		}
		else if (dId == 2) {//����
			worker = new Manager(id, name, dId);
		}
		else if (dId == 3) {//�ϰ�
			worker = new Boss(id, name, dId);
		}
		this->m_EmpArray[index] = worker;
		index++;
	}
	//�ر��ļ�
	ifs.close();
}

void WorkerManager::show_Emp() {
	//�ж��ļ��Ƿ�Ϊ��
	if (this->m_FileIsEmpty) {
		cout << "�ļ������ڻ��߼�¼Ϊ��!" << endl;
	}
	else {
		for (int i = 0; i < this->m_EmpNum; i++) {
			//���ö�̬���ó���ӿ�
			this->m_EmpArray[i]->showInfo();
		}
	}
	system("pause");
}

int WorkerManager::IsExist(int id) {
	int index = -1;
	for (int i = 0; i < this->m_EmpNum; i++) {
		if (id == this->m_EmpArray[i]->m_Id) {
			index = i;
			break;
		}
	}
	return index;
}

void WorkerManager::Del_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "�ļ������ڻ��¼Ϊ��!" << endl;
	}
	else {
		//����ְ�����ɾ��
		cout << "��������Ҫɾ����ְ����ţ�" << endl;
		int id = -1;
		cin >> id;
		int index = this->IsExist(id);
		if (index != -1) {//˵��ְ�����ڣ�����Ҫɾ��indexλ���ϵ�ְ��
			for (int i = index; i < this->m_EmpNum - 1; i++) {
				//����ǰ��
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			//delete m_EmpArray[this->m_EmpNum-1];
			this->m_EmpNum--;//���������м�¼��Ա����
			//ͬ�����µ��ļ���
			this->save();
			cout << "ɾ���ɹ�!" << endl;
		}
		else {
			cout << "ɾ��ʧ�ܣ�δ�ҵ���ְ��" << endl;
		}
		system("pause");
	}
}

void WorkerManager::Mod_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "�ļ������ڻ��¼Ϊ��!" << endl;
	}
	else {
		cout << "�������޸�ְ���ı�ţ�" << endl;
		int id;
		cin >> id;

		int ret = this->IsExist(id);
		if (ret != -1) {
			//���ҵ���ŵ�ְ��
			int newId = -1;
			string newName = "";
			int dSelect = -1;
			cout << "���ҵ�" << id << "��ְ��" << endl;
			this->m_EmpArray[ret]->showInfo();
			delete this->m_EmpArray[ret];
			cout << "��������ְ���ţ�" << endl;
			cin >> newId;
			cout << "��������ְ�����֣�" << endl;
			cin >> newName;
			cout << "��ѡ����ְ���ĸ�λ��" << endl;
			cout << "1:��ְͨ��" << endl;
			cout << "2:����" << endl;
			cout << "3:�ϰ�" << endl;
			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(newId, newName, dSelect);
				break;
			case 2:
				worker = new Manager(newId, newName, dSelect);
				break;
			case 3:
				worker = new Boss(newId, newName, dSelect);
				break;
			default:
				break;
			}
			this->m_EmpArray[ret] = worker;
			cout << "�޸ĳɹ�" << endl;
			//���浽�ļ���
			this->save();
		}
		
		else {
			cout << "�޸�ʧ�ܣ����޴���" << endl;
		}
		system("pause");
	}

}

void WorkerManager::Find_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "�ļ������ڻ��¼Ϊ��!" << endl;
	}
	else {
		cout << "��������ҵķ�ʽ" << endl;
		cout << "1.��ְ����Ų���" << endl;
		cout << "2.��ְ����������" << endl;
		int select;
		cin >> select;
		if (select == 1) {
			cout << "����ְ����Ų���" << endl;
			int id;
			cout << "��������ҵ�ְ����ţ�" << endl;
			cin >> id;
			int ret = IsExist(id);
			if (ret != -1) {
				cout << "���ҳɹ�!��ְ����Ϣ���£�" << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else
			{
				cout << "���޴���" << endl;
			}
		}
		else if (select == 2) {
			cout << "����ְ����������" << endl;
			string name;
			//�����Ƿ�鵽�ı�־
			bool flag = false;//Ĭ��δ�ҵ�ְ����

			cout << "��������ҵ�����:" << endl;
			cin >> name;
			for (int i = 0; i < this->m_EmpNum; i++) {
				if (name == this->m_EmpArray[i]->m_Name) {
					flag = true;
					cout << "���ҳɹ���ְ�����Ϊ��" << this->m_EmpArray[i]->m_Id << endl;
					cout << "��Ϣ���£�" << endl;
					this->m_EmpArray[i]->showInfo();
				}
			}
			if (flag == false) {
				cout << "����ʧ�ܣ����޴���" << endl;
			}
		}
		else {
			cout << "�������" << endl;
		}
		system("pause");
	}

}

void WorkerManager::Sort_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
		system("pause");
	}
	else
	{
		cout << "��ѡ������ʽ��" << endl;
		cout << "1.��ְ���Ž���������" << endl;
		cout << "2.��ְ���Ž��н�����" << endl;
		int select = 0;
		cin >> select;
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			int minOrMax = i;//������Сֵ�������ֵ���±�
			for (int j = i + 1; j < this->m_EmpNum; j++)
			{
				if (select == 1)//����
				{
					if (this->m_EmpArray[minOrMax]->m_Id > this->m_EmpArray[j]->m_Id)
					{
						minOrMax = j;
					}				
				}
				else {//����
					if (this->m_EmpArray[minOrMax]->m_Id < this->m_EmpArray[j]->m_Id)
					{
						minOrMax = j;
					}

				}

				
			}
			//�ж��ʼ�϶�����Сֵ�����ֵ�ǲ��Ǽ������Сֵ�����ֵ��������ǣ���������2
			if (i != minOrMax) {
				Worker* temp = this->m_EmpArray[i];
				this->m_EmpArray[i] = this->m_EmpArray[minOrMax];
				this->m_EmpArray[minOrMax] = temp;
		}			
	}
		cout << "����ɹ��������Ľ����" << endl;
		this->save();//�����Ľ�����浽�ļ���
		this->show_Emp();//չʾ���е�ְ��
	}
}

void WorkerManager::Clean_File() {
	cout << "ȷ����գ�" << endl;
	cout << "1.ȷ��" << endl;
	cout << "2.����" << endl;
	int select = 0;

	cin >> select;
	if (select == 1) {
		//����ļ�
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();

		if (this->m_EmpArray != NULL)
		{
			//ɾ������ÿ��ְ������
			for (int i = 0; i < this->m_EmpNum; i++) {
				delete this->m_EmpArray[i];
				this->m_EmpArray[i] = NULL;
			}
			//ɾ����������ָ��
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_EmpNum = 0;
			this->m_FileIsEmpty = true;
		}
		cout << "��ճɹ�" << endl;
		system("pause");
	}
}

WorkerManager::~WorkerManager()
{
	if (this->m_EmpArray != NULL)
	{
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}

