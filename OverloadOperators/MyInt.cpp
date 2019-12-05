#include "MyInt.h"
#include <iostream>

//默认构造
MyInt::MyInt()
{
	this->m_Num = new int;
	*m_Num = 0;
}

//含参构造
MyInt::MyInt(int num)
{
	this->m_Num = new int;
	*m_Num = num;
}

//拷贝函数
MyInt::MyInt(const MyInt& temp)
{
	this->m_Num = new int(*temp.m_Num);
}

//重载赋值符号
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

//析构函数
MyInt::~MyInt()
{
	if (this->m_Num != NULL)
	{
		delete m_Num;
		m_Num = NULL;
	}
}
