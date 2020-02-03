/*
 * @Author: Mengsen.Wang
 * @Date: 2020-02-03 21:03:24
 * @Last Modified by: Mengsen.Wang
 * @Last Modified time: 2020-02-03 21:25:19
 */

static const int A = 48271;
static const int M = 2147483647;
static const int Q = M / A;
static const int R = M % A;
/**
 * 随机数生成器类
 */
class Random {
 public:
  explicit Random(int initialValue = 1);
  int randomInt();
  double random0_1();
  int randomInt(int low, int high);

 private:
  int state;
};

/**
 * 用 state 的 initiaValue 构造
 */
Random::Random(int initialValue) {
  if (initialValue < 0) initialValue += M;
  state = initialValue;
  if (state == 0) state = 1;
}

/**
 * 返回伪随机的 int 型变量
 * 并改变内部 state 的值
 */
int Random::randomInt() {
  int tepState = A * (state % Q) - R * (state / Q);
  if (tepState >= 0)
    state = tepState;
  else
    state = tepState + M;
  return state;
}

/**
 * 返回开区间 (0, 1) 中的伪随机 double 型变量
 * 并改变内部变量 state 的值
 */
double Random::random0_1() { return static_cast<double>(randomInt()) / M; }

int main() { return 0; }