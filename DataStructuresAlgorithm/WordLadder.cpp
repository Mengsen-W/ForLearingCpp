/*
 * @Author: Mengsen.Wang
 * @Date: 2020-02-02 10:46:01
 * @Last Modified by: Mengsen.Wang
 * @Last Modified time: 2020-02-02 10:46:46
 */

#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * 从邻接映射( adjacency map )进行最短路径计算
 * 返回一个向量
 * 该向量包含从 first 到 second 得到的单词相继变化
 */
unordered_map<string, string> findChain(
    const unordered_map<string, vector<string> >& adjacentWords,
    const string& first, const string& second) {
  unordered_map<string, string> previousWord;
  queue<string> q;

  q.push(first);

  while (!q.empty()) {
    string current = q.front();
    q.pop();
    auto itr = adjacentWords.find(current);

    const vector<string> & adj = itr->second;
    for (const string& str : adj) {
      if (previousWord[str] == "") {
        previousWord[str] = current;
        q.push(str);
      }
    }
  }
  previousWord[first] = "";
  return previousWord;
}

/** 在最短路径计算运行之后，计算包含从 first 到 second 得到的
  * 单词相继变化的vector对象
*/

vector<string> getChainFromPreviousMap(
    const unordered_map<string, string>& previous, const string& second) {
  vector<string> result;
  auto& prev = const_cast<unordered_map<string, string>&>(previous);

  for (string current = second; current != ""; current = prev[current]) {
    result.push_back(current);
  }
  reverse(begin(result), end(result));
  return result;
}

int main() { return 0; }