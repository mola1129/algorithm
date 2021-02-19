#include <iostream>
#include <vector>

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
  for (int i = 0; i < N - 1; ++i) {
    // 足場 i -> 足場 i + 1
    dp[i + 1] =
        std::min(dp[i + 1], dp[i] + std::abs(height[i + 1] - height[i]));

    if ((i + 2) < N) {
      // 足場 i -> 足場 i + 2
      dp[i + 2] =
          std::min(dp[i + 2], dp[i] + std::abs(height[i + 2] - height[i]));
    }
  }

  std::cout << dp[N - 1] << std::endl;
}
