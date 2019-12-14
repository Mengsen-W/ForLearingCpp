#pragma once
#include <iostream>

using namespace std;

class MyInt
{
	/*
	 * This Class MyInt is my learnting pverload operator in Cpp.
	*/
public:

	//默认构造
	MyInt();

	//含参构造
	MyInt(int);

	//析构函数
	~MyInt();

	//拷贝构造
	MyInt(const MyInt&);

	//重载等于
	MyInt& operator=(const MyInt&);

	//重载加法运算符
	friend MyInt operator+(const MyInt&, int);
	//重载前置自增
	MyInt& operator++();

	//重载前置自减
	MyInt& operator--();

	//重载后置自增
	MyInt operator++(int);

	//重载后置自减
	MyInt operator--(int);

	//重载加等于
	MyInt& operator+=(const MyInt&);

	//重载减等于
	MyInt& operator-=(const MyInt&);

	//重载值判断运算符
	bool operator==(MyInt);

	//重载与运算符

	//重载或运算符

	//重载函数运算符

protected:
private:
	int* m_Num;
};


