#include <iostream>
#include <vector>

constexpr long long INF = 1LL << 60;

// 貰う DP
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
    if (i == 1) {
      // 足場 0 -> 足場 1 のみ 1通り
      dp[i] = abs(height[i] - height[i - 1]);
    } else {
      dp[i] = std::min(dp[i - 1] + abs(height[i] - height[i - 1]),
                       dp[i - 2] + abs(height[i - 2] - height[i]));
    }
  }

  std::cout << dp[N - 1] << std::endl;
}