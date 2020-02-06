/*
 * @Author: Mengsen.Wang
 * @Date: 2020-01-31 19:31:46
 * @Last Modified by: Mengsen.Wang
 * @Last Modified time: 2020-01-31 20:16:03
 */

#include <string>
#include <vector>
using namespace std;
/**
 * 对 String 类对象数组 (array of string) 进行的基数排序
 * 假设全部为 ASCII 码
 * 并设所有字符串都有相同的长度
 */
void radixSortA(vector<string>& arr, int stringLen) {
  const int BUCKETS = 256;
  vector<vector<string> > buckets(BUCKETS);

  for (int pos = stringLen - 1; pos >= 0; --pos) {
    for (string& s : arr) buckets[s[pos]].push_back(std::move(s));

    int idx = 0;
    for (auto& thisbucket : buckets) {
      for (string& s : thisbucket) arr[idx] = std::move(s);
      thisbucket.clear();
    }
  }
}

/**
 * 对 String 类对象的数组 ( array of string) 进行的计数基数排序
 * 假设全部为 ASCII 码
 * 并设所有字符串都有相同的长度
 */
void countingRadixSort(vector<string>& arr, int stringlen) {
  const int BUCKETS = 256;
  int N = arr.size();
  vector<string> buffer(N);

  vector<string>* in = &arr;
  vector<string>* out = &buffer;

  for (int pos = stringlen - 1; pos >= 0; --pos) {
    vector<int> count(BUCKETS + 1);

    for (int i = 0; i < N; ++i) {
      ++count[(*in)[i][pos]];
    }
    for (int b = 1; b <= BUCKETS; ++b) {
      count[b] += count[b - 1];
    }
    for (int i = 0; i < N; ++i) {
      (*out)[count[(*in)[i][pos]]++] = std::move((*in)[i]);
    }
    std::swap(in, out);
  }
  if (stringlen / 2 == 1)
    for (int i = 0; i < arr.size(); ++i) (*out)[i] = std::move((*in)[i]);
}

/**
 * 对 String 类对象的数组 ( array of string) 进行的计数基数排序
 * 假设全部为 ASCII 码
 * 并设所有字符串都以最大长度 maxLen 为界
 */
void radixSort(vector<string>& arr, int maxLen) {
  const int BUCKETS = 256;

  vector<vector<string> > wordByLength(maxLen + 1);
  vector<vector<string> > buckets(BUCKETS);

  for (string& s : arr) wordByLength[s.length()].push_back(std::move(s));

  int idx = 0;
  for (auto& wordList : wordByLength)
    for (string& s : wordList) arr[idx++] = std::move(s);

  int startingIndex = arr.size();
  for (int pos = maxLen - 1; pos >= 0; --pos) {
    startingIndex -= wordByLength[pos + 1].size();

    for (int i = startingIndex; i < arr.size(); ++i) {
      buckets[arr[i][pos]].push_back(std::move(arr[i]));
    }
    idx = startingIndex;
    for (auto& thisBucket : buckets) {
      for (string& s : thisBucket) arr[idx++] = std::move(s);
      thisBucket.clear();
    }
  }
}

int main() { return 0; }