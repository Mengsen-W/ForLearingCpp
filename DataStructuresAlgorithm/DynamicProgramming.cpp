/*
 * @Author: Mengsen.Wang
 * @Date: 2020-02-03 14:48:07
 * @Last Modified by: Mengsen.Wang
 * @Last Modified time: 2020-02-03 15:39:23
 */

#include <vector>

using namespace std;
/**
 * 递归方法调用斐波那契数列
 */
long long fib(int n) {
  if (n <= 1)
    return 1;
  else
    return fib(n - 1) + fib(n - 2);
}
/**
 * 利用循环构造斐波那契数列
 * 运用动态规划避免重复计算
 */
long long fibonacci(int n) {
  if (n <= 1) return 1;
  long long last = 1;        //储存 n - 1
  long long nextToLast = 1;  // 储存 n - 2
  long long answer = 1;      // 储存 n

  for (int i = 2; i <= n; ++i) {
    answer = last + nextToLast;
    nextToLast = last;
    last = answer;
  }
  return answer;
}

/**
 * 计算一个递归关系 P378 (公式7.14)
 */
double evalR(int n) {
  if (n == 0)
    return 1.0;
  else {
    double sum = 0.0;
    for (int i = 0; i < n; ++i) sum += evalR(i);
    return 2.0 * sum / n + n;
  }
}

/**
 * 非递归写法
 */
double evalC(int n) {
  vector<double> c(n + 1);
  c[0] = 1.0;
  for (int i = 1; i <= n; ++i) {
    double sum = 0.0;
    for (int j = 0; j < i; ++j) {
      sum += c[j];
      c[i] = 2.0 * sum / i + i;
    }
  }
  return c[n];
}

int main() {
  int a = 10;
  return 0;
}