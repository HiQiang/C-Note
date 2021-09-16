#include<iostream>
#include<fstream>
#include<string>
using namespace std;

void test01()
{
	//1.包含头文件
	//2.创建流对象
	ifstream ifs;
	//3.打开文件，并且判定是否打开成功
	ifs.open("text.txt", ios::in);

	if (!ifs.is_open()) {
		cout << "文件打开失败" << endl;
		return;
	};

	//4.读数据 4种方式
	//char buf[1024] = { 0 };
	//while (ifs >> buf)
	//{
	//	cout << buf << endl;
	//}
	//

	/*char buf[1024] = { 0 };
	while (ifs.getline(buf, sizeof(buf))) 
	{
		cout << buf << endl;
	}
	ifs.close();*/
	string buf;
	while (getline(ifs, buf)) {
		cout << buf << endl;
	}
	char c;
	while ((c = ifs.get() != EOF))
	{
		cout << c ;
	}
}

int main()
{
	test01();
	return 0;
}
