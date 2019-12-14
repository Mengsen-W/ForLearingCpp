/*
 * @Author: Mengsen.Wang
 * @Date: 2019-12-13 14:27:53
 * @Last Modified by: Mengsen.Wang
 * @Last Modified time: 2019-12-13 14:49:47
 */
#include <iostream>

int main() {
    unsigned u = 10, u2 = 42;
    std::cout << u2 - u << std::endl;
    std::cout << u - u2 << std::endl;

    int i = 10, i2 = 42;
    std::cout << i2 - i << std::endl;
    std::cout << i - i2 << std::endl;
    std::cout << i - u << std::endl;
    std::cout << u - i << std::endl;
   //字符串是 const 区 不加 const会
   // ISO C++11 does not allow conversion from string literal to 'char *'
    const char *p = "HelloWorld";
    std::cout << *(p+5) << std::endl;

    return 0;
}

/*
32
4294967264
32
-32
0
0
*/


/*
   * 有无符号参与全部为无符号
   * 无符号没有负值
*/
