#include<iostream>
#include"WokerManger.h"

using namespace std;

int main() {
	WorkerManger wm;
	int chioce = 0;

	while (true){
		wm.Show_Menu();
		cout << "����������ѡ��" << endl;
		cin >> chioce;

		switch (chioce) {
		case 0 : // �˳�ϵͳ
			wm.exitSystem();
			break;
		case 1 : // ���ְ��
			break;
		case 2 : // ��ʾְ��
			break;
		case 3 : // ɾ��ϵͳ
			break;
		case 4 : // �޸�ϵͳ
			break;
		case 5 : // ����ϵͳ
			break;
		case 6 : // ����ϵͳ
			break;
		case 7 : // ���ϵͳ
			break;
		default:
			system("cls");
			break;
		}
	}

	system("pause");
	return 0;
}
