#pragma once
#include <iostream>
#include <string>
#include "Address.h"
#include "addPerson.h"
#include "showMenu.h"

using namespace std;
//用于显示用户菜单
void showMenu(void);

//用于用户选择的框架
void Frame(int*, Addressbooks*);

//用于新增通讯地址
void addPerson(Addressbooks* abs);

