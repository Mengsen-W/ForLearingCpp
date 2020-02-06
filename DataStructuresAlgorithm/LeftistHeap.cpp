/*
 * @Author: Mengsen.Wang
 * @Date: 2020-01-29 16:27:46
 * @Last Modified by: Mengsen.Wang
 * @Last Modified time: 2020-01-29 18:35:46
 */
#include <utility>

template <typename Comparable>
class LeftistHeap {
 public:
  LeftistHeap();
  LeftistHeap(const LeftistHeap& rhs);
  LeftistHeap(LeftistHeap&& rhs);
  ~LeftistHeap();
  LeftistHeap& operator=(const LeftistHeap& rhs);
  LeftistHeap& operator=(LeftistHeap&& rhs);

  bool isEmpty() const;
  const Comparable& findMin() const;

  void insert(const Comparable& x);
  void insert(Comparable&& x);
  void deleteMin();
  void deleteMin(Comparable& minItem);
  void makeEmpty();
  void merge(LeftistHeap& rhs);

 private:
  struct LeftistNode {
    Comparable element;
    LeftistNode* left;
    LeftistNode* right;
    int npl;  // 零路径长
    LeftistNode(const Comparable& e, LeftistNode* lt = nullptr,
                LeftistNode* rt = nullptr, int np = 0)
        : element{e}, left{lt}, right{rt}, npl{np} {}
    LeftistNode(Comparable&& e, LeftistNode* lt = nullptr,
                LeftistNode* rt = nullptr, int np = 0)
        : element{std::move(e)}, left{lt}, right{rt}, npl{np} {}
  };

  LeftistNode* root;
  LeftistNode* merge(LeftistNode* h1, LeftistNode* h2);
  LeftistNode* mergel(LeftistNode* h1, LeftistNode* h2);

  void swapChildren(LeftistNode* t);
  void reclaimMemory(LeftistNode* t);
  LeftistNode* clone(LeftistNode* t);
};

/**
 * 将 rhs 合并到优先队列
 * rhs 变为空，rhs 必须不同于 this
 */
template <typename Comparable>
void LeftistHeap<Comparable>::merge(LeftistHeap<Comparable>& rhs) {
  if (this == &rhs)  //比较指针
    return;
  root = merge(root, rhs.root);
  rhs.root = nullptr;
}

/**
 * 合并两个根的内部方法
 * 处理不正常情形并调用递归的 mengel
 */
template <typename Comparable>
typename LeftistHeap<Comparable>::LeftistNode* LeftistHeap<Comparable>::merge(
    LeftistNode* h1, LeftistNode* h2) {
  if (h1 == nullptr) return h2;
  if (h2 == nullptr) return h1;
  if (h1->element < h2->element)
    return mergel(h1, h2);
  else
    return mergel(h2, h1);
}

/**
 * 合并两个根的内部方法
 * 假设树非空，并且 h1 的根是最小项
 */
template <typename Comparable>
typename LeftistHeap<Comparable>::LeftistNode* LeftistHeap<Comparable>::mergel(
    LeftistNode* h1, LeftistNode* h2) {
  if (h1->left == nullptr)  //单节点
    h1->left = h2;
  else {
    h1->right = merge(h1->right, h2);
    if (h1->left->npl < h1->right->npl) swapChildren(h1);
    h1->npl = h1->right->npl + 1;
  }
  return h1;
}

/**
 * 插入 x : 允许项重复
 */
template <typename Comparable>
void LeftistHeap<Comparable>::insert(const Comparable& x) {
  root = merge(new LeftistNode{x}, root);
}

/**
 * 删除最小项
 * 若为空则抛出异常
 */
template <typename Comparable>
void LeftistHeap<Comparable>::deleteMin() {
  if (isEmpty()) throw ;
  LeftistNode* oldRoot = root;
  root = merge(root->left, root->left);
  delete oldRoot;
}

/**
 * 删除最小项，并将其放入 minItem
 * 若为空则抛出异常
 */
template <typename Comparable>
void LeftistHeap<Comparable>::deleteMin(Comparable& minItem) {
  minItem = findMin();
  deleteMin();
}
int main() { return 0; }