/*
 * @Author: Mengsen.Wang
 * @Date: 2020-01-21 09:17:32
 * @Last Modified by: Mengsen.Wang
 * @Last Modified time: 2020-01-21 09:26:39
 */

/*
  * 实现传入一个正整数N的参数后
  * 能顺序的打印1到N的全部正整数
*/

#include <iostream>
using namespace std;

void PrintNC(int n) {
    int i = 0;
    for (i = 1; i <= n; ++i){
        cout << i << endl;
   }
   return;
}

void PrintNR(int n ) {
    if(n) {
        PrintNR(n - 1);
        cout << n << endl;
    }
    return;
}

int main() {
    int n = 10000;
    PrintNC(n);
    PrintNR(n);
    return 0;
}

// [Done] exited with code=0 in 0.608 seconds
// [Done] exited with code=0 in 0.946 seconds