/*
 * @Author: Mengsen.Wang
 * @Date: 2020-02-06 18:09:00
 * @Last* Modified by: Mengsen.Wang
 * @Last Modified time: 2020-02-06 18:21:45
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct PairNode;
typedef PairNode* Position;

/**
 * 保持序的基本操作的内部方法
 * 将first和 second 链接在一起以满足配对堆要求
 * first是数1的跟，他可以不是nullptr
 * first->nextSibling 在接入时必须是 nullptr
 * second 是树2的跟，它可以是nullptr
 * first成为合并的结果
 */
void comparaAndLink(PairNode*& first, PairNode*& second) {
  if (second == nullptr) return;
  if (second->element < first->element) {
    // 将 first 作为 second 的最左儿子附接上
    second->prev = first->prev;
    first->prev = second;
    first->nextSibling = second->leftChild;
    if (first->nextSibling != nullptr) first->nextSibling->prev = first;
    second->leftChild = first;
    first = second;
  } else {
    // 将 second 作为 first 的左儿子附接
    second->prev = first;
    first->nextSibling = second->nextSibling;
    if (first->nextSibling != nullptr) first->nextSibling->prev = first;
    second->nextSibling = first->leftChild;
    if (second->nextSibling != nullptr) second->nextSibling->prev = second;
    first->leftChild = second;
  }
}

/**
 * 将x插入到优先队列，保持堆序
 * 返回含有新项的 Position 型对象 (指向该节点的指针)
 */
Position insert(const Comparable& x) {
  PairNode* newNode = new PairNode{x};
  if (root == nullptr)
    root = newNode;
  else
    comparaAndLink(root, newNode);
  return newNode;
}

/**
 * 改变存储在配对堆中的项的值
 * 如果 newValue 大于当前储存的值，抛出异常
 * p 是由 insert 返回的一个 Position 型对象
 * newValue 是新值，他必须小于当前储存的值
 */
void decreaseKey(Position p, const Comparable& newValue) {
  if (p->element < newValue) throw;
  p->element = newValue;
  if (p != root) {
    if (p->nextSibling != nullptr) p->nextSibling->prev = p->prev;
    if (p->prev->leftChild == p)
      p->prev->leftChild = p->nextSibling;
    else
      p->prev->nextSibling = p->nextSibling;

    p->nextSibling = nullptr;
    comparaAndLink(root, p);
  }
}

void deleteMin() {
  if (isEmpty()) throw;
  PairNode* oldRoot = root;

  if (root->leftChild == nullptr)
    root = nullptr;
  else
    root = combineSibling(root->leftChild);
  delete oldRoot;
}

/**
 * 实现两趟合并的内部方法
 * firstSibling 合并后的树的根，并假设不是 nullptr
 */
PairNode* combineSibling(PairNode* firstSibling) {
  if (firstSibling->nextSibling == nullptr) return firstSibling;

  // 配置数组
  static vector<PairNode*> treeArray(5);

  // 将各子树存在一个数组里面
  int numSiblings = 0;
  for (; firstSibling != nullptr; ++numSiblings) {
    if (numSiblings == treeArray.size()) {
      treeArray.resize(numSiblings * 2);
    }
    treeArray[numSiblings] = firstSibling;
    firstSibling->prev->nextSibling = nullptr;  // 断开连接
    firstSibling = firstSibling->nextSibling;
  }
  if (numSiblings == treeArray.size()) treeArray.resize(numSiblings + 1);
  treeArray[numSiblings] = nullptr;

  // 从左到右，一次合并两颗子树
  int i = 0;
  for (; i < numSiblings; i += 2) {
    comparaAndLink(treeArray[i], treeArray[i + 1]);
  }
  int j = i - 2;

  // j 有最新 comparaAndLink 的结果
  // 如果是奇数棵树，则获取最后一棵
  if (j == numSiblings - 3) comparaAndLink(treeArray[j], treeArray[j + 2]);

  // 如果从右到左，最后一棵树与倒数第二棵合并
  // 结果成为新树
  for (; j >= 2; j -= 2) comparaAndLink(treeArray[j - 2], treeArray[j]);

  return treeArray[0];
}