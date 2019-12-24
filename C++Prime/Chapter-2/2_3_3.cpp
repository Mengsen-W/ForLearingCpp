/*
 * @Author: Mengsen.Wang
 * @Date: 2019-12-15 09:46:50
 * @Last Modified by: Mengsen.Wang
 * @Last Modified time: 2019-12-19 18:01:04
 */

#include <iostream>

int main() {
    int *p1 = nullptr;
    int a = 1;
    p1 = &a;
    std::cout << 'a' << ' ' << '=' << ' ' << a << std::endl;
    std::cout << "p1 = " << p1 << std::endl;
    p1 = nullptr;
    std::cout << "p1 = " << p1 << std::endl;

    int *p2 = nullptr;
    std::cout << "p2 = " << p2 << std::endl;
}


//测试指针
/**
 * a = 1
 * p1 = 0x61fe08
 * p1 = 0
 * p2 = 0
*/

/**
 * 可以在声明的时候直接初始化
 * 可以在实用完成后初始化
*/