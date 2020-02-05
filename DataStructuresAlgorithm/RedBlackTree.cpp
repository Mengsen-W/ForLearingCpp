/*
 * @Author: Mengsen.Wang
 * @Date: 2020-02-05 10:11:21
 * @Last Modified by: Mengsen.Wang
 * @Last Modified time: 2020-02-05 12:38:31
 */

#include <iostream>
#include <utility>
#include <vector>

using namespace std;

template <typename Comparable>
class RedBlackTree {
 public:
  explicit RedBlackTree(const Comparable& negInf);
  RedBlackTree(const RedBlackTree& rhs);
  RedBlackTree(RedBlackTree&& rhs);
  ~RedBlackTree();

  const Comparable& findMin() const;
  const Comparable& findMax() const;
  bool contains(const Comparable& x) const;
  bool isEmpty() const;
  void printTree() const;

  void makeEmpty();
  void insert(const Comparable& x);
  void remove(const Comparable& x);

  enum { RED, BLACK };

  RedBlackTree& operator=(const RedBlackTree& rhs);
  RedBlackTree& operator=(RedBlackTree&& rhs);

 private:
  struct RedBlackNode {
    Comparable element;
    RedBlackNode* left;
    RedBlackNode* right;
    int color;

    RedBlackNode(const Comparable& theElement = Comparable{},
                 RedBlackNode* lt = nullptr, RedBlackNode* rt = nullptr,
                 int c = BLACK)
        : element{theElement}, left{lt}, right{rt}, color{c} {}
    RedBlackNode(const Comparable&& theElement, RedBlackNode* lt = nullptr,
                 RedBlackNode* rt = nullptr, int c = BLACK)
        : element{std::move(theElement)}, left{lt}, right{rt}, color{c} {}
  };

  //  节点操作
  void printTree(RedBlackNode* t) const;
  void reclaimMemory(RedBlackNode* t);
  RedBlackNode* clone(RedBlackNode* t) const;

  // 树的操作
  void handleReorient(const Comparable& item);
  RedBlackNode* rotate(const Comparable& item, RedBlackNode* theParent);
  void rotateWithLeftChild(RedBlackNode*& k2);
  void rotateWithRightChild(RedBlackNode*& k1);

  // 树的头结点 包含 (negInf)
  RedBlackNode* header;
  RedBlackNode* nullNode;

  // 用于 insert 方法及其辅助对象，逻辑上是 static 型
  RedBlackNode* current;
  RedBlackNode* parent;
  RedBlackNode* grand;
  RedBlackNode* great;
};

/**
 * 树的构建
 * negInf 是小于或等于所有其余项的一个值
 */
template <typename Comparable>
RedBlackTree<Comparable>::RedBlackTree(const Comparable& negInf) {
  nullNode = new RedBlackNode;
  nullNode->left = nullNode->right = nullNode;

  header = new RedBlackNode{negInf};
  header->left = header->right = nullNode;
}
/**
 * 拷贝构造函数
 */
template <typename Comparable>
RedBlackTree<Comparable>::RedBlackTree(const RedBlackTree& rhs) {
  nullNode = new RedBlackNode;
  nullNode->left = nullNode->right = nullNode;

  header = new RedBlackNode{rhs.header->element};
  header->left = nullNode;
  header->right = clone(rhs.header->right);
}
/**
 * 私有 clone 方法
 */
template <typename Comparable>
typename RedBlackTree<Comparable>::RedBlackNode*
RedBlackTree<Comparable>::clone(RedBlackNode* t) const {
  if (t == t->left)  // 不能对 nullNode 测试
    return nullNode;
  else
    return new RedBlackNode{t->element, clone(t->left), clone(t->right),
                            t->color};
}

/**
 * 遍历打印树
 */
template <typename Comparable>
void RedBlackTree<Comparable>::printTree() const {
  if (header->right = nullNode)
    cout << "Empty Tree" << endl;
  else
    printTree(header->right);
}
template <typename Comparable>
void RedBlackTree<Comparable>::printTree(RedBlackNode* t) const {
  if (t != t->left) {
    printTree(t->left);
    cout << t->element << endl;
    printTree(t->right);
  }
}

/**
 * 执行单旋转或双旋转的内部例程
 * 以为结果被依附到父节点，故有四种情形
 * 通过 handleReorient 而被调用
 * item 是handleReorient 中的 item
 * theParent 为所旋转子树的根的父节点
 * 返回旋转子树的根
 */
template <typename Comparable>
typename RedBlackTree<Comparable>::RedBlackNode*
RedBlackTree<Comparable>::rotate(const Comparable& item,
                                 RedBlackNode* theParent) {
  if (item < theParent->element) {
    item < theParent->left->element ? rotateWithLeftChild(theParent->left)
                                    : rotateWithRightChild(theParent->left);
    return theParent->left;
  } else {
    item < theParent->left->element ? rotateWithLeftChild(theParent->right)
                                    : rotateWithRightChild(theParent->right);
    return theParent->right;
  }
}

/**
 * 用左儿子旋转二叉树的节点
 * 这是对 AVL 树在情形一的一次单旋转
 * 更新高度设置新根
 */
template <typename Comparable>
void RedBlackTree<Comparable>::rotateWithLeftChild(RedBlackNode*& k2) {
  RedBlackNode* k1 = k2->left;
  k2->left = k1->right;
  k1->right = k2;
  k2->height = max(height(k2->left), height(k2->right)) + 1;
  k1->height = max(height(k1->left), k2->height) + 1;
  k2 = k1;
}

/**
 * 用右儿子旋转二叉树的节点
 * 这是对 AVL 树在情形一的一次单旋转
 * 更新高度设置新根
 */
template <typename Comparable>
void RedBlackTree<Comparable>::rotateWithRightChild(RedBlackNode*& k2) {
  RedBlackNode* k1 = k2->right;
  k2->right = k1->left;
  k1->left = k2;
  k2->height = max(height(k2->left), height(k2->right)) + 1;
  k1->height = max(height(k1->right), k2->height) + 1;
  k2 = k1;
}

/**
 * 内部例程
 * 如果一个父节点有两个红儿子，则例程在插入期间被执行
 * 执行颜色反转和旋转
 * item是要被插入的项
 */
template <typename Comparable>
void RedBlackTree<Comparable>::handleReorient(const Comparable& item) {
  // 进行颜色翻转
  current->color = RED;
  current->left->color = BLACK;
  current->right->color = BLACK;

  //必须翻转
  if (parent->color == RED) {
    grand->color = RED;
    if (item < grand->element != item < parent->element)
      parent = rotate(item, great);
    current->color = BLACK;
  }
  // 使根变为黑色
  header->right->color = BLACK;
}

template <typename Comparable>
void RedBlackTree<Comparable>::insert(const Comparable& x) {
  current = parent = grand = header;
  nullNode->element = x;

  while (current->element != x) {
    great = grand;
    grand = parent;
    parent = current;
    current = x < current->element ? current->left : current->right;

    // 检查是否两个红儿子；若是，则调整
    if (current->left->color == RED && current->right->color == RED)
      handleReorient(x);
  }

  // 如果已存在，则插入失败
  if (current != nullNode) return;
  current = new RedBlackNode{x, nullNode, nullNode};

  // 连接到父节点上
  if (x < parent->element)
    parent->left = current;
  else
    parent->right = current;
  handleReorient(x);
}

int main() { return 0; }