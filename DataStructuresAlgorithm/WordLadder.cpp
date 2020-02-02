/*
 * @Author: Mengsen.Wang
 * @Date: 2020-02-02 10:46:01
 * @Last Modified by: Mengsen.Wang
 * @Last Modified time: 2020-02-02 10:46:46
 */

#if(__cplusplus == 201103L)
#include <unordered_map>
#include <unordered_set>
#else
#include <tr1/unordered_map>
#include <tr1/unordered_set>
namespace std
{
    using std::tr1::unordered_map;
    using std::tr1::unordered_set;
}
#endif

#include <queue>
#include <string>
#include <vector>

using namespace std;

/**
  * 从邻接映射( adjacency map )进行最短路径计算
  * 返回一个向量
  * 该向量包含从 first 到 second 得到的单词相继变化
 */
unordered_map<string, string> findChain(const unordered_map<string, vector<string> >& adjacentWords, const string& first, const string& second)
{
}

int main() { return 0; }