/*
 * @Author: Mengsen.Wang
 * @Date: 2020-01-30 17:04:59
 * @Last Modified by: Mengsen.Wang
 * @Last Modified time: 2020-01-30 17:40:08
 */
#include <vector>
using namespace std;

/**
 * 使用一种流行但是不理想增量的希尔排序
 */
template <typename Comparable>
void shellSort(vector<Comparable>& a) {
  for (int gap = a.size() / 2; gap > 0; gap /= 2) {
    for (int i = gap; i < a.size(); ++i) {
      Comparable tmp = std::move(a[i]);
      int j = i;
      for (; j >= gap && tmp < a[j - gap]; j -= gap)
        a[j] = std::move(a[j - gap]);
      a[j] = std::move(tmp);
    }
  }
}
int main() { return 0; }