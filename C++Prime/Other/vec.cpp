/*
 * @Author: Mengsen.Wang
 * @Date: 2019-12-17 18:48:04
 * @Last Modified by: Mengsen.Wang
 * @Last Modified time: 2019-12-17 19:02:22
 */

#include <iostream>
#include <vector>

void test() {
    std::vector<int> v;
    //v.reserve(10000000);
    int num = 0;
    int *p = nullptr;
    for (int i = 0; i < 10000000; ++i) {
        v.push_back(i);
        if (p != &v[0]) {
            p = &v[0];
            ++num;
        }
    }
    std::cout << num << std::endl;
}

int main() {
    test();
    return 0;
}