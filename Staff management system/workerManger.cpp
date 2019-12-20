#include "wokerManger.h"

WorkerManger::WorkerManger()
{
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
