#include<iostream>
#include"workerManager.h"
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"

using namespace std;

int main() {
	WorkerManager wm;
	int choice = 0;
	while (true) {
		//���Դ���
		/*
		Worker* worker = NULL;
		worker = new Employee(1,"����",1);
		worker->showInfo();
		delete worker;

		worker = new Manager(2, "����", 2);
		worker->showInfo();
		delete worker;

		worker = new Boss(3, "����", 3);
		worker->showInfo();
		delete worker;
		*/

		wm.Show_Menu();
		cout << "���������ѡ��:" << endl;
		cin >> choice;
		switch (choice) {
		case 0://�˳�ϵͳ
			wm.ExitSystem() ;
			return 0;//����PVS-Studio ���棬�������в�����仰��������һ��������ֱ���˳�main()
		case 1://����ְ��
			wm.Add_Emp();
			break;
		case 2://��ʾְ��
			wm.show_Emp();
			break;
		case 3://ɾ��ְ��
			wm.Del_Emp();
			//���Դ���
			/*cout << wm.IsExist(3) << endl;
			system("pause");
			*/
			break;			
		case 4://�޸�ְ��
			wm.Mod_Emp();
			break;
		case 5://����ְ��
			wm.Find_Emp();
			break;
		case 6://����ְ��
			wm.Sort_Emp();
			break;
		case 7://����ĵ�
			wm.Clean_File();
			break;
		default:
			system("cls");
		}
		system("cls");
	}

	return 0;
}