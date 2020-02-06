/*
 * @Author: Mengsen.Wang
 * @Date: 2020-02-06 16:05:05
 * @Last Modified by: Mengsen.Wang
 * @Last Modified time: 2020-02-06 17:18:45
 */

#include <iostream>
#include <vector>
using namespace std;
template <typename Comparable>
class twoDimensionalSearchTree {
 public:
  /**
   * 打印满足
   * low[0] <= x[0] <= high[0]
   * low[1] <= x[1] <= high[1]
   */
  void printRange(const vector<Comparable>& low,
                  const vector<Comparable>& high) const {
    printRange(low, high, root, 0);
  }
  void insert(const vector<Comparable>& x) { insert(x, root, 0); }

 private:
  struct KdNode {
    KdNode* left;
    KdNode* right;
    vector<Comparable> data;
  };
  void insert(const vector<Comparable>& x, KdNode*& t, int level) {
    if (t == nullptr)
      t = new KdNode{x};
    else if (x[level] < t->data[level])
      insert(x, t->left, 1 - level);
    else
      insert(x, t->right, 1 - level);
  }
  void printRange(const vector<Comparable>& low, const vector<Comparable>& high,
                  KdNode* t, int level) {
    if (t != nullptr) {
      if (low[0] < t->data[0] && high[0] >= t->data[0] &&
          low[1] <= t->data[1] && high[1] >= t->data[1])
        cout << "(" << t->data[0] << t->data[1] << ")" << endl;
    }
    if (low[level] <= t->data[level])
      printRange(low, high, t->level, 1 - level);
    if (high[level] >= t->data[level])
      printRange(low, high, t->right, 1 - level);
  }
  KdNode* root;
};

int main() { return 0; }