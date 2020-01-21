/*
 * @Author: Mengsen.Wang
 * @Date: 2020-01-21 09:28:40
 * @Last Modified by: Mengsen.Wang
 * @Last Modified time: 2020-01-21 11:07:09
 */

/*
  * 多项式的两种实现方式
*/

#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

#define MAXN 10
#define MAXK 1e10

clock_t start, stop;
/* clock_t 是 clock() 函数返回的变量类型*/
double duration;
/* 记录被测函数的运行时间，以秒为单位*/

double Polynomial1 (int n, double a[], double x ) {
    int i = 0;
    double p = a[0];
    for ( i = 1; i <= n; ++i) {
        p += (a[i] * pow(x, i));
    }
    return p;
}

// 秦九韶算法
double Polynomial2 (int n, double a[], double x) {
    int i = 0;
    double p = a[n];
    for ( i = n; i > 0; --i) {
        p = a[i - 1] + x * p;
    }
    return p;
}

int main() {
    // 函数的前期工作 算 1 到 9 的 求和
    int i = 0;
    double a[MAXN];
    for (i = 0; i < MAXN; ++i) {
        a[i] = (double)i;
    }
    //  计时工作
    start = clock();
    for ( i = 0; i < MAXK; ++i)
        Polynomial1(MAXN - 1, a, 1.1);
    stop = clock();
    duration = ((double)(stop - start)) / CLK_TCK;
    cout << duration << endl;

    start = clock();
    for ( i = 0; i < MAXK; ++i)
        Polynomial2(MAXN - 1, a, 1.1);
    stop = clock();
    duration = ((double)(stop - start)) / CLK_TCK;
    cout << duration << endl;

    return 0 ;
}