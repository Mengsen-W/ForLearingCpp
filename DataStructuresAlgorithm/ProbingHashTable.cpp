/*
 * @Author: Mengsen.Wang
 * @Date: 2020-01-28 11:51:24
 * @Last Modified by: Mengsen.Wang
 * @Last Modified time: 2020-01-28 13:30:48
 */

#include <cmath>
#include <string>
#include <vector>
using namespace std;

// 产生输入数的下一个素数
int nextPrime(int);

template <typename HashedObj>
class HashTable {
 public:
  explicit HashTable(int size = 101) : array(size) { makeEmpty(); }

  bool contains(const HashedObj& x) const { return isActive(findPos(x)); }

  void makeEmpty() {
    currentSize = 0;
    for (auto& entry : array) entry.info = EMPTY;
  }
  bool insert(const HashedObj& x) {
    int currentPos = findPos(x);
    // 如果存在标记为 active 则什么都不做 插入了重复的元素
    if (isActive(currentPos)) return false;

    array[currentPos].element = x;
    array[currentPos].info = ACTIVE;

    //再散列
    if ((++currentSize) > array.size() / 2) rehash();

    return true;
  }
  bool insert(HashedObj&& x);
  bool remove(const HashedObj& x) {
    int currentPos = findPos(x);
    // 弱国不是激活状态就不需要删除
    if (!isActive(currentPos)) return false;
    // 标记删除状态
    array[currentPos].info = DELETED;
    return true;
  }

  enum EntryType { ACTIVE, EMPTY, DELETED };

 private:
  struct HashEntry {
    // 储存 info 成员的状态
    HashedObj element;
    EntryType info;
    HashEntry(const HashedObj& e = HashedObj{}, EntryType i = EMPTY)
        : element{e}, info{i} {}
    HashEntry(const HashedObj&& e, EntryType i = EMPTY)
        : element{std::move(e)}, info{i} {}
  };

  vector<HashEntry> array;
  int currentSize;

  bool isActive(int currentPos) const {
    return array[currentPos].info == ACTIVE;
  }

  int findPos(const HashedObj& x) const {
    int offset = 1;
    int currentPos = myHash(x);
    while (array[currentPos].info != EMPTY && array[currentPos].element != x) {
      currentPos += offset;  //计算第 i 次探测
      offset += 2;
      if (currentPos >= array.size()) currentPos -= array.size();
    }
    return currentPos;
  }

  void rehash() {
    vector <HashEntry> oldArray = array;

    array,resize(nextPrime(2 * oldArray.size()));
    for(auto & entry : array)
      entry.info = EMPTY;
    currentSize = 0;
    for(auto & entry : oldArray)
      if(entry.info == ACTIVE)
      insert(std::move(entry.element));
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

int main() { return 0; }