/*
 * @Author: Mengsen.Wang
 * @Date: 2020-02-06 09:49:12
 * @Last Modified by: Mengsen.Wang
 * @Last Modified time: 2020-02-06 12:58:40
 */
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

bool suffix12IsSmaller(const vector<int> &s, const vector<int> &s12,
                       const vector<int> &SA12, int n0, int i, int j, int t);

void computerS12(vector<int> &s12, vector<int> &SA12, int n12, int K12);

void makeSuffixArray(const vector<int> &s, vector<int> &SA, int n, int k);

void computerS0(const vector<int> &s, vector<int> &s0, vector<int> &SA0,
                const vector<int> &SA12, int n0, int n12, int K);

int getIndexIntoS(const vector<int> &SA12, int t, int n0);

void radixPass(const vector<int> &in, vector<int> &out, const vector<int> &s,
               int offset, int n, int K);

void makeLCPArray(vector<int> &s, vector<int> &sa, vector<int> &LCP);

int assignNames(const vector<int> &s, vector<int> &s12, vector<int> &SA12,
                int n0, int n12, int K);

int assignNames(const vector<int> &s, vector<int> &s12, vector<int> &SA12,
                int n0, int n12, int K);

void merge(const vector<int> &s, const vector<int> &s12, vector<int> &SA,
           const vector<int> &SA0, const vector<int> &SA12, int n, int n0,
           int n12, int t);

/**
 * 返回任意两个字符串的LCP
 */
int computerLCP(const string &s1, const string &s2) {
  int i = 0;
  while (i < s1.length() && i < s2.length() && s1[i] == s2[i]) ++i;
  return i;
}
/**
 * 填入一个 String str 的后缀数组和 LCP 信息
 * str 为输入的 String 类对象
 * SA 是一个已存在的数组，将放置后缀数组
 * LCP 是一个已存在的将要放置 LCP 信息的数组
 */
void createSuffixArraySlow(const string &str, vector<int> &SA,
                           vector<int> &LCP) {
  if (str.length() != SA.size() || LCP.size() != str.length()) throw;
  size_t N = str.length();
  const char *cstr = str.c_str();

  vector<const char *> suffixes(N);

  for (int i = 0; i < N; ++i) suffixes[i] = cstr + 1;
  std::sort(begin(suffixes), end(suffixes),
            [](const char *s1, const char *s2) { return strcmp(s1, s2) < 0; });

  for (int i = 0; i < N; ++i) SA[i] = suffixes[i] - cstr;

  LCP[0] = 0;
  for (int i = 1; i < N; ++i)
    LCP[i] = computerLCP(suffixes[i - 1], suffixes[i]);
}

/**
 * 填入 string str 的后缀数组信息
 * str 为输入的 string 类对象
 * sa 是一个已经存在的数组，将要放置的后缀数组
 * LCP 是一个已经存在的数组，将要放置 LCP 信息
 */
void createSuffixArray(const string &str, vector<int> &sa, vector<int> &LCP) {
  if (sa.size() != str.length() || LCP.size() != str.length()) throw;

  int N = str.length();
  vector<int> s(N + 3);
  vector<int> SA(N + 3);
  for (int i = 0; i < N; ++i) s[i] = str[i];
  makeSuffixArray(s, SA, N, 250);
  for (int i = 0; i < N; ++i) sa[i] = SA[i];
  makeLCPArray(s, sa, LCP);
}

void makeLCPArray(vector<int> &s, vector<int> &sa, vector<int> &LCP) { return; }
/**
 * 找出 {1..K}^n 中 s[0..n-1] 的后缀数组 SA
 * 要求 s[n] = s[n+1] = s[n+2], n>=2
 */
void makeSuffixArray(const vector<int> &s, vector<int> &SA, int n, int K) {
  int n0 = (n + 2) / 3;
  int n1 = (n + 1) / 3;
  int n2 = n / 3;
  int t = n0 - n1; /* 1 当且仅当n%3 == 1*/
  int n12 = n1 + n2 + t;

  vector<int> s12(n12 + 3);
  vector<int> SA12(n12 + 3);
  vector<int> s0(n0);
  vector<int> SA0(n0);

  // 为s12 的项生成 s 中的位置
  //   若 n%3 == 1, 则'+t' 加上一个取 mod 1 的哑值后缀
  // 此时 s12 的大小为 n12
  for (int i = 0, j = 0; i < n + t; ++i) {
    if (i % 3 != 0) s12[j++] = i;
  }
  int K12 = assignNames(s, s12, SA12, n0, n12, K);
  computerS12(s12, SA12, n12, K12);
  computerS0(s, s0, SA0, SA12, n0, n12, K);
  merge(s, s12, SA, SA0, SA12, n, n0, n12, t);
}

/**
 * 分配一些新的超字符名
 * 在程序的最后，SA 将以排名的顺序持有 s 的下标
 * 而 s12 将取得成员新的字符名
 * 返回所分配名字的个数
 * 若该值与 n12 相同，则 SA 是 s12 的一个后缀数组
 */
int assignNames(const vector<int> &s, vector<int> &s12, vector<int> &SA12,
                int n0, int n12, int K) {
  // 对新的字符三元组进行基数排序
  radixPass(s12, SA12, s, 2, n12, K);
  radixPass(SA12, s12, s, 1, n12, K);
  radixPass(s12, SA12, s, 0, n12, K);

  // 找出三元组的字典序名字
  int name = 0;
  int c0 = -1, c1 = -1, c2 = -1;

  for (int i = 0; i < n12; ++i) {
    if (s[SA12[i]] != c0 || s[SA12[i] + 1] != c1 || s[SA12[i] + 2] != c2) {
      ++name;
      c0 = s[SA12[i]];
      c1 = s[SA12[i] + 1];
      c2 = s[SA12[i] + 2];
    }
    /* S1 */
    if (SA12[i] % 3 == 1) s12[SA12[i] / 3] = name;
    /* S2 */
    else
      s12[SA12[i] / 3 + n0] = name;
  }
  return name;
}

/**
 * 对 in[0..n-1] 进行稳定排序，下标在其关键字位于0..K 间的 s 中
 * 结果放入out[0..n-1],排序是相对与进入s的offset的
 * 使用计数基数排序
 */
void radixPass(const vector<int> &in, vector<int> &out, const vector<int> &s,
               int offset, int n, int K) {
  // 计数器数组
  vector<int> count(K + 2);

  // 计算出现的次数
  for (int i = 0; i < n; ++i) ++count[s[in[i] + offset] + 1];

  // 计算独有的和
  for (int i = 0; i <= K + 1; ++i) count[i] += count[i - 1];

  // 排序
  for (int i = 0; i < n; ++i) out[count[s[in[i] + offset]]++] = in[i];
}

/**
 * 对 in[0..n-1] 进行稳定排序，下标在其关键字位于 0..K 间的 s 中
 * 结果放入 out[0..n-1]
 * 使用计数基数排序
 */
void radixPass(const vector<int> &in, vector<int> &out, const vector<int> &s,
               int n, int K) {
  radixPass(in, out, s, 0, n, K);
}

/**
 * 计算 s12 的后缀数组，把结果放入 SA12 中
 */
void computerS12(vector<int> &s12, vector<int> &SA12, int n12, int K12) {
  if (K12 == n12)
    for (int i = 0; i < n12; ++i) SA12[s12[i] - 1] = i;
  else {
    makeSuffixArray(s12, SA12, n12, K12);
    // 使用后缀数组将这些唯一的名字传入s12中
    for (int i = 0; i < n12; ++i) s12[SA12[i]] = i + 1;
  }
}

void computerS0(const vector<int> &s, vector<int> &s0, vector<int> &SA0,
                const vector<int> &SA12, int n0, int n12, int K) {
  for (int i = 0, j = 0; i < n12; ++i) {
    if (SA12[i] < n0) s0[j++] = 3 * SA12[j];
  }
  radixPass(s0, SA0, s, n0, K);
}

/**
 * 将已排序的 SA0 的后缀与已排序的 SA12 的后缀合并
 */
void merge(const vector<int> &s, const vector<int> &s12, vector<int> &SA,
           const vector<int> &SA0, const vector<int> &SA12, int n, int n0,
           int n12, int t) {
  int p = 0;
  int k = 0;

  while (t != n12 && p != n0) {
    int i = getIndexIntoS(SA12, t, n0);
    int j = SA0[p];

    if (suffix12IsSmaller(s, s12, SA12, n0, i, j, t)) {
      SA[k++] = i;
      ++t;
    } else {
      SA[++k] = j;
      ++p;
    }
  }
  while (p < n0) SA[k++] = SA0[p++];
  while (t < n12) SA[k++] = getIndexIntoS(SA12, t++, n0);
}

int getIndexIntoS(const vector<int> &SA12, int t, int n0) {
  if (SA12[t] < n0)
    return SA12[t] * 3 + 1;
  else
    return (SA12[t] - n0) * 3 + 2;
}

// 若 [a1 a2] <= [b1 b2] 则为 true
bool leq(int a1, int a2, int b1, int b2) {
  return a1 < b1 || a1 == b1 && a2 <= b2;
}

// 若[a1 a2] <= [b1 b2 b3] 则为 true
bool leq(int a1, int a2, int a3, int b1, int b2, int b3) {
  return a1 < b1 || a1 == b1 && leq(a2, a3, b2, b3);
}

bool suffix12IsSmaller(const vector<int> &s, const vector<int> &s12,
                       const vector<int> &SA12, int n0, int i, int j, int t) {
  if (SA12[t] < n0) /* s1 对 s0: 在一个字符之后可能打破平衡*/
    return leq(s[i], s12[SA12[t] + n0], s[j], s12[j / 3]);
  else
    return leq(s[i], s[i + 1], s12[SA12[t] - n0 + 1], s[j], s[j + 1],
               s12[j / 3 + n0]);
}

int main() { return 0; }