#include <iostream>
#include <vector>

int main() {
  int N, W;
  std::cin >> N >> W;

  std::vector<int> a(N);
  for (int i = 0; i < N; ++i) {
    std::cin >> a[i];
  }

  std::vector<std::vector<bool>> dp(N + 1, std::vector<bool>(W + 1, false));
  dp[0][0] = true;

  for (int i = 1; i <= N; ++i) {
    for (int w = 0; w <= W; ++w) {
      // 選ばない
      dp[i][w] = dp[i - 1][w];

      if (w - a[i - 1] >= 0) {
        // 選ぶ
        dp[i][w] = dp[i][w] || dp[i - 1][w - a[i - 1]];
      }
    }
  }

  if (dp[N][W]) {
    std::cout << "Yes" << std::endl;
  } else {
    std::cout << "No" << std::endl;
  }
}