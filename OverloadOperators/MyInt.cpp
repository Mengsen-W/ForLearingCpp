#include "MyInt.h"
#include <iostream>

//Ĭ�Ϲ���
MyInt::MyInt()
{
	this->m_Num = new int;
	*m_Num = 0;
}

//���ι���
MyInt::MyInt(int num)
{
	this->m_Num = new int;
	*m_Num = num;
}

//��������
MyInt::MyInt(const MyInt& temp)
{
	this->m_Num = new int(*temp.m_Num);
}

//���ظ�ֵ����
MyInt& MyInt::operator=(MyInt& p)
{
	{
		if (m_Num != NULL)
		{
			delete m_Num;
			m_Num = NULL;
		}
		m_Num = new int(*p.m_Num);
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
}
