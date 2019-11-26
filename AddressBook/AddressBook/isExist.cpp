#include <iostream>
#include <string>
#include "isExist.h"

using namespace std;

int isExist(Addressbooks* p, string name) {
	for (int i = 0; i < p->m_Size; ++i) {
		if (p->personArrary[i].m_Name == name)
		{
			return i;
		}
	}
	return -1;
}