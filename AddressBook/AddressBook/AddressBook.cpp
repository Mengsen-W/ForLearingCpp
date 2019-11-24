#include <iostream>
#include <string>
#include "Frame.h"

using namespace std;

int main(void) {
	//初始化联系人结构体
	Addressbooks* pabs = new Addressbooks;
	pabs->m_Size = 0;

	//初始化操作数
	int select = 0;

	//循环程序
	while (true)
	{
		showMenu();
		cout << " 请输入操作数 = ";
		cin >> select;
		cout << endl;
		Frame(&select, pabs);
		if (select == 0) { break; }
	}
	delete pabs;
	return 0;
}