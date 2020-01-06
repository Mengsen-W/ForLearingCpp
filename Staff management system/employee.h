// 普通员工文件
#pragma once
#include "worker.h"
class Employee :public Worker {
public:
	//构造函数
	Employee(int id, string name, int dId);
	// 显示个人全部信息
	virtual void showInfo();
	// 显示岗位信息
	virtual string getDeptName();
	// 职工编号
	int m_Id;
	// 职工姓名
	string m_Name;
	// 部门编号
	int m_DeptId;
};
