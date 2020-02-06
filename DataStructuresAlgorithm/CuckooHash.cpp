/*
 * @Author: Mengsen.Wang
 * @Date: 2020-01-28 16:14:55
 * @Last Modified by: Mengsen.Wang
 * @Last Modified time: 2020-01-28 16:23:01
 */

#include <Random>
#include <vector>
using namespace std;

int nextPrime(int);
/**
 * 实现杜鹃散列需要一组散列函数
 * 能够用来发出多簇散列
 */
template <typename AnyType>
class CuckooHashFamily {
 public:
  size_t Hash(const AnyType& x, int which) const;
  int getNumberOfFunctions();
  void generateNewFunctions();
};

/**
 * 杜鹃散列接口
 * 构造散列维一数组
 */
template <typename AnyType, typename HashFamily>
class CuckooHashTable {
 public:
  // 初始化函数
  explicit CuckooHashTable(int size = 101) : array(nextPrime(size)) {
    numHashFunctions = hashFunctions.getNumberOfFunctions();
    rehashes = 0;
    makeEmpty();
  }

  void makeEmpty() {
    currentSize = 0;
    for (auto& entry : array) entry.isActive = false;
  }
  /**
   * 如果找到x返回true
   */
  bool contains(const AnyType& x) const { return findPos(x) != -1; }
  /**
   * 从散列表中删除x
   * 若项x被找到且被删除返回true
   */
  bool remove(const AnyType& x) {
    int currentPos = findPos(x);
    if (!isActive(currentPos)) return false;
    array[currentPos].isActive = false;
    --currentSize;
    return true;
  }

  //公有插入函数
  bool insert(const AnyType& x) {
    if (contains(x)) return false;
    if (currentSize >= array.size() * MAX_LOAD) expand();  //扩展表

    return insertHelperl(x);
  }
  bool insert(AnyType&& x);

 private:
  struct HashEntry {
    AnyType element;
    bool isActive;

    HashEntry(const AnyType& e = AnyType(), bool a = false)
        : element{e}, isActive{a} {}
    HashEntry(const AnyType&& e, bool a = false)
        : element{std::move(e)}, isActive{a} {}
  };

  //插入助手
  bool insertHelperl(const AnyType& xx) {
    const int COUNT_LIMIT = 100;
    AnyType x = xx;
    while (true) {
      int lastPos = -1;
      int pos;
      for (int count = 0; count < COUNT_LIMIT; ++count) {
        for (int i = 0; i < numHashFunctions; ++i) {
          pos = myHash(x, i);
          // 找一个合适的位置可能用到不同的散列函数
          if (!isActive(pos)) {
            array[pos] = std::move(HashEntry{std::move(x), true});
            ++currentSize;
            return true;
          }
        }
        // 无可用位置 选择逐出的项
        int i = 0;
        do {
          pos = myHash(x, r.nextInt(numHashFunctions));
        } while (pos == lastPos && i++ < 5);

        lastPos = pos;
        std::swap(x, array[pos].element);
      }

      if (++rehashes > ALLOWED_REHASHS) {
        expand();  // 再散列太多次就扩大散列表，直接创建一个更大的表不用一次又一次的再散列了
        rehashes = 0;
      } else
        rehash();
    }
  }
  bool insertHelperl(AnyType&& xx);
  bool isActive(int currentPos) const { return (array[currentPos].isActive); }
  /**
   * 选取适当的散列函数，换算成合法的下标
   */
  int myHash(const AnyType& x, int which) const {
    return hashFunctions.hash(x, which) % array.size();
  }
  /**
   * 查找所有散列函数的位置
   * 返回查找终止的位置，若找不到返回 -1
   */
  int findPos(const AnyType& x) const {
    for (int i = 0; i < numHashFunctions; ++i) {
      int pos = myHash(x, i);
      if (isActive(pos) && array[pos].element == x) return pos;
    }
    return -1;
  }

  void expand() { rehash(static_cast<int>(array.size() / MAX_LOAD)); }
  void rehash() {
    hashFunctions.generateNewFunctions();
    rehash(array.size() * 2);
  }
  void rehash(int newSize) {
    vector<HashEntry> oldArray = array;
    //新的散列表也是array，并置空
    array.resize(nextPrime(newSize));
    for (auto& entry : array) entry.isActive = false;
    currentSize = 0;
    for (auto& entry : oldArray) {
      if (entry.isActive) insert(std::move(entry.element));
    }
  }

  // 负载因子
  static constexpr double MAX_LOAD = 0.40;
  // 如果逐出花费太长，再进行再散列的最大次数
  static constexpr int ALLOWED_REHASHS = 5;

  vector<HashEntry> array;   // 一个结构数组
  int currentSize;           // 现在激活的散列项数目
  int numHashFunctions;      // 选择 Hash 的方程
  int rehashes;              // 在插入的过程中尝试了多少次再散列
  UniformRandom r;           // 随机数
  HashFamily hashFunctions;  //维护了一个选择 hash 函数的类
};

template <int count>
class StringHashFamily {
 public:
  StringHashFamily() : MULTIPLIERS(count) { generateNewFunctions(); }
  int getNumberOfFunctions() const { return count; }
  void generateNewFunctions() {
    for (auto& mult : MULTIPLIERS) mult = r.nextInt();
  }
  size_t Hash(const string& x, int which) const {
    const int multiplier = MULTIPLIERS[which];
    size_t hashVal = 0;
    for (auto ch : x) {
      hashVal = multiplier * hashVal + ch;
    }
    return hashVal;
  }

 private:
  vector<int> MULTIPLIERS;
  UniformRandom r;
};

int main() { return 0; }