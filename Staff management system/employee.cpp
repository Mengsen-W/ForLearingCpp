#include "employee.h"

//���캯��
Employee::Employee(int id, string name, int dId) {
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}
// ��ʾ����ȫ����Ϣ
void Employee::showInfo() {
	cout << "ְ�����" << this->m_Id << "\n"
		 << "��λ���" << this->m_DeptId << "\n"
		 << "ְ������" << this->getDeptName() << "\n"
		 << "��λְ��" << "��ɾ�������" << endl;
}
// ��ʾ��λ��
string Employee::getDeptName() {
	return string("��ͨԱ��");
}