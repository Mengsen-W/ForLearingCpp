#include "manger.h"

//���캯��
Manger::Manger(int id, string name, int dId) {
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}
// ��ʾ����ȫ����Ϣ
void Manger::showInfo() {
	cout << "ְ�����" << this->m_Id << "\n"
		 << "��λ���" << this->m_DeptId << "\n"
		 << "ְ������" << this->getDeptName() << "\n"
		 << "��λְ��" << "����ϰ����񣬲��·�����ͨԱ��" << endl;
}
// ��ʾ��λ��
string Manger::getDeptName() {
	return string("����");
}