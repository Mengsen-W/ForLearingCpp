#pragma once
#include <iostream>

using namespace std;

class MyInt
{
	/*
	 * This Class MyInt is my learnting pverload operator in Cpp.
	*/
public:

	//Ĭ�Ϲ���
	MyInt();

	//���ι���
	MyInt(int);

	//��������
	~MyInt();

	//��������
	MyInt(const MyInt&);

	//���ص���
	MyInt& operator=(const MyInt&);

	//���ؼӷ������
	friend MyInt operator+(const MyInt&, int);
	//����ǰ������
	MyInt& operator++();

	//����ǰ���Լ�
	MyInt& operator--();

	//���غ�������
	MyInt operator++(int);

	//���غ����Լ�
	MyInt operator--(int);

	//���ؼӵ���
	MyInt& operator+=(const MyInt&);

	//���ؼ�����
	MyInt& operator-=(const MyInt&);

	//����ֵ�ж������
	bool operator==(MyInt);

	//�����������

	//���ػ������

	//���غ��������

protected:
private:
	int* m_Num;
};


