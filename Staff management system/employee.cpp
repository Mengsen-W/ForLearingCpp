#include "employee.h"

//构造函数
Employee::Employee(int id, string name, int dId) {
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}
// 显示个人全部信息
void Employee::showInfo() {
	cout << "职工编号" << this->m_Id << "\n"
		 << "岗位编号" << this->m_DeptId << "\n"
		 << "职工姓名" << this->getDeptName() << "\n"
		 << "岗位职责" << "完成经理任务" << endl;
}
// 显示岗位信
string Employee::getDeptName() {
	return string("普通员工");
}