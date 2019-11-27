#include"modPerson.h"
#include <iostream>
#include <string>

using namespace std;

void modPerson(Addressbooks* p) {
	int i = 0;
	cout << "请输出要修改的联系人" << endl;
	cin >> i;
	i = i - 1;

	// 姓名
	string name;
	cout << "请输入姓名 ：" << endl;
	cin >> name;
	p->personArrary[i].m_Name = name;

	// 性别
	cout << "请输入性别 ：" << endl;
	cout << " 1--男， 0--女 " << endl;
	int sex = 0;

	while (true)
	{
		cin >> sex;
		if (sex == 0 || sex == 1)
		{
			p->personArrary[i].m_Sex = sex;
			break;
		}
		cout << "输入有误请重新输入" << endl;
	}
	// 年龄
	int age = 0;
	while (true)
	{
		cout << "请输入年龄 ：" << endl;
		cin >> age;
		if (age > 0 && age < 150)
		{
			p->personArrary[i].m_Age = age;
			break;
		}
		cout << "输入有误请重新输入" << endl;
	}

	// 电话
	cout << "请输入联系电话 ：" << endl;
	string phone;
	cin >> phone;
	p->personArrary[i].m_Phone = phone;

	// 住址
	cout << "请输入家庭住址 ：" << endl;
	string address;
	cin >> address;
	p->personArrary[i].m_Addr = address;
}
