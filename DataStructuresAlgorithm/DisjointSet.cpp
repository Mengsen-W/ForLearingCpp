/*
 * @Author: Mengsen.Wang
 * @Date: 2020-02-01 11:12:19
 * @Last Modified by: Mengsen.Wang
 * @Last Modified time: 2020-02-01 11:31:32
 */
#include <vector>
using namespace std;
class DisjSets {
 public:
  explicit DisjSets(int numElements);
  int find(int x) const;
  int find(int x);
  int findByPathCompression(int x);
  void unionSets(int root1, int root2);
  void unionSetsByHigh(int root1, int root2);

 private:
  vector<int> s;
};

/**
 * 构造不相交集对象
 */
DisjSets::DisjSets(int numElement) : s{numElement, -1} {}

/**
 * 合并两个不相交集合
 * 为简明起见，假设 root1 和 root2 是互异的
 * 并各自代表一个集合的名字
 * root1 为集合 1 的根
 * root2 为集合 2 的根
 */
void DisjSets::unionSets(int root1, int root2) { s[root2] = root1; }

/**
 * 执行一次 find
 * 为简单起见，忽略差错检验
 * 返回包含x的集合
 */
int DisjSets::find(int x) const {
  if (s[x] < 0)
    return x;
  else
    return find(s[x]);
}

/**
 * 合并两个不相交的集合
 * 为简单起见，假设 root1 和 root2 互异
 * 并且均代表集合的名字
 * root1 是 set1 的根
 * root2 是 set2 的根
 */
void DisjSets::unionSetsByHigh(int root1, int root2) {
  if (s[root2] < s[root1])  // root2 的根更深
    s[root1] = root2;       //使 root2 成为 root1 的新根
  else {
    if (s[root1] == s[root2]) --s[root1];  //如果相同则更新高度
    s[root2] = root1;                      //把 root2 成为 root1 的新根
  }
}

/**
 * 利用路径压缩执行一次 find
 * 为简单起见，忽略差错检查
 * 返回包含 x 的集合
 */
int DisjSets::findByPathCompression(int x) {
  if (s[x] < 0)
    return x;
  else
    return s[x] = findByPathCompression(s[x]);
}

int main() { return 0; }