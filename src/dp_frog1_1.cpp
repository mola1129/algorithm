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

constexpr long long INF = 1LL << 60;

// 配る DP
int main() {
  int N;
  std::cin >> N;
  std::vector<long long> height(N);
  for (int i = 0; i < N; ++i) {
    std::cin >> height[i];
  }

  std::vector<long long> dp(N, INF);
  dp[0] = 0;

  //   足場 0 -> 足場 1: 1 通りのルートしかない
  for (int i = 0; i < N; ++i) {
    // 足場 i -> 足場 i + 1
    if (i + 1 < N) {
      chmin(dp[i + 1], dp[i] + abs(height[i + 1] - height[i]));
    }

    if (i + 2 < N) {
      // 足場 i -> 足場 i + 2
      chmin(dp[i + 2], dp[i] + abs(height[i + 2] - height[i]));
    }
  }

  std::cout << dp[N - 1] << std::endl;
}
