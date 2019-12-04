#pragma once
#include <iostream>

using namespace std;

class MyInt
{
public:
	MyInt();
	~MyInt();
	MyInt(const MyInt&);
	MyInt& operator=(MyInt& p);
	MyInt& operator++();
	MyInt& operator--();
protected:
private:
	int m_Num;
};

