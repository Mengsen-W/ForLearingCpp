#include "MyInt.h"
#include <iostream>

//默认构造
MyInt::MyInt() {
	this->m_Num = new int(0);
	//cout << "默认构造" << endl;
}

//含参构造
MyInt::MyInt(int num) {
	this->m_Num = new int(num);
	//cout << "含参构造" << endl;
}

//拷贝函数
MyInt::MyInt(const MyInt& temp) {
	this->m_Num = new int(*(temp.m_Num));
	//cout << "拷贝构造" << endl;
}

//重载赋值符号
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

MyInt MyInt::operator=(int val) {
	MyInt temp;
	*(temp.m_Num) = val;
	return temp;
}

//析构函数
MyInt::~MyInt() {
	if (this->m_Num != NULL)
	{
		delete m_Num;
		m_Num = NULL;
	}
	//cout << "析构函数" << endl;
}

//加法运算符
//MyInt operator+(const MyInt& temp1, int val) {
//	MyInt temp;
//	*(temp.m_Num) = *(temp1.m_Num) + val;
//	return temp;
//}


MyInt operator+(int val, const MyInt& temp1) {
	MyInt temp;
	*(temp.m_Num) = val + *(temp1.m_Num);
	return temp;
}

MyInt MyInt::operator+(const MyInt& temp1) {
	MyInt temp;
	*(temp.m_Num)= *(this->m_Num) + *(temp1.m_Num);
	return temp;
}

//减法运算符
//MyInt operator-(const MyInt& temp1, int val) {
//	MyInt temp;
//	*(temp.m_Num) = *(temp1.m_Num) - val;
//	return temp;
//}

MyInt operator-(int val, const MyInt& temp1) {
	MyInt temp;
	*(temp.m_Num) = val - *(temp1.m_Num);
	return temp;
}


MyInt MyInt::operator-(const MyInt& temp1) {
	MyInt temp;
	*(temp.m_Num)= *(this->m_Num) - *(temp1.m_Num);
	return temp;
}

//乘法运算符

MyInt operator*(int val, const MyInt &temp1) {
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

MyInt MyInt::operator*(const MyInt& temp1) {
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

//除法运算符
//MyInt operator/(const MyInt& temp1, int val) {
//	MyInt temp;
//	if (val == 0) {
//		cout << "/0?" << endl;
//		*(temp.m_Num) = NULL;
//		return temp;
//	}
//	else {
//		if (*(temp1.m_Num) == 0) {
//			(temp.m_Num) = 0;
//			return temp;
//		}
//		else {
//			*(temp.m_Num) = *(temp.m_Num) / val;
//			return temp;
//		}
//	}
//}

MyInt operator/(int val, const MyInt& temp1) {
	MyInt temp;
	if (*(temp1.m_Num) == 0) {
		cout << "/0?" << endl;
		*(temp.m_Num) = NULL;
		return temp;
	}
	else {
		if (val == 0) {
			(temp.m_Num) = 0;
			return temp;
		}
		else {
			*(temp.m_Num) = val / *(temp.m_Num);
			return temp;
		}
	}
}
MyInt MyInt::operator/(const MyInt& temp1) {
	MyInt temp;
	if (*(temp1.m_Num) == 0) {
		cout << "/0?" << endl;
		*(temp.m_Num) = 0;
		return temp;
	}
	else {
		if (*(temp.m_Num) == 0) {
			*(temp.m_Num) = 0;
			return temp;
		}
		else {
			*(temp.m_Num) = *(temp.m_Num) / *(temp.m_Num);
			return temp;
		}
	}
}

//前置自增
MyInt& MyInt::operator++() {
	*m_Num = *m_Num + 1;
	return *this;
}

//前置自减
MyInt& MyInt::operator--() {
	*m_Num = *m_Num - 1;
	return *this;
}

//重载后置自增
MyInt MyInt::operator++(int) {
	MyInt temp = *(this->m_Num);
	++(*(this->m_Num));
	return temp;
}

//重载后置自减
MyInt MyInt::operator--(int) {
	MyInt temp = *(this->m_Num);
	--(*(this->m_Num));
	return temp;
}


//重载加等于
MyInt& MyInt::operator+=(const MyInt& temp) {
	*(this->m_Num) += *(temp.m_Num);
	return *this;
}

//重载减等于
MyInt& MyInt::operator-=(const MyInt& temp) {
	*(this->m_Num) -= *(temp.m_Num);
	return *this;
}

//重载值判断运算符
bool MyInt::operator==(const MyInt &temp) const {
	if (*(this->m_Num) == *(temp.m_Num))
		return true;
	else
	{
		return false;
	}
}

bool operator==(int& val, const MyInt& temp) {
	if (*(temp.m_Num) == val)
		return true;
	else
	{
		return false;
	}
}

bool operator==(const MyInt& temp, int& val) {
	if (*(temp.m_Num) == val)
		return true;
	else
	{
		return false;
	}
}

//重载与运算符
bool operator&&(const MyInt& temp, int& val) {
	if (*(temp.m_Num) == 0 || val == 0)
		return false;
	else
		return true;
}

bool operator&&(int& val,const MyInt& temp) {
	if (*(temp.m_Num) == 0 || val == 0)
		return false;
	else
		return true;
}

bool MyInt::operator&&(const MyInt& temp) const{
	if (*(temp.m_Num) == 0 || *(this->m_Num) == 0)
		return false;
	else
		return true;
}

//重载或运算符
bool operator||(const MyInt& temp, int& val) {
	if (*(temp.m_Num) != 0 || val != 0)
		return true;
	else
		return false;
}

bool operator||(int& val, const MyInt& temp) {
	if (*(temp.m_Num) != 0 || val != 0)
		return true;
	else
		return false;
}

bool MyInt::operator||(const MyInt& temp) const {
	if (*(temp.m_Num) != 0 || *(this->m_Num) != 0)
		return true;
	else
		return false;
}

//重载函数运算符
void MyInt::operator()(const MyInt& temp) const {
	cout << *(temp.m_Num) << endl;
}


//重载左移运算符
ostream& operator<<(ostream& out, const MyInt& temp) {
	out << *(temp.m_Num);
	return out;
}
