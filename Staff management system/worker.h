#pragma once
#include <iostream>
#include <string>

using namespace std;

// ְ��������

class Worker {
public:
	// ��ʾ����ȫ����Ϣ
	virtual void showInfo() = 0;
	// ��ʾ��λ��Ϣ
	virtual string getDeptName() = 0;
	// ְ�����
	int m_Id = 0;
	// ְ������
	string m_Name = "";
	// ���ű��
	int m_DeptId = 0;
};