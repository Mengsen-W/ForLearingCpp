#include <iostream>
#include <string>
#include "addPerson.h"

void addPerson(Addressbooks* abs) {
	// 判断通讯录是否已满
	if (abs->m_Size == MAX)
	{
		cout << "通讯录已满，无法添加" << endl;
		return;
	}
	else
	{
		// 添加具体联系人

		// 姓名
		string name;
		cout << "请输入姓名 ：" << endl;
		cin >> name;
		abs->personArrary[abs->m_Size].m_Name = name;

		// 性别
		cout << "请输入性别 ：" << endl;
		cout << " 1--男， 0--女 " << endl;
		int sex = 0;

		while (true)
		{
			cin >> sex;
			if (sex == 0 || sex == 1)
			{
				abs->personArrary[abs->m_Size].m_Sex = sex;
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
				abs->personArrary[abs->m_Size].m_Age = age;
				break;
			}
			cout << "输入有误请重新输入" << endl;
		}

		// 电话
		cout << "请输入联系电话 ：" << endl;
		string phone;
		cin >> phone;
		abs->personArrary[abs->m_Size].m_Phone = phone;

		// 住址
		cout << "请输入家庭住址 ：" << endl;
		string address;
		cin >> address;
		abs->personArrary[abs->m_Size].m_Addr = address;
	}
	abs->m_Size++;

	cout << "添加成功" << endl;
	system("pause");
	system("cls");
	return;
}
