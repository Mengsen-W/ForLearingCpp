/*
 * @Author: Mengsen.Wang
 * @Date: 2020-01-30 21:22:22
 * @Last Modified by: Mengsen.Wang
 * @Last Modified time: 2020-01-30 21:23:37
 */

#include <iostream>
#include <utility>
#include <vector>
using namespace std;

/**
 * 合并子数组已排序成两半部分的内部方法
 * a 为 Comparable 项的数组
 * tmpArray 为放置归并结果的数组
 * leftPos 为子数组最左元素的下标
 * leftEnd 为前半段数组终点的下标
 * rightPos 为后半段起点的下标
 * rightEnd 为子数组最右元素的下标
 */
template <typename Comparable>
void merge(vector<Comparable>& a, vector<Comparable>& tmpArray, int leftPos,
           int rightPos, int rightEnd) {
    int leftEnd = rightPos - 1;
    int tmpPos = leftPos;
    int numElements = rightEnd - leftPos + 1;

    // 主循环
    while (leftPos <= leftEnd && rightPos <= rightEnd)
      if (a[leftPos] <= a[rightPos])
        tmpArray[tmpPos++] = std::move(a[leftPos++]);
      else
        tmpArray[tmpPos++] = std::move(a[rightPos++]);

    while (leftPos <= leftEnd)  // 复制前半部分
      tmpArray[tmpPos++] = std::move(a[leftPos++]);
    while (rightPos <= rightEnd)  // 复制后半部分
      tmpArray[tmpPos++] = std::move(a[rightPos++]);

    //将 tmpArray 复制回原数组 a
    for (int i = 0; i < numElements; ++i, --rightEnd)
      a[rightEnd] = std::move(tmpArray[rightEnd]);
}

/**
 * 进行递归调用的内部方法
 * a 为 Comparable 项的数组
 * tmpArray 为放置归并结果的数组
 * left 为子数组最左原色的下标
 * right 为子数组最右元素的下标
 */
template <typename Comparable>
void mergeSort(vector<Comparable>& a, vector<Comparable>& tmpArray, int left,
               int right) {
  if (left < right) { /* 出口 */
    int center = (left + right) / 2;
    mergeSort(a, tmpArray, left, center);
    mergeSort(a, tmpArray, center + 1, right);
    merge(a, tmpArray, left, center + 1, right);
  }
}

/**
 * 归并排序算法（驱动程序）
 */
template <typename Comparable>
void mergeSort(vector<Comparable>& a) {
  vector<Comparable> tmpArray(a.size());
  mergeSort(a, tmpArray, 0, a.size() - 1);
}

int main() {
  vector<int> a = {24, 13, 26, 1, 2, 27, 38, 15};
  mergeSort<int>(a);
  for (int i = 0; i < a.size(); ++i) {
    cout << a[i] << endl;
  }
  return 0;
}