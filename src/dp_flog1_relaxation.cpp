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

constexpr long long INF = 1LL << 60;

int main() {
  int N;
  std::cin >> N;
  std::vector<long long> height(N);
  for (int i = 0; i < N; ++i) {
    std::cin >> height[i];
  }

  std::vector<long long> dp(N, INF);
  dp[0] = 0;

  for (int i = 1; i < N; ++i) {
    chmin(dp[i], dp[i - 1] + abs(height[i] - height[i - 1]));
    if (i > 1) {
      chmin(dp[i], dp[i - 2] + abs(height[i] - height[i - 2]));
    }
  }

  std::cout << dp[N - 1] << std::endl;
}