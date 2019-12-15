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
	MyInt operator=(int);

	//重载加法运算符
	//friend MyInt operator+(const MyInt&, int);
	friend MyInt operator+(int, const MyInt&);
	MyInt operator+(const MyInt&);

	//重载减法运算符
	//friend MyInt operator-(const MyInt&, int);
	friend MyInt operator-(int, const MyInt&);
	MyInt operator-(const MyInt&);

	//重载乘法运算符
	//friend MyInt operator*(const MyInt&, int);
	friend MyInt operator*(int, const MyInt&);
	MyInt operator*(const MyInt&);

	//重载除法运算符
	//friend MyInt operator/(const MyInt&, int);
	friend MyInt operator/(int, const MyInt&);
	MyInt operator/(const MyInt&);

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
	bool operator==(const MyInt&) const;
	friend bool operator==(int&,const MyInt &);
	friend bool operator==(const MyInt&, int&);

	//重载与运算符
	friend bool operator&&(const MyInt&, int&);
	friend bool operator&&(int&, const MyInt&);
	bool operator&&(const MyInt&) const;
	//重载或运算符
	friend bool operator||(const MyInt&, int&);
	friend bool operator||(int&, const MyInt&);
	bool operator||(const MyInt&) const;

	//重载函数运算符
	void operator()(const MyInt&) const;

	//重载左移运算符
	friend ostream& operator<<(ostream&, const MyInt&);

protected:
private:
	int* m_Num;
};


