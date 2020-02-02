/*
 * @Author: Mengsen.Wang
 * @Date: 2020-01-30 09:19:55
 * @Last Modified by: Mengsen.Wang
 * @Last Modified time: 2020-01-30 09:23:23
 */
#include <utility>
#include <vector>
using namespace std;

template <typename Comparable>
class BinomialQueue {
 public:
  BinomialQueue();
  BinomialQueue(const Comparable& item);
  BinomialQueue(const BinomialQueue& rhs);
  BinomialQueue(BinomialQueue&& rhs);
  BinomialQueue& operator=(const BinomialQueue& rhs);
  BinomialQueue& operator=(BinomialQueue&& rhs);
  ~BinomialQueue();

  bool isEmpty() const;

  const Comparable& findMin() const;

  void insert(const Comparable& x);
  void insert(Comparable&& x);
  void deleteMin();

  /**
   * 删除最小项并放入minItem
   * 若为空，则抛出异常
   */
  void deleteMin(Comparable& minItem) {
    if (isEmpty()) throw;
    int minIndex = findMinIndex();
    minItem = theTrees[minIndex]->element;

    BinomialNode* oldRoot = theTrees[minIndex];
    BinomialNode* deletedTree = oldRoot->leftChild;
    delete oldRoot;

    // 构建 H'' 删除后的那一个二项堆的分裂
    BinomialQueue deletedQueue;
    deletedQueue.theTrees.resize(minIndex + 1);
    deletedQueue.currentSize = (1 << minIndex) - 1;
    for (int j = minIndex - 1; j >= 0; --j) {
      deletedQueue.theTrees[j] = deletedTree;
      deletedTree = deletedTree->nextSibling;
      deletedQueue.theTrees[j]->nextSibling = nullptr;
    }

    //构建 H' 删除过的二项树
    theTrees[minIndex] = nullptr;
    currentSize -= deletedQueue.currentSize + 1;
    merge(deletedQueue);
  }

  void makeEmpty();

  /**
   * 将 rhs 合并到优先队列中
   * rhs 变为空， rhs 不同于 this
   */
  void merge(BinomialQueue& rhs) {
    if (this == &rhs) return;

    currentSize += rhs.currentSize;

    if (currentSize > capacity()) {
      int oldNumTrees = theTrees.size();
      int newNumTrees = max(theTrees.size(), rhs.theTrees.size()) + 1;
      theTrees.resize(newNumTrees);
      for (int i = oldNumTrees; i < newNumTrees; ++i) theTrees[i] = nullptr;
    }
    BinomialNode* carry = nullptr;  // 上一步合并而来的树
    for (int i = 0, j = 1; j <= currentSize; ++i, j *= 2) {
      BinomialNode* t1 = theTrees[i];
      BinomialNode* t2 = i < rhs.theTrees.size() ? rhs.theTrees[i] : nullptr;
      int whichCase = t1 == nullptr ? 0 : 1;
      whichCase += t2 == nullptr ? 0 : 2;
      whichCase += carry == nullptr ? 0 : 4;

      switch (whichCase) {
        case 0:  // 无树的情况
        case 1:  //只有this的情况
          break;
        case 2:  // 只有 rhs 的情况
          theTrees[i] = t2;
          rhs.theTrees[i] = nullptr;
          break;
        case 4:  // 只有carry的情况
          theTrees[i] = carry;
          carry = nullptr;
          break;
        case 3:  // this 和 rhs 的情况
          carry = combinTrees(t1, t2);
          theTrees[i] = nullptr;
          break;
        case 5:  // this 和 carry 的情况
          carry = combineTrees(t1, carry);
          theTrees[i] = nullptr;
          break;
        case 6:  // rhs 和 carry 的情况
          carry = combineTrees(t2, carry);
          rhs.theTrees[i] = nullptr;
          break;
        case 7:  // 全体树的情况
          theTrees[i] = carry;
          carry = combineTrees(t1, t2);
          rhs.theTrees[i] = nullptr;
          break;
      }
    }
    for (auto& root : rhs.theTrees) root = nullptr;
    rhs.currentSize = 0;
  }

 private:
  // 结点的结构
  struct BinomialNode {
    Comparable element;         //存储信息
    BinomialNode* leftChild;    // 指向左儿子
    BinomialNode* nextSibling;  // 指向右兄弟
    BinomialNode(const Comparable& e, BinomialNode* lt, BinomialNode* rt)
        : element{e}, leftChild{lt}, nextSibling{rt} {}
    BinomialNode(Comparable&& e, BinomialNode* lt, BinomialNode* rt)
        : element{std::move(e)}, leftChild{lt}, nextSibling{rt} {}
  };

  const static int DEFAULT_TREES = 1;

  vector<BinomialNode*> theTrees;  //  树根组成的数组
  int currentSize;                 //  优先队列中的项数

  /**
   * 找出包含优先队列中最小的树的下标
   * 这个优先队列不能为空
   * 返回包含最小项的下标
   */
  int findMinIndex() const {
    int i;
    int minIndex;
    if (isEmpty()) throw;

    //找第一个不空的下标
    for (i = 0; theTrees[i] == nullptr; ++i)
      ;
    for (minIndex = i; i < theTrees.size(); ++i) {
      if (theTrees[i] != nullptr &&
          theTrees[i]->element < theTrees[minIndex]->element)
        minIndex = i;
    }
    return minIndex;
  }
  int capacity() const;

  /**
   * 返回合并 t1 和 t2 的结果，其中 t1 和 t2 大小相同
   * 默认 t1 的根节点小
   */
  BinomialNode* combineTrees(BinomialNode* t1, BinomialNode* t2) {
    if (t2->element < t1->element) return conbineTrees(t2, t1);
    t2->nextSibling = t1->leftChild;
    t1->leftchild = t2;
    return t1;
  }
  void makeEmpty(BinomialNode*& t);
  BinomialNode* clone(BinomialNode* t) const;
};

int main() { return 0; }