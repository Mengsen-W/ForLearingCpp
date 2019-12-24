/*
 * @Author: Mengsen.Wang
 * @Date: 2019-12-19 17:41:57
 * @Last Modified by: Mengsen.Wang
 * @Last Modified time: 2019-12-19 18:58:48
 */

#include <iostream>
#include <string>

using namespace std;

void test() {
    string str = "Hello World";
    for (auto &c : str) {
        cout << c << endl;
    }
    cout << str << endl;
}

void test01(){
    string str = "Hello World";
    for (decltype(str.size()) index = 0; index != str.size(); ++index) {
        str[index] = 'X';
        // 这里注意每一个string内部其实是字符 char
    }
    cout << str << endl;
}

void test02(){
    string str = "Hello World";
    for (char &c : str) {
        // char 和 auto 是一样的
        string::size_type i = 0;
        c = 'X';
        ++i;
    }
    cout << str << endl;
}


int main(int argc, char *argv[]) {
    //test();
    //test01();
    //test02();
    return 0;
}