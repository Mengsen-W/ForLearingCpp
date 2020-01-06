#pragma once
#include <iostream>
#include <string>

using namespace std;

// 职工抽象类

class Worker {
public:
	// 显示个人全部信息
	virtual void showInfo() = 0;
	// 显示岗位信息
	virtual string getDeptName() = 0;
	// 职工编号
	int m_Id = 0;
	// 职工姓名
	string m_Name = "";
	// 部门编号
	int m_DeptId = 0;
};