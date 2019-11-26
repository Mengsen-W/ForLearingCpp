#include <iostream>
#include <string>
#include "showPerson.h"
using namespace std;

void showPerson(const Addressbooks* p) {
	if (p->m_Size == 0)
	{
		cout << " 联系人数量为零 " << endl;
	}
	else
	{
		for (int i = 0; i < p->m_Size; ++i) {
			cout << "联系人 : " << i + 1 << endl;
			cout << "姓名 ：" << p->personArrary[i].m_Name << endl;
			cout << "性别 : " << (p->personArrary[i].m_Sex == 1 ? "男" : "女") << endl;
			cout << "年龄 ：" << p->personArrary[i].m_Age << endl;
			cout << "联系方式 ：" << p->personArrary[i].m_Phone << endl;
			cout << "联系地址 ：" << p->personArrary[i].m_Addr << endl;
		}
	}
	system("pause");
	system("cls");
}