#include<iostream>
#include<fstream>
using namespace std;
//文本文件 写文件

//
/*
ofstream 输出到文件中 写操作
ifstream 输入         读操作
fstream  读写操作
*/

void test01()
{
	//创建流对象
	ofstream ofs;
	//指定打开方式
	ofs.open("text.txt", ios::out);
	//写内容
	ofs << "姓名：张三" << endl;
	ofs << "性别：男" << endl;
	ofs << "年龄：18" << endl;
	
	ofs.close();
}


int main() {
	test01();
	return 0;
}
