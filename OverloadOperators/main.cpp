/**
* 自己写了一个 MyInt 用于练习重载
*/

#include <iostream>
#include "MyInt.h"

using namespace std;
int main() {
	int val1 = 0;
	int val2 = 1;
	int val3 = 2;
	MyInt myInt1;
	MyInt myInt2 = 5;
	MyInt myInt3 = myInt1;
	MyInt myInt4(10);
	MyInt myInt5(100);

	cout << myInt1++ << endl;
	cout << myInt1 << endl;
	cout << ++myInt2 << endl;
	cout << myInt2 << endl;
	cout << myInt1-- << endl;
	cout << myInt1 << endl;
	cout << --myInt2 << endl;
	cout << myInt2 << endl;
	myInt4(myInt1);

	cout << myInt1 * myInt2 << endl;
	cout << myInt2 * myInt4 << endl;
	cout << myInt2 * 10 << endl;
	cout << 10 * myInt2 << endl;
	cout << 0 * myInt2 << endl;

	cout << myInt1 / myInt2 << endl;
	cout << myInt4 / myInt2 << endl;
	cout << myInt4 / 2 << endl;
	cout << 50 / myInt4 << endl;

	return 0;
}