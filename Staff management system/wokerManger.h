#pragma once
#include <iostream>
#include "worker.h"
#include "boss.h"
#include "employee.h"
#include "manger.h"

class WorkerManger
{
public:
	// 构造函数
	WorkerManger();

	// 析构函数
	~WorkerManger();

	// 记录职工人数
	int m_EmpNum;

	// 职工数组指针
	Worker** m_EmpArray;

	// 添加职工
	void Add_Emp();

	// 展示函数
	void Show_Menu();

	// 退出系统
	void exitSystem();

private:

};


