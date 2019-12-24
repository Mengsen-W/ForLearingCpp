#include <bits/c++config.h>
#include <stdio.h>
#include <cstdio>
#include <iostream>
#include <ostream>
#include <string>

using namespace std;

int main(void) {
  int a = 10;
  int &b = a;
  cout << &a << endl;
  cout << &b << endl;

  return 0;
}