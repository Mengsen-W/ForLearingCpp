#include "MyInt.h"
#include <iostream>

//默认构造
MyInt::MyInt()
{
	this->m_Num = new int(0);
	cout << "默认构造" << endl;
}

//含参构造
MyInt::MyInt(int num)
{
	this->m_Num = new int(num);
	cout << "含参构造" << endl;
}

//拷贝函数
MyInt::MyInt(const MyInt& temp)
{
	this->m_Num = new int(*temp.m_Num);
	cout << "拷贝构造" << endl;
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
		this->m_Num = new int(*p.m_Num);
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
	cout << "析构函数" << endl;
}

//前置自增
MyInt& MyInt::operator++()
{
	m_Num = m_Num + 1;
	return *this;
}

//前置自减