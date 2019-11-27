#include "findPerson.h"
#include "Address.h"
#include <iostream>
#include <string>

void findPerson(Addressbooks* p)
{
	string name;
	cout << "请输入查找的人" << endl;
	cin >> name;
	int result = isExist(p, name);
	if (result == -1)
		cout << "查无此人" << endl;
	else
	{
		cout << "找到此人" << endl;
		cout << "联系人 : " << result + 1 << endl;
		cout << "姓名 ：" << p->personArrary[result].m_Name << endl;
		cout << "性别 : " << (p->personArrary[result].m_Sex == 1 ? "男" : "女") << endl;
		cout << "年龄 ：" << p->personArrary[result].m_Age << endl;
		cout << "联系方式 ：" << p->personArrary[result].m_Phone << endl;
		cout << "联系地址 ：" << p->personArrary[result].m_Addr << endl;
	}
	system("pause");
	system("cls");
	return;
}