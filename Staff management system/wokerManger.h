#pragma once
#include <iostream>
#include "worker.h"
#include "boss.h"
#include "employee.h"
#include "manger.h"

class WorkerManger
{
public:
	// ���캯��
	WorkerManger();

	// ��������
	~WorkerManger();

	// ��¼ְ������
	int m_EmpNum;

	// ְ������ָ��
	Worker** m_EmpArray;

	// ���ְ��
	void Add_Emp();

	// չʾ����
	void Show_Menu();

	// �˳�ϵͳ
	void exitSystem();

private:

};


