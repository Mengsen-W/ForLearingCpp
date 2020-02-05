/*
 * @Author: Mengsen.Wang
 * @Date: 2020-02-05 14:04:13
 * @Last Modified by: Mengsen.Wang
 * @Last Modified time: 2020-02-05 16:39:33
 */
#include <random>
#include <utility>
#include "UniformRandom.cpp"

using namespace std;

template <typename Comparable>
class TreapTree {
 public:
  TreapTree() {
    nullNode = new TreapNode;
    nullNode->left = nullNode->right = nullNode;
    nullNode->priority = __INT_MAX__;
    root = nullNode;
  }
  TreapTree(const TreapTree& rhs);
  TreapTree(TreapTree&& rhs);
  ~TreapTree();
  TreapTree& operator=(const TreapTree& rhs);
  TreapTree& operator=(TreapTree&& rhs);

 private:
  struct TreapNode {
    Comparable element;
    TreapNode* left;
    TreapNode* right;
    // 优先级
    int priority;

    TreapNode() : left{nullptr}, right{nullptr}, priority{__INT_MAX__} {}
    TreapNode(const Comparable& e, TreapNode* lt, TreapNode* rt, int pr)
        : element{e}, left{lt}, right{rt}, priority{pr} {}
    TreapNode(const Comparable&& e, TreapNode* lt, TreapNode* rt, int pr)
        : element{std::move(e)}, left{lt}, right{rt}, priority{pr} {}
  };

  TreapNode* root;
  TreapNode* nullNode;
  UniformRandom randomNums;

  /**
   * 用左儿子旋转二叉树的节点
   * 更新高度设置新根
   */
  void rotateWithLeftChild(TreapNode*& k2) {
    TreapNode* k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;
    k2->height = max(height(k2->left), height(k2->right)) + 1;
    k1->height = max(height(k1->left), k2->height) + 1;
    k2 = k1;
  }

  /**
   * 用右儿子旋转二叉树的节点
   * 更新高度设置新根
   */
  void rotateWithRightChild(TreapNode*& k2) {
    TreapNode* k1 = k2->right;
    k2->right = k1->left;
    k1->left = k2;
    k2->height = max(height(k2->left), height(k2->right)) + 1;
    k1->height = max(height(k1->right), k2->height) + 1;
    k2 = k1;
  }

  // 向一课子树进行插入的内部方法
  void insert(const Comparable& x, TreapNode*& t);
  // 向一棵子树移出节点的方法
  void remove(const Comparable& x, TreapNode*& t);
};

/**
 * 像一棵子树进行插入的内部方法
 * x 是要被插入的项
 * t 为该树的根节点
 * 建立该子树的新根
 */
template <typename Comparable>
void TreapTree<Comparable>::insert(const Comparable& x, TreapNode*& t) {
  if (t == nullNode) {
    t = new TreapNode{x, nullNode, nullNode, randomNums.nextInt()};
  } else if (x < t->left) {
    insert(x, t->left);
    if (t->left->priority < t->priority) rotateWithLeftChild(t);
  } else if (x > t->element) {
    insert(x, t->right);
    if (t->right->priority < t->priority) rotateWithRightChild(t);
  }
  // 否则是重复元什么都不做
}
/**
 * 向一棵子树移出节点的方法
 * x是要被删除的项
 * t 是该树的根节点
 * 建立子树新的根
 */
template <typename Comparable>
void TreapTree<Comparable>::remove(const Comparable& x, TreapNode*& t) {
  if (t != nullNode) {
    if (x < t->element)
      remove(x, t->left);
    else if (x > t->element)
      remove(x, t->right);
    else {
      // 找到匹配
      if (t->left->priority < t->right->priority)
        rotateWithLeftChild(t);
      else
        rotateWithRightChild(t);
      if (t != nullNode)
        // 继续下行
        remove(x, t);
      else {
        delete t->left;
        // 在叶节点上
        t->left = nullNode;
      }
    }
  }
}

int main() { return 0; }