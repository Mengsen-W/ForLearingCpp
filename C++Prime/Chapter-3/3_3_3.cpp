/*
 * @Author: Mengsen.Wang
 * @Date: 2019-12-19 18:14:26
 * @Last Modified by: Mengsen.Wang
 * @Last Modified time: 2019-12-19 19:26:58
 */

#include <cctype>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void test() {
    string str = "Hello World";
    string word;
    vector<string> text;
    cin >> word;
    text.push_back(word);
    for (int i = 0; i != text.size(); ++i) {
        for (auto &v : text[i]) {
            v = toupper(v);
            cout << v << endl;
    }
    }
    cout << text.size() << endl;
    cout << word.size() << endl;
    return;
}

int main(int argc, char *argv[]) {
    test();
    return 0;
}