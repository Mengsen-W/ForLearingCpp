/*
 * @Author: Mengsen.Wang
 * @Date: 2019-11-23 19:45:31
 * @Last Modified by: Mengsen.Wang
 * @Last Modified time: 2019-11-23 19:59:59
 */

#include <bits/c++config.h>
#include <cstdio>
#include <iostream>
#include <ostream>
#include <stdio.h>
#include <string>

using namespace std;

int main(void) {
  int a = 10;
  int b = 0x100F;
  printf("%d\n", b);
  cout << b << endl;
  cout << (size_t)&a << endl;
  cout << &a << endl;
  printf("%#X\n", &a);
  printf("%d\n", &a);
  return 0;
}
/*
int 类型 默认10进制输出
& 返回的是一个 void * 类型默认16进制输出
强制类型转换成 size_t 本质上还是整形 故以 10 进制输出
因为如果一个数是整形，那么这个数默认 10 进制输出
*/