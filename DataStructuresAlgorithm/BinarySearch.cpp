/*
 * @Author: Mengsen.Wang
 * @Date: 2020-01-24 14:19:39
 * @Last Modified by: Mengsen.Wang
 * @Last Modified time: 2020-02-04 16:42:41
 */

/**
 * 每次循环使用两次比较以执行标准的折半查找
 * 找到时返回所求想的下标，找不到返回 -1
 * 给定的序列已经排序过
 * 复杂度 O(logN)
 */

#include <iostream>
#include <vector>
#define NOT_FOUND -1

using namespace std;

template <typename Comparable>
int binarySearch(const vector<Comparable>& a, const Comparable x) {
  int low = 0, high = a.size() - 1;

  while (low <= high) {
    int mid = (low + high) / 2;
    if (a[mid] < x)
      low = mid + 1;
    else if (a[mid] > x)
      high = mid - 1;
    else
      return mid;
  }
  return NOT_FOUND;
}

int main() {
  vector<int> testList = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  int testNum = 8;
  int testSearch = 0;
  testSearch = binarySearch(testList, testNum);

  cout << testSearch << endl;
  return 0;
}