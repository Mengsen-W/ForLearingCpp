/*
 * @Author: Mengsen.Wang
 * @Date: 2019-12-13 19:17:49
 * @Last Modified by: Mengsen.Wang
 * @Last Modified time: 2019-12-13 19:28:06
 */

#include <iostream>
#include <string>

std::string global_str;
int global_int;
int main() {
    int local_int;
    std::string local_str;
    std::cout << local_str << std::endl;
    std::cout << local_int << std::endl;
    std::cout << global_int << std::endl;
    std::cout << global_str << std::endl;
    return 0;
}
/*
    int local_int;
                 ^
                  = 0
1 warning generated.

1
0

*/
/*
* 1 str类型全部为空
* 2 int 类型，全局下初始化为0，局部下初始化为1.
* 3 强力建议初始化
*/
