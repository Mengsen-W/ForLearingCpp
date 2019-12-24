#include <iostream>
#include <stdio.h>

int &test() {
  int a = 10;
  return a;
}

int main() {
  int &b = test();
  printf("%d", b);
  printf("%d", b);
  test() = 1000;
  printf("%d", b);
  printf("%d", b);
  return 0;
}
