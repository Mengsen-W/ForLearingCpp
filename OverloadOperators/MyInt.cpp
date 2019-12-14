#include "MyInt.h"
#include <iostream>

//Ĭ�Ϲ���
MyInt::MyInt() {
	this->m_Num = new int(0);
	cout << "Ĭ�Ϲ���" << endl;
}

//���ι���
MyInt::MyInt(int num) {
	this->m_Num = new int(num);
	cout << "���ι���" << endl;
}

//��������
MyInt::MyInt(const MyInt& temp) {
	this->m_Num = new int(*temp.m_Num);
	cout << "��������" << endl;
}

//���ظ�ֵ����
MyInt& MyInt::operator=(const MyInt& p) {
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
MyInt::~MyInt() {
	if (this->m_Num != NULL)
	{
		delete m_Num;
		m_Num = NULL;
	}
	cout << "��������" << endl;
}

//�ӷ������
MyInt& operator+(const MyInt& temp1, int val) {
	MyInt temp;
	*(temp.m_Num) = *(temp1.m_Num) + val;
	return temp;
}


MyInt& operator+(int val, const MyInt& temp1) {
	MyInt temp;
	*(temp.m_Num) = val + *(temp1.m_Num);
	return temp;
}

MyInt& MyInt::operator+(const MyInt& temp1) {
	MyInt temp;
	*(temp.m_Num)= *(this->m_Num) + *(temp1.m_Num);
	return temp;
}

//���������
MyInt& operator-(const MyInt& temp1, int val) {
	MyInt temp;
	*(temp.m_Num) = *(temp1.m_Num) - val;
	return temp;
}

MyInt& operator-(int val, const MyInt& temp1) {
	MyInt temp;
	*(temp.m_Num) = val - *(temp1.m_Num);
	return temp;
}


MyInt& MyInt::operator-(const MyInt& temp1) {
	MyInt temp;
	*(temp.m_Num)= *(this->m_Num) - *(temp1.m_Num);
	return temp;
}

//�˷��������
MyInt& operator*(const MyInt& temp1, int val) {
	MyInt temp;
	if (val == 0 && *(temp1.m_Num) == 0){
		*(temp.m_Num) = 0;
		return temp;
	}
	else{
		*(temp.m_Num) = *(temp1.m_Num) * val;
		return temp;
	}
}

MyInt& MyInt::operator-(const MyInt& temp1) {
	MyInt temp;
	if (*(this->m_Num) == 0 && *(temp1.m_Num) == 0){
		*(temp.m_Num) = 0;
		return temp;
	}
	else{
		*(temp.m_Num) = *(temp1.m_Num) * *(this->m_Num);
		return temp;
	}
}

//���������
MyInt& operator/(const MyInt& temp1, int val) {
	MyInt temp;
	if (val == 0) {
		cout << "/0?" << endl;
		*(temp.m_Num) = NULL;
		return temp;
	}
	else {
		if (*(temp1.m_Num) == 0) {
			(temp.m_Num) = 0;
			return temp;
		}
		else {
			*(temp.m_Num) = *(temp.m_Num) / val;
			return temp;
		}
	}
}

MyInt& MyInt::operator-(const MyInt& temp1) {
	MyInt temp;
	*(temp.m_Num)= *(this->m_Num) - *(temp1.m_Num);
	return temp;
}

//ǰ������
MyInt& MyInt::operator++() {
	*m_Num = *m_Num + 1;
	return *this;
}

//ǰ���Լ�
MyInt& MyInt::operator--() {
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
