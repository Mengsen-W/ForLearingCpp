/*
 * @Author: Mengsen.Wang
 * @Date: 2020-01-29 09:28:57
 * @Last Modified by: Mengsen.Wang
 * @Last Modified time: 2020-01-29 11:27:03
 */

#include <vector>
using namespace std;

template <typename Comparable>
class BinaryHeap {
 public:
  explicit BinaryHeap(int capacity = 100);
  explicit BinaryHeap(const vector<Comparable>& item)
      : array(item.size() + 10), currentSize{item.size()} {
    for (int i = 0; i < item.size(); ++i) array[i + 1] = item[i];
    buildHeap();
  }
  bool isEmpty() const;
  const Comparable& findMin() const;

  /**
   * 将项 x 插入，允许重复元
   */
  void insert(const Comparable& x) {
    // 判断是否满了
    if (currentSize == array.size() - 1) array.resize(array.size() * 2);
    // 上滤
    int hole = ++currentSize;
    Comparable copy = x;

    array[0] = std::move(copy);

    for (; x < array[hole / 2]; hole /= 2)
      array[hole] = std::move(array[hole / 2]);
    array[hole] = std::move(array[0]);
  }

  void insert(Comparable&& x);
  /**
   * 删除最小项并将其放在 minItem 处
   * 若为空则抛异常
   */
  void deleteMin(Comparable& minItem) {
    if (isEmpty()) throw UnderflowException{};
    minItem = std::move(array[1]);
    array[1] = std::move(array[currentSize--]);
    percolateDown(1);
  }
  /**
   * 删除最小项
   * 若为空则抛出异常
   */
  void deleteMin() {
    if (isEmpty()) throw UnderflowException{};
    array[1] = std::move(array[currentSize--]);
    percolateDown(1);
  }

  void makeEmpty();

 private:
  int currentSize;           // 堆中的元素个数
  vector<Comparable> array;  // 堆的数组
  /**
   * 从项的任一排列建立起堆序性质
   * 以线性时间运行
  */
  void buildHeap(){
    for(int i = currentSize / 2; i > 0; --i)
    percolateDown(i);
  }
  /**
   * 在堆中惊醒下滤的内部方法
   * 空穴是下滤开始处的下标
   */
  void percolateDown(int hole) {
    int child;
    Comparable tmp = std::move(array[hole]);
    for (; hole * 2 <= currentSize; hole = child) {
      child = hole * 2;
      if (child != currentSize && array[child + 1] < array[child]) ++child;
      if (array[child] < tmp)
        array[hole] = std::move(array[child]);
      else
        break;
    }
    array[hole] = std::move(tmp);
  }
};

int main() { return 0; }