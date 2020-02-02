/*
 * @Author: Mengsen.Wang
 * @Date: 2020-01-31 10:38:36
 * @Last Modified by: Mengsen.Wang
 * @Last Modified time: 2020-01-31 12:28:41
 */
/**
 * 可能会有部分失败的原因是没有在 规模小于10 的时候调用插排
 */

#include <iostream>
#include <utility>
#include <vector>
using namespace std;
/**
 * 一种简单的递归快速排序算法
 */
template <typename Comparable>
void SORT(vector<Comparable>& items) {
  if (items.size() > 1) {
    vector<Comparable> smaller;
    vector<Comparable> same;
    vector<Comparable> larger;

    auto chosenItem = items[items.size() / 2];
    for (auto& i : items) {
      if (i < chosenItem)
        smaller.push_back(std::move(i));
      else if (chosenItem < i)
        larger.push_back(std::move(i));
      else
        same.push_back(std::move(i));
    }
    SORT(smaller);
    SORT(larger);

    std::move(begin(smaller), end(smaller), begin(items));
    std::move(begin(same), end(same), begin(items) + smaller.size());
    std::move(begin(larger), end(larger), end(items) - larger.size());
  }
}

/**
 * 三数中值分割法枢纽元
 * 返回 left center right 三项的中值
 * 将他们排序并隐匿枢纽元，将枢纽元放在 right - 1
 */

template <typename Comparable>
const Comparable& median3(vector<Comparable>& a, int left, int right) {
  int center = (left + right) / 2;

  if (a[center] < a[left]) std::swap(a[left], a[center]);
  if (a[right] < a[left]) std::swap(a[left], a[right]);
  if (a[right] < a[center]) std::swap(a[center], a[right]);

  std::swap(a[center], a[right - 1]);
  return a[right - 1];
}
/**
 * 进行递归调用的内部快速排序方法
 * 使用三数中值分割法，以及截至范围是10的截止技术
 * a 是 Comparable 项的数组
 * left 为子数组最左元素的下标
 * right 为子数组最右元素的下标
 */
template <typename Comparable>
void quickSort(vector<Comparable>& a, int left, int right) {
  if (left + 10 < right) {
    /*数组太小没必要快排，反而是插排会更简单，空间复杂度也低*/
    const Comparable& pivot = median3(a, left, right);

    //开始分割
    int i = left;       //左标记
    int j = right - 1;  // 右标记
    for (;;) {
      while (a[++i] < pivot) {
      } /* 直到遇到一个大于枢纽元的数*/
      while (pivot < a[--j]) {
      }          /* 直到遇到一个小于枢纽元的数*/
      if (i < j) /* 如果没有越界*/
        std::swap(a[i], a[j]);
      else /*i 在后半组的第一个位置*/
        break;
    }
    std::swap(a[i], a[right - 1]); /*恢复枢纽元*/
    quickSort(a, left, i - 1);     /*将小于枢纽元的元素排列*/
    quickSort(a, i + 1, right);    /*将大于枢纽元的元素排列*/
  }
}

/**
 * 快速排序算法(驱动程序)
 */
template <typename Comparable>
void quickSort(vector<Comparable>& a) {
  quickSort(a, 0, a.size() - 1);
}

/**
 * 一种更快的交换方式
 * 在 a[i] = a[j] = pivot 时出现无限循环
 * 因为只有while条件满足才会移动标记
 */
template <typename Comparable>
void quickSwap(vector<Comparable>& a, int left, int right, int pivot) {
  int i = left;
  int j = right - 2; /* right - 1 现在时 pivot*/
  for (;;) {
    while (a[i] < pivot) ++i;
    while (a[j] > pivot) --j;
    if (i < j)
      std::move(a[i], a[j]);
    else
      break;
  }
}

/**
 * 进行递归调用的内部选择方法
 * 使用三数中值分割法以及截至范围是10的截止技术
 * 把第 k 个最小项放在 a[k - 1] 处
 * a 为 Comparable 项的数组
 * left 是子数组最左元素的下标
 * right 为子数组最右元素的下标
 * k 是在整个数组中想要的排位
 * 时间复杂度 O(NlogN)
 */

template <typename Comparable>
void quickSelect(vector<Comparable>& a, int left, int right, int k) {
  if (left + 10 < right) {
    const Comparable& pivot = median3(a, left, right);
    //开始分割
    int i = left, j = right - 1;
    for (;;) {
      while (a[++i] < pivot) {
      }
      while (pivot < a[--j]) {
      }
      if (i < j)
        std::swap(a[i], a[j]);
      else
        break;
    }

    std::swap(a[i], a[right - 1]); /* 恢复枢纽元 */

    /**
     * 实施递归
     * 但是要判断前半组还是后半组
     * 因为不需要全部排序
     * 只需要用到的部分排序
     */
    if (k <= i)
      quickSelect(a, left, i - 1, k); /*k 从 1 计数*/
    else if (k > i + 1)
      quickSelect(a, i + 1, right, k);
  }
}

int main() {
  vector<int> a = {8, 1, 4, 9, 0, 3, 5, 2, 7, 6};
  quickSort<int>(a);
  for (int i = 0; i < a.size(); ++i) {
    cout << a[i] << '\t';
  }
  cout << endl;
  vector<int> b = {8, 1, 4, 9, 0, 3, 5, 2, 7, 6};

  quickSelect<int>(b, 0, b.size(), 6);
  cout << b[6 - 1] << endl;
  return 0;
}