#include "wokerManger.h"

WorkerManger::WorkerManger()
{
	// ��ʼ������
	this->m_EmpNum = 0;
	this->m_EmpArray = nullptr;
}

WorkerManger::~WorkerManger()
{
}

// ��ʾ�˵�
void WorkerManger::Show_Menu() {

	std::cout << "*******************************************" << std::endl;
	std::cout << "*********** ��ӭʹ��ְ������ϵͳ ***********" << std::endl;
	std::cout << "************* 0. �˳�������� **************" << std::endl;
	std::cout << "************* 1. ����ְ����Ϣ **************" << std::endl;
	std::cout << "************* 2. ��ʾְ����Ϣ **************" << std::endl;
	std::cout << "************* 3. ɾ��ְ����Ϣ **************" << std::endl;
	std::cout << "************* 4. �޸�ְ����Ϣ **************" << std::endl;
	std::cout << "************* 5. ����ְ����Ϣ **************" << std::endl;
	std::cout << "************* 6. ���ձ������ **************" << std::endl;
	std::cout << "************* 7. ��������ĵ� **************" << std::endl;
	std::cout << "*******************************************" << std::endl;
	std::cout << std::endl;
}

// �Ƴ�ϵͳ
void WorkerManger::exitSystem() {
	std::cout << "��ӭ�´�ʹ��" << std::endl;
	system("pause");
	exit(0);
}

// ���ְ��
void WorkerManger::Add_Emp() {
	cout << "���������ְ��������" << endl;
	int addnum = 0;
	cin >> addnum;
	if (addnum > 0) {
		// ���Ա��
		// ��������¿ռ��С
		int newSize = this->m_EmpNum + addnum;

		// �����¿ռ�
		Worker** newSpace = new(Worker * [newSize]);

		// ��ԭ�����ݿ���
		if (this->m_EmpArray != nullptr) {
			for (int i = 0; i < this->m_EmpNum; ++i) {
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		// ��������� �������
		for (int i = 0; i < addnum; ++i) {
			// ְ�����
			int id;
			//ְ������
			string name;
			// ����ѡ��
			int dSelect;

			cout << "������� " << (i + 1) << " ����ְ���ı��" << endl;
			cin >> id;
			cout << "������� " << (i + 1) << " ����ְ��������" << endl;
			cin >> name;

			cout << "��ѡ���ְ���ĸ�λ��" << endl;
			cout << "1. ��ְͨ��" << endl;
			cout << "2. ����" << endl;
			cout << "3. �ϰ�" << endl;
			cin >> dSelect;

			// �����¶���
			Worker* worker = nullptr;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(id, name, 1);
				break;
			case 2:
				worker = new Manger(id, name, 2);
				break;
			case 3:
				worker = new Boss(id, name, 3);
			default:
				break;
			}
			// ��ָ����ӽ�����
			newSpace[(this->m_EmpNum + i)] = worker;
		}
		// �ͷ�ԭ�пռ�
		delete[] this->m_EmpArray;

		// ����ָ���¿ռ�
		this->m_EmpArray = newSpace;

		//�����µ�ְ������
		this->m_EmpNum = newSize;

		// ��ʾ��ӳɹ�
		cout << "��ӳɹ� " << addnum << " ����Ա��"<< endl;
	}
	else{
		cout << "������������" << endl;
	}

	// ����������������ص��ϼ�Ŀ¼
	system("pause");
	system("cls");

}

WorkerManger::~WorkerManger()
{
	if (this->m_EmpArray != NULL)
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			if (this->m_EmpArray[i] != NULL)
			{
				delete this->m_EmpArray[i];
			}
		}

		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}
