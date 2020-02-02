/*
 * @Author: Mengsen.Wang
 * @Date: 2020-01-30 15:35:33
 * @Last Modified by: Mengsen.Wang
 * @Last Modified time: 2020-01-30 16:00:37
 */
#include <utility>
#include <vector>
using namespace std;

/**
 * 简单的插入排序
 */
template <typename Comparable>
void insertionSort(vector<Comparable>& a) {
  for (int p = 1; p < a.size(); ++p) {
    Comparable tmp = std::move(a[p]);
    int j;
    for (j = p; j > 0 && tmp < a[j - 1]; --j) a[j] = std::move(a[j - 1]);
    a[j] = std::move(tmp);
  }
}

/**
 * 2-参数版排序调用3-参数版排序
 * 用 decltype
 */
template <typename Iterator>
void insertionSort(const Iterator& begin, const Iterator& end) {
  insertionSort(begin, end, less<decltype(*begin)>{});
}

/**
 * 3-参数版排序
 * 用 decltype
 */
template <typename Iterator, typename Comparator>
void insertionSort(const Iterator& begin, const Iterator& end,
                   Comparator lessThan) {
  if (begin == end) return;
  Iterator j;
  for (Iterator p = begin + 1; p != end; ++p) {
    auto tmp = std::move(*p);
    for (j = p; j != begin && lessThan(tmp, *(j - 1)); --j)
      *j = std::move(*(j - 1));
    *j = std::move(tmp);
  }
}