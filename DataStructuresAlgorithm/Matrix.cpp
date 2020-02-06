/*
 * @Author: Mengsen.Wang
 * @Date: 2020-01-23 14:11:17
 * @Last Modified: Mengsen.Wang
 * @Last Modified time: 2020-01-23 14:12:34
 */

/*
 * 手写一个二维数组, 即矩阵类
 */

#include <vector>
using namespace std;

template <typename Object>
class Matrix {
 public:
  Matrix(int rows, int cols) : array(rows) {
    for (auto &thisRow : array) {
      thisRow.resize(cols);
    }
  }

  Matrix(vector<vector<Object> > v) : array{v} {}
  Matrix(vector<vector<Object> > &&v) : array{std::move(v)} {}
  const vector<Object> &operator[](int row) const { return array[row]; }
  vector<Object> &operator[](int row) { return array[row]; }

  int numrows() const { return array.size(); }
  int numcols() const { return numrows() ? array[0].size : 0; }
  friend void copy(const Matrix<int> &from, Matrix<int> &to);
  friend Matrix<int> operator*(const Matrix<int> &a, const Matrix<int> &b);

 private:
  vector<vector<Object> > array;
};

void copy(const Matrix<int> &from, Matrix<int> &to) {
  for (int i = 0; i < to.numrows(); ++i) {
    to[i] = from[i];
  }
  // 试图将Matrix from 的每一行复制到 Matrix to 的对应行
  // 若 operator[] 返回的是一个常量引用，则 to[i] 不能出现在赋值语句的左边
  // 若 operator[] 返回的是一个引用，from[i] = to[i] 这样的语句就会被允许
  // 故需要两个版本的 operator[] 以用来应对 from 和 to
}
/**
 * 标准的矩阵乘法
 * 数组下标从零开始
 * 假设 a 和 b 为方阵
 */
Matrix<int> operator*(const Matrix<int> &a, const Matrix<int> &b) {
  int n = a.numrows();
  Matrix<int> c{n, n};
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) c[i][j] = 0;
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      for (int k = 0; k < n; ++k) c[i][j] = a[i][k] * b[k][j];
    }
  }
  return c;
}

int main() { return 0; }