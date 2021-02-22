#include <iostream>
#include <vector>

/*
 * 最小値に更新する
 * @param a 最小値 (更新対象)
 * @param b 比較対象
 */
template <class T>
void chmin(T &a, const T b) {
  if (a > b) {
    a = b;
  }
}

// rec(i, height): 足場 0 -> 足場 i まで至るまでの最小コスト
long long rec(int i, const std::vector<long long> &height,
              std::vector<long long> &memo, const long long &INF = 1e14) {
  // メモ化
  if (memo[i] != INF) {
    return memo[i];
  }

  // 足場 0 のコストは 0
  if (i == 0) {
    return 0;
  }

  // 答え
  long long res = INF;

  // 足場 i - 1 から来た場合
  chmin(res, rec(i - 1, height, memo) + abs(height[i] - height[i - 1]));

  // 足場 i - 2 から来た場合
  if (i >= 2) {
    chmin(res, rec(i - 2, height, memo) + abs(height[i] - height[i - 2]));
  }

  return memo[i] = res;
}

// メモ化再帰
long long solver(const int N, const std::vector<long long> &height,
                 const long long &INF = 1e14) {
  // メモ化配列
  std::vector<long long> memo(N, INF);
  return rec(N - 1, height, memo, INF);
}

int main() {
  int N;
  std::cin >> N;

  std::vector<long long> height(N);
  for (int i = 0; i < N; ++i) {
    std::cin >> height[i];
  }

  std::cout << solver(N, height) << std::endl;
}