#include <iostream>
#include <vector>

int main() {
  int N, W = 10000;  // 取りうる値は Max で 10000
  std::cin >> N;
  std::vector<int> p(N);
  for (int i = 0; i < N; ++i) {
    std::cin >> p[i];
  }

  std::vector<std::vector<bool>> dp(N + 1, std::vector<bool>(W + 1, false));
  dp[0][0] = true;

  for (int i = 1; i <= N; ++i) {
    for (int w = 0; w <= W; ++w) {
      dp[i][w] = dp[i - 1][w];

      if (w - p[i - 1] >= 0) {
        dp[i][w] = dp[i][w] || dp[i - 1][w - p[i - 1]];
      }
    }
  }

  int result = 0;
  for (int w = 0; w <= W; ++w) {
    if (dp[N][w]) ++result;
  }

  std::cout << result << std::endl;
}