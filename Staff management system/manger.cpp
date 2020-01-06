#include "manger.h"

//构造函数
Manger::Manger(int id, string name, int dId) {
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}
// 显示个人全部信息
void Manger::showInfo() {
	cout << "职工编号" << this->m_Id << "\n"
		 << "岗位编号" << this->m_DeptId << "\n"
		 << "职工姓名" << this->getDeptName() << "\n"
		 << "岗位职责" << "完成老板任务，并下发给普通员工" << endl;
}
// 显示岗位信
string Manger::getDeptName() {
	return string("经理");
}