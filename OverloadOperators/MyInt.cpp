#include "MyInt.h"
#include <iostream>

//Ĭ�Ϲ���
MyInt::MyInt()
{
	this->m_Num = new int(0);
	cout << "Ĭ�Ϲ���" << endl;
}

//���ι���
MyInt::MyInt(int num)
{
	this->m_Num = new int(num);
	cout << "���ι���" << endl;
}

//��������
MyInt::MyInt(const MyInt& temp)
{
	this->m_Num = new int(*temp.m_Num);
	cout << "��������" << endl;
}

//���ظ�ֵ����
MyInt& MyInt::operator=(const MyInt& p)
{
	{
		if (this->m_Num != NULL)
		{
			delete this->m_Num;
			this->m_Num = NULL;
		}
		this->m_Num = new int(*p.m_Num);
		return *this;
	}

}

//��������
MyInt::~MyInt()
{
	if (this->m_Num != NULL)
	{
		delete m_Num;
		m_Num = NULL;
	}
	cout << "��������" << endl;
}

//ǰ������
MyInt& MyInt::operator++()
{
	*m_Num = *m_Num + 1;
	return *this;
}

//ǰ���Լ�
MyInt& MyInt::operator--()
{
	*m_Num = *m_Num - 1;
	return *this;
}

//���غ�������
MyInt MyInt::operator++(int) {
	MyInt temp = *(this->m_Num);
	m_Num++;
	return temp;
}

//���غ����Լ�
MyInt MyInt::operator--(int) {
	MyInt temp = *(this->m_Num);
	m_Num--;
	return temp;
}


//���ؼӵ���
MyInt& MyInt::operator+=(const MyInt& temp) {
	*(this->m_Num) += *(temp.m_Num);
	return *this;
}

//���ؼ�����
MyInt& MyInt::operator-=(const MyInt& temp) {
	*(this->m_Num) -= *(temp.m_Num);
	return *this;
}

//����ֵ�ж������
bool operator==(MyInt);

//�����������

//���ػ������

//���غ��������
