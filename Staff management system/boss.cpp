#include "boss.h"

//���캯��
Boss::Boss(int id, string name, int dId) {
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}
// ��ʾ����ȫ����Ϣ
void Boss::showInfo() {
	cout << "ְ�����" << this->m_Id << "\n"
		<< "��λ���" << this->m_DeptId << "\n"
		<< "ְ������" << this->getDeptName() << "\n"
		<< "��λְ��" << "������" << endl;
}
// ��ʾ��λ��
string Boss::getDeptName() {
	return string("�ϰ�");
}
