#pragma once
#include "worker.h"

class Manger :public Worker {
public:
	//���캯��
	Manger(int id, string name, int dId);
	// ��ʾ����ȫ����Ϣ
	virtual void showInfo();
	// ��ʾ��λ��Ϣ
	virtual string getDeptName();
	// ְ�����
	int m_Id;
	// ְ������
	string m_Name;
	// ���ű��
	int m_DeptId;
};