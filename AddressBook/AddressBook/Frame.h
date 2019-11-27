#pragma once
#include <iostream>
#include <string>
#include "Address.h"
#include "addPerson.h"
#include "showMenu.h"
#include "showPerson.h"
#include "isExist.h"
#include "deletePerson.h"
#include"findPerson.h"
#include "modPerson.h"

using namespace std;
//用于显示用户菜单
void showMenu(void);

//用于用户选择的框架
void Frame(int*, Addressbooks*);

//用于新增通讯地址
void addPerson(Addressbooks* abs);

//用于显示联系人
void showPerson(const Addressbooks*);

//用于检查联系人是否存在
int isExist(Addressbooks *, string);

//删除联系人
void deletePerson(Addressbooks*);

//查找联系人
void findPerson(Addressbooks*);

//修改联系人
void modPerson(Addressbooks*);