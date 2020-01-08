#include "wokerManger.h"

WorkerManger::WorkerManger()
{
	// 初始化属性
	this->m_EmpNum = 0;
	this->m_EmpArray = nullptr;
}

WorkerManger::~WorkerManger()
{
}

// 显示菜单
void WorkerManger::Show_Menu() {

	std::cout << "*******************************************" << std::endl;
	std::cout << "*********** 欢迎使用职工管理系统 ***********" << std::endl;
	std::cout << "************* 0. 退出管理程序 **************" << std::endl;
	std::cout << "************* 1. 增加职工信息 **************" << std::endl;
	std::cout << "************* 2. 显示职工信息 **************" << std::endl;
	std::cout << "************* 3. 删除职工信息 **************" << std::endl;
	std::cout << "************* 4. 修改职工信息 **************" << std::endl;
	std::cout << "************* 5. 查找职工信息 **************" << std::endl;
	std::cout << "************* 6. 按照编号排序 **************" << std::endl;
	std::cout << "************* 7. 清空所有文档 **************" << std::endl;
	std::cout << "*******************************************" << std::endl;
	std::cout << std::endl;
}

// 推出系统
void WorkerManger::exitSystem() {
	std::cout << "欢迎下次使用" << std::endl;
	system("pause");
	exit(0);
}

// 添加职工
void WorkerManger::Add_Emp() {
	cout << "请输入添加职工的数量" << endl;
	int addnum = 0;
	cin >> addnum;
	if (addnum > 0) {
		// 添加员工
		// 计算添加新空间大小
		int newSize = this->m_EmpNum + addnum;

		// 开辟新空间
		Worker** newSpace = new(Worker * [newSize]);

		// 将原来数据拷贝
		if (this->m_EmpArray != nullptr) {
			for (int i = 0; i < this->m_EmpNum; ++i) {
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		// 添加新数据 批量添加
		for (int i = 0; i < addnum; ++i) {
			// 职工编号
			int id;
			//职工姓名
			string name;
			// 部门选择
			int dSelect;

			cout << "请输入第 " << (i + 1) << " 个新职工的编号" << endl;
			cin >> id;
			cout << "请输入第 " << (i + 1) << " 个新职工的姓名" << endl;
			cin >> name;

			cout << "请选择该职工的岗位：" << endl;
			cout << "1. 普通职工" << endl;
			cout << "2. 经理" << endl;
			cout << "3. 老板" << endl;
			cin >> dSelect;

			// 创建新对象
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
			// 将指针添加进数组
			newSpace[(this->m_EmpNum + i)] = worker;
		}
		// 释放原有空间
		delete[] this->m_EmpArray;

		// 更改指向新空间
		this->m_EmpArray = newSpace;

		//更新新的职工人数
		this->m_EmpNum = newSize;

		// 提示添加成功
		cout << "添加成功 " << addnum << " 名新员工"<< endl;
	}
	else{
		cout << "输入数据有误" << endl;
	}

	// 按任意键后清屏，回到上级目录
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
