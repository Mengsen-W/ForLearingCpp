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
	MyInt operator=(int);

	//���ؼӷ������
	//friend MyInt operator+(const MyInt&, int);
	friend MyInt operator+(int, const MyInt&);
	MyInt operator+(const MyInt&);

	//���ؼ��������
	//friend MyInt operator-(const MyInt&, int);
	friend MyInt operator-(int, const MyInt&);
	MyInt operator-(const MyInt&);

	//���س˷������
	//friend MyInt operator*(const MyInt&, int);
	friend MyInt operator*(int, const MyInt&);
	MyInt operator*(const MyInt&);

	//���س��������
	//friend MyInt operator/(const MyInt&, int);
	friend MyInt operator/(int, const MyInt&);
	MyInt operator/(const MyInt&);

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
	bool operator==(const MyInt&) const;
	friend bool operator==(int&,const MyInt &);
	friend bool operator==(const MyInt&, int&);

	//�����������
	friend bool operator&&(const MyInt&, int&);
	friend bool operator&&(int&, const MyInt&);
	bool operator&&(const MyInt&) const;
	//���ػ������
	friend bool operator||(const MyInt&, int&);
	friend bool operator||(int&, const MyInt&);
	bool operator||(const MyInt&) const;

	//���غ��������
	void operator()(const MyInt&) const;

	//�������������
	friend ostream& operator<<(ostream&, const MyInt&);

protected:
private:
	int* m_Num;
};


