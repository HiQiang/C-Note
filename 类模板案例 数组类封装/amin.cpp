#include<iostream>
#include"MyArray.hpp"

using namespace std;


void printIntArray(MyArray<int> & arr)
{
	for (int i = 0; i < arr.getSize(); i++)
	{
		cout << arr[i] << endl;
	}
}


void test01()
{
	MyArray<int> arr1(5);
	for (int i = 0; i < 5; i++)
	{
		//利用尾插法向数组中插入数据
		arr1.Push_Back(i);

	}

	cout << "arr1的打印输出为：" << endl;
	printIntArray(arr1);
	cout << "arr1的容量" << arr1.getCapacity() << endl;
	cout << "arr1的大小" << arr1.getSize() << endl;

	MyArray<int> arr2(arr1);
	arr2.Pop_Back();
	cout << "arr2的打印输出为：" << endl;
	printIntArray(arr2);
	cout << "arr2的容量" << arr2.getCapacity() << endl;
	cout << "arr2的大小" << arr2.getSize() << endl;


	//MyArray<int> arr2(arr1);
	//MyArray<int> arr3(100);
	//arr3 = arr1;
	//MyArray<A> arr(5);
}

//测试自定义数据类型
class Person {
public:
	Person() {};
	Person(string name, int age) {
		this->m_Name = name;
		this -> m_Age = age;
	}
	string m_Name;
	int m_Age;
};

void printPersonArray(MyArray<Person> & arr)
{
	for (int i = 0; i < arr.getSize(); i++)
	{
		cout << arr[i].m_Name << " " << arr[i].m_Age << endl;
	}

}

void test02()
{
	MyArray<Person> arr(10);
	Person p1("孙大圣", 999);
	Person p2("孙", 999);
	Person p3("大", 999);
	Person p4("圣", 999);
	Person p5("大圣", 999);
	//将数据插入到数组中
	arr.Push_Back(p1);
	arr.Push_Back(p2); 
	arr.Push_Back(p3);
	arr.Push_Back(p4);
	arr.Push_Back(p5);
	//打印数组
	printPersonArray(arr);
	//输出容量和大小
	cout << arr.getCapacity() << endl;
	cout << arr.getSize() << endl;

}

int main()
{
	//test01();
	test02();
	return 0;
}
