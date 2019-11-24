#pragma once
#include <iostream>
#include <string>
#define MAX 1000
using namespace std;

struct Person
{
	// 姓名
	string m_Name;
	// 性别 1-Male 0-Female
	int m_Sex = 0;
	// 年龄
	int m_Age = 0;
	// 电话
	string m_Phone;
	// 住址
	string m_Addr;
};

struct Addressbooks
{
	struct Person personArrary[MAX];
	int m_Size = 0;
};
