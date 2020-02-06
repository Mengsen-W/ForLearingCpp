/*
 * @Author: Mengsen.Wang
 * @Date: 2020-01-28 10:00:46
 * @Last Modified by: Mengsen.Wang
 * @Last Modified time: 2020-01-28 10:55:36
 */

#include <algorithm>
#include <deque>
#include <functional>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

class Employee {
 public:
  const std::string& getName() const { return name; }

  bool operator==(const Employee& rhs) const {
    return getName() == rhs.getName();
  }
  bool operator!=(const Employee& rhs) const { return !(*this == rhs); }

 private:
  std::string name;
  double salary;
  int seniority;
};

template <typename Key>
class Hash {
 public:
  size_t operator()(const Key& k) const;
};
template <>
class Hash<std::string> {
 public:
  size_t operator()(const std::string& Key) const {
    size_t hashVal = 0;
    for (char ch : Key) {
      hashVal = 37 * hashVal + ch;
    }
    return hashVal;
  }
};
template <>
class Hash<Employee> {
 public:
  size_t operator()(const Employee& item) {
    static Hash<std::string> hf;
    return hf(item.getName());
  }
};

template <typename HashedObj>
class HashTable {
 public:
  explicit HashTable(int size = 101);
  bool contains(const HashedObj& x) const {
    auto& whichList = theLists[myHash(x)];
    //   进入List find（a.begin(),a.end(),value）
    return find(begin(whichList), end(whichList), x);
  }

  void makeEmpty() {
    for (auto& theList : theLists) theList.clear();
  }

  bool insert(const HashedObj& x) {
    auto& whichList = theLists[myHash(x)];
    if (find(begin(whichList), end(whichList), x) != end(whichList))
      return false;
    whichList.push_back(x);
    // 再散列
    if (++currentSize > theLists.size()) reHash();
    return true;
  }
  bool insert(HashedObj&& x);
  bool remove(const HashedObj& x) {
    auto& whichList = theLists[myHash(x)];
    auto itr = find(begin(whichList), end(whichList), x);
    if (itr == end(whichList)) return false;
    whichList.erase(itr);
    --currentSize;
    return true;
  }

 private:
  // 存放链表的数组
  std::vector<std::list<HashedObj> > theLists;
  int currentSize;

  void reHash();
  size_t myHash(const HashedObj& x) const {
    static Hash<HashedObj> hf;
    return hf(x) % theLists.size();
  }
};



int main() { return 0; }