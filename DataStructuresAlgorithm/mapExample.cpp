/*
 * @Author: Mengsen.Wang
 * @Date: 2020-01-27 17:08:21
 * @Last Modified by: Mengsen.Wang
 * @Last Modified time: 2020-01-27 18:46:21
 */
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

/**
 * 打印 map
 */
void printHighChangeables(const map<string, vector<string> >& adjacentWords,
                          int minWords = 15) {
  for (auto& entry : adjacentWords) {
    const vector<string>& words = entry.second;
    if (words.size() >= minWords) {
      cout << entry.first << " ( " << words.size() << " ): ";
      for (auto& str : words) {
        cout << " " << str;
      }
      cout << endl;
    }
  }
}

/**
 * 如果 word1 和 word2 具有相同的长度
 * 并且只有一个字母不同，则返回 true
 */
bool oneCharOff(const string& word1, const string& word2) {
  if (word1.length() != word2.length()) return false;
  int diffs = 0;

  for (int i = 0; i < word1.length(); ++i) {
    if (word1[i] != word2[i]) {
      if ((++diffs) > 1) return false;
    }
  }
  return diffs == 1;
}

/**
 * 计算 map 对象，其中关键字为单词而值则是一些字母
 * 与对应的关键字不同单词组成的向量
 * 使用一个二次的算法
 */
map<string, vector<string> > computerAdjacentWords(
    const vector<string>& words) {
  map<string, vector<string> > adjWords;

  for (int i = 0; i < words.size(); ++i) {
    for (int j = i + 1; j < words.size(); ++j) {
      if (oneCharOff(words[i], words[j])) {
        adjWords[words[i]].push_back(words[j]);
        adjWords[words[j]].push_back(words[i]);
      }
    }
  }
  return adjWords;
}

/**
 * 计算 map 对象，其中关键字为单词，而值是单词组成的向量
 * 向量中的单词旨在一个字母上域对应的关键子不同
 * 使用一个二次算法，通过保留一个附加的 map 加速处理过程
 * 这个附加的 map 按长度将单词分组
 */
map<string, vector<string> > computerAdjacentWordsGroup(
    const vector<string>& words) {
  map<string, vector<string> > adjWords;
  map<int, vector<string> > wordsByLength;

  //将单词按长度分组
  for (auto& thisWord : words) {
    wordsByLength[thisWord.length()].push_back(thisWord);
  }
  //对每个分组进行处理
  for (auto& entry : wordsByLength) {
    const vector<string>& groupsWords = entry.second;

    for (int i = 0; i < groupsWords.size(); ++i) {
      for (int j = 1 + i; j < groupsWords.size(); ++j) {
        if (oneCharOff(groupsWords[i], groupsWords[j])) {
          adjWords[groupsWords[i]].push_back(groupsWords[j]);
          adjWords[groupsWords[j]].push_back(groupsWords[i]);
        }
      }
    }
  }
  return adjWords;
}

/**
 * 计算 map 对象，其中关键词为单词，值为单词的 Vector
 * vector 中的这些单词只是在一个字母上不同于这些对应的关键词
 * 使用一个更高效的算法，该算法用到一个 map 的运行时间为 O(N log N)
 */
map<string, vector<string> > computerAdjacentWordsGroupSplit(
    const vector<string>& words) {
  map<string, vector<string> > adjWords;
  map<int, vector<string> > wordsByLength;

  //将单词按长度分组
  for (auto& str : words) {
    wordsByLength[str.length()].push_back(str);
  }
  // 对每个分组进行处理
  for (auto& entry : wordsByLength) {
    const vector<string>& groupsWords = entry.second;
    int groupNum = entry.first;  //单词长度个数

    // 对每组的每一个位置进行处理
    for (int i = 0; i < groupNum; ++i) {
      // 删除特定位置上的字母，算出代表即去除相同字母的单词
      // 具有相同代表的单词是相邻的：填充 map
      map<string, vector<string> > repToWord;

      for (auto& str : groupsWords) {
        string rep = str;
        repToWord[rep].push_back(str);
      }

      // 查找那些具有多于一个串的 map 值
      for (auto& entry : repToWord) {
        const vector<string>& clique = entry.second;
        if (clique.size() >= 2) {
          for (int p = 0; p < clique.size(); ++p) {
            for (int q = p + 1; p < clique.size(); ++q) {
              adjWords[clique[p]].push_back(clique[q]);
              adjWords[clique[q]].push_back(clique[p]);
            }
          }
        }
      }
    }
  }
  return adjWords;
}
int main() { return 0; }