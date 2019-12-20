#include<iostream>
#include"WokerManger.h"

using namespace std;

int main() {
	WorkerManger wm;
	int chioce = 0;

	while (true){
		wm.Show_Menu();
		cout << "请输入您的选择" << endl;
		cin >> chioce;

		switch (chioce) {
		case 0 : // 退出系统
			wm.exitSystem();
			break;
		case 1 : // 添加职工
			break;
		case 2 : // 显示职工
			break;
		case 3 : // 删除系统
			break;
		case 4 : // 修改系统
			break;
		case 5 : // 查找系统
			break;
		case 6 : // 排序系统
			break;
		case 7 : // 清空系统
			break;
		default:
			system("cls");
			break;
		}
	}

	system("pause");
	return 0;
}
