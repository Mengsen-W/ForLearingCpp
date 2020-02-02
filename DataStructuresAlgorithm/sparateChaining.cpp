/*
 * @Author: Mengsen.Wang
 * @Date: 2020-01-28 09:29:08
 * @Last Modified by: Mengsen.Wang
 * @Last Modified time: 2020-01-28 13:25:06
 */

#include <iostream>
#include <list>
#include <string>
#include <vector>
using namespace std;

int nextPrime(int);

template <typename HashedObj>
class HashTable {
 public:
  explicit HashTable(int size = 101);
  bool contains(const HashedObj& x) const;

  void makeEmpty();
  bool insert(const HashedObj& x);
  bool insert(HashedObj&& x);
  bool remove(const HashedObj& x);

 private:
  vector<list<HashedObj> > theLists;
  int currentSize;

  void reHash() {
    vector<list<HashedObj> > oldLists = theLists;

    // 把自己改为两倍大的空表
    theLists.resize(nextPrime(2 * theLists.size()));
    //清空表
    for (auto& thisList : theLists) thisList.clear();
    //复制表
    currentSize = 0;
    for (auto& thisList : oldLists) {
      for (auto& x : thisList) insert(std::move(x));
    }
  }
  size_t myHash(const HashedObj& x) const;
};

template <typename Key>
class Hash {
 public:
  size_t operator()(const Key& k) const;
};

template <>
class Hash<string> {
 public:
  size_t operator()(const string& Key) const {
    size_t hashVal = 0;
    for (char ch : Key) {
      hashVal = 37 * hashVal + ch;
    }
    return hashVal;
  }
};

template <typename HashedObj>
size_t HashTable<HashedObj>::myHash(const HashedObj& x) const {
  static Hash<HashedObj> hf;
  return hf(x) & theLists.size();
}

int main() { return 0; }