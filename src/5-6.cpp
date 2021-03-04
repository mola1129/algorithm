#include <cmath>
#include <iostream>
#include <vector>

/*
 * 最小値に更新する
 * @param a 最小値 (更新対象)
 * @param b 比較対象
 */
template <class T>
void chmin(T& a, const T b) {
  if (a > b) {
    a = b;
  }
}

constexpr int INF = 1 << 29;

int main() {
  int N, W;
  std::cin >> N >> W;

  std::vector<int> a(N), m(N);
  for (int i = 0; i < N; ++i) {
    std::cin >> a[i] >> m[i];
  }

  // dp[i][w]: 最初の i 個の整数のみを用いて、整数 j
  // を作る方法のうち、最後の整数を用いる回数の最小値
  std::vector<std::vector<int>> dp(N + 1, std::vector<int>(W + 1, INF));
  dp[0][0] = 0;

  // O (NW)
  for (int i = 1; i <= N; ++i) {
    for (int w = 0; w <= W; ++w) {
      if (dp[i - 1][w] < INF) {
        chmin(dp[i][w], 0);  // 選ばない
      }

      if (w - a[i - 1] >= 0 && dp[i][w - a[i - 1]] < m[i]) {
        chmin(dp[i][w], dp[i][w - a[i - 1]] + 1);  // 重複を許して選ぶ
      }
    }
  }

  if (dp[N][W] < INF) {
    std::cout << "Yes" << std::endl;
  } else {
    std::cout << "No" << std::endl;
  }
}