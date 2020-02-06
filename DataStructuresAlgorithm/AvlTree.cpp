/*
 * @Author: Mengsen.Wang
 * @Date: 2020-01-27 09:37:50
 * @Last Modified by: Mengsen.Wang
 * @Last Modified time: 2020-01-27 10:30:37
 */

#include <utility>
// Avl 树
template <typename Comparable>
class AvlTree {
 public:
  struct AvlNode {
   public:
    Comparable element;
    AvlNode* left;
    AvlNode* right;
    int height;

    AvlNode(const Comparable& ele, AvlNode* lt, AvlNode* rt, int h = 0)
        : element{ele}, left{lt}, right{rt}, height{h} {}
    AvlNode(const Comparable&& ele, AvlNode* lt, AvlNode* rt, int h = 0)
        : element{std::move(ele)}, left{lt}, right{rt}, height{h} {}
  };
  /**
   * 返回系欸但t的高度，如果是 nullptr 则返回-1
   */
  int height(AvlNode* t) const { return t == nullptr ? -1 : t->height; }

  /**
   * 向一棵子树进行插入的方法
   * x 是要插入的项
   * t 为该子树的根节点
   * 设置子树的新根
   */
  void instert(const Comparable& x, AvlNode* t) {
    if (t == nullptr) {
      // 创建一个新节点
      t = new AvlNode{x, nullptr, nullptr};
    } else if (x < t->element) {
      insert(x, t->left);
    } else if (x > t->element) {
      insert(x, t->right);
    }
    // 平衡二叉查找树
    balance(t);
  }
  // 左子树和右子树深度不能超过 1
  static const int ALLOWED_IMBALANCE = 1;

  // 平衡函数
  void balance(AvlNode*& t) {
    if (t == nullptr) {
      return;
    }
    if (height(t->left) = hight(t->right) > ALLOWED_IMBALANCE) {
      if (height(t->left->left) >= height(t->left->right)) {
        rotateWithLeftChild(t);
      } else
        doubleWithLeftChild(t);
    } else if (height(t->right) - height(t->left) > ALLOWED_IMBALANCE) {
      if (height(t->right->right) >= height(t->right->left)) {
        rotateWithRightChild(t);
      } else
        doubleWithRightChild(t);
    }
    t - height = max(height(t->left), height(t->right)) + 1;
  }

  /**
   * 用左儿子旋转二叉树的节点
   * 这是对 AVL 树在情形一的一次单旋转
   * 更新高度设置新根
   */
  void rotateWithLeftChild(AvlNode*& k2) {
    AvlNode* k1 = k2->left;
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
  void rotateWithRightChild(AvlNode*& k2) {
    AvlNode* k1 = k2->right;
    k2->right = k1->left;
    k1->left = k2;
    k2->height = max(height(k2->left), height(k2->right)) + 1;
    k1->height = max(height(k1->right), k2->height) + 1;
    k2 = k1;
  }

  /**
   * 双旋转二叉树的节点：首先左儿子和右儿子进行
   * 然后节点 k3 和新的做儿子进行
   * 这是对 AVL 树情形2的一个双旋转
   * 更新高度，设计新根
   */
  void doubleWithLeftChild(AvlNode*& k3) {
    rotateWithRightChild(k3->left);
    rotateWithLeftChild(k3);
  }
  /**
   * 双旋转二叉树的节点：首先左儿子和右儿子进行
   * 然后节点 k3 和新的做儿子进行
   * 这是对 AVL 树情形2的一个双旋转
   * 更新高度，设计新根
   */
  void doubleWithRightChild(AvlNode*& k3) {
    rotateWithLeftChild(k3->right);
    rotateWithRightChild(k3);
  }

  /**
   * 从子树实施删除的方法
   * x 是要被删除的根节点
   * t 为该子树的根节点
   * 设置该子树的新根
   */
  void remove(const Comparable& x, AvlNode*& t) {
    if (t == nullptr) {
      return;  // 什么都不做
    }
    // 寻找过程
    if (x < t->element) {
      remove(x, t->left);
    } else if (x > t->element) {
      remove(x, t->right);
    } else if (t->left != nullptr && t->right != nullptr) {
      // 两个儿子，把右侧最小值放在父亲节点，然后把右侧最小值移除
      t->element = findMin(t->right)->element;
      remove(t->element, t->right);
    } else {
      // 只有左孩子或右孩子
      AvlNode* oldNode = t;
      t = (t->left != nullptr) ? t->left : t->right;
      delete oldNode;
    }
    balance(t);  //重新平衡
  }

  AvlNode* findMin(AvlNode* t) const {
    if (t == nullptr) return nullptr;
    if (t->left == nullptr) return t;
    return findMin(t->left);
  }
};

int main() { return 0; }