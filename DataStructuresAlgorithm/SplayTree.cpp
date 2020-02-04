/*
 * @Author: Mengsen.Wang
 * @Date: 2020-02-04 15:04:49
 * @Last Modified by: Mengsen.Wang
 * @Last Modified time: 2020-02-04 17:52:40
 */

#include <utility>
template <typename Comparable>
class SplayTree {
 public:
  SplayTree() {
    nullNode = new BinaryNode;
    nullNode->left = nullNode->right = nullNode;
    root = nullNode;
  }
  ~SplayTree() {
    makeEmpty(root);
    delete nullNode;
  }
  void insert(const Comparable& x);
  void remove(const Comparable& x);

 private:
  struct BinaryNode {
    Comparable element;
    BinaryNode* left;
    BinaryNode* right;
    BinaryNode(const Comparable& theElement, BinaryNode* lt, BinaryNode* rt)
        : element{theElement}, left{lt}, right{rt} {}
    BinaryNode(Comparable&& theElement, BinaryNode* lt, BinaryNode* rt)
        : element{std::move(theElement)}, left{lt}, right{rt} {}
  };

  BinaryNode* root;
  BinaryNode* nullNode;

  void makeEmpty(BinaryNode*& t) {
    if (t != nullptr) {
      makeEmpty(t->left);
      makeEmpty(t->right);
      delete t;
    }
    t = nullptr;
  }
  void rotateWithLeftChild(BinaryNode*& k2);
  void rotateWithRightChild(BinaryNode*& k1);
  void splay(const Comparable& x, BinaryNode*& t);
};

/**
 * 执行自顶向下展开的内部方法
 * 最后访问的节点成为新的根
 * 为了使用不同的展开算法，可以覆盖这个方法
 * 展开树代码依赖于所访问的桐乡根的项
 * x 是要再其展开的目标项
 * t 是要展开的子树的根
 */
template <typename Comparable>
void SplayTree<Comparable>::splay(const Comparable& x, BinaryNode*& t) {
  BinaryNode *leftTreeMax, *rightTreeMin;
  static BinaryNode header;

  header.left = header.right = nullNode;
  leftTreeMax = rightTreeMin = &header;

  nullNode->element = x;

  for (;;) {
    if (x < t->element) {
      if (x < t->left->element) rotateWithLeftChild(t);
      if (t->left == nullNode) break;

      // 链接右侧
      rightTreeMin->left = t;
      rightTreeMin = t;
      t = t->left;
    } else if (t->element < x) {
      if (x > t->right->element) rotateWithRightChild(t);
      if (t->right == nullNode) break;

      // 链接右侧
      leftTreeMax->right = t;
      leftTreeMax = t;
      t = t->right;
    } else
      break;
  }

  leftTreeMax->right = t->left;
  rightTreeMin->left = t->right;
  t->left = header.right;
  t->right = header.left;
  return;
}

/**
 * 插入一个新节点
 * 若树是空的那就建立一个新的单节点树
 * 否则围绕被插入值展开root
 * 若新根上的数据等于x，有重复元
 * 为将来插入保留 newNode 并立即返回
 * 如果新根包含的值大于x，那么新根和他的右子树变成 newNode 的一棵右子树
 * root的左子树成为 newNode 的左子树
 * 如果 root 的新根包含的值小鱼x，那么做法类似
 */
template <typename Comparable>
void SplayTree<Comparable>::insert(const Comparable& x) {
  static BinaryNode* newNode = nullptr;

  if (newNode == nullptr) newNode = new BinaryNode;
  newNode->element = x;

  if (root == nullNode) {
    newNode->left = newNode->right = nullNode;
    root = newNode;
  } else {
    splay(x, root);
    if (x < root->element) {
      newNode->left = root->left;
      newNode->right = root;
      root->left = nullNode;
      root = newNode;
    } else if (x > root->element) {
      newNode->right = root->right;
      newNode->left = root;
      root->right = nullNode;
      root = newNode;
    } else
      return;
  }
  newNode = nullptr;
}

/**
 * 一个删除结点的方法
 */
template <typename Comparable>
void SplayTree<Comparable>::remove(const Comparable& x) {
  if (!contains(x)) return;

  // 如果找到x，则通过constains向根处展开
  BinaryNode* newTree;

  if (root->left == nullNode)
    newTree = root->right;
  else {
    // 找到左子树的最大值
    // 向根节点处展开
    // 附上右儿子
    newTree = root->left;
    splay(x, newTree);
    newTree->right = root->right;
  }
  delete root;
  root = newTree;
}
int main() { return 0; }