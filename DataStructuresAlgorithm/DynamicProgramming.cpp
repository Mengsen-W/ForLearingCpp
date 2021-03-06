/*
 * @Author: Mengsen.Wang
 * @Date: 2020-02-03 14:48:07
 * @Last Modified by: Mengsen.Wang
 * @Last Modified time: 2020-02-03 19:28:10
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

/**
 * 计算矩阵乘法的最优排列
 * c 包含 n 个矩阵每个矩阵的列数
 * c[0] 为矩阵1的行数
 * 乘法的最少次数置于 m[l][n] 中
 * 具体的排序通过使用 lastChange 的另外过程来计算
 * m 和 lastChange 的下标从 1 开始，而不是从 0 开始
 * 注意： m 和 lastChange 主对角线下方的元素无意义
 * 不用初始化
 */
void optMatrix(const vector<int> &c, vector<vector<int> > &m,
               vector<vector<int> > &lastChange) {
  static const int INFINITY = 10000000;
  int n = c.size() - 1;

  for (int left = 1; left <= n; ++left) m[left][left] = 0;

  for (int k = 1; k < n; ++k)  // k 为 right - left
    for (int left = 1; left <= n - k; ++left) {
      // 对每一个位置进行
      int right = left + k;
      m[left][right] = INFINITY;
      for (int i = left; i < right; ++i) {
        int thisCost =
            m[left][i] + m[i + 1][right] + c[left - 1] * c[i] * c[right];
        if (thisCost < m[left][right]) {
          m[left][right] = thisCost;
          lastChange[left][right] = i;
        }
      }
    }
}

/**
 * 计算所有点对的路径
 * a 包含邻接矩阵
 * a[i][i] 假设为0
 * d 包含最短路径的值
 * 顶点从 0 开始编号
 * 所有的数组维数相等
 * 如果 d[i][i] 置为负值，则负值圈存在
 * 具体路径可以用 path[][] 来计算
 * NOT_A_VERTES 为 -1
 */
void allPairs(const vector<vector<int> > &a, vector<vector<int> > &d,
              vector<vector<int> > &path) {
  static const int NOT_A_VERTES = -1;
  int n = a.size();

  // 初始化 d 和 path
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      d[i][j] = a[i][j];
      path[i][j] = NOT_A_VERTES;
    }
  }
  for (int k = 0; k < n; ++k) {
    // 把每个顶点看作为一个中间节点
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        if (d[i][k] + d[k][j] < d[i][j]) {
          // 更新最短路径
          d[i][j] = d[i][k] + d[k][j];
          path[i][j] = k;
        }
  }
}
int main() {
  int a = 10;
  return 0;
}