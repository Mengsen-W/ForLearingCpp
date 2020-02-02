/*
 * @Author: Mengsen.Wang
 * @Date: 2020-01-30 18:15:35
 * @Last Modified by: Mengsen.Wang
 * @Last Modified time: 2020-01-30 19:31:11
 */
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

/**
 * 堆排序的内部方法
 * i 是堆中一项的下标
 * 返回左儿子的下标
 */
inline int leftChild(int i) { return 2 * i + 1; }

/**
 * 在 deleteMax 和 buildHeap 中用到的堆排序的内部方法
 * i 是开始下滤的位置
 * n 是二叉堆的逻辑大小
 */
template <typename Comparable>
void precDown(vector<Comparable>& a, int i, int n) {
  int child;
  Comparable tmp;
  for (tmp = std::move(a[i]); leftChild(i) < n; i = child) {
    child = leftChild(i);
    if (child != n - 1 && a[child] < a[child + 1]) child++;
    if (tmp < a[child])
      a[i] = std::move(a[child]);
    else
      break;
  }
  a[i] = std::move(tmp);
}

/**
 * 标准的堆排序
 */
template <typename Comparable>
void heapSort(vector<Comparable>& a) {
  for (int i = a.size() / 2 - 1; i >= 0; --i) { /* buildHeap */
    precDown(a, i, a.size());
  }
  for (int j = a.size() - 1; j > 0; --j) {
    std::swap(a[0], a[j]); /* deleteMax*/
    precDown(a, 0, j);
  }
}

int main() {
  vector<int> a = {31, 41, 59, 26, 53, 58, 97};
  heapSort<int>(a);
  for (int i = 0; i < a.size(); ++i) {
    cout << a[i] << endl;
  }
  return 0;
}