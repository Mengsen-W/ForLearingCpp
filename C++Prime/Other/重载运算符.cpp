/*
 * @Author: Mengsen.Wang
 * @Date: 2019-12-04 18:50:16
 * @Last Modified by: Mengsen.Wang
 * @Last Modified time: 2019-12-09 18:46:44
 */

#include <iostream>
#include <ostream>
#include <string>
#include <type_traits>
using namespace std;
class MyInteger
{
  friend ostream &operator<<(ostream &, MyInteger &);

public:
  MyInteger()
  {
    m_Num = 0;
  }
  MyInteger &operator++()
  { // ++ 是一元运算符，返回调用成员本身
    //前置递增,相当于 空.operator++()
    //返回引用是为了对一个数进行递增操作，不能返回指针，因为下面的操作没有解引用操作
    m_Num++;
    return *this;
  }
  MyInteger operator++(int)
  {
    //后置++ int 是占位参数可以区分前置和后置
    MyInteger temp = *this; //记录当前本身的值，然后让本身的值加1，但是返回的是以前的值，达到先返回后++；
    m_Num++;
    return temp;
  }

private:
  int m_Num;
};

ostream &operator<<(ostream &cout, MyInteger &myint)
{
  cout << myint.m_Num;
  return cout;
}

void test01()
{
  MyInteger myint;
  cout << myint << endl;
  cout << ++myint << endl;
  myint.operator++();
  cout << myint << endl;
}

void test02()
{
  MyInteger myint;
  cout << myint++ << endl;
  cout << myint << endl;
}
int main(void)
{
  test01();
  return 0;
}