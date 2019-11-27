#include <iostream>
#include <string>
#include "Frame.h"

using namespace std;

void Frame(int* s, Addressbooks* pabs) {
	switch (*s) {
	case 1:
		//添加联系人
		addPerson(pabs);
		//showPerson(pabs);
		break;
	case 2:
		//显示联系人
		showPerson(pabs);
		break;
	case 3:
		//删除联系人
		deletePerson(pabs);
		break;
	case 4:
		findPerson(pabs);
		//查找联系人
		break;
	case 5:
		//修改联系人
		modPerson(pabs);
		break;
	case 6:
	{
		//清空联系人
		delete pabs;
		cout << "清楚联系人成功" << endl;
		system("pause");
		system("cls");
		break;
	}
	case 0:
		//退出通讯录
		cout << " 欢迎下次使用 " << endl;
		system("pause");
		break;
	}

	return;
}