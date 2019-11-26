#include <iostream>
#include <string>
#include "deletePerson.h"

void deletePerson(Addressbooks* p) {
	string name;
	cout << "请输入要查找人的姓名 ： ";
	cin >> name;
	int result = isExist(p, name);
	if(result == -1)
		cout << "查无此人" << endl;
	else
	{
		cout << "找到此人" << endl;
		for (int i = result; i < p->m_Size; ++i) {
			//数据前移
			p->personArrary[i] = p->personArrary[i + 1];
		}
		//更新数据库中的人员数
		p->m_Size--;
		cout << "删除成功" << endl;
	}
	system("pause");
	system("cls");

	return ;
}