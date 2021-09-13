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
		//测试代码
		/*
		Worker* worker = NULL;
		worker = new Employee(1,"张三",1);
		worker->showInfo();
		delete worker;

		worker = new Manager(2, "李四", 2);
		worker->showInfo();
		delete worker;

		worker = new Boss(3, "王五", 3);
		worker->showInfo();
		delete worker;
		*/

		wm.Show_Menu();
		cout << "请输入你的选择:" << endl;
		cin >> choice;
		switch (choice) {
		case 0://退出系统
			wm.ExitSystem() ;
			return 0;//消除PVS-Studio 警告，程序运行不到这句话，将在上一个函数中直接退出main()
		case 1://增加职工
			wm.Add_Emp();
			break;
		case 2://显示职工
			wm.show_Emp();
			break;
		case 3://删除职工
			wm.Del_Emp();
			//测试代码
			/*cout << wm.IsExist(3) << endl;
			system("pause");
			*/
			break;			
		case 4://修改职工
			wm.Mod_Emp();
			break;
		case 5://查找职工
			wm.Find_Emp();
			break;
		case 6://排序职工
			wm.Sort_Emp();
			break;
		case 7://清空文档
			wm.Clean_File();
			break;
		default:
			system("cls");
		}
		system("cls");
	}

	return 0;
}