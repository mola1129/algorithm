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

constexpr long long INF = 1L << 23;

int main() {
  int N;
  std::cin >> N;

  std::vector<std::vector<long long>> c(N + 1,
                                        std::vector<long long>(N + 1, 0));
  for (int i = 0; i <= N; ++i) {
    for (int j = 0; j <= N; ++j) {
      std::cin >> c[i][j];
    }
  }

  // dp[i] : [0, i) の最小コスト
  std::vector<long long> dp(N + 1, INF);

  // 初期条件
  dp[0] = 0;

  for (int i = 0; i <= N; ++i) {
    // j: 最後に区切った位置
    for (int j = 0; j < i; ++j) {
      chmin(dp[i], dp[j] + c[j][i]);
    }
  }

  std::cout << dp[N] << std::endl;
}